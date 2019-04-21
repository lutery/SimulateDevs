#include "abshandler.h"
#include "crc16xmodemverify.h"
#include "crc16ccitt.h"
#include <QDebug>

AbsHandler::AbsHandler(QObject *parent) : QObject(parent)
{
    mpVerify = new CRC16CCITT();
}

AbsHandler::~AbsHandler()
{

}

void AbsHandler::ReadDataHandler(DevClient &devClient, DeviceOrder &deviceOrder)
{
    qDebug() << "handler data";

    if (this->handle(devClient, deviceOrder))
    {
        return;
    }
    else
    {
        if (this->mpNext != nullptr)
        {
            this->mpNext->ReadDataHandler(devClient, deviceOrder);
        }
    }
}

void AbsHandler::setNext(AbsHandler *pNext)
{
    mpNext = pNext;
}
