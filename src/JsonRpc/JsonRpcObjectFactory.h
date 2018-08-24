// Copyright (c) 2012-2018, The CryptoNote developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

// Copyright (c) 2018-2019, The Naza developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.


#include <QByteArray>

class QJsonObject;
class QJsonValue;

namespace JsonRpc {

class JsonRpcObject;

class JsonRpcObjectFactory {
public:
  static JsonRpcObject* createJsonRpcObject(const QJsonValue& _jsonValue, int& _jsonRpcErrorCode, QString& _jsonRpcErrorString,
    QString& _jsonRpcErrorData);

private:
  static JsonRpcObject* parseJsonRpcObject(const QJsonObject& _jsonObject, int& _jsonRpcErrorCode, QString& _jsonRpcErrorString,
  QString& _jsonRpcErrorData);
};

}
