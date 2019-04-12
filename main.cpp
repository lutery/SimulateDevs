#include <QCoreApplication>
#include <iostream>
#include "devinit.h"
#include "devicemanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DevInit devInit;
//    devInit.initParam();

    std::cout << devInit;

    DeviceManager devManager(devInit);

    return a.exec();
}
