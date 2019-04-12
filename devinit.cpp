#include "devinit.h"
#include <iostream>
#include <string>

using namespace std;

DevInit::DevInit(QObject *parent) : QObject(parent)
{

}

ostream & operator<<(ostream &out, DevInit& devInit)
{
    out << "devNumbers is " << devInit.mDevCount << std::endl;
    out << "serverIp is " << devInit.mServerIP.toStdString() << std::endl;
    out << "serverPort is " << devInit.mServerPort << std::endl;

    return out;
}

void DevInit::initParam()
{
    int devNumbers = 1;
    cout << "please enter dev number: ";
    cin >> devNumbers;
//    cin.ignore(INT_MAX);

    if (devNumbers <= 0)
    {
        cout << "enter an incorrect number, default devNumbers is 1";
        devNumbers = 1;
    }

    mDevCount = devNumbers;

    cout << "please enter server ip(default serverprinter.com.cn):";
    std::string serverIP;
    cin >> serverIP;
//    cin.ignore(INT_MAX);

    if (serverIP.length() > 5)
    {
        mServerIP = QString::fromStdString(serverIP);
    }

    cout << "please enter server port(default port is 9100):";
    int serverPort;
    cin >> serverPort;
//    cin.ignore(INT_MAX);

    if (serverPort > 0)
    {
        mServerPort = serverPort;
    }
}

QString DevInit::serverIP() const
{
    return mServerIP;
}

int DevInit::serverPort() const
{
    return mServerPort;
}

int DevInit::devCount() const
{
    return mDevCount;
}
