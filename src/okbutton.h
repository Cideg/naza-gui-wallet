// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#pragma once

#include <QPushButton>

namespace WalletGUI {

class WalletOkButton : public QPushButton
{
    Q_OBJECT
    Q_DISABLE_COPY(WalletOkButton)

public:
    explicit WalletOkButton(QWidget* parent);
    ~WalletOkButton();
};

}
