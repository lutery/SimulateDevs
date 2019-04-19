#include "crc16ccitt.h"

CRC16CCITT::CRC16CCITT(QObject *parent) : IVerify(parent)
{

}

bool CRC16CCITT::verifyContent(QByteArray verifyCode, QByteArray verifyContent)
{

}

QByteArray CRC16CCITT::generateVerifyCode(QByteArray content)
{

}

VerifyType CRC16CCITT::verifyType()
{
    return VerifyType::CRC16CCITT;
}
