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
