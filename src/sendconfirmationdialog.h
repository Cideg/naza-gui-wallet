// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#ifndef SENDCONFIRMATIONDIALOG
#define SENDCONFIRMATIONDIALOG

#include <QMessageBox>
#include <QTimer>

class QAbstractButton;

namespace WalletGUI
{

class SendConfirmationDialog : public QMessageBox
{
    Q_OBJECT

public:
    SendConfirmationDialog(
            const QString& title,
            const QString& text,
            int secDelay,
            QWidget *parent = 0);

    int exec();

private slots:
    void countDown();
    void updateYesButton();

private:
    QAbstractButton* yesButton_;
    QTimer countDownTimer_;
    int seconds_;
};

}

#endif // SENDCONFIRMATIONDIALOG

