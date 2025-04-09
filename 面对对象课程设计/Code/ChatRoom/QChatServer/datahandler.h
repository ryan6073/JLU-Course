#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "qqinfo.h"
#include <QList>
#include <QDomDocument>
#include <QTextStream>
#include <QDir>

class DataHandler
{
private:
    DataHandler();
    ~DataHandler();

public:
    static DataHandler* GetInstance();

    bool registerQQ(QString qqNumber, QString qqName, QString registerDate,QString qqPassword,
                    QString identificationNumber = "",QString userAddress = "", QString birthDate = "");
    bool loginQQ(QString qqNumber, QString qqPassword);

    QQInfo queryQQ(QString qqNumber,bool& outRet);
    bool updateQQ(QString qqNumber, QString qqName, QString registerDate,QString qqPassword,
                  QString identificationNumber = "",QString userAddress = "", QString birthDate = "");
    bool addQQFriend(QString qqNumber,QString friendNumber);
    bool deleteQQFriend(QString qqNumber,QString friendNumber);
    bool alterQQFriend(QString qqNumber,QString friendNumber,QString remark);
    QVariantMap getQQFriendList(QString qqNumber);
    bool isQQFriend(QString qqNumber,QString friendNumber);

    void writeQQ();
    bool readQQ();

public:
    QList<QQInfo> qqList;
};

#endif // DATAHANDLER_H
