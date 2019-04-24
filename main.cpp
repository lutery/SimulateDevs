#include <QCoreApplication>
#include <iostream>
#include "devinit.h"
#include "devicemanager.h"
#include <QEventLoop>
#include <QDebug>
#include "devdaemon.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DevInit devInit;
//    devInit.initParam();

    std::cout << devInit;

//    DevDaemon devDaemon(&devInit);
//    devDaemon.start();

//    for (;;)
//    {

//    }
    QEventLoop loop;
    DeviceManager::getInstance(devInit);
    QObject::connect(DeviceManager::getInstance(), SIGNAL(finish()), &loop, SLOT(quit()));
    loop.exec();

//    qDebug() << "core application exit";

    return a.exec();
//    return loop.exec();
}
