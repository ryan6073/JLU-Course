#ifndef BaseInfo_Zhujs_H
#define BaseInfo_Zhujs_H

#include <QString>

class BaseInfo_Zhujs
{
public:
    BaseInfo_Zhujs();
    BaseInfo_Zhujs(QString identificationNumber, QString userAddress, QString birthDate);
    virtual ~BaseInfo_Zhujs();

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

#endif // BaseInfo_Zhujs_H
