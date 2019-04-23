#include "devdaemon.h"
#include "devinit.h"
#include "devicemanager.h"
#include <QEventLoop>

DevDaemon::DevDaemon(DevInit *pDevInit, QObject *parent) : QThread(parent)
{
    mpDevInit = pDevInit;
}

void DevDaemon::run()
{
        QEventLoop loop;
        DeviceManager::getInstance(*mpDevInit);
        QObject::connect(DeviceManager::getInstance(), SIGNAL(finish()), &loop, SLOT(quit()));
        loop.exec();
    while (true)
    {

    }
}
