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
    return data.toHex().toInt();
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
