#include "stdafx.h"
#include<iostream>
#include"chat.h"
#include"GreedySnake.h"
#include<Windows.h>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
//void MainMenu();
//void Loding();

extern QQTools_CHC;
extern WeiBoTools_CHC WeiBoTools;
extern WeiChatTools_CHC WeiChatTools;
extern MainMenu mainmenu;


int main()
{
	SetConsoleTitle("Chat-2017�����ִ�ѧ�������9��º賬����");
	//Loding();
	StartChatInterface Start;
	Start.PrintText();
	SetCursorPosition(17, 22);
	cout << "�����������" << endl;
	_getch();
	_getch();
	system("CLS");
	
	
	/*SetWindowSize(41, 32);*/
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//�����ļ���
	CreateDirectory(WeiChat.c_str(), NULL);
	CreateDirectory(WeiBo.c_str(), NULL);
	CreateDirectory(Parties.c_str(), NULL);
	
	string Parties1 = "WeiChat\\Parties";
	CreateDirectory(Parties1.c_str(), NULL);
	/*Menu();*/
	WeiBoTools.GetWeiBo();
	QQTools.GetQQ();
	WeiChatTools.GetWeiChat();


	mainmenu.Menu();
	return 0;
}

void MainMenu::Menu()
{
	system("CLS");
	PrintfChat pfchat;
	pfchat.PrintText();
	int select, key = 1;
	bool flag = false;

	SetCursorPosition(15, 15);
	cout << "��ѡ���½/ע����ʺ�" << endl;

	/*SetBackColor();*/
	SetCursorPosition(15, 16);
	cout << "1.QQ" << endl;
	//SetColor(3);

	SetCursorPosition(15, 17);
	cout << "2.΢��" << endl;

	SetCursorPosition(15, 18);
	cout << "3.΢��" << endl;

	SetCursorPosition(15, 19);
	cout << "���ѡ��:" << endl;

	SetCursorPosition(15 + 5, 19);
	cin >> select;
	switch (select)
	{
	case 1:
	{
		QQTools.Menu();
		break;
	case 2:
		WeiBoTools.Menu();
		break;

	case 3:
		WeiChatTools.Menu();
		break;
	}
	default:
	{
		Menu();
		break;
	}
	}
}
//void Loding()
//{
//	SetCursorPosition(15, 15);
//	cout << "����������:";
//	for (int i = 0; i < 20; i++)
//	{
//		Sleep(100);
//		cout << "-";
//	}
//	system("CLS");
//	SetCursorPosition(15, 15);
//}
