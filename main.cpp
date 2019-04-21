#include <QCoreApplication>
#include <iostream>
#include "devinit.h"
#include "devicemanager.h"
#include <QEventLoop>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DevInit devInit;
//    devInit.initParam();

    std::cout << devInit;

    QEventLoop loop;
    DeviceManager devManager(devInit);
    QObject::connect(&devManager, SIGNAL(finish()), &loop, SLOT(quit()));
//    loop.exec();

//    return a.exec();
    return loop.exec();
}
