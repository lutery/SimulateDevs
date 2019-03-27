#ifndef DEVCLIENT_H
#define DEVCLIENT_H

#include <QObject>
#include <QAbstractSocket>

class QTcpSocket;

class DevClient : public QObject
{
    Q_OBJECT
public:
    explicit DevClient(QObject *parent = nullptr);
    void initDevice(QString serverIP, int serverPort);

signals:

public slots:
    void readData();
    void netError(QAbstractSocket::SocketError& socketError);

private:
    QTcpSocket* mpClient;
};

#endif // DEVCLIENT_H
