// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>

#include <iostream>

using namespace std;

#include "emailsenddialog.h"
#include "ui_emailsenddialog.h"

namespace WalletGUI
{
	EmailSendDialog::EmailSendDialog(QWidget* parent)
		: QDialog(parent)
		, m_ui(new Ui::EmailSendDialog)
	{
		m_ui->setupUi(this);
	}

	EmailSendDialog::~EmailSendDialog()
	{
		delete m_ui;
	}

	EmailAddress* EmailSendDialog::stringToEmail(const QString & str)
	{
		int p1 = str.indexOf("<");
		int p2 = str.indexOf(">");
		if (p1 == -1)
		{
			// no name, only email address
			return new EmailAddress(str);
		}
		else
		{
			return new EmailAddress(str.mid(p1 + 1, p2 - p1 - 1), str.left(p1));
		}
	}


	void EmailSendDialog::errorMessage(const QString & message)
	{
		QErrorMessage err(this);
		err.showMessage(message);
		err.exec();
	}

	Q_SLOT void EmailSendDialog::on_addAttachment_clicked()
	{
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::ExistingFiles);
		if (dialog.exec())
			m_ui->attachments->addItems(dialog.selectedFiles());
	}

	Q_SLOT void EmailSendDialog::on_sendEmail_clicked()
	{
		QString host = m_ui->host->text();
		int port = m_ui->port->value();
		bool ssl = m_ui->ssl->isChecked();
		bool auth = m_ui->auth->isChecked();
		QString user = m_ui->username->text();
		QString password = m_ui->password->text();

		EmailAddress * sender = stringToEmail(m_ui->sender->text());

		QStringList rcptStringList = m_ui->recipients->text().split(';');

		QString subject = m_ui->subject->text();
		QString html = m_ui->texteditor->toHtml();

		SmtpClient smtp(host, port, ssl ? SmtpClient::SslConnection : SmtpClient::TcpConnection);

		MimeMessage message;

		message.setSender(sender);
		message.setSubject(subject);

		for (int i = 0; i < rcptStringList.size(); ++i)
			message.addRecipient(stringToEmail(rcptStringList.at(i)));

		MimeHtml content;
		content.setHtml(html);

		message.addPart(&content);

		for (int i = 0; i < m_ui->attachments->count(); ++i)
		{
			message.addPart(new MimeAttachment(new QFile(m_ui->attachments->item(i)->text())));
		}

		if (!smtp.connectToHost())
		{
			errorMessage("Connection Failed!!");


			return;
		}

		if (auth)
			if (!smtp.login(user, password))
			{
				errorMessage("Authentification Failed!!");
				return;
			}

		if (!smtp.sendMail(message))
		{
			errorMessage("Mail sending failed!!");
			return;
		}
		else
		{
			QMessageBox okMessage(this);
			okMessage.setText("The email was succesfully sent!!");
			okMessage.exec();

		}

		smtp.quit();
	}



}
