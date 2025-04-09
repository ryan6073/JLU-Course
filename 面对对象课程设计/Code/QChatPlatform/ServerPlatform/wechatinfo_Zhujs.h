#ifndef WECHATINFO_H
#define WECHATINFO_H

#include "BaseInfo_Zhujs.h"

class WeChatInfo_Zhujs : public BaseInfo_Zhujs
{
public:
    WeChatInfo_Zhujs();
    WeChatInfo_Zhujs(QString wechatNumber, QString wechatName, QString registerDate,QString wechatPassword);
    ~WeChatInfo_Zhujs();

    QString getNumber();
    QString getName();
    QString getRegister();
    QString getPassword();

private:
    QString wechatNumber;
    QString wechatName;
    QString registerDate;
    QString wechatPassword;
};

#endif // WECHATINFO_H
