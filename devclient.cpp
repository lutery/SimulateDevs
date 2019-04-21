#include "devclient.h"
#include <QTcpSocket>
#include <QDebug>
#include <QUuid>
#include "toolutil.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "printerorder.h"
#include <QByteArray>
#include "devinfohandler.h"
#include "unknownorderhandler.h"

DevClient::DevClient(QObject *parent) : QObject(parent), mpClient(nullptr)
{
    mpClient = new QTcpSocket(this);

    connect(mpClient, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(mpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(netError()));
    connect(mpClient, SIGNAL(connected()), this, SLOT(connected()));
    connect(mpClient, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(mpClient, SIGNAL(bytesWritten), this, SLOT(hasWritten()));


    DevInfoHandler* infoHandler = new DevInfoHandler();
    UnknownOrderHandler* unknownHandler = new UnknownOrderHandler();

    mpHandler = infoHandler;
    infoHandler->setNext(unknownHandler);
}

void DevClient::initDevice(QString serverIP, quint16 serverPort)
{
    mpClient->connectToHost(serverIP, serverPort);
    mDevID = ToolUtil::str2Md5(QUuid::createUuid().toString());
}

void DevClient::readData()
{
    qDebug() << "receive dara";

    if (mpClient->bytesAvailable() <= 0)
    {
        return;
    }

    QByteArray readBuff = mpClient->readAll();
    mBuffLock.lock();
    mClientBuff.append(readBuff);
    mBuffLock.unlock();

    int lenthOfCheck = 1;
    int lengthOfContent = 4;
    int lengthOfOrder = 4;
    char endByte = 0x24;

    int headerLength = lenthOfCheck + lengthOfOrder + lengthOfContent;
    if (mClientBuff.length() <= headerLength)
    {
        return;
    }

    char verifyByte = mClientBuff.at(8);
    int lengthOfVerifyType = ToolUtil::verifyTypeLength(VerifyType(verifyByte));

    if (mClientBuff.length() <= (lengthOfVerifyType + headerLength))
    {
        return;
    }

    QByteArray lengthOfJson;
    lengthOfJson[0] = mClientBuff[3];
    lengthOfJson[1] = mClientBuff[4];
    lengthOfJson[2] = mClientBuff[5];
    lengthOfJson[3] = mClientBuff[6];

    int jsonLength = ToolUtil::bytesToInt(lengthOfJson);

    if (mClientBuff.length() <= (jsonLength + lengthOfVerifyType + headerLength))
    {
        return;
    }

    int endIndex = jsonLength + lengthOfVerifyType + headerLength;
    if (endByte != mClientBuff[endIndex])
    {
        qDebug() << "严重错误，尾部标识错误";
        return;
    }

    DeviceOrder deviceOrder;
    deviceOrder.setOrderType(mClientBuff.mid(0, lengthOfOrder));
    deviceOrder.setMlengthBytes(mClientBuff.mid(lengthOfOrder, lengthOfContent));
    deviceOrder.setVerifyType(mClientBuff.mid((lengthOfOrder + lengthOfContent), lenthOfCheck));
    deviceOrder.setVerifyCode(mClientBuff.mid((lengthOfOrder + lengthOfContent + lenthOfCheck), lengthOfVerifyType));
    deviceOrder.setVerifyCode(mClientBuff.mid((lengthOfOrder + lengthOfContent + lenthOfCheck + lengthOfVerifyType), jsonLength));
    deviceOrder.setEnd(mClientBuff.mid(endIndex));

    mClientBuff = mClientBuff.right(mClientBuff.length() - (lengthOfOrder + lengthOfContent + lenthOfCheck + lengthOfVerifyType + jsonLength + 1));

    mpHandler->ReadDataHandler(*this, deviceOrder);
}

void DevClient::netError(QAbstractSocket::SocketError& socketError)
{

}

void DevClient::connected()
{
    qDebug() << "与服务器连接成功";

    QByteArray initArray;
    initArray.append(PrinterOrder::DEVINIT());
    initArray.append(QByteArrayLiteral("\x00\x00\x00\x00"));
    initArray.append(QByteArrayLiteral("\x03\x00\x00"));
    initArray.append(QByteArrayLiteral("\x24"));

    mpClient->write(initArray);
}

void DevClient::disconnected()
{
    qDebug() << "与服务器断开连接";
}

void DevClient::hasWritten(qint64 bytes)
{
    qDebug() << "has writer bytes count is " << bytes;
}

void DevClient::writeAndFlush(QByteArray &data)
{
    mpClient->write(data);
    mpClient->flush();
}

QString DevClient::devID() const
{
    return mDevID;
}
