#include "QQInfo.h"

QQInfo::QQInfo()
{
}

QQInfo::QQInfo(QString identificationNumber, QString userAddress, QString registerDate, QString birthDate, QString qqNumber, QString qqName)
	:BaseInfo(identificationNumber, userAddress, registerDate, birthDate)
{
	this->qqNumber = qqNumber;
	this->qqName = qqName;
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
