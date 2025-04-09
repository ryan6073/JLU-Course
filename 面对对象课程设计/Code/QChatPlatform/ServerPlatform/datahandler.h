#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "qqinfo_Zhujs.h"
#include "wechatinfo_Zhujs.h"

#include <QList>
#include <QDomDocument>
#include <QTextStream>
#include <QDir>
#include <fstream>
using namespace std;

struct Function
{
    bool qqOpen = false;
    bool weChatOpen = false;
    bool weiBoOpen = false;
};

class DataHandler
{
private:
    DataHandler();
    ~DataHandler();

public:
    static DataHandler* GetInstance();

    bool canRegister(QString identification,int type);
    bool registerQQ(QString qqNumber, QString qqName, QString registerDate,QString qqPassword,
                    QString identificationNumber = "",QString userAddress = "", QString birthDate = "");
    bool loginQQ(QString qqNumber, QString qqPassword);

    QQInfo_Zhujs queryQQ(QString qqNumber,bool& outRet);
    bool updateQQ(QString qqNumber, QString qqName, QString registerDate,QString qqPassword,
                  QString identificationNumber = "",QString userAddress = "", QString birthDate = "");
    bool addQQFriend(QString qqNumber,QString friendNumber);
    bool deleteQQFriend(QString qqNumber,QString friendNumber);
    bool alterQQFriend(QString qqNumber,QString friendNumber,QString remark);
    QVariantMap getQQFriendList(QString qqNumber);
    bool isQQFriend(QString qqNumber,QString friendNumber);

    void writeQQ();
    bool readQQ();

    void writeFunction();
    void readFunction();

    bool registerWeChat(QString wechatNumber, QString wechatName, QString registerDate,QString wechatPassword,
                    QString identificationNumber = "",QString userAddress = "", QString birthDate = "");
    bool loginWeChat(QString wechatNumber, QString wechatPassword);

    QString getIdentification(QString number,bool isQQ = true);

    void writeWeChat();
    bool readWeChat();

public:
    QList<QQInfo_Zhujs> qqList;
    QList<WeChatInfo_Zhujs> wechatList;
    QMap<QString,Function> functionMap;
};

#endif // DATAHANDLER_H
