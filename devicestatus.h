#ifndef DEVICESTATUS_H
#define DEVICESTATUS_H

#include <QMap>

class DeviceStatus
{
public:
    static QMap<QByteArray, QString> shortOfPaper();
    static QMap<QByteArray, QString> ready();
    static QMap<QByteArray, QString> offline();
    static QMap<QByteArray, QString> printing();
};

#endif // DEVICESTATUS_H
