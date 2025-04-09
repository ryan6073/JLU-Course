
#include "QChatPlatform/ServerPlatform/wechatinfo_Zhujs.h"
#include "QChatPlatform/ServerPlatform/qqinfo_Zhujs.h"
#ifndef GROUPINFO_ZHUJS_H
#define GROUPINFO_ZHUJS_H
class GroupInfo_Zhujs
{
public:
	GroupInfo_Zhujs();
	GroupInfo_Zhujs(QString groupNumber, bool isQQ, QString masterNumber);
	virtual ~GroupInfo_Zhujs();

public:
	virtual void appendGroup(BaseInfo_Zhujs user);
	virtual void deleteGroup( QString number);
	QList<BaseInfo_Zhujs> queryGroup(QString number);
	QString getNumber(QString groupNumber);
private:
	QString groupNumber;
	QString masterNumber;
	QList<BaseInfo_Zhujs> List;
};
class QQGroup_Zhujs : public GroupInfo_Zhujs
{
public:
	QQGroup_Zhujs();
	QQGroup_Zhujs(QString groupNumber, QString masterNumber);
	~QQGroup_Zhujs();

public:
	void appendGroup(QQInfo_Zhujs qq);
	void deleteGroup(QString number);
	QList<QQInfo_Zhujs> queryGroup(QString number);

private:
	QString QQGroupnumber;
	QString masterNumber;
	QList<QQInfo_Zhujs> qqList;

};

#endif



/*    不实现多态的情况
#include "QChatPlatform/ServerPlatform/wechatinfo_Zhujs.h"
#include "QChatPlatform/ServerPlatform/qqinfo_Zhujs.h"

class GroupInfo_Zhujs
{
public:
	GroupInfo_Zhujs();
	GroupInfo_Zhujs(QString groupNumber, bool isQQ, QString masterNumber);
	~GroupInfo_Zhujs();

public:
	void appendQQ(QQInfo_Zhujs user);
	void appendWechat(WeChatInfo_Zhujs wechat);
	void deleteMember(bool isQQ, QString number);
	QList<QQInfo_Zhujs> queryQQMember(QString number);
	QList<WeChatInfo_Zhujs> queryWechatMember(QString number);

private:
	QString groupNumber;
	bool isQQ=false;
	QString masterNumber;

	QList<QQInfo_Zhujs> qqList;
	QList<WeChatInfo_Zhujs> wechatList;
};*/