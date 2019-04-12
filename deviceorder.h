#ifndef DEVICEORDER_H
#define DEVICEORDER_H

#include <QByteArray>

class DeviceOrder
{
public:
    DeviceOrder();

    QByteArray combine();

    QByteArray orderType() const;
    void setOrderType(const QByteArray &orderType);

private:
    QByteArray mOrderType;
};

#endif // DEVICEORDER_H
