// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

#include <QFileDialog>
#include <QMessageBox>

#include "exportkeydialog.h"
#include "ui_exportkeydialog.h"

namespace WalletGUI
{

ExportKeyDialog::ExportKeyDialog(const QString& key, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExportKeyDialog)
{
    ui->setupUi(this);
    ui->keyEdit->setPlainText(key);
}

ExportKeyDialog::~ExportKeyDialog()
{
    ui->keyEdit->setText(QString{1000, '0'});
    ui->keyEdit->clear();
    delete ui;
}

void ExportKeyDialog::saveKey()
{
    const QString filePath =
            QFileDialog::getSaveFileName(
                this,
                tr("Save key to..."),
                QDir::homePath(),
                tr("Key file (*)"));

    if (filePath.isEmpty())
        return;

    QFile keyFile(filePath);
    if (!keyFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save key to the selected file."));
        return;
    }

    keyFile.write(QByteArray::fromHex(ui->keyEdit->toPlainText().toUtf8()));
    keyFile.close();
}

}
