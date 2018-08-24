// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#ifndef EMAILSENDDIALOG_H
#define EMAILSENDDIALOG_H

#include "email/email.h"
#include <QDialog>

namespace Ui {
	class EmailSendDialog;
}

namespace WalletGUI
{

	class EmailSendDialog : public QDialog {
		Q_OBJECT
		Q_DISABLE_COPY(EmailSendDialog)

	public:
		explicit EmailSendDialog(QWidget* _parent);
		~EmailSendDialog();

		static EmailAddress * stringToEmail(const QString & str);

	private:
		Ui::EmailSendDialog* m_ui;
		void errorMessage(const QString & message);

		Q_SLOT   void on_addAttachment_clicked();
		Q_SLOT   void on_sendEmail_clicked();

	};


}


#endif
