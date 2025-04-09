#include<iostream>
#include"tools.h"
#include<fstream>
#include<conio.h>

extern QQTools_CHC QQTools;
extern WeiBoTools_CHC WeiBoTools;

void WeiBoToolsBase_CHC::SaveWeiBo()//���濪ͨ��΢��
{
	fstream WeiBoListFile;
	string WeiBoListFileName = "WeiBoList.txt";
	WeiBoListFile.open(WeiBoListFileName, ios::app);
	string m = QQTools.ReturnQQid();
	WeiBoListFile << QQTools.ReturnQQid() << endl;
	WeiBoListFile.close();
}

void WeiBoToolsBase_CHC::GetWeiBo()
{
	ofstream WeiBoListFileCheck;
	fstream WeiBoListFile;
	string WeiBoListFileName = "WeiBoList.txt";
	string WeiBoListTemp;

	WeiBoListFileCheck.open(WeiBoListFileName, ios::out | ios::app);
	/*if (!WeiBoListFileCheck)
	{
	WeiBoListFileCheck.close();
	cout << "û����ע��΢����" << endl;
	cout << "�����������WeiChat���˵�" << endl;
	_getch();
	_getch();
	QQTools.Menu();
	}*/
	WeiBoListFileCheck.close();


	WeiBoListFile.open(WeiBoListFileName);
	while (!WeiBoListFile.eof())
	{
		getline(WeiBoListFile, WeiBoListTemp);

		WeiBoTools.ReturnWeiBolist().emplace_back(new WeiBo_CHC(WeiBoListTemp));
	}
	WeiBoTools.ReturnWeiBolist().pop_back();

	WeiBoListFile.close();


}

void WeiBoToolsBase_CHC::Login()
{
	system("CLS");
	string WeiBoID;
	string WeiBoPW;
	int ThisWeiBo;
	bool isCheckFlag = false;
	bool PWCheckFlag = false;
	cout << "���������΢��(QQ)��" << endl;
	cin >> WeiBoID;
	

	//�ж�΢���˺��Ƿ����
	while (1)
	{
		for (int i = 0; i < size(QQTools.ReturnQQ()); i++)
		{
			if (QQTools.ReturnQQ()[i]->ReturnID() == WeiBoID)
			{
				isCheckFlag = true;
				ThisWeiBo = i;
				WeiBoTools.LoginedWeiBoID = WeiBoID;
				break;
			}
		}

		if (isCheckFlag == false)
		{
			cout << "��������˺Ų����ڣ����������������#����΢�����˵�" << endl;
			cin >> WeiBoID;
			if (WeiBoID == "#")
			{
				Menu();
			}
			continue;
		}
		else
		{
			break;
		}
	}


	cout << "���������΢��(WeiChat)������" << endl;
	cin >> WeiBoPW;
	while (1)
	{
		if (QQTools.ReturnQQ()[ThisWeiBo]->ReturnPassWord() == WeiBoPW)
		{
			cout << "��½�ɹ�,�����������΢����ҳ" << endl;
			_getch();
			_getch();
			WeiBoMenu();
			break;
		}
		else
		{
			cout << "�����������,���������������#����΢�����˵�" << endl;
			cin >> WeiBoPW;
			if (WeiBoPW == "#")
			{
				Menu();
			}
			continue;
		}
	}


}

void WeiBoToolsBase_CHC::Menu()
{
	system("CLS");
	PrintfChat pfchat;
	pfchat.PrintText();
	int select;
	SetCursorPosition(15, 15);
	cout << "��ѡ��������Ĺ���" << endl;
	SetCursorPosition(15, 16);
	cout << "1.��½΢��" << endl;
	SetCursorPosition(15, 17);
	cout << "2.������һ���˵�" << endl;
	SetCursorPosition(15, 18);
	cout << "���ѡ��:" << endl;
	SetCursorPosition(15+5, 18);
	cin >> select;

	switch (select)
	{
	case 1:
		Login();
		break;
	case 2:
		mainmenu.Menu();
	default:
		Menu();
		/*system("CLS");
		SetCursorPosition(15, 15);
		cout << "�������,�����������΢�����˵�" << endl;
		_getch();
		_getch();
		Menu();*/
		break;
	}
}

void WeiBoToolsBase_CHC::WeiBoMenu()
{
	system("CLS");
	int select;
	cout << "��ӭ����΢��" << endl;
	cout << "���΢����Ϊ" << WeiBoTools.LoginedWeiBoID;
	cout << "��ѡ������Ĺ���" << endl;
	cout << "0.�������˵�" << endl;
	cin >> select;
	switch (select)
	{

	default:
		QQTools.Menu();
		break;
	}
}
