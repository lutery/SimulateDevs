#include "deviceorder.h"

DeviceOrder::DeviceOrder()
{

}

QByteArray DeviceOrder::combine()
{
    return QByteArrayLiteral("\x00");
}

QByteArray DeviceOrder::orderType() const
{
    return mOrderType;
}

void DeviceOrder::setOrderType(const QByteArray &orderType)
{
    mOrderType = orderType;
}
