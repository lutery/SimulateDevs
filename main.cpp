#include <QCoreApplication>
#include <iostream>
#include "devinit.h"
#include "devicemanager.h"
#include <QEventLoop>
#include <QDebug>
#include <QThreadPool>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "max thread count " << QThreadPool::globalInstance()->maxThreadCount() << "stack Size is " << QThreadPool::globalInstance()->stackSize();
    QThreadPool::globalInstance()->setMaxThreadCount(100);

    DevInit devInit;
    devInit.initParam();

    std::cout << devInit;

    QEventLoop loop;
    DeviceManager::getInstance(devInit);
    QObject::connect(DeviceManager::getInstance(), SIGNAL(finish()), &loop, SLOT(quit()));
    loop.exec();

    return a.exec();
//    return loop.exec();
}
