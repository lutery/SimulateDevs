#include "devstatushandler.h"
#include "printerorder.h"
#include <random>

DevStatusHandler::DevStatusHandler(QObject *parent) : AbsHandler(parent)
{

}

DevStatusHandler::~DevStatusHandler()
{

}

bool DevStatusHandler::handle(DevClient &devClient, DeviceOrder &deviceOrder)
{
    if (deviceOrder.orderType().at(0) != PrinterOrder::GETDEVSTATUS().at(0))
    {
        return false;
    }

    qDebug() << "服务器请求设备状态";

    std::default_random_engine random;

}
