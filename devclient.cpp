#include "devclient.h"
#include <QTcpSocket>

DevClient::DevClient(QObject *parent) : QObject(parent), mpClient(nullptr)
{
    mpClient = new QTcpSocket(this);

    connect(mpClient, SIGNAL(readyRead), this, SLOT(readData));
    connect(mpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(netError));
    connect(mpClient, )
}

void DevClient::initDevice(QString serverIP, int serverPort)
{
    mpClient->connectToHost(serverIP, serverPort);
}

void DevClient::readData()
{

}

void DevClient::netError(QAbstractSocket::SocketError& socketError)
{

}
