// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#ifndef IMPORTKEYDIALOG_H
#define IMPORTKEYDIALOG_H

#include <QDialog>

namespace Ui {
class ImportKeyDialog;
}

namespace WalletGUI
{

class ImportKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImportKeyDialog(QWidget *parent = 0);
    ~ImportKeyDialog();

    QByteArray getKey() const;

private slots:
    void loadKey();
    void keyChanged();

private:
    Ui::ImportKeyDialog *ui;
    QByteArray key_;
};

}

#endif // IMPORTKEYDIALOG_H
