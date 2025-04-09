#include "BaseInfo_Zhujs.h"

BaseInfo_Zhujs::BaseInfo_Zhujs()
{
}

BaseInfo_Zhujs::BaseInfo_Zhujs(QString identificationNumber, QString userAddress, QString birthDate)
{
    this->identificationNumber = identificationNumber;
    this->userAddress = userAddress;
    this->birthDate = birthDate;
}

BaseInfo_Zhujs::~BaseInfo_Zhujs()
{
}

QString BaseInfo_Zhujs::getIdentificationNumber()
{
    return identificationNumber;
}

QString BaseInfo_Zhujs::getUserAddress()
{
    return userAddress;
}

QString BaseInfo_Zhujs::getBirthDate()
{
    return birthDate;
}

void BaseInfo_Zhujs::setIdentificationNumber(QString identificationNumber)
{
    this->identificationNumber = identificationNumber;
}

void BaseInfo_Zhujs::setUserAddress(QString userAddress)
{
    this->userAddress = userAddress;
}

void BaseInfo_Zhujs::setBirthDate(QString birthDate)
{
    this->birthDate = birthDate;
}
