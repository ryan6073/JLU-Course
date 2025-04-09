#include "qqinfo.h"

QQInfo::QQInfo()
{

}

QQInfo::QQInfo(QString qqNumber, QString qqName, QString registerDate,QString qqPassword)
{
    this->qqNumber = qqNumber;
    this->qqName = qqName;
    this->registerDate = registerDate;
    this->qqPassword = qqPassword;
}

QQInfo::~QQInfo()
{

}

QString QQInfo::getNumber()
{
    return qqNumber;
}

QString QQInfo::getName()
{
    return qqName;
}

QString QQInfo::getRegister()
{
    return registerDate;
}

QString QQInfo::getPassword()
{
    return qqPassword;
}

void QQInfo::setNumber(QString qqNumber)
{
    this->qqNumber = qqNumber;
}

void QQInfo::setName(QString qqName)
{
    this->qqName = qqName;
}

void QQInfo::setRegister(QString registerDate)
{
    this->registerDate = registerDate;
}

void QQInfo::setPassword(QString qqPassword)
{
    this->qqPassword = qqPassword;
}
