#include "devicemanager.h"
#include "devclient.h"
#include "devinit.h"

DeviceManager::DeviceManager(QObject *parent) : QObject(parent)
{

}

DeviceManager::DeviceManager(DevInit &devInit, QObject *parent):QObject (parent)
  ,mDevCount(devInit.devCount()),mServerIP(devInit.serverIP()),mServerPort(devInit.serverPort())
{
    for (int i = 0; i < mDevCount; ++i)
    {
        DevClient* devClient = new DevClient(nullptr);
        devClient->initDevice(mServerIP, mServerPort);

        mDevs.append(devClient);
    }
}

DeviceManager::~DeviceManager()
{
    qDebug() << "释放所有客户端";

    for (auto& pDevClient : mDevs)
    {
        delete pDevClient;
    }
}
