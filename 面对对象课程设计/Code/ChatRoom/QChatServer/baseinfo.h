#ifndef BASEINFO_H
#define BASEINFO_H

#include <QString>

class BaseInfo
{
public:
    BaseInfo();
    BaseInfo(QString identificationNumber, QString userAddress, QString birthDate);
    ~BaseInfo();

    QString getIdentificationNumber();
    QString getUserAddress();
    QString getBirthDate();

    void setIdentificationNumber(QString identificationNumber);
    void setUserAddress(QString userAddress);
    void setBirthDate(QString birthDate);

private:
    QString identificationNumber;
    QString userAddress;
    QString birthDate;
};

#endif // BASEINFO_H
