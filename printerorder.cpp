#include "printerorder.h"

PrinterOrder::PrinterOrder()
{

}

QByteArray PrinterOrder::DEVINIT()
{
    static QByteArray devInit = QByteArrayLiteral("\x11\x00\x00\x00");

    return devInit;
}

QByteArray PrinterOrder::DEVINFO()
{
    static QByteArray devInfo = QByteArrayLiteral("\x00\x00\x00\x00");

    return devInfo;
}

QByteArray PrinterOrder::HEARTBEAT()
{
    static QByteArray heartBeat = QByteArrayLiteral("\xff\x00\x00\x00");

    return heartBeat;
}