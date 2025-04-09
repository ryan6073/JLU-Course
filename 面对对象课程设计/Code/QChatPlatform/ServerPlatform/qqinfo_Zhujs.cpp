#include "qqinfo_Zhujs.h"

QQInfo_Zhujs::QQInfo_Zhujs()
{

}

QQInfo_Zhujs::QQInfo_Zhujs(QString qqNumber, QString qqName, QString registerDate,QString qqPassword)
{
    this->qqNumber = qqNumber;
    this->qqName = qqName;
    this->registerDate = registerDate;
    this->qqPassword = qqPassword;
}

QQInfo_Zhujs::~QQInfo_Zhujs()
{

}

QString QQInfo_Zhujs::getNumber()
{
    return qqNumber;
}

QString QQInfo_Zhujs::getName()
{
    return qqName;
}

QString QQInfo_Zhujs::getRegister()
{
    return registerDate;
}

QString QQInfo_Zhujs::getPassword()
{
    return qqPassword;
}

void QQInfo_Zhujs::setNumber(QString qqNumber)
{
    this->qqNumber = qqNumber;
}

void QQInfo_Zhujs::setName(QString qqName)
{
    this->qqName = qqName;
}

void QQInfo_Zhujs::setRegister(QString registerDate)
{
    this->registerDate = registerDate;
}

void QQInfo_Zhujs::setPassword(QString qqPassword)
{
    this->qqPassword = qqPassword;
}
