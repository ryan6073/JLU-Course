#include "groupinfo_Zhujs.h"


GroupInfo_Zhujs::GroupInfo_Zhujs()
{
}

GroupInfo_Zhujs::GroupInfo_Zhujs(QString groupNumber, bool isQQ, QString masterNumber)
{
	this->groupNumber = groupNumber;
	this->masterNumber = masterNumber;
}

GroupInfo_Zhujs::~GroupInfo_Zhujs()
{
}

void GroupInfo_Zhujs::appendGroup(BaseInfo_Zhujs user)
{
	List.append(user);
}

void QQGroup_Zhujs::appendGroup(QQInfo_Zhujs wechat)
{
	qqList.append(wechat);
}

void GroupInfo_Zhujs::deleteGroup( QString number)
{
	return;

}
QString GroupInfo_Zhujs::getNumber(QString GroupNumber)
{
	return GroupNumber;
}
QList<BaseInfo_Zhujs> GroupInfo_Zhujs::queryGroup(QString number)
{
	return List;
}

QList<QQInfo_Zhujs> QQGroup_Zhujs::queryGroup(QString number)
{
	for (int i = 0; i < qqList.size(); i++)
	{
		if (qqList[i].getNumber() == number)
		{
			return qqList;
		}
	}
}