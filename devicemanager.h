#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include <QObject>
#include <QVector>

class DevClient;
class DevInit;

class DeviceManager : public QObject
{
    Q_OBJECT
public:
    explicit DeviceManager(QObject *parent = nullptr);
    explicit DeviceManager(DevInit& devInit, QObject* parent = nullptr);
    ~DeviceManager();

signals:

public slots:

private:
    int mDevCount;
    QString mServerIP;
    int mServerPort;
    QVector<DevClient*> mDevs;
};

#endif // DEVICEMANAGER_H
