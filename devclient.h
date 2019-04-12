#ifndef DEVCLIENT_H
#define DEVCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QMutex>

class QTcpSocket;

class DevClient : public QObject
{
    Q_OBJECT
public:
    explicit DevClient(QObject *parent = nullptr);
    void initDevice(QString serverIP, quint16 serverPort);

signals:

public slots:
    void readData();
    void netError(QAbstractSocket::SocketError& socketError);
    void connected();
    void disconnected();

private:
    QTcpSocket* mpClient;
    QByteArray mClientBuff;
    QMutex mBuffLock;
    QString mDevID;
};

#endif // DEVCLIENT_H
