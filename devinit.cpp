#include "devinit.h"
#include <iostream>

using namespace std;

DevInit::DevInit(QObject *parent) : QObject(parent)
{

}

void DevInit::initParam()
{
    int devNumbers = 1;
    cout << "please enter dev number: ";
    cin >> devNumbers;

    if (devNumbers <= 0)
    {
        cout << "enter an incorrect number, default devNumbers is 1";
        devNumbers = 1;
    }

    mDevCount = devNumbers;
}
