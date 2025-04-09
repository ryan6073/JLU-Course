#pragma once
#ifndef QQTOOLS_H
#define QQTOOLS_H
#include<iostream>
#include"chat.h"
#include<vector>
#include<string>
#include<deque>
#include"GreedySnake.h"


using namespace std;
//class WeiBo_CHC;
class QQTools_CHC;
class WeiBoTools_CHC;
class WeiChatTools_CHC;
class MainMenu;



extern QQTools_CHC QQTools;
extern WeiBoTools_CHC WeiBoTools;
extern WeiChatTools_CHC WeiChatTools;
extern MainMenu mainmenu;
extern int GameReturnFlag;

class ToolsBase_CHC
{
public:

	virtual void Apply() = 0;

	virtual void Login() = 0;

	virtual void Menu() = 0;

	virtual void AddFriend() = 0;

	virtual void SaveFriends() = 0;

	virtual void GetFriends() = 0;

	virtual void ShowFriends() = 0; 

	virtual void DeleteFriend() = 0;

	virtual void AgreeFriend() = 0;

	virtual void ShowFriendInformation() = 0;

	virtual void ChangeFriendRemarks() = 0;

	virtual void SaveChange() = 0;

	virtual void AgreeMember() = 0;

	virtual void ShowMyInformation() = 0;

	virtual void ChangePassWord() = 0;

	virtual void ChangeName() = 0;

	virtual void ChangeAutoGraph() = 0;

	virtual void ChangeArea() = 0;;

	virtual void GetLinks() = 0;


protected:


private:

	virtual void isFatherBase() = 0;
};


class QQToolsBase_CHC : public ToolsBase_CHC
{

public:
	virtual void Menu();

	virtual void Apply();

	virtual void Login();

	virtual void Client();

	virtual void QQMenu();

	virtual void SaveQQ();

	virtual void GetQQ();

	virtual void ShowQQ();

	virtual void AddFriend();

	virtual void DeleteFriend();

	virtual void ShowFriends();

	virtual void GetFriends();

	virtual void CreatQQparty();

	virtual void SaveQQParty();

	virtual void ShowQQParty();

	virtual void GetQQParty();

	virtual void PlayGame();

	virtual void AddPartyMember();

	virtual void AgreeMember();

	virtual void AgreeFriend();

	virtual void DeletePartyMember();

	virtual void AddPartyAdmin();

	virtual void SaveFriends();

	virtual void QuitParty();

	virtual void ShowMyInformation();

	virtual void ChangePassWord();

	virtual void SaveChange();

	virtual void ChangeName();

	virtual void ChangeAutoGraph();

	virtual void ChangeArea();

	virtual void ShowFriendInformation();

	virtual void ShowFriendNoReturn();

	virtual void ChangeFriendRemarks();

	virtual void ShowPartyInformation();

	virtual void ShowQQPartyNoReturn();

	virtual void ShowPartyMemberS();

	virtual void CreateWeiBo();

	virtual void ShowWeiChatCommonFriends();

	virtual string &ReturnQQid() { return QQid; }

	virtual vector<QQ_CHC*> &ReturnQQ() { return QQ; }

	virtual void GetLinks();

	virtual void LinkWeiChat();

	virtual void ShowWeiChatCommonFriendsNoReturn();

	virtual void AddWeiChatCommonFriend();

	virtual void CreatTemporaryParty();

	virtual void JoinTemporaryParty();

	/*virtual void PartyMenu();*/

	virtual void PartyType();

	virtual void ShowPartyInformationNoReturn(string partyId);

	vector<QQParties_CHC*> ReturnAllQQTemporaryParty() { return AllQQTemporaryParty; }

	/*virtual void ShowFriendsNoReturn();*/

	/*friend WeiChatToolsBase_CHC;*/

protected:

	vector<QQ_CHC*>QQ;

	string QQid; //登陆的QQ号

	string QQparty;//创建的群号;

	string PartyMember; //申请加群的QQ号

	vector<QQParties_CHC*>AllQQTemporaryParty;//临时讨论组

private:

	void ToolsBase_CHC::isFatherBase() {}

};


class WeiBoToolsBase_CHC : public ToolsBase_CHC
{

public:

	virtual vector<WeiBo_CHC*> &ReturnWeiBolist() { return WeiBoList; }

	virtual void SaveWeiBo();

	virtual void GetWeiBo();

	virtual void WeiBoMenu();

	virtual void Menu();

	virtual void Login();

	virtual void Apply() { cout << "请登录QQ开通微博" << endl; }

	virtual void AddFriend() { cout << "未开发"; }

	virtual void SaveFriends() { cout<<"未开发"; }

	virtual void GetFriends() { cout << "未开发"; }

	virtual void ShowFriends() { cout << "未开发"; }

	virtual void DeleteFriend() {}

	virtual void AgreeFriend() {}

	virtual void ShowFriendInformation() {}

	virtual void ChangeFriendRemarks() {}

	virtual void SaveChange() {}

	virtual void AgreeMember() {}

	virtual void ShowMyInformation(){}

	virtual void ChangePassWord() {}

	virtual void ChangeName() {}

	virtual void ChangeAutoGraph(){}

	virtual void ChangeArea() {}

	virtual void GetLinks() {}

protected:

	vector<WeiBo_CHC*> WeiBoList;

	string LoginedWeiBoID;

private:
	void ToolsBase_CHC::isFatherBase() {}

};


class WeiChatToolsBase_CHC:public ToolsBase_CHC
{
public:

	virtual void Apply();

	virtual void Menu();

	virtual void WeiChatMenu();

	virtual void Login();

	virtual void SaveWeiChat();

	virtual void GetWeiChat();

	virtual void ShowWeiChat();

	virtual void AddFriend();

	virtual void SaveFriends();

	virtual void GetFriends();

	virtual void ShowFriends();

	virtual void CreatParty();

	virtual void SaveParty();

	virtual void GetParty();

	virtual void DeleteFriend();

	virtual void AgreeFriend();

	virtual void ShowFriendInformation();

	virtual void ShowFriendNoReturn();

	virtual void ChangeFriendRemarks();

	virtual void SaveChange();

	virtual void ShowParty();

	virtual void AgreeMember();

	virtual void ShowPartyNoReturn();

	virtual void AddPartyMember();

	virtual void QuitParty();

	virtual void DeletePartyMember();

	virtual void ShowPartyInformation();

	virtual void ShowMyInformation();

	virtual void ChangePassWord();

	virtual void ChangeName();

	virtual void ChangeAutoGraph();

	virtual void ChangeArea();

	virtual void PlayGame();

	virtual void Client();

	virtual void LinkQQ();

	virtual void GetLinks();

	virtual void ShowQQCommonFriends();

	virtual string &ReturnLoginedWeiChat() { return LoginedWeiChat; }

	/*friend QQToolsBase_CHC;*/
	virtual void ShowQQCommonFriendsNoReturn();

	virtual void ShowFriendsNoReturn();

	virtual void AddQQCommonFriend();

	virtual void InvitePartyMember();

	virtual void ShowPartyInformationNoReturn(string partyId);

	virtual vector<WeiChat_CHC*> &ReturnWeiChatList() { return WeiChatList; }

protected:

	vector<WeiChat_CHC*>WeiChatList;

	string LoginedWeiChat;

	string WeiChatparty;//创建的群号;

	string WeiChatPartyMember; //申请加群的QQ号

	//string LinkedQQ;// 绑定的QQ




private:

	void ToolsBase_CHC::isFatherBase(){}

};












class QQTools_CHC : public QQToolsBase_CHC
{

public:


};


class WeiBoTools_CHC : public WeiBoToolsBase_CHC
{


};


class WeiChatTools_CHC:public WeiChatToolsBase_CHC
{

};



class MainMenu
{
public:
	void Menu();

private:

};



#endif