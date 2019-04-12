#include "abshandler.h"

AbsHandler::AbsHandler(QObject *parent) : QObject(parent)
{

}

AbsHandler::~AbsHandler()
{

}

void AbsHandler::ReadDataHandler(DevClient &devClient, DeviceOrder &deviceOrder)
{
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
