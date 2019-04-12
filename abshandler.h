#ifndef ABSHANDLER_H
#define ABSHANDLER_H

#include <QObject>
#include "devclient.h"
#include "deviceorder.h"

class AbsHandler : public QObject
{
    Q_OBJECT
public:
    explicit AbsHandler(QObject *parent = nullptr);
    virtual ~AbsHandler();

    virtual void ReadDataHandler(DevClient& devClient, DeviceOrder& deviceOrder) final;
    virtual bool handle(DevClient& devClient, DeviceOrder& deviceOrder) = 0;

signals:

public slots:

protected:
    AbsHandler* mpNext;
};

#endif // ABSHANDLER_H
