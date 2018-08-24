// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#ifndef EXPORTKEYDIALOG_H
#define EXPORTKEYDIALOG_H

#include <QDialog>

namespace Ui {
class ExportKeyDialog;
}

namespace WalletGUI
{

class ExportKeyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportKeyDialog(const QString& key, QWidget *parent = 0);
    ~ExportKeyDialog();

public slots:
    void saveKey();

private:
    Ui::ExportKeyDialog *ui;
};

}

#endif // EXPORTKEYDIALOG_H
