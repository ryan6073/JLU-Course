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

bool DataHandler::registerQQ(QString qqNumber, QString qqName, QString registerDate, QString qqPassword,QString identificationNumber, QString userAddress, QString birthDate)
{
    foreach(QQInfo info,qqList)
    {
        if(info.getNumber() == qqNumber)
        {
            return false;
        }
    }
    QQInfo newQQ(qqNumber,qqName,registerDate,qqPassword);
    newQQ.setIdentificationNumber(identificationNumber);
    newQQ.setUserAddress(userAddress);
    newQQ.setBirthDate(birthDate);
    qqList.append(newQQ);
    return true;
}

bool DataHandler::loginQQ(QString qqNumber, QString qqPassword)
{
    foreach(QQInfo info,qqList)
    {
        if(info.getNumber() == qqNumber && info.getPassword() == qqPassword)
        {
            return true;
        }
    }
    return false;
}

QQInfo DataHandler::queryQQ(QString qqNumber, bool &outRet)
{
    outRet = false;
    foreach(QQInfo info,qqList)
    {
        if(info.getNumber() == qqNumber)
        {
            outRet = true;
            return info;
        }
    }
    return QQInfo();
}

bool DataHandler::updateQQ(QString qqNumber, QString qqName, QString registerDate, QString qqPassword, QString identificationNumber, QString userAddress, QString birthDate)
{
    for (int i=0;i<qqList.size();i++)
    {
        if(qqList[i].getNumber()==qqNumber)
        {
            QQInfo newQQ(qqNumber,qqName,registerDate,qqPassword);
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
    QQInfo friendInfo = queryQQ(friendNumber,retFriend);
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
    QQInfo friendInfo = queryQQ(friendNumber,retFriend);
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
    QQInfo friendInfo = queryQQ(friendNumber,retFriend);
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
    foreach(QQInfo info,qqList)
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
    foreach(QQInfo self,qqList)
    {
        if(self.getNumber() == qqNumber && self.friendMap.contains(friendNumber))
        {
            foreach(QQInfo friendInfo,qqList)
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
    path = "../QChatServer/Data/qq.xml";
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
    path = QCoreApplication::applicationDirPath() + "/database/Income.db";
#else
    path = "../QChatServer/Data/qq.xml";
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

                QQInfo newQQ(number,name,registerDate,password);
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
