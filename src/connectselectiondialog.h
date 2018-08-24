// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#ifndef CONNECTSELECTIONDIALOG_H
#define CONNECTSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectSelectionDialog;
}

namespace WalletGUI
{

class ConnectSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectSelectionDialog(QWidget *parent = 0);
    ~ConnectSelectionDialog();

    Q_SLOT void accept() override;

private:
    Ui::ConnectSelectionDialog *ui;
};

}

#endif // CONNECTSELECTIONDIALOG_H
