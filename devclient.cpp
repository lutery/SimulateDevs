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

DevClient::DevClient(QObject *parent) : QObject(parent), mpClient(nullptr)
{
    mpClient = new QTcpSocket(this);

    connect(mpClient, SIGNAL(readyRead), this, SLOT(readData));
    connect(mpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(netError));
    connect(mpClient, SIGNAL(connected()), this, SLOT(connected()));
    connect(mpClient, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(mpClient, SIGNAL(bytesWritten), this, SLOT(hasWritten()));
}

void DevClient::initDevice(QString serverIP, quint16 serverPort)
{
    mpClient->connectToHost(serverIP, serverPort);
    mDevID = ToolUtil::str2Md5(QUuid::createUuid().toString());
}

void DevClient::readData()
{
    if (mpClient->bytesAvailable() <= 0)
    {
        return;
    }

    QByteArray readBuff = mpClient->readAll();
    mBuffLock.lock();
    mClientBuff.append(readBuff);
    mBuffLock.unlock();


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

QString DevClient::devID() const
{
    return mDevID;
}
