#include "datahandler.h"

DataHandler::DataHandler()
{

}

DataHandler::~DataHandler()
{
}

DataHandler* DataHandler::GetInstance()
{
    static DataHandler instance;
    return &instance;
}

bool DataHandler::canRegister(QString identification, int type)
{
    if(functionMap.contains(identification))
    {
        Function function=functionMap[identification];
        if(type==1)
        {
            foreach(QQInfo_Zhujs info,qqList)
            {
                if(info.getIdentificationNumber() == identification)
                {
                    return false;
                }
            }
            return function.qqOpen;
        }
        if(type==2)
        {
            foreach(WeChatInfo_Zhujs info,wechatList)
            {
                if(info.getIdentificationNumber() == identification)
                {
                    return false;
                }
            }
            return function.weChatOpen;
        }
        if(type==3)
        {
            return function.weiBoOpen;
        }
    }
    return false;
}

bool DataHandler::registerQQ(QString qqNumber, QString qqName, QString registerDate, QString qqPassword,QString identificationNumber, QString userAddress, QString birthDate)
{
    if(!canRegister(identificationNumber,1))
    {
        return false;
    }
    foreach(QQInfo_Zhujs info,qqList)
    {
        if(info.getNumber() == qqNumber)
        {
            return false;
        }
    }
    QQInfo_Zhujs newQQ(qqNumber,qqName,registerDate,qqPassword);
    newQQ.setIdentificationNumber(identificationNumber);
    newQQ.setUserAddress(userAddress);
    newQQ.setBirthDate(birthDate);
    qqList.append(newQQ);
    return true;
}

bool DataHandler::loginQQ(QString qqNumber, QString qqPassword)
{
    foreach(QQInfo_Zhujs info,qqList)
    {
        if(info.getNumber() == qqNumber && (info.getPassword() == qqPassword || qqPassword == "auto"))
        {
            return true;
        }
    }
    return false;
}

QQInfo_Zhujs DataHandler::queryQQ(QString qqNumber, bool &outRet)
{
    outRet = false;
    foreach(QQInfo_Zhujs info,qqList)
    {
        if(info.getNumber() == qqNumber)
        {
            outRet = true;
            return info;
        }
    }
    return QQInfo_Zhujs();
}

bool DataHandler::updateQQ(QString qqNumber, QString qqName, QString registerDate, QString qqPassword, QString identificationNumber, QString userAddress, QString birthDate)
{
    for (int i=0;i<qqList.size();i++)
    {
        if(qqList[i].getNumber()==qqNumber)
        {
            QQInfo_Zhujs newQQ(qqNumber,qqName,registerDate,qqPassword);
            newQQ.setIdentificationNumber(identificationNumber);
            newQQ.setUserAddress(userAddress);
            newQQ.setBirthDate(birthDate);
            newQQ.friendMap=qqList[i].friendMap;
            qqList[i]=newQQ;
            return true;
        }
    }
    return false;
}

bool DataHandler::addQQFriend(QString qqNumber, QString friendNumber)
{
    if(qqNumber == friendNumber)
    {
        return false;
    }
    bool retFriend = false;
    QQInfo_Zhujs friendInfo = queryQQ(friendNumber,retFriend);
    if(retFriend)
    {
        for (int i=0;i<qqList.size();i++)
        {
            if(qqList[i].getNumber()==qqNumber)
            {
                if(qqList[i].friendMap.contains(friendNumber))
                {
                    return false;
                }
                qqList[i].friendMap[friendInfo.getNumber()] = friendInfo.getName();
                return true;
            }
        }
    }
    return false;
}

bool DataHandler::deleteQQFriend(QString qqNumber, QString friendNumber)
{
    if(qqNumber == friendNumber)
    {
        return false;
    }
    bool retFriend = false;
    QQInfo_Zhujs friendInfo = queryQQ(friendNumber,retFriend);
    if(retFriend)
    {
        for (int i=0;i<qqList.size();i++)
        {
            if(qqList[i].getNumber()==qqNumber)
            {
                if(!qqList[i].friendMap.contains(friendNumber))
                {
                    return false;
                }
                qqList[i].friendMap.remove(friendNumber);
                return true;
            }
        }
    }
    return false;
}

bool DataHandler::alterQQFriend(QString qqNumber, QString friendNumber, QString remark)
{
    if(qqNumber == friendNumber)
    {
        return false;
    }
    bool retFriend = false;
    QQInfo_Zhujs friendInfo = queryQQ(friendNumber,retFriend);
    if(retFriend)
    {
        for (int i=0;i<qqList.size();i++)
        {
            if(qqList[i].getNumber()==qqNumber)
            {
                if(!qqList[i].friendMap.contains(friendNumber))
                {
                    return false;
                }
                qqList[i].friendMap[friendNumber]=remark;
                return true;
            }
        }
    }
    return false;
}

QVariantMap DataHandler::getQQFriendList(QString qqNumber)
{
    foreach(QQInfo_Zhujs info,qqList)
    {
        if(info.getNumber() == qqNumber)
        {
            return info.friendMap;
        }
    }
    return QVariantMap();
}

bool DataHandler::isQQFriend(QString qqNumber, QString friendNumber)
{
    foreach(QQInfo_Zhujs self,qqList)
    {
        if(self.getNumber() == qqNumber && self.friendMap.contains(friendNumber))
        {
            foreach(QQInfo_Zhujs friendInfo,qqList)
            {
                if(friendInfo.getNumber()==friendNumber && friendInfo.friendMap.contains(qqNumber))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void DataHandler::writeQQ()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/qq.xml";
#else
    path = "../ServerPlatform/Data/qq.xml";
#endif
    QString dir = QDir::currentPath();
    QFile qfile(path);
    if (qfile.open(QIODevice::WriteOnly))
    {
        QDomDocument doc;
        QDomProcessingInstruction instruction;
        instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        doc.appendChild(instruction);
        QDomElement root = doc.createElement("AllData");
        doc.appendChild(root);
        for (int i = 0;i < qqList.size();i++)
        {
            QString qqNumber = qqList[i].getNumber();

            QDomElement qqNode = doc.createElement("qq");
            qqNode.setAttribute("number", qqList[i].getNumber());
            qqNode.setAttribute("name", qqList[i].getName());
            qqNode.setAttribute("register", qqList[i].getRegister());
            qqNode.setAttribute("password", qqList[i].getPassword());
            qqNode.setAttribute("identification", qqList[i].getIdentificationNumber());
            qqNode.setAttribute("birth", qqList[i].getBirthDate());
            qqNode.setAttribute("address", qqList[i].getUserAddress());
            for(auto iter = qqList[i].friendMap.begin();iter != qqList[i].friendMap.end();++iter)
            {
                QDomElement friendNode = doc.createElement("friend");
                friendNode.setAttribute("number", iter.key());
                friendNode.setAttribute("remark", iter.value().toString());
                qqNode.appendChild(friendNode);
            }
            root.appendChild(qqNode);
        }

        QTextStream stream(&qfile);
        doc.save(stream, 4);
        qfile.close();
    }
}

bool DataHandler::readQQ()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/qq.xml";
#else
    path = "../ServerPlatform/Data/qq.xml";
#endif
    QFile qfile(path);
    if (qfile.open(QIODevice::ReadOnly))
    {
        if (qfile.size() == 0)
        {
            qfile.close();
            return false;
        }
        qqList.clear();

        QDomDocument xmlDoc;
        xmlDoc.setContent(&qfile);
        qfile.close();

        QDomNode root = xmlDoc.namedItem("AllData");
        QDomNodeList qqNodeList = root.childNodes();
        for (int i = 0; i < qqNodeList.size(); i++)
        {
            QDomNode qqNode = qqNodeList.item(i);
            QString nodeName = qqNode.nodeName();
            if (nodeName == "qq")
            {
                QDomElement attribute = qqNode.toElement();
                QString number = attribute.attribute("number");
                QString name = attribute.attribute("name");
                QString registerDate = attribute.attribute("register");
                QString password = attribute.attribute("password");
                QString identification = attribute.attribute("identification");
                QString birth = attribute.attribute("birth");
                QString address = attribute.attribute("address");

                QQInfo_Zhujs newQQ(number,name,registerDate,password);
                newQQ.setIdentificationNumber(identification);
                newQQ.setBirthDate(birth);
                newQQ.setUserAddress(address);

                QDomNodeList friendList = qqNode.childNodes();
                for (int m = 0; m < friendList.length(); m++)
                {
                    QDomNode friendNode = friendList.item(m);
                    QString nodeName = friendNode.nodeName();
                    if (nodeName == "friend")
                    {
                        QDomElement friendAttribute = friendNode.toElement();
                        QString friendNumber = friendAttribute.attribute("number");
                        QString friendRemark = friendAttribute.attribute("remark");
                        newQQ.friendMap[friendNumber] = friendRemark;
                    }
                }
                qqList.append(newQQ);
            }
        }
        return true;
    }
    return false;
}

void DataHandler::writeFunction()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/function.txt";
#else
    path = "../ServerPlatform/Data/function.txt";
#endif
    ofstream outFile(path.toStdString());
    for (auto iter=functionMap.begin();iter!=functionMap.end();++iter)
    {
        outFile<<iter.key().toStdString()<<"  "<<iter.value().qqOpen<<"  "
              <<iter.value().weChatOpen<<"  "<<iter.value().weiBoOpen<<"  "<<endl;
    }
    outFile.close();
}

void DataHandler::readFunction()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/function.txt";
#else
    path = "../ServerPlatform/Data/function.txt";
#endif
    ifstream inFile(path.toStdString());
    string identification;
    int qqOpen = false;
    int weChatOpen = false;
    int weiBoOpen = false;
    while (!inFile.eof())
    {
        inFile >> identification >> qqOpen >> weChatOpen >> weiBoOpen;
        if(inFile.fail())
        {
            break;
        }
        Function function;
        function.qqOpen=qqOpen;
        function.weChatOpen=weChatOpen;
        function.weiBoOpen=weiBoOpen;
        functionMap[QString::fromStdString(identification)]=function;
    }
    inFile.close();
}

bool DataHandler::registerWeChat(QString wechatNumber, QString wechatName, QString registerDate, QString wechatPassword, QString identificationNumber, QString userAddress, QString birthDate)
{
    if(!canRegister(identificationNumber,2))
    {
        return false;
    }
    foreach(WeChatInfo_Zhujs info,wechatList)
    {
        if(info.getNumber() == wechatNumber)
        {
            return false;
        }
    }
    WeChatInfo_Zhujs newWeChat(wechatNumber,wechatName,registerDate,wechatPassword);
    newWeChat.setIdentificationNumber(identificationNumber);
    newWeChat.setUserAddress(userAddress);
    newWeChat.setBirthDate(birthDate);
    wechatList.append(newWeChat);
    return true;
}

bool DataHandler::loginWeChat(QString wechatNumber, QString wechatPassword)
{
    foreach(WeChatInfo_Zhujs info,wechatList)
    {
        if(info.getNumber() == wechatNumber && (info.getPassword() == wechatPassword || wechatPassword == "auto"))
        {
            return true;
        }
    }
    return false;
}

QString DataHandler::getIdentification(QString number, bool isQQ)
{
    if(isQQ)
    {
        foreach(QQInfo_Zhujs info,qqList)
        {
            if(info.getNumber() == number)
            {
                return info.getIdentificationNumber();
            }
        }
    }
    else
    {
        foreach(WeChatInfo_Zhujs info,wechatList)
        {
            if(info.getNumber() == number)
            {
                return info.getIdentificationNumber();
            }
        }
    }
    return "";
}

void DataHandler::writeWeChat()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/wechat.xml";
#else
    path = "../ServerPlatform/Data/wechat.xml";
#endif
    QString dir = QDir::currentPath();
    QFile qfile(path);
    if (qfile.open(QIODevice::WriteOnly))
    {
        QDomDocument doc;
        QDomProcessingInstruction instruction;
        instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        doc.appendChild(instruction);
        QDomElement root = doc.createElement("AllData");
        doc.appendChild(root);
        for (int i = 0;i < wechatList.size();i++)
        {
            QString wechatNumber = wechatList[i].getNumber();

            QDomElement wechatNode = doc.createElement("wechat");
            wechatNode.setAttribute("number", wechatList[i].getNumber());
            wechatNode.setAttribute("name", wechatList[i].getName());
            wechatNode.setAttribute("register", wechatList[i].getRegister());
            wechatNode.setAttribute("password", wechatList[i].getPassword());
            wechatNode.setAttribute("identification", wechatList[i].getIdentificationNumber());
            wechatNode.setAttribute("birth", wechatList[i].getBirthDate());
            wechatNode.setAttribute("address", wechatList[i].getUserAddress());
            root.appendChild(wechatNode);
        }

        QTextStream stream(&qfile);
        doc.save(stream, 4);
        qfile.close();
    }
}

bool DataHandler::readWeChat()
{
    QString path;
#ifdef QT_NO_DEBUG
    path = QCoreApplication::applicationDirPath() + "/Data/wechat.xml";
#else
    path = "../ServerPlatform/Data/wechat.xml";
#endif
    QFile qfile(path);
    if (qfile.open(QIODevice::ReadOnly))
    {
        if (qfile.size() == 0)
        {
            qfile.close();
            return false;
        }
        wechatList.clear();

        QDomDocument xmlDoc;
        xmlDoc.setContent(&qfile);
        qfile.close();

        QDomNode root = xmlDoc.namedItem("AllData");
        QDomNodeList wechatNodeList = root.childNodes();
        for (int i = 0; i < wechatNodeList.size(); i++)
        {
            QDomNode wechatNode = wechatNodeList.item(i);
            QString nodeName = wechatNode.nodeName();
            if (nodeName == "wechat")
            {
                QDomElement attribute = wechatNode.toElement();
                QString number = attribute.attribute("number");
                QString name = attribute.attribute("name");
                QString registerDate = attribute.attribute("register");
                QString password = attribute.attribute("password");
                QString identification = attribute.attribute("identification");
                QString birth = attribute.attribute("birth");
                QString address = attribute.attribute("address");

                WeChatInfo_Zhujs newWeChat(number,name,registerDate,password);
                newWeChat.setIdentificationNumber(identification);
                newWeChat.setBirthDate(birth);
                newWeChat.setUserAddress(address);

                wechatList.append(newWeChat);
            }
        }
        return true;
    }
    return false;
}
