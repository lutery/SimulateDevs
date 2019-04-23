#ifndef DEVDAEMON_H
#define DEVDAEMON_H

#include <QThread>

class DevInit;
//class DeviceManager;

class DevDaemon : public QThread
{
    Q_OBJECT
public:
    explicit DevDaemon(DevInit* pDevInit, QObject *parent = nullptr);
    void run() override;

signals:

public slots:

private:
//    DeviceManager* mpDevManager;
    DevInit* mpDevInit;
};

#endif // DEVDAEMON_H
