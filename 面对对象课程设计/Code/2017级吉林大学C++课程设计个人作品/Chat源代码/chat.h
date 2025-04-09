#pragma once
#ifndef CHAT_H
#define CHAT_H
#include<string>
#include<vector>
#include<iostream>
#include"Date.h"
using namespace std;
class Date;
class QQFriends_CHC;
class QQParties_CHC;
class Tencent_CHC;
class TencentFriends_CHC;

class Tencent_CHC //帐号基类
{

public:

	virtual string ReturnAge()
	{
		//Age=ApplyDate.ReturnYear
		return Age;
	}

	virtual int ReturnFriendNumber() {return FriendNumber;}

	virtual int ReturnPartyNumber() { return PartyNumber; }

	virtual string ReturnID() { return ID; }

	virtual string  ReturnPassWord(){return PassWord;}

	virtual string  ReturnName(){return Name;}

	virtual string  ReturnArea(){return Area;}

	virtual string  ReturnAutograph(){return Autograph;}

	virtual void ChangePartyNumbers(int num){PartyNumber = num;}

	virtual void ChangeFriendsNumber(int num){FriendNumber = num;}

	virtual void ChangePassWord(string pw) { PassWord = pw; }

	virtual void ChangeName(string newname) { Name = newname; }

	virtual void ChangeAutoGraph(string newautograph) { Autograph = newautograph; }

	virtual void ChangeArea(string newarea) { Area = newarea; }

	virtual Date &ReturnApplyDate() { return ApplyDate; }


protected:

	//int Age; //注册天数
	string Age;

	int FriendNumber; //好友数量

	int PartyNumber; //群数量

	string ID;  //帐号
	
	string Name;  //用户姓名

	string PassWord; //用户密码

	string Area;//用户所在地区

	string Autograph;//用户个性签名

	string Sex;

	Date ApplyDate;//用户注册日期

	struct SexType
	{
		string SexFlag;
	}Man{ "男" }, WoMan{ "女" };

private:

};

//class TencentFriends_CHC
//{
//public:
//
//	/*friend class QQ_CHC;*/
//
//	TencentFriends_CHC(string name, string id, string newremarks);
//
//	TencentFriends_CHC(string name, string id);
//
//	string ReturnFriendName() { return FriendName; }
//
//	string ReturnID() { return ID; }
//
//	string ReturnRemarks() { return Remarks; }
//
//	void ChangeRemarks(string newremarks) { Remarks = newremarks; }
//
//private:
//
//	string FriendName;
//
//	string ID;
//
//	string Remarks;
//};


class QQ_CHC : public Tencent_CHC
{

public:

	QQ_CHC();

	QQ_CHC(string qqid, string qage, string qqpw, string qqname,string qqpv, string ag);

	~QQ_CHC();

	vector<QQFriends_CHC*>& ReturnFriendList(){return FriendList;}

	vector<QQParties_CHC*>& ReturnPartyList(){return PartyList;}

	vector<QQParties_CHC*>& ReturnTemporaryPartyList() { return TemporaryPartyList;}

	void ChangeLinkedWeiChat(string weichat) { LinkedWeiChat = weichat; }

	string &ReturnLinkedWeiChat() { return LinkedWeiChat; }

	void GetFriends();

	void GetLinks();


	


private:

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

	vector<QQParties_CHC*> TemporaryPartyList;

	string LinkedWeiChat;

};


class QQFriends_CHC
{

public:

	friend class QQ_CHC;

	QQFriends_CHC(string name, string id, string newremarks);

	QQFriends_CHC(string name, string id);

	string ReturnFriendName(){return FriendName;}

	string ReturnID(){return ID;}

	string ReturnRemarks() {return Remarks;}

	void ChangeRemarks(string newremarks) { Remarks = newremarks; }

private:
	
	string FriendName;

	string ID;

	string Remarks;

};


class QQParties_CHC
{

public:

	friend class QQ_CHC;

	QQParties_CHC(string id , string name ,string userid);

	vector<string> &ReturnPartyMembers() { return PartyMembrs; }

	vector<string> &ReturnAdminsID() { return AdminsList; }

	string ReturnPartyID() { return PartyID; }

	string ReturnPartyName() { return PartyName; }

	string ReturnCreatUserID() { return CreatUserID; }

	void ChangeTypeID(int id) { TypeID = id; }


protected:

	int TypeID;
	
	string PartyID;//群号

	string PartyName;//群名称

	string CreatUserID;//群主

	vector<string> PartyMembrs;//群成员列表

	vector<string> AdminsList;//管理员列表

};


//class QQParties_Game_CHC :public QQParties_CHC
//{
//public:
//	
//	void PlayGame();
//
//private:
//
//};
//
//class QQParties_Study_CHC :public QQParties_CHC
//{
//
//};


class WeiBo_CHC: public Tencent_CHC//微博类
{
public:

	

	WeiBo_CHC(){}

	WeiBo_CHC(string id) { ID = id; LinkedQQ = id; }

	vector<QQFriends_CHC*>& ReturnFriendList() { return FriendList; }

	vector<QQParties_CHC*>& ReturnPartyList() { return PartyList; }

	vector<string> &ReturnWeiBoContent() { return WeiBoContent; }


private:

	string LinkedQQ;//绑定的QQ

	vector<string>WeiBoContent;//微博内容

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;


};


class WeiChat_CHC : public Tencent_CHC
{
public:

	WeiChat_CHC();

	WeiChat_CHC(string qqid, string qage, string qqpw, string qqname, string qqpv, string ag);

	~WeiChat_CHC();

	vector<QQFriends_CHC*>& ReturnFriendList() { return FriendList; }

	vector<QQParties_CHC*>& ReturnPartyList() { return PartyList; }

	string &ReturnLinkedQQ() { return LinkedQQ; }

	void ChangeLinkedQQ(string qq) { LinkedQQ = qq; }

	void GetLinks();

	void GetFriends();

	


private:

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

	string LinkedQQ;

};




#endif