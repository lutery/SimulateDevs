#include "devinfohandler.h"
#include "toolutil.h"
#include "printerorder.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "iverify.h"

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

    qDebug() << "返回设备信息给服务器";

    QString devId = devClient.devID();

    QJsonObject devInfoJson;
    devInfoJson.insert("deviceid", devId);

    QJsonDocument document;
    document.setObject(devInfoJson);
    QByteArray devBytes = ToolUtil::strCodecTo(document.toJson(), "gb18030");


    QByteArray byteBuf;
    byteBuf.append(PrinterOrder::DEVINFO());
    byteBuf.append(ToolUtil::intToBytes(devBytes.length()));
    byteBuf.append(0x03);
    byteBuf.append(mpVerify->generateVerifyCode(devBytes));
    byteBuf.append(devBytes);
    byteBuf.append(0x24);

    devClient.writeAndFlush(byteBuf);
}