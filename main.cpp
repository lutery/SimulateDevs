#include <QCoreApplication>
#include <iostream>
#include "devinit.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DevInit devInit;
    devInit.initParam();

    return a.exec();
}
