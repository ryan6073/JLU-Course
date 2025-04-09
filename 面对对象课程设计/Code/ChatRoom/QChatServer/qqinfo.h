#ifndef QQINFO_H
#define QQINFO_H

#include "baseinfo.h"
#include <QMap>
#include <QVariantMap>

class QQInfo : public BaseInfo
{
public:
    QQInfo();
    QQInfo(QString qqNumber, QString qqName, QString registerDate,QString qqPassword);
    ~QQInfo();

    QString getNumber();
    QString getName();
    QString getRegister();
    QString getPassword();

    void setNumber(QString qqNumber);
    void setName(QString qqName);
    void setRegister(QString registerDate);
    void setPassword(QString qqPassword);

    QVariantMap friendMap;

private:
    QString qqNumber;
    QString qqName;
    QString registerDate;
    QString qqPassword;
};

#endif // QQINFO_H
