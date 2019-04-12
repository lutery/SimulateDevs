#include "devinfohandler.h"
#include <QJsonObject>
#include <QJsonDocument>

DevInfoHandler::DevInfoHandler(QObject *parent):AbsHandler (parent)
{

}

DevInfoHandler::~DevInfoHandler()
{

}

bool DevInfoHandler::handle(DevClient &devClient, DeviceOrder &deviceOrder)
{
    if (deviceOrder.orderType().at(0) != 0x10)
    {
        return false;
    }

    QString devId = devClient.devID();

    QJsonObject devInfoJson;
    devInfoJson.insert("deviceid", devId);

    QJsonDocument document;
    document.setObject(devInfoJson);
    QByteArray devBytes = document.toJson();


}
