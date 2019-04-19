#include "toolutil.h"
#include <QCryptographicHash>
#include <QTextCodec>

ToolUtil::ToolUtil()
{

}

QString ToolUtil::str2Md5(QString &&str)
{
    return QString().append(QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5).toHex());
}

QString ToolUtil::bytes2Md5(QByteArray &byteArray)
{
    return QString().append(QCryptographicHash::hash(byteArray, QCryptographicHash::Md5).toHex());
}

QByteArray ToolUtil::strCodecTo(QString src, QString toCodec)
{
    QTextCodec* srcStrCodec = QTextCodec::codecForName("utf-8");
    QTextCodec* toStrCodec = QTextCodec::codecForName(toCodec.toLocal8Bit());

    return toStrCodec->fromUnicode(srcStrCodec->toUnicode(src.toUtf8()));
}

QByteArray ToolUtil::intToBytes(int length)
{
    QByteArray intBytes;
    intBytes[0] = (length >> 24) & 0xff;
    intBytes[1] = (length >> 16) & 0xff;
    intBytes[2] = (length >> 8) & 0xff;
    intBytes[3] = (length >> 0) & 0xff;

    return intBytes;
}

int ToolUtil::bytesToInt(QByteArray data)
{
    return data.toHex().toInt(nullptr, 16);
}

QString ToolUtil::bytes2HexStr(QByteArray data)
{
    QString ret(data.toHex().toUpper());
        int len = ret.length()/2;
//        qDebug()<<len;
        for(int i=1;i<len;i++)
        {
//            qDebug()<<i;
            ret.insert(2*i+i-1," ");
        }

        return ret;
}

int ToolUtil::verifyTypeLength(VerifyType verifyType)
{
    switch (verifyType)
    {
    case VerifyType::MD5:
        return 16;

    case VerifyType::CRC8:
        return 1;

    case VerifyType::CRC16:
        return 2;

    case VerifyType::CRC32:
        return 4;

    default:
        return 0;
    }
}

quint16 ToolUtil::generalCRC16(quint16 wCRCin, quint16 wCPoly, quint16 wResultXOR, bool input_invert, bool ouput_invert, const char *puchMsg, int usDataLen)
{
    quint8 wChar = 0;
    while (usDataLen--)
    {
        wChar = *(puchMsg++);
        if(input_invert)//输入值反转
        {
            quint8 temp_char = wChar;
            wChar=0;
            for(int i=0;i<8;++i)
            {
                if(temp_char&0x01)
                    wChar|=0x01<<(7-i);
                temp_char>>=1;
            }
        }
        wCRCin ^= (wChar << 8);
        for (int i = 0; i < 8; i++)
        {
            if (wCRCin & 0x8000)
                wCRCin = (wCRCin << 1) ^ wCPoly;
            else
                wCRCin = wCRCin << 1;
        }
    }
    if(ouput_invert)
    {
        quint16 temp_short = wCRCin;
        wCRCin=0;
        for(int i=0;i<16;++i)
        {
            if(temp_short&0x01)
                wCRCin|=0x01<<(15-i);
            temp_short>>=1;
        }
    }
    return (wCRCin^wResultXOR);
}
