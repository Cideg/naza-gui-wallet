// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#include "addressbooksortedmodel.h"
#include "addressbookmodel.h"

namespace WalletGUI
{

SortedAddressBookModel::SortedAddressBookModel(QAbstractItemModel* _sourceModel, QObject* _parent)
    : QSortFilterProxyModel(_parent)
{
  setSourceModel(_sourceModel);
  setDynamicSortFilter(true);
  sort(AddressBookModel::COLUMN_LABEL, Qt::DescendingOrder);
}

SortedAddressBookModel::~SortedAddressBookModel()
{}

bool SortedAddressBookModel::lessThan(const QModelIndex& _left, const QModelIndex& _right) const
{
  QString leftLabel = _left.data(AddressBookModel::ROLE_LABEL).toString();
  QString rightLabel = _right.data(AddressBookModel::ROLE_LABEL).toString();

  return QString::compare(leftLabel, rightLabel, Qt::CaseInsensitive) > 0;
}

}
