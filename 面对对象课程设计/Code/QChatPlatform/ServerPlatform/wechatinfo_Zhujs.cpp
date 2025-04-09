#include "wechatinfo_Zhujs.h"

WeChatInfo_Zhujs::WeChatInfo_Zhujs()
{

}

WeChatInfo_Zhujs::WeChatInfo_Zhujs(QString wechatNumber, QString wechatName, QString registerDate, QString wechatPassword)
{
    this->wechatNumber = wechatNumber;
    this->wechatName = wechatName;
    this->registerDate = registerDate;
    this->wechatPassword = wechatPassword;
}

WeChatInfo_Zhujs::~WeChatInfo_Zhujs()
{

}

QString WeChatInfo_Zhujs::getNumber()
{
    return wechatNumber;
}

QString WeChatInfo_Zhujs::getName()
{
    return wechatName;
}

QString WeChatInfo_Zhujs::getRegister()
{
    return registerDate;
}

QString WeChatInfo_Zhujs::getPassword()
{
    return wechatPassword;
}
