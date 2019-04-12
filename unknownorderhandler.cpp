#include "unknownorderhandler.h"

UnknownOrderHandler::UnknownOrderHandler(QObject *parent):AbsHandler (parent)
{

}

UnknownOrderHandler::~UnknownOrderHandler()
{

}

bool UnknownOrderHandler::handle(DevClient &devClient, DeviceOrder &deviceOrder)
{
    qDebug() << "##############receive unknown data from server start##############";
//    qDebug() <<
    qDebug() << "##############receive unknown data from server end##############";
}
