#ifndef QQINFO_H
#define QQINFO_H

#include "BaseInfo_Zhujs.h"
#include <QMap>
#include <QVariantMap>

class QQInfo_Zhujs : public BaseInfo_Zhujs
{
public:
    QQInfo_Zhujs();
    QQInfo_Zhujs(QString qqNumber, QString qqName, QString registerDate,QString qqPassword);
    ~QQInfo_Zhujs();

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
