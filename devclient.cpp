#include "devclient.h"
#include <QTcpSocket>
#include <QDebug>
#include <QUuid>
#include "toolutil.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

DevClient::DevClient(QObject *parent) : QObject(parent), mpClient(nullptr)
{
    mpClient = new QTcpSocket(this);

    connect(mpClient, SIGNAL(readyRead), this, SLOT(readData));
    connect(mpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(netError));
    connect(mpClient, SIGNAL(connected()), this, SLOT(connected()));
    connect(mpClient, SIGNAL(disconnected()), this, SLOT(disconnected()));
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

}

void DevClient::disconnected()
{

}
