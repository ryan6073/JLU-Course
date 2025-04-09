#include "baseinfo.h"

BaseInfo::BaseInfo()
{
}

BaseInfo::BaseInfo(QString identificationNumber, QString userAddress, QString birthDate)
{
    this->identificationNumber = identificationNumber;
    this->userAddress = userAddress;
    this->birthDate = birthDate;
}

BaseInfo::~BaseInfo()
{
}

QString BaseInfo::getIdentificationNumber()
{
    return identificationNumber;
}

QString BaseInfo::getUserAddress()
{
    return userAddress;
}

QString BaseInfo::getBirthDate()
{
    return birthDate;
}

void BaseInfo::setIdentificationNumber(QString identificationNumber)
{
    this->identificationNumber = identificationNumber;
}

void BaseInfo::setUserAddress(QString userAddress)
{
    this->userAddress = userAddress;
}

void BaseInfo::setBirthDate(QString birthDate)
{
    this->birthDate = birthDate;
}
