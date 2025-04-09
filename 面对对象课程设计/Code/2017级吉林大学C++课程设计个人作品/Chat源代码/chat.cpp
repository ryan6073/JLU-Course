#include<iostream>
#include"chat.h"
#include<time.h>
#include "stdafx.h"
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
#include"tools.h"
using namespace std;

//QQTools_CHC QQTools;

QQ_CHC::QQ_CHC()
{
	for (int i = 0; i<1000000; i++) //��ǿQQ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p , temp , 10);
	ID = string(temp);
	/*ID = rand()*rand();*/
	cout << "���QQ��Ϊ:" << ID <<endl;
	cout << "�������������" << endl;
	string PassWordAgin;
	cin >> PassWord;

	cout << "���ٴ�ȷ���������" << endl;
	cin >> PassWordAgin;
	while (1)
	{
		if (PassWord == PassWordAgin)
		{
			break;
		}
		else
		{
			cout << "����������벻���������������" << endl;
			cout << "�������������" << endl;
			cin >> PassWord;
			cout << "���ٴ�ȷ���������" << endl;
			cin >> PassWordAgin;
			continue;
		}
	}

	ApplyDate.ShowDate();
	/*Age = 0;*/
	Age = ApplyDate.ReturnDate();
	cout << "���������QQ����:" << endl;
	cin >> Name;
	cout << "�����������ڵĵ���" << endl;
	cin >> Area;

	cout << "��ѡ������Ա�" << endl;
	cout << "1.����" << endl;
	cout << "2.Ů��" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		Sex = Man.SexFlag;
		break;
	default:
		Sex = WoMan.SexFlag;
		break;
	}
	cout << "����Ա�:" << Sex << endl;

	cout << "������ĸ���ǩ��" << endl;
	cin >> Autograph;
	cout << "QQ������ɹ�" << endl;
	cout << "���QQ��Ϊ:" << ID << endl;
	cout << "���QQ����Ϊ:" << PassWord << endl;
	cout << "�����Ʊ����ʺź�����" << endl;

	string QQ = "QQ\\" + ID;
	CreateDirectory(QQ.c_str(), NULL);//ÿ��QQ����һ���ļ���

}

QQ_CHC::QQ_CHC(string qqid, string qage, string qqpw, string qqname, string qqpv, string ag)
{
	ID = qqid;
	Age = qage;
	PassWord = qqpw;
	Name = qqname;
	Area = qqpv;
	Autograph = ag;
	FriendNumber = 0;
	PartyNumber = 0;
}

QQ_CHC::~QQ_CHC()
{
	for (int i = 0; i < size(FriendList); i++)
	{
		delete FriendList[i];
	}

	for (int i = 0; i < size(PartyList); i++)
	{
		delete PartyList[i];
	}
}

void QQ_CHC::GetFriends()
{
	ifstream file;
	string qq = ID;
	string txt = ".txt";
	string filename = "QQ\\" + qq + "\\" + qq + "Friendlist.txt";
	string id;
	string name;
	string remarks;
	char c;
	int line = 0;
	int Myqq;
	file.open(filename, ios::app);
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	/*for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnID() == QQid)
		{
			Myqq = i;
		}
	}*/
	/*ChangeFriendsNumber(line);*/
	FriendNumber = line;

	file.open(filename, ios::app);

	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		file >> remarks;
		FriendList.emplace_back(new QQFriends_CHC(name, id, remarks));
	}

	file.close();
}

void QQ_CHC::GetLinks()
{
	fstream CheckFile;
	fstream GetLinksFile;
	string GetLinkFileName = "QQ\\" + ID + "\\Links.txt";

	CheckFile.open(GetLinkFileName, ios::in);
	if (!CheckFile)
	{
		CheckFile.close();
		CheckFile.open(GetLinkFileName, ios::out);
	}
	CheckFile.close();

	GetLinksFile.open(GetLinkFileName, ios::out | ios::in);
	vector<string> Links;
	string GetLinksFileTemp;
	int Myqq;

	//for (int i = 0; i < size(QQ); i++)
	//{
	//	if (QQ[i]->ReturnID() == QQid)
	//	{
	//		Myqq = i;
	//	}
	//}

	while (!GetLinksFile.eof())
	{
		getline(GetLinksFile, GetLinksFileTemp);

		GetLinksFileTemp.erase(GetLinksFileTemp.begin() + 0);
		GetLinksFileTemp.erase(GetLinksFileTemp.begin() + 0);
		GetLinksFileTemp.erase(GetLinksFileTemp.begin() + 0);
		GetLinksFileTemp.erase(GetLinksFileTemp.begin() + 0);
		GetLinksFileTemp.erase(GetLinksFileTemp.begin() + 0);

		//�����ַ���Ҫerase����

		Links.emplace_back(GetLinksFileTemp);
	}
	if (Links.size() != 0)
	{
		LinkedWeiChat = Links[0];
	};
	/*LinkedWeiChat = Links[1];*/
}







QQFriends_CHC::QQFriends_CHC(string name, string id , string newremarks)
{
	FriendName = name;
	ID = id;
	Remarks = newremarks;
}

QQFriends_CHC::QQFriends_CHC(string name, string id)
{
	FriendName = name;
	ID = id;
	Remarks = "δ��ע";
}

QQParties_CHC::QQParties_CHC(string id, string name, string userid)
{
	PartyID = id;
	PartyName = name;
	CreatUserID = userid;
}

//void QQParties_Game_CHC::PlayGame()
//{
//	QQTools.PlayGame();
//}




WeiChat_CHC::WeiChat_CHC()
{
	for (int i = 0; i<1000000; i++) //��ǿQQ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p, temp, 10);
	string PassWordAgin;
	int select;
	//cout << "���������΢���˺�" << endl;
	ID = temp;
	/*ID = rand()*rand();*/
	cout << "���΢�ź�Ϊ:" << ID << endl;
	cout << "�������������" << endl;
	cin >> PassWord;
	cout << "���ٴ�ȷ���������" << endl;
	cin >> PassWordAgin;
	while (1)
	{
		if (PassWord == PassWordAgin)
		{
			break;
		}
		else
		{
			cout << "����������벻���������������" << endl;
			cout << "�������������" << endl;
			cin >> PassWord;
			cout << "���ٴ�ȷ���������" << endl;
			cin >> PassWordAgin;
			continue;
		}
	}
	ApplyDate.ShowDate();
	Age = ApplyDate.ReturnDate();
	cout << "���������΢������:" << endl;
	cin >> Name;
	cout << "�����������ڵĵ���" << endl;
	cin >> Area;

	cout << "��ѡ������Ա�" << endl;
	cout << "1.����" << endl;
	cout << "2.Ů��" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		Sex = Man.SexFlag;
		break;
	default:
		Sex = WoMan.SexFlag;
		break;
	}
	cout << "����Ա�:" << Sex << endl;
	cout << "������ĸ���ǩ��" << endl;
	cin >> Autograph;
	cout << "΢�ź�����ɹ�" << endl;
	cout << "���΢�ź�Ϊ:" << ID << endl;
	cout << "���΢������Ϊ:" << PassWord << endl;
	cout << "�����Ʊ����ʺź�����" << endl;

	string WeiChat = "WeiChat\\" + ID;
	CreateDirectory(WeiChat.c_str(), NULL);//ÿ��΢�Ŵ���һ���ļ���
}

WeiChat_CHC::WeiChat_CHC(string qqid, string qage, string qqpw, string qqname, string qqpv, string ag)
{
	ID = qqid;
	Age = qage;
	PassWord = qqpw;
	Name = qqname;
	Area = qqpv;
	Autograph = ag;
	FriendNumber = 0;
	PartyNumber = 0;
}

WeiChat_CHC::~WeiChat_CHC()
{
	for (int i = 0; i < size(FriendList); i++)
	{
		delete FriendList[i];
	}

	for (int i = 0; i < size(PartyList); i++)
	{
		delete PartyList[i];
	}
}

void WeiChat_CHC::GetLinks()
{

	int ThisWeiChat;
	fstream GetLinksFile;
	fstream CheckFile;
	string GetLinkFileName = "WeiChat\\" + ID + "\\Links.txt";

	CheckFile.open(GetLinkFileName, ios::in);
	if (!CheckFile)
	{
		CheckFile.close();
		CheckFile.open(GetLinkFileName, ios::out);
	}
	CheckFile.close();

	GetLinksFile.open(GetLinkFileName);
	vector<string> Links;
	string GetLinksFileTemp;

	/*for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			ThisWeiChat = i;
		}
	}*/

	while (!GetLinksFile.eof())
	{
		getline(GetLinksFile, GetLinksFileTemp);
		GetLinksFileTemp.erase(GetLinksFileTemp.begin());
		GetLinksFileTemp.erase(GetLinksFileTemp.begin());
		GetLinksFileTemp.erase(GetLinksFileTemp.begin());

		Links.emplace_back(GetLinksFileTemp);
	}

	if (Links.size() != 0)
	{
		/*WeiChatList[ThisWeiChat]->ChangeLinkedQQ(Links[0]);*/
		LinkedQQ = Links[0];
	}
}

void WeiChat_CHC::GetFriends()
{
	ifstream file;
	string qq = ID;
	string txt = ".txt";
	string filename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
	string id;
	string name;
	string remarks;
	char c;
	int line = 0;
	int Myqq;
	file.open(filename, ios::app);
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	/*for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}*/
	/*WeiChatList[Myqq]->ChangeFriendsNumber(line);*/
	FriendNumber = line;

	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		file >> remarks;
		FriendList.emplace_back(new QQFriends_CHC(name, id, remarks));
	}

	file.close();
}