#ifndef TOOLUTIL_H
#define TOOLUTIL_H

#include <QString>
#include <QByteArray>

class ToolUtil
{
private:
    ToolUtil();

public:
    static QString str2Md5(QString&& str);
    static QString bytes2Md5(QByteArray& byteArray);
};

#endif // TOOLUTIL_H
