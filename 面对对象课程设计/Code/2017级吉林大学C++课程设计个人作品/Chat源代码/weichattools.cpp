#include<iostream>
#include"tools.h"
#include<conio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
#include"GreedySnake.h"


void WeiChatToolsBase_CHC::Menu()
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
	cout << "2.ע��΢��" << endl;
	SetCursorPosition(15, 18);
	cout << "3.�鿴��ע��΢��" << endl;
	SetCursorPosition(15, 19);
	cout << "4.������һ���˵�" << endl;
	SetCursorPosition(15, 20);
	cout << "���ѡ��:" << endl;
	SetCursorPosition(15 + 5, 20);
	cin >> select;

	switch (select)
	{
	case 1:
		Login();
		break;
	case 2:
		Apply();
		break;
	case 3:
		ShowWeiChat();
		break;
	case 4:
		mainmenu.Menu();
		break;
	default:
		Menu();
		break;
	}
}

void WeiChatToolsBase_CHC::Apply()
{
	system("CLS");
	WeiChatList.emplace_back(new WeiChat_CHC());
	SaveWeiChat();

	cout << "�����������" << endl;
	_getch();
	_getch();
	Menu();
}

void WeiChatToolsBase_CHC::SaveWeiChat()
{
	ofstream file;
	file.open("WeiChat.txt", ios::app);
	/*auto iter = WeiChatList.begin();*/
	int i = 0;
	for (i = 0; i < size(WeiChatList); i++)
	{

	}
	file << WeiChatList[i - 1]->ReturnID() << endl;
	file << WeiChatList[i - 1]->ReturnAge() << endl;
	/*file << WeiChatList[i - 1]->ReturnApplyDate().ReturnDate() << endl;*/
	file << WeiChatList[i - 1]->ReturnPassWord() << endl;
	file << WeiChatList[i - 1]->ReturnName() << endl;
	file << WeiChatList[i - 1]->ReturnArea() << endl;
	file << WeiChatList[i - 1]->ReturnAutograph() << endl;
	file << " " << endl;
	file.close();
}

void WeiChatToolsBase_CHC::GetWeiChat()
{
	string qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("WeiChat.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("WeiChat.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		WeiChatList.emplace_back(new WeiChat_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	file.close();
}

void WeiChatToolsBase_CHC::Login()
{
	system("CLS");
	string ID;
	bool flag = false;
	string PassWord;
	bool flag1 = true;
	//vector<QQ_CHC*>::iterator iter = WeiChatList.begin();
	cout << "������Ҫ��½��΢��:" << endl;
	cin >> ID;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		while (1)
		{
			cout << "û�и�΢�źţ������������#�������˵�" << endl;
			cin >> ID;
			if (ID == "#")
			{
				Menu();
			}
			else
			{
				for (int i = 0; i < size(WeiChatList); i++)
				{
					if (WeiChatList[i]->ReturnID() == ID)
					{
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
			{
				break;
			}
			/*cout << "�����������" << endl;
			_getch();
			_getch();
			Menu();*/
		}
	}
	//if (flag != true)
	//{
	//	cout << "û�и�WeiChatList�ţ���������" << endl;
	//	cout << "�����������" << endl;
	//	_getch();
	//	Menu();
	//}
	cout << "�������΢�ŵ�����" << endl;
	cin >> PassWord;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() == PassWord)
		{
			LoginedWeiChat = ID;
			GetFriends();//��ȡ����
			GetParty();//��ȡȺ
			GetLinks();//��ȡ��
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��΢��" << endl;
			_getch();
			WeiChatMenu();
			break;
		}
		else if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() != PassWord)
		{
			cout << "�����������" << endl;
			cout << "��������������,������#�������˵�" << endl;
			cin >> PassWord;
			if (PassWord == "#")
			{
				Menu();
			}
			while (1)
			{
				if (WeiChatList[i]->ReturnPassWord() == PassWord)
				{
					cout << "��½�ɹ�" << endl;
					cout << "���������ʼʹ��WeiChatList" << endl;
					_getch();
					_getch();
					WeiChatMenu();
				}
				else
				{
					cout << "�����������" << endl;
					cout << "��������������,������#�������˵�" << endl;
					cin >> PassWord;
					if (PassWord == "#")
					{
						Menu();
					}
					continue;
				}
			}
			/*	if (WeiChatList[i]->ReturnPassWord() == PassWord)
			{
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��WeiChatList" << endl;
			_getch();
			_getch();
			WeiChatMenu();
			break;
			}
			else
			{
			cout << "�����������" << endl;
			cout << "��������������" << endl;
			cin >> PassWord;
			}
			break;*/
		}


	}
}

void WeiChatToolsBase_CHC::ShowWeiChat()
{
	system("CLS");
	vector<WeiChat_CHC*>WeiChat;
	string  qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;

	file.open("WeiChat.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("WeiChat.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		WeiChat.emplace_back(new WeiChat_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	for (int i = 0; i < line; i++)
	{
		cout << "΢�ź�:" << WeiChat[i]->ReturnID() << endl;
		cout << "΢��:" << WeiChat[i]->ReturnAge() << endl;
		cout << "΢������:" << WeiChat[i]->ReturnPassWord() << endl;
		cout << "΢������:" << WeiChat[i]->ReturnName() << endl;
		cout << "���ڵ���:" << WeiChat[i]->ReturnArea() << endl;
		cout << "����ǩ��:" << WeiChat[i]->ReturnAutograph() << endl;
		cout << endl;

	}
	/*vector<int>qqid;
	for (int i = 0; i < 2; i++)
	{
	int qq;
	file >> qq;
	qqid.emplace_back(qq);
	}
	file.close();
	cout << qqid[0] << endl;;
	cout << qqid[1];*/
	/*int num = file.gcount();
	int i = 0;
	for (string s; file >> s;)
	{
	WeiChatList[i].push_back(s);
	}
	for (int i = 0; i < file.gcount(); i++)
	{
	file.read((char *)&WeiChatList[i], sizeof(QQ_CHC));
	}*/

	//for (int i = 0; i < size(WeiChatList); i++)
	//{
	//	cout << WeiChatList[i]->ID << endl;
	//}
	file.close();

	cout << "�����������" << endl;
	_getch();
	_getch();
	Menu();

}

void WeiChatToolsBase_CHC::WeiChatMenu()
{
	system("CLS");
	/*SetColor(6);*/
	int select;
	//vector<QQFriends_CHC*> FL;
	//vector<QQParties_CHC*> PL;
	int Myqq;
	cout << "��ӭʹ��΢��" << endl;
	cout << "���΢�ź�Ϊ:" << LoginedWeiChat << endl;
	cout << "��ѡ��ʹ�õĹ���" << endl;
	cout << "1.���ѹ���" << endl;
	cout << "2.Ⱥ����" << endl;
	cout << "3.��Ϸ����" << endl;
	cout << "4.���칦��" << endl;
	cout << "5.��������" << endl;
	cout << "6.����������" << endl;
	cout << "0.�������˵�" << endl;
	//cout << "1.��������������" << endl;
	//cout << "2.���WeiChatList����" << endl;
	//cout << "3,�鿴WeiChatList����" << endl;
	//cout << "4.����WeiChatListȺ" << endl;
	//cout << "5.����WeiChatListȺ" << endl;
	//cout << "6.�鿴�Լ�����WeiChatListȺ" << endl;
	//cout << "7.����WeiChatListȺ" << endl;
	//cout << "8.ɾ��WeiChatList����" << endl;
	//cout << "9.С��Ϸ" << endl;
	//cout << "10.�鿴��������" << endl;
	//cout << "11.���Ⱥ����Ա" << endl;
	//cout << "0.�������˵�" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		/*Client();*/
		cout << "��ѡ��ʹ�õĺ��ѹ���" << endl;
		cout << "1.��Ӻ���" << endl;
		cout << "2.��ʾ���к���" << endl;
		cout << "3.ɾ������" << endl;
		cout << "4.�鿴��������" << endl;
		cout << "5.�鿴��������" << endl;
		cout << "6.�޸ĺ��ѱ�ע" << endl;
		cout << "7.�鿴QQ��ͬ����" << endl;
		cout << "8.���QQ��ͬ����" << endl;
		cout << "0.����΢�����˵�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddFriend();
			break;
		case 2:
			ShowFriends();
			break;
		case 3:
			DeleteFriend();
			break;
		case 4:
			AgreeFriend();
			break;
		case 5:
			ShowFriendInformation();
			break;
		case 6:
			ChangeFriendRemarks();
			break;
		case 7:
			ShowQQCommonFriends();
			break;
		case 8:
			AddQQCommonFriend();
			break;
		default:
			WeiChatMenu();
			break;

		}
		break;

	case 2:

		cout << "��ѡ��ʹ�õ�Ⱥ����" << endl;
		/*cout << "1.����΢��Ⱥ" << endl;*/
		cout << "1.�˳�΢��Ⱥ" << endl;
		cout << "2.����΢��Ⱥ" << endl;
		cout << "3.�鿴�Ѽ����΢��Ⱥ" << endl;
		/*cout << "5.�鿴��Ⱥ����" << endl;*/
		/*cout << "6.���WeiChatListȺ����Ա" << endl;*/
		cout << "4.�߳�Ⱥ��Ա" << endl;
		cout << "5.�鿴Ⱥ��Ա��Ϣ" << endl;
		cout << "6.������ѽ�Ⱥ" << endl;
		cout << "0.�������˵�" << endl;
		cin >> select;
		switch (select)
		{
		/*case 1:
			AddPartyMember();
			break;*/
		case 1:
			QuitParty();
			break;
		case 2:
			CreatParty();
			break;
		case 3:
			ShowParty();
			break;
		/*case 5:
			AgreeMember();*/
			break;
		//case 6:
		//	/*AddPartyAdmin();*/
		//	break;
		case 4:
			DeletePartyMember();
			break;
		case 5:
			ShowPartyInformation();
		case 6:
			InvitePartyMember();
			break;
		default:
			WeiChatMenu();
			break;
		}
		break;

	case 3:
		cout << "��ѡ�������Ϸ" << endl;
		cout << "1.̰����" << endl;
		cout << "0.����΢�����˵�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			PlayGame();
			break;
		default:
			WeiChatMenu();
			break;
		}
		break;

	case 4:
		cout << "��ѡ��ʹ�õ����칦��" << endl;
		cout << "1.����������" << endl;
		cout << "0.����΢�����˵�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Client();
			break;
		default:
			WeiChatMenu();
			break;
		}

	case 5:
		cout << "��ѡ����������Ϲ���" << endl;
		cout << "1.�鿴��������" << endl;
		cout << "2.�޸�����" << endl;
		cout << "3.�޸�����" << endl;
		cout << "4.�޸�ǩ��" << endl;
		cout << "5.�޸����ڵ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			ShowMyInformation();
			break;
		case 2:
			ChangePassWord();
			break;
		case 3:
			ChangeName();
			break;
		case 4:
			ChangeAutoGraph();
			break;
		case 5:
			ChangeArea();
			break;
		default:
			WeiChatMenu();
			break;
		}
		break;
	case 6:
		cout << "��ѡ�����蹦��:" << endl;
		cout << "1.��QQ" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			LinkQQ();
			break;
		default:
			cout << "ѡ����󣬰����������WeiChatList���˵�" << endl;
			_getch();
			_getch();
			WeiChatMenu();
			break;
		}
		break;
	case 0:

		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}

		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
		{
			delete WeiChatList[Myqq]->ReturnFriendList()[i];
		}
		WeiChatList[Myqq]->ReturnFriendList().resize(0);
		WeiChatList[Myqq]->ReturnFriendList().clear();
		WeiChatList[Myqq]->ReturnFriendList().shrink_to_fit();
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
		{
			delete  WeiChatList[Myqq]->ReturnPartyList()[i];
		}
		WeiChatList[Myqq]->ReturnPartyList().resize(0);
		WeiChatList[Myqq]->ReturnPartyList().clear();
		WeiChatList[Myqq]->ReturnPartyList().shrink_to_fit();
		
		mainmenu.Menu();
		break;

	default:
		WeiChatMenu();
		break;

	}
	_getch();
}



void WeiChatToolsBase_CHC::AddFriend()
{
	system("CLS");
	int Myqq;
	string id;
	string name;
	bool flag = false;
	cout << "��������Ӻ��ѵ�΢�ź�" << endl;
	cin >> id;

	if (id == LoginedWeiChat)
	{
		cout << "�㲻������Լ�Ϊ����" << endl;
		cout << "�����������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			Myqq = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (id == WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID())
		{
			cout << "������Ӵ˺���,�밴���������΢����ҳ" << endl;
			_getch();
			_getch();
			WeiChatMenu();
		}
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			flag = true;
			name = WeiChatList[i]->ReturnName();
			cout << "��������ɹ�����ȴ��Է�ȷ��" << endl;
		}
	}

	if (flag == false)
	{
		cout << "��΢�źŻ�û��ע�ᣬ���������������΢�ź�" << endl;
		cout << "1.��������΢�ź���Ӻ���" << endl;
		cout << "2.����΢����ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AddFriend();
			break;

		case 2:
			WeiChatMenu();
			break;

		default:
			cout << "�������,�����������΢����ҳ" << endl;
			_getch();
			WeiChatMenu();
			break;
		}

	}

	string mark = "&";
	string ID = mark + id;
	if (flag)
	{
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, ID));
		WeiChatList[Myqq]->ChangeFriendsNumber(WeiChatList[Myqq]->ReturnFriendNumber() + 1);
	}
	SaveFriends();


	//�����WeiChatList�ļ�����ӱ�WeiChatList
	fstream file;
	string friendfilename = "WeiChat\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "δ��ע";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();

	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveFriends()
{
	int i = 0, Myqq, n;
	ofstream file;
	string qq = LoginedWeiChat;
	string txt = ".txt";
	string filename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
	file.open(filename, ios::app);
	for (i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(WeiChatList[Myqq]->ReturnFriendList()); n++)
	{
	}

	if (n > 0)
	{
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnID() << endl;
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnFriendName() << endl;
		file << WeiChatList[Myqq]->ReturnFriendList()[n - 1]->ReturnRemarks() << endl;
		file << " " << endl;
		file.close();
	}
	else
	{
		file.close();
		file.open(filename, ios::trunc | ios::out);//����ļ�����
		file.close();
	}
}

void WeiChatToolsBase_CHC::GetFriends()
{
	ifstream file;
	string qq = LoginedWeiChat;
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
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ChangeFriendsNumber(line);
	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		file >> remarks;
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id, remarks));
	}

	file.close();
}

void WeiChatToolsBase_CHC::ShowFriends()
{
	system("CLS");
	//GetFriends();

	int friendsnum;
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	friendsnum = size(WeiChatList[Myqq]->ReturnFriendList());
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//�ж���Ӻ��ѱ��
		{
			friendsnum--;
		}
	}

	cout << "����" << friendsnum << "������" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "��" << friends + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}

	cout << "�����������WeiChatList��ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowFriendsNoReturn()
{
	int friendsnum;
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	friendsnum = size(WeiChatList[Myqq]->ReturnFriendList());
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//�ж���Ӻ��ѱ��
		{
			friendsnum--;
		}
	}

	cout << "����" << friendsnum << "������" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "��" << friends + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}
}

void WeiChatToolsBase_CHC::CreatParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i<1000000; i++) //��ǿWeiChatListȺ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p, temp, 10);
	string ID;
	/*cin >> ID;*/
	ID = string(temp);
	cout << "���Ⱥ��Ϊ:" << ID << endl;
	WeiChatparty = ID;
	cout << "������Ⱥ����" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(ID, name, LoginedWeiChat));
	WeiChatList[Myqq]->ChangePartyNumbers(WeiChatList[Myqq]->ReturnPartyNumber() + 1);
	SaveParty();


	//ÿ��WeiChatList�����Լ���Ⱥ�б�
	fstream FILE;
	string qq;
	qq = LoginedWeiChat;
	string txt1 = "PartyList.txt";
	/*"WeiChatList\\" + LoginedWeiChat + "\\" + LoginedWeiChat + ".txt";*/
	string FILEName = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "PartyList.txt";
	FILE.open(FILEName, ios::app);
	FILE << ID << endl;

	fstream PartyListFile;
	string PartyListFileName = "PartyList.txt";
	PartyListFile.open(PartyListFileName, ios::app);
	PartyListFile << ID << endl;

	PartyListFile.close();
	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveParty()
{
	system("CLS");
	int i = 0, Myqq, n;
	string ID;
	ID = WeiChatparty;
	string txt = ".txt";
	string DirectoryName = "WeiChat\\Parties\\" + ID;
	CreateDirectory(DirectoryName.c_str(), NULL);
	string PartyID = "WeiChat\\Parties\\" + ID + "\\" + ID + ".txt";
	fstream file;
	file.open(PartyID, ios::app);
	for (i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(WeiChatList[Myqq]->ReturnPartyList()); n++)
	{
	}
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyID() << endl;
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyName() << endl;
	file << WeiChatList[Myqq]->ReturnPartyList()[n - 1]->ReturnCreatUserID() << endl;
	file << "��" << endl;
	file.close();
}

void WeiChatToolsBase_CHC::GetParty()
{
	int Myqq, line = 0;
	char c;
	string txt1 = "PartyList.txt";

	string txt = ".txt";

	ifstream listfile;

	ifstream partyfile;

	string qq = LoginedWeiChat;

	vector<string>party;

	string temp;
	/*string myqqfilename = "WeiChatList\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";*/
	string filename = "WeiChat\\" + qq + "\\" + qq + "PartyList.txt";
	string partyfilename;

	listfile.open(filename);

	while (listfile.get(c))
	{
		string x;
		x = c;
		temp += x;

		if (c == '\n')
		{
			line++;
			temp.pop_back();
			party.emplace_back(temp);
			temp.clear();
		}
	}
	listfile.close();


	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ChangePartyNumbers(line);

	for (int i = 0; i < size(party); i++)
	{
		temp = party[i];
		/*filename = temp + txt;*/
		partyfilename = "WeiChat\\Parties\\" + temp + "\\" + temp + ".txt";
		partyfile.open(partyfilename);
		string id;
		string name;
		string userid;
		partyfile >> id;
		partyfile >> name;
		partyfile >> userid;
		partyfile.close();
		WeiChatList[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(id, name, userid));
	}



	//��ȡȺ��Ա
	fstream QQPartyMemberFile;
	string QQPartyMemberFileName;
	string QQPartyMemberFileTemp;
	string OwnerQQ;
	vector<string>QQPartyMemberFileContent;

	int ThisPartyID;
	string QQPartyID;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	for (int i = 0; i < size(party); i++)
	{
		QQPartyMemberFileName = "WeiChat\\Parties\\" + party[i] + "\\" + party[i] + ".txt";
		QQPartyMemberFile.open(QQPartyMemberFileName);

		while (!QQPartyMemberFile.eof())
		{
			getline(QQPartyMemberFile, QQPartyMemberFileTemp);

			QQPartyMemberFileContent.push_back(QQPartyMemberFileTemp);
		}
		QQPartyID = QQPartyMemberFileContent[0];
		OwnerQQ = QQPartyMemberFileContent[2];
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		QQPartyMemberFileContent.erase(QQPartyMemberFileContent.begin());
		if (QQPartyMemberFileContent.size() != 0)
		{
			QQPartyMemberFileContent.pop_back();
		}

		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
			{
				ThisPartyID = i;
				break;
			}
		}

		WeiChatList[Myqq]->ReturnPartyList()[ThisPartyID]->ReturnPartyMembers().push_back(OwnerQQ);
		for (int i = 0; i < QQPartyMemberFileContent.size(); i++)
		{
			WeiChatList[Myqq]->ReturnPartyList()[ThisPartyID]->ReturnPartyMembers().push_back(QQPartyMemberFileContent[i]);
		}


		//BUG�޸�
		QQPartyMemberFileContent.clear();
		QQPartyMemberFileContent.shrink_to_fit();
		QQPartyMemberFile.close();
	}




	//��ȡȺ����ԱWeiChatList
	fstream adminfile;
	string adminfilename;
	string admintemp;
	string ThidPartyID;

	//int ThisAdmin;
	/*vector<string> AdminQQ;*/
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		ThidPartyID = WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID();

		fstream CheckPartyAdminFile;
		string GetLinkFileName = "WeiChat\\Parties\\" + ThidPartyID + "\\" + ThidPartyID + "admin.txt";
		CheckPartyAdminFile.open(GetLinkFileName, ios::in);
		if (!CheckPartyAdminFile)
		{
			CheckPartyAdminFile.close();
			CheckPartyAdminFile.open(GetLinkFileName, ios::out);
		}
		CheckPartyAdminFile.close();


		adminfilename = "WeiChat\\Parties\\" + ThidPartyID + "\\" + ThidPartyID + "admin.txt";
		adminfile.open(adminfilename);

		while (!adminfile.eof())
		{

			getline(adminfile, admintemp);

			WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().push_back(admintemp);

		}
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().size() != 0)
		{
			WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnAdminsID().pop_back();
		}

		adminfile.close();

	}
	/*adminfilename = "WeiChatList\\Parties\\" + id + "\\" + id + "admin.txt";*/
	/*adminfile.open(adminfilename);*/
	/*while (!adminfile.eof())
	{

	getline(adminfile, temp);

	AdminQQ.push_back(temp);

	}*/
	/*AdminQQ.pop_back();*/
}

void WeiChatToolsBase_CHC::DeleteFriend()
{
	system("CLS");

	//��ʾ���к���
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "����" << WeiChatList[Myqq]->ReturnFriendNumber() << "������" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnFriendNumber(); i++)
	{
		cout << "��" << i + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "΢�ź�:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}


	//ɾ����WeiChatList�еĺ���
	string qq;
	cout << "��������ɾ�����ѵ�΢�ź�" << endl;
	cin >> qq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	bool flag = false;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "��û�д˺���" << endl;
		cout << "1.��������΢�ź�" << endl;
		cout << "2.����΢����ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			DeleteFriend();
			break;

		default:
			WeiChatMenu();
			break;
		}

	}
	int num = WeiChatList[Myqq]->ReturnFriendNumber();
	for (int i = 0; i < (WeiChatList[Myqq]->ReturnFriendNumber()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == qq)
		{
			WeiChatList[Myqq]->ReturnFriendList().erase(WeiChatList[Myqq]->ReturnFriendList().begin() + i);
			WeiChatList[Myqq]->ReturnFriendList().resize(num - 1);//�������ú���������С
			WeiChatList[Myqq]->ChangeFriendsNumber(num - 1);
		}
	}

	/*SaveFriends();*/
	//ɾ����WeiChatList�еĺ���WeiChatList
	fstream myqqfile;
	string temp1;
	string content1;
	int word = 0;
	string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
	string friendqqfilename = "WeiChat\\" + qq + "\\" + qq + "Friendlist.txt";
	myqqfile.open(myqqfilename);
	while (!myqqfile.eof())
	{
		getline(myqqfile, temp1);
		for (int i = 0; i < size(temp1); i++)
		{
			content1.push_back(temp1[i]);
			word++;
		}
		content1.push_back('\n');
		word++;
	}
	int m = content1.find(qq);//�ҵ�����WeiChatList�ļ��б�WeiChatList��λ��
	for (int i = m; i < (m + word); i++)
	{
		content1.erase(content1.begin() + m);//ɾ��
	}
	myqqfile.close();
	myqqfile.open(myqqfilename, ios::trunc | ios::out);
	myqqfile << content1;
	myqqfile.close();



	//ɾ������WeiChatList�ļ��еı�WeiChatList
	fstream outfile;
	outfile.open(friendqqfilename);
	string temp;
	string content;
	int words = 0;
	while (!outfile.eof())
	{
		getline(outfile, temp);
		for (int i = 0; i < size(temp); i++)
		{
			content.push_back(temp[i]);
			words++;
			//if (temp[i] < 0 || temp[i] > 127)//�����ַ�ռ�����ֽ�
			//{
			//	words++;
			//}
		}
		content.push_back('\n');
		words++;
	}

	m = content.find(LoginedWeiChat);//�ҵ�����WeiChatList�ļ��б�WeiChatList��λ��
	for (int i = m; i < (m + words); i++)
	{
		content.erase(content.begin() + m);//ɾ��
	}
	outfile.close();

	outfile.open(friendqqfilename, ios::trunc | ios::out);
	outfile << content;
	outfile.close();

	cout << "ɾ�����ѳɹ�" << endl;
	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::AgreeFriend()
{
	system("CLS");
	fstream myqqfile;
	string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
	string friendqqfilename;


	myqqfile.open(myqqfilename);
	int Myqq, friendqq;
	string qq;
	string temp;
	string fdqq;

	string name, id;

	char c;
	int line = 0;
	bool flag = false;
	while (myqqfile.get(c))//��ȡ������WeiChat
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}

		if (line == 1) //��ȡ����Ӻ��ѵ���WeiChat��
		{
			if (c == '\n')
			{
				break;
			}
			temp.push_back(c);
		}
	}
	if (flag == false)
	{
		cout << "û�к�������" << endl;
		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	myqqfile.close();
	fdqq = temp;
	/*string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";*/
	friendqqfilename = "WeiChat\\" + fdqq + "\\" + fdqq + "Friendlist.txt";

	//temp.pop_back();
	cout << "���Ƿ�ͬ��" << temp << "�ĺ�������?" << endl;
	cout << "1.ͬ��" << endl;
	cout << "2.�ܾ�" << endl;

	string FriendApplyQQ = temp;

	int select;
	cin >> select;

	string content;
	string msg;
	fstream friendqqfile;
	int n = 0;
	int linefriend = 0;
	string contentfriend;
	string msgfriend;


	string myacepttemp;
	vector<string> myaceptcontent;
	string friendacepttemp;
	vector<string> friendaceptcontent;
	switch (select)
	{
	case 1:
		myqqfile.open(myqqfilename);


		while (!myqqfile.eof())
		{

			//char ch[1000];

			/*getline(myqqfile, msg);*/
			getline(myqqfile, myacepttemp);
			myaceptcontent.push_back(myacepttemp);

			//for (int i = 0; i < size(msg); i++)
			//{
			//	content.push_back(msg[i]);//��ȡ�ļ�����
			//}


			//content.push_back('\n');

		}
		myaceptcontent.pop_back();
		/*content.pop_back();
		content.shrink_to_fit();*/


		//for (int i = 0; i < size(content); i++)//��δ������ɾ��
		//{
		//	if (content[i] == '^')
		//	{

		//		content.erase(content.begin() + i);
		//	}
		//}
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			if (myaceptcontent[i] == ("^" + FriendApplyQQ))
			{
				myaceptcontent[i] = FriendApplyQQ;
			}
		}

		myqqfile.close();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //���ԭ���ļ�����

															/*myqqfile << content;*/
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			myqqfile << myaceptcontent[i] << endl;
		}

		/*cout << "ȷ������ɹ�" << endl;*/

		myqqfile.close();





		friendqqfile.open(friendqqfilename);

		while (!friendqqfile.eof())//��ȡ�����ļ�����
		{

			/*getline(friendqqfile, msgfriend);*/
			getline(friendqqfile, friendacepttemp);
			friendaceptcontent.push_back(friendacepttemp);

			/*for (int i = 0; i < size(msgfriend); i++)
			{
			contentfriend.push_back(msgfriend[i]);
			}
			contentfriend.push_back('\n');*/
		}
		friendaceptcontent.pop_back();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();*/

		//for (int i = 0; i < size(contentfriend); i++)//ɾ�������ļ��еı��
		//{
		//	if (contentfriend[i] == '&')
		//	{
		//		contentfriend.erase(contentfriend.begin() + i);
		//	}
		//}
		for (int i = 0; i < size(friendaceptcontent); i++)
		{
			if (friendaceptcontent[i] == ("&" + LoginedWeiChat))
			{
				friendaceptcontent[i] = LoginedWeiChat;
			}
		}
		friendqqfile.close();

		friendqqfile.open(friendqqfilename, ios::out | ios::trunc);//��պ����ļ�����
																   //friendqqfile << contentfriend;//����д��ɾ����Ǻ�ĺ����ļ�����
		for (int i = 0; i < size(friendaceptcontent); i++)
		{
			friendqqfile << friendaceptcontent[i] << endl;
		}
		friendqqfile.close();

		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == fdqq)
			{
				friendqq = i;
			}
		}
		name = WeiChatList[friendqq]->ReturnName();
		id = WeiChatList[friendqq]->ReturnID();
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
		WeiChatList[Myqq]->ChangeFriendsNumber(WeiChatList[Myqq]->ReturnFriendNumber() + 1);

		friendqqfile.close();
		cout << "ȷ������ɹ�" << endl;
		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "���Ѿܾ�������" << endl;

		myqqfile.open(myqqfilename);

		string myqqfiletemp;
		vector<string> myqqfilecontent;

		while (!myqqfile.eof())
		{

			/*getline(myqqfile, msg);*/
			getline(myqqfile, myqqfiletemp);

			myqqfilecontent.push_back(myqqfiletemp);

			//for (int i = 0; i < size(msg); i++)
			//{
			//	content.push_back(msg[i]);//��ȡ�ļ�����
			//}

			//content.push_back('\n');

		}
		myqqfilecontent.pop_back();

		/*content.pop_back();
		content.shrink_to_fit();*/

		//for (int i = 0; i < size(content); i++)
		//{
		//	if (content[i] == '^')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			content.erase(content.begin() + n); //ɾ��������WeiChat


		//			if (content[n] == '\n')
		//			{
		//				content.erase(content.begin() + n);
		//				break;
		//			}

		//		}
		//		break;
		//	}
		//}
		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			if (myqqfilecontent[i] == ("^" + FriendApplyQQ))
			{
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				myqqfilecontent.erase(myqqfilecontent.begin() + i);
				break;
			}
		}
		myqqfile.close();
		myqqfilecontent.shrink_to_fit();

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //���ԭ���ļ�����
															/*myqqfile << content;*/

		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			myqqfile << myqqfilecontent[i] << endl;
		}
		myqqfile.close();





		//ɾ�������ļ��е�WeiChat
		friendqqfile.open(friendqqfilename);
		string friendfiletemp;
		vector<string> friendfilecontent;

		while (!friendqqfile.eof())
		{
			/*getline(friendqqfile, msgfriend);*/
			getline(friendqqfile, friendfiletemp);
			friendfilecontent.push_back(friendfiletemp);

			//for (int i = 0; i < size(msgfriend); i++)
			//{
			//	contentfriend.push_back(msgfriend[i]);//��ȡ�ļ�����
			//}

			//contentfriend.push_back('\n');
		}
		friendfilecontent.pop_back();
		friendqqfile.close();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();
		friendqqfile.close();*/

		//for (int i = 0; i < size(contentfriend); i++) //ɾ�������ļ��еı�WeiChat
		//{
		//	if (contentfriend[i] == '&')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			contentfriend.erase(contentfriend.begin() + n); //ɾ��������WeiChat

		//			if (contentfriend[n] == '\n')
		//			{
		//				contentfriend.erase(contentfriend.begin() + n);
		//				break;
		//			}

		//		}
		//		break;
		//	}
		//}

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			if (friendfilecontent[i] == ("&" + LoginedWeiChat))
			{
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
				friendfilecontent.erase(friendfilecontent.begin() + i);
			}
		}
		friendfilecontent.shrink_to_fit();

		friendqqfile.open(friendqqfilename, ios::out, ios::trunc);//���ԭ������
																  /*friendqqfile << contentfriend;*/

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			friendqqfile << friendfilecontent[i] << endl;
		}
		friendqqfile.close();





		cout << "�����������WeiChat��ҳ" << endl;
		_getch();
		WeiChatMenu();
		break;
	}
}

void WeiChatToolsBase_CHC::ShowFriendInformation()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "�����������ѯ�ĺ���WeiChatList�ţ�������#����WeiChatList���˵�" << endl;
	string FriendQQ;
	cin >> FriendQQ;

	int Myqq;
	if (FriendQQ == "#")
	{
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	bool FriendCheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
			{
				FriendCheckFlag = true;
			}
		}
		if (FriendCheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "��û�д˺��ѣ����������������#����WeiChatList���˵�" << endl;
			cin >> FriendQQ;
			if (FriendQQ == "#")
			{
				WeiChatMenu();
			}
			else
			{
				continue;
			}
		}
	}

	int friendid;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == FriendQQ)
		{
			friendid = i;
		}
	}

	int friendremarks;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
		{
			friendremarks = i;
		}
	}

	cout << "����Ϊ�˺�����Ϣ" << endl;
	cout << "�ʺ�:" << WeiChatList[friendid]->ReturnID() << endl;
	cout << "����:" << WeiChatList[friendid]->ReturnName() << endl;
	cout << "��ע:" << WeiChatList[Myqq]->ReturnFriendList()[friendremarks]->ReturnRemarks() << endl;
	cout << "����ǩ��:" << WeiChatList[friendid]->ReturnAutograph() << endl;
	cout << "���ڵ���:" << WeiChatList[friendid]->ReturnArea() << endl;

	cout << endl;

	cout << "�����������WeiChatList���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowFriendNoReturn()
{
	system("CLS");
	//GetFriends();

	int friendsnum;
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	friendsnum = size(WeiChatList[Myqq]->ReturnFriendList());
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//�ж���Ӻ��ѱ��
		{
			friendsnum--;
		}
	}

	cout << "����" << friendsnum << "������" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "��" << friends + 1 << "λ����" << endl;
		cout << "����:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}
}

void WeiChatToolsBase_CHC::ChangeFriendRemarks()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "�����������ѯ�ĺ���WeiChatList�ţ�������#����WeiChatList���˵�" << endl;
	string FriendQQ;
	cin >> FriendQQ;

	int Myqq;
	if (FriendQQ == "#")
	{
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	bool FriendCheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
			{
				FriendCheckFlag = true;
			}
		}
		if (FriendCheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "��û�д˺��ѣ����������������#����WeiChatList���˵�" << endl;
			cin >> FriendQQ;
			if (FriendQQ == "#")
			{
				WeiChatMenu();
			}
			else
			{
				continue;
			}
		}
	}



	cout << "�����������޸ĵı�ע" << endl;
	string NewRemarks;
	cin >> NewRemarks;



	int friendid;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() == FriendQQ)
		{
			friendid = i;
		}
	}

	WeiChatList[Myqq]->ReturnFriendList()[friendid]->ChangeRemarks(NewRemarks);
	SaveChange();

	cout << "�޸ı�ע�ɹ�" << endl;
	cout << "�����������WeiChatList���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::SaveChange()
{
	fstream qqfile;
	string qqfilename = "WeiChat.txt";
	qqfile.open(qqfilename, ios::trunc | ios::out);
	for (int i = 0; i < size(WeiChatList); i++)
	{
		qqfile << WeiChatList[i]->ReturnID() << endl;
		qqfile << WeiChatList[i]->ReturnAge() << endl;
		qqfile << WeiChatList[i]->ReturnPassWord() << endl;
		qqfile << WeiChatList[i]->ReturnName() << endl;
		qqfile << WeiChatList[i]->ReturnArea() << endl;
		qqfile << WeiChatList[i]->ReturnAutograph() << endl;
		qqfile << " " << endl;
	}
	qqfile.close();


	fstream qqfriendlistfile;
	string qqfriendlistfilename = "WeiChatList\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";
	qqfriendlistfile.open(qqfriendlistfilename, ios::out | ios::trunc);

	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		qqfriendlistfile << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnRemarks() << endl;
		qqfriendlistfile << " " << endl;
	}
	qqfriendlistfile.close();
}

void WeiChatToolsBase_CHC::ShowParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "�㹲��" << WeiChatList[Myqq]->ReturnPartyNumber() << "��Ⱥ" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "��" << i + 1 << "��Ⱥ" << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "Ⱥ����:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "�����������WeiChatList��ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::AgreeMember()
{
	system("CLS");
	ShowPartyNoReturn();
	cout << "������Ҫ�����Ⱥ��" << endl;
	char c;
	int line = 0;
	bool flag = false;
	string id;
	string txt = ".txt";
	cin >> id;
	string filename = "WeiChat\\Parties\\" + id + "\\" + id + ".txt";
	ifstream infile;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cout << "û�д�Ⱥ,����������򷵻�΢����ҳ" << endl;
		cout << "1.��������" << endl;
		cout << "2.����WeiChatList��ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AgreeMember();
			break;

		case 2:
			WeiChatMenu();
			break;
		}
	}
	infile.close();
	fstream outfile;
	outfile.open(filename);

	string temp;
	while (outfile.get(c))
	{
		if (c == '\n')
		{
			line++;
			continue;
		}
		if (line == 2) //��ȡȺ��WeiChatList��
		{
			temp.push_back(c);
		}

	}
	string OwnerQQ = temp;

	/*temp.pop_back(); *///ɾ��ĩβ\n


						 //��ȡȺ����ԱWeiChatList
	fstream adminfile;
	string adminfilename;
	string admintemp;
	vector<string> AdminQQ;
	adminfilename = "WeiChatList\\Parties\\" + id + "\\" + id + "admin.txt";
	adminfile.open(adminfilename);

	while (!adminfile.eof())
	{

		getline(adminfile, temp);

		AdminQQ.push_back(temp);

	}
	AdminQQ.pop_back();


	bool Adminflag = false;
	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == LoginedWeiChat)
		{
			Adminflag = true;
			break;
		}
	}

	if (OwnerQQ == LoginedWeiChat)
	{
		cout << "Ⱥ����ã���ӭ�鿴��Ⱥ����" << endl;

	}
	else if (Adminflag == true)
	{
		cout << "����Ա��ã���ӭ�鿴��Ⱥ����" << endl;
	}
	else
	{
		cout << "�㲻�Ǹ�Ⱥ��Ⱥ�������Ա,�޷������Ⱥ" << endl;
		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	outfile.close();
	temp.clear();


	line = 0;
	outfile.open(filename);


	while (outfile.get(c))
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}
		//if (line == 1) //��ȡ������Ⱥ����WeiChatList��
		//{
		//	temp.push_back(c);
		//	//temp.clear();//�����
		//	line++;
		//}
		if (line == 1)
		{
			temp.push_back(c);
		}

	}

	if (flag == false)
	{
		cout << "û�м�Ⱥ����" << endl;
		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		WeiChatMenu();
	}
	//}
	outfile.close();
	temp.pop_back();
	cout << "���Ƿ�ͬ��" << temp << "��Ⱥ?" << endl;
	cout << "1.ͬ��" << endl;
	cout << "2.�ܾ�" << endl;
	int select;
	cin >> select;

	string member = temp;
	string PartyList = "PartyList.txt";
	string filename1 = "WeiChatList\\" + member + "\\" + member + "PartyList.txt";
	string msg;
	vector<char> content;
	int n = 0;

	/*auto iter = content.begin();
	auto iter1 = temp.begin();*/
	/*int m = 0;*/
	/*char ch1[1000];*/
	/*int words = 0;*/

	switch (select)
	{
	case 1:
		outfile.open(filename, ios::in | ios::out);

		while (!outfile.eof())
		{

			char ch[1000];

			outfile.getline(ch, 1000);
			for (int i = 0; i < strlen(ch); i++)
			{
				msg.push_back(ch[i]);//��ȡ�ļ�����
			}


			msg.push_back('\n');

		}



		for (int i = 0; i < size(msg); i++)//��δ������ɾ��
		{
			if (msg[i] == '^')
			{
				/*			content[i];*/
				//content.erase(content.begin() + i);
				msg.erase(msg.begin() + i);
				break;
			}
		}
		msg.pop_back();
		/*size(temp);*/
		/*cout << msg;*/


		outfile.close();

		outfile.open(filename, ios::out, ios::trunc); //���ԭ���ļ�����

		outfile << msg;

		cout << "ȷ������ɹ�" << endl;

		outfile.close();

		outfile.open(filename1, ios::app);

		outfile << id << endl;

		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "���Ѿܾ�������" << endl;
		outfile.open(filename);

		while (!outfile.eof())
		{

			char ch[1000];

			outfile.getline(ch, 1000);
			for (int i = 0; i < strlen(ch); i++)
			{
				msg.push_back(ch[i]);//��ȡ�ļ�����
			}

			msg.push_back('\n');

		}
		outfile.close();

		/*while (outfile.get(c))
		{
		content.emplace_back(c);
		}*/

		for (int i = 0; i < size(msg); i++)
		{
			if (msg[i] == '^')
			{

				n = i;

				while (1)
				{
					msg.erase(msg.begin() + n); //ɾ��������WeiChatList


					if (msg[n] == '\n')
					{
						msg.erase(msg.begin() + n);
						break;
					}


				}

				break;
			}
		}
		msg.pop_back();

		outfile.open(filename, ios::out, ios::trunc);//���ԭ������

		outfile << msg;

		outfile.close();

		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		WeiChatMenu();

		break;
	}
}

void WeiChatToolsBase_CHC::ShowPartyNoReturn()
{
	/*system("CLS");*/
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "�㹲��" << WeiChatList[Myqq]->ReturnPartyNumber() << "��Ⱥ" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "��" << i + 1 << "��Ⱥ" << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "Ⱥ����:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "Ⱥ��:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	
}

void WeiChatToolsBase_CHC::AddPartyMember()
{
	system("CLS");
	cout << "��������������Ⱥ" << endl;
	string partyid;
	cin >> partyid;
	WeiChatPartyMember = partyid;
	string id;
	int Myqq;
	id = WeiChatPartyMember;
	string txt = ".txt";

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == partyid)
		{
			cout << "������Ӵ�Ⱥ" << endl;
			cout << "�����������QQ��ҳ" << endl;
			_getch();
			_getch();
			WeiChatMenu();
		}
	}

	fstream CheckPartyListFile;
	string GetLinkFileName = "PartyList.txt";
	CheckPartyListFile.open(GetLinkFileName, ios::in);
	if (!CheckPartyListFile)
	{
		CheckPartyListFile.close();
		CheckPartyListFile.open(GetLinkFileName, ios::out);
	}
	CheckPartyListFile.close();

	bool IsPartyFlag = false;
	fstream IsPartyFile;
	string ISpartyFileName = "PartyList.txt";
	vector<string>AllPartyIDList;
	string IsPartyTemp;
	IsPartyFile.open(ISpartyFileName);
	while (!IsPartyFile.eof())
	{
		getline(IsPartyFile, IsPartyTemp);

		AllPartyIDList.emplace_back(IsPartyTemp);
	}
	IsPartyFile.close();
	for (int i = 0; i < size(AllPartyIDList); i++)
	{
		if (AllPartyIDList[i] == partyid)
		{
			IsPartyFlag = true;
			break;
		}
	}

	if (IsPartyFlag == false)
	{
		cout << "û�д�Ⱥ�������������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}



	string filename = "WeiChat\\Parties\\" + partyid + "\\" + partyid + ".txt";
	ofstream ofile;
	ofile.open(filename, ios::app);
	ofile << "^" << LoginedWeiChat << endl;
	/*for (int i = 0; i < size(WeiChatList); i++)
	{
	if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
	{
	Myqq = i;
	}
	}*/
	ofile.close();
	cout << "������Ⱥ�ɹ�,��ȴ�Ⱥ��ͬ��" << endl;
	cout << "�����������WeiChatList��ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::QuitParty()
{
	bool flag = false;
	int Myqq, select;
	string partyid;
	cout << "�����������˳���΢��Ⱥ" << endl;
	cin >> partyid;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == partyid)
		{
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "��û�м����Ⱥ" << endl;
		cout << "��ѡ����������򷵻�΢�����˵�" << endl;
		cout << "1.��������΢��Ⱥ" << endl;
		cout << "2.����΢�����˵�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			QuitParty();
			break;
		default:
			WeiChatMenu();
			break;
		}
	}


	//��WeiChatListȺ�б���ɾ����Ⱥ
	fstream myqqpartylistfile;
	string temp;//��ȡ�ļ�ÿ������
	string content;//�����ļ���������
	string myqqpartylistfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "PartyList.txt";
	myqqpartylistfile.open(myqqpartylistfilename);

	while (!myqqpartylistfile.eof())
	{
		getline(myqqpartylistfile, temp);

		if (temp == partyid)
		{
			continue;
		}

		for (int i = 0; i < size(temp); i++)
		{
			content.push_back(temp[i]);
		}
		content.push_back('\n');


	}
	content.pop_back();//ɾ������\n
	myqqpartylistfile.close();

	myqqpartylistfile.open(myqqpartylistfilename, ios::out | ios::trunc);
	myqqpartylistfile << content;
	myqqpartylistfile.close();



	//�ӱ�Ⱥ�б���ɾ����WeiChatList
	fstream partyfile;
	string partyfilename = "WeiChat\\Parties\\" + partyid + "\\" + partyid + ".txt";
	partyfile.open(partyfilename);
	string partycontent;
	string partytemp;
	vector<string> partyvec;

	while (!partyfile.eof())
	{
		getline(partyfile, partytemp);
		partyvec.push_back(partytemp);
		for (int i = 0; i < size(partytemp); i++)
		{
			partycontent.push_back(partytemp[i]);
		}

		partycontent.push_back('\n');
	}
	partycontent.pop_back();//ɾ��ĩβ\n
	partyvec.pop_back();
	partyfile.close();
	partyvec.shrink_to_fit();

	partyfile.open(partyfilename, ios::out | ios::trunc);

	for (int i = 0; i < size(partyvec); i++)
	{
		if (partyvec[i] == LoginedWeiChat)
		{
			partyvec.erase(partyvec.begin() + i);
			break;
		}
	}
	partyvec.shrink_to_fit();
	for (int i = 0; i < size(partyvec); i++)
	{
		partyfile << partyvec[i] << endl;
	}
	/*partyfile << partycontent;*/
	partyfile.close();



	fstream partyadminfile;
	string partyadminfilename;
	string admincontent;
	string admintemp;
	vector<string> AdminQQ;
	partyadminfilename = "WeiChat\\Parties\\" + partyid + "\\" + partyid + "admin.txt";
	partyadminfile.open(partyadminfilename);

	while (!partyadminfile.eof())
	{
		getline(partyadminfile, admintemp);
		/*admintemp.push_back('\n');*/
		AdminQQ.push_back(admintemp);
		for (int i = 0; i < size(admintemp); i++)
		{
			admincontent.push_back(admintemp[i]);
		}

		admincontent.push_back('\n');
	}
	admincontent.pop_back();
	AdminQQ.pop_back();
	partyadminfile.close();

	bool adminflag = false;
	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == LoginedWeiChat)
		{
			adminflag = true;
			break;
		}
	}


	if (adminflag == false)
	{
		cout << "�˳�Ⱥ" << partyid << "�ɹ�" << endl;
		cout << "�����������WeiChatList���˵�" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	partyadminfile.open(partyadminfilename, ios::out | ios::trunc);

	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == LoginedWeiChat)
		{
			AdminQQ.erase(AdminQQ.begin() + i);
		}
	}

	AdminQQ.clear();
	AdminQQ.shrink_to_fit();
	for (int i = 0; i < size(AdminQQ); i++)
	{
		partyadminfile << AdminQQ[i] << endl;
	}

	partyadminfile.close();


	cout << "�˳�Ⱥ" << partyid << "�ɹ�" << endl;
	cout << "�����������WeiChatList���˵�" << endl;

	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::DeletePartyMember()
{
	system("CLS");
	ShowPartyNoReturn();
	cout << "������Ҫ�����Ⱥ��" << endl;
	char c;
	int line = 0;
	bool flag = false;
	string id;
	string txt = ".txt";
	string PartyOwner;
	cin >> id;
	string filename = "WeiChat\\Parties\\" + id + "\\" + id + ".txt";
	ifstream infile;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cout << "û�д�Ⱥ,����������򷵻�WeiChatList��ҳ" << endl;
		cout << "1.��������" << endl;
		cout << "2.����WeiChatList��ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AgreeMember();
			break;

		case 2:
			WeiChatMenu();
			break;
		}
	}
	infile.close();



	//��ȡȺ��WeiChatList
	fstream outfile;
	outfile.open(filename);
	string temp;
	while (outfile.get(c))
	{
		if (c == '\n')
		{
			line++;
			continue;
		}
		if (line == 2) //��ȡȺ��WeiChatList��
		{
			temp.push_back(c);
		}

	}
	/*temp.pop_back(); *///ɾ��ĩβ\n
	PartyOwner = temp;//Ⱥ��WeiChatList


					  //��ȡȺ����ԱWeiChatList
	fstream adminfile;
	string adminfilename;
	string admintemp;
	vector<string> AdminQQ;
	adminfilename = "WeiChat\\Parties\\" + id + "\\" + id + "admin.txt";
	adminfile.open(adminfilename);
	while (!adminfile.eof())
	{

		getline(adminfile, temp);

		AdminQQ.push_back(temp);

	}
	AdminQQ.pop_back();



	//�ж��Ƿ��ǹ���Ա��Ⱥ��
	bool Adminflag = false;
	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (AdminQQ[i] == LoginedWeiChat)
		{
			Adminflag = true;
			break;
		}
	}

	if (PartyOwner == LoginedWeiChat)
	{
		cout << "Ⱥ����ã���ӭ����Ⱥ��Ա����" << endl;
		/*cout << "�㲻�Ǹ�Ⱥ��Ⱥ�������Ա,�޷������Ⱥ" << endl;
		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();*/
	}
	else if (Adminflag == true)
	{
		cout << "����Ա��ã���ӭ����Ⱥ��Ա����" << endl;
	}
	else
	{
		cout << "�㲻�Ǹ�Ⱥ��Ⱥ�������Ա,�޷������Ⱥ" << endl;
		cout << "�����������WeiChatList��ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	outfile.close();
	temp.clear();




	//��ȡȺ��Ա
	fstream Partyfile;
	string Partyfilename = "WeiChat\\Parties\\" + id + "\\" + id + ".txt";
	string PartyMembertemp;
	vector<string> PartyMember;
	Partyfile.open(Partyfilename);
	while (!Partyfile.eof())
	{
		getline(Partyfile, PartyMembertemp);

		PartyMember.push_back(PartyMembertemp);
	}
	PartyMember.pop_back();





	bool Ownerflag = false;
	Adminflag = false;
	if (LoginedWeiChat == PartyOwner)
	{
		cout << "��Ϊ��ȺȺ�������߳���������κ���" << endl;
		Ownerflag = true;
	}
	else
	{
		cout << "��Ϊ��Ⱥ����Ա�������߳���Ⱥ���͹���Ա�������" << endl;
		Adminflag = true;
	}


	ShowPartyInformationNoReturn(id);
	cout << "������Ҫ�߳��ĳ�Ա΢�ź�" << endl;
	string DeleteMemberQQ;
	cin >> DeleteMemberQQ;


	//�������WeiChatList�Ƿ���Ⱥ�������Լ�
	bool checkflag = false;//����Ƿ��д˳�Ա
						   /*if (DeleteMemberQQ == PartyOwner|| DeleteMemberQQ == LoginedWeiChat)
						   {*/
						   /*cout << "�޷��߳�Ⱥ�����Լ�������������" << endl;
						   cin >> DeleteMemberQQ;*/
	while (1)
	{
		if (DeleteMemberQQ == PartyOwner || DeleteMemberQQ == LoginedWeiChat)
		{
			cout << "�޷��߳�Ⱥ�����Լ�������������" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

		for (int i = 0; i < size(PartyMember); i++)//����Ƿ��д˳�Ա
		{
			if (DeleteMemberQQ == PartyMember[i])
			{
				checkflag = true;
				break;
			}
		}

		if (checkflag == false)
		{
			cout << "û�д˳�Ա����������" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

		if (Adminflag == true)//������˺��ǹ���Ա�����߳���Ա�Ƿ��ǹ���Ա
		{
			for (int i = 0; i < size(AdminQQ); i++)
			{
				if (AdminQQ[i] == DeleteMemberQQ)
				{
					cout << "����Ա�����߳���������Ա,����������" << endl;
					cin >> DeleteMemberQQ;
					continue;
				}
			}
		}


		//����Ƿ���Ⱥ�����Լ�
		if (DeleteMemberQQ != PartyOwner && DeleteMemberQQ != LoginedWeiChat)
		{
			break;
		}
		else
		{
			cout << "�޷��߳�Ⱥ�����Լ�������������" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

	}
	/*}*/



	//�Ӹó�ԱȺ�б���ɾ����Ⱥ
	fstream memberpartylistfile;
	string memberpartylistfilename = "WeiChat\\" + DeleteMemberQQ + "\\" + DeleteMemberQQ + "PartyList.txt";
	string memberpartylisttemp;
	vector<string> memeberpartylistcontent;
	memberpartylistfile.open(memberpartylistfilename);
	while (!memberpartylistfile.eof())
	{
		getline(memberpartylistfile, memberpartylisttemp);
		memeberpartylistcontent.push_back(memberpartylisttemp);
	}
	memeberpartylistcontent.pop_back();
	memberpartylistfile.close();

	for (int i = 0; i < size(memeberpartylistcontent); i++)
	{
		if (memeberpartylistcontent[i] == id)
		{
			memeberpartylistcontent.erase(memeberpartylistcontent.begin() + i);
		}
	}
	memeberpartylistcontent.shrink_to_fit();

	memberpartylistfile.open(memberpartylistfilename, ios::trunc | ios::out);
	for (int i = 0; i < size(memeberpartylistcontent); i++)
	{
		memberpartylistfile << memeberpartylistcontent[i] << endl;
	}
	memberpartylistfile.close();



	//�ӱ�Ⱥ��Ա�б���ɾ���˳�Ա
	fstream PartyMemberListFile;
	string PartyMEmberListFileName = "WeiChat\\Parties\\" + id + "\\" + id + ".txt";
	string PartyMEmberListTemp;
	vector<string> PartyMemberListContent;
	PartyMemberListFile.open(PartyMEmberListFileName);
	while (!PartyMemberListFile.eof())
	{
		getline(PartyMemberListFile, PartyMEmberListTemp);

		PartyMemberListContent.push_back(PartyMEmberListTemp);
	}
	PartyMemberListContent.pop_back();
	PartyMemberListFile.close();

	for (int i = 0; i < size(PartyMemberListContent); i++)
	{
		if (PartyMemberListContent[i] == DeleteMemberQQ)
		{
			PartyMemberListContent.erase(PartyMemberListContent.begin() + i);
			break;
		}
	}
	PartyMemberListContent.shrink_to_fit();

	PartyMemberListFile.close();
	PartyMemberListFile.open(PartyMEmberListFileName, ios::trunc | ios::out);
	for (int i = 0; i < size(PartyMemberListContent); i++)
	{

		PartyMemberListFile << PartyMemberListContent[i] << endl;

	}
	PartyMemberListFile.close();



	int ThisParty;
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == id)
		{
			ThisParty = i;
			break;
		}
	}
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()[i] == DeleteMemberQQ)
		{
			WeiChatList[Myqq]->ReturnPartyList()[ThisParty]->ReturnPartyMembers().erase(WeiChatList[Myqq]->ReturnPartyList()[ThisParty]->ReturnPartyMembers().begin() + i);
			break;
		}
	}
	WeiChatList[Myqq]->ReturnPartyList()[ThisParty]->ReturnPartyMembers().shrink_to_fit();



	//����ó�Ա�ǹ���Ա��ӹ���Ա�б���ɾ����WeiChatList
	for (int i = 0; i < size(AdminQQ); i++)
	{
		if (DeleteMemberQQ == AdminQQ[i])
		{
			AdminQQ.erase(AdminQQ.begin() + i);
			adminfile.open(adminfilename, ios::trunc);
			for (int i = 0; i < size(AdminQQ); i++)
			{
				adminfile << AdminQQ[i];
			}
			adminfile.close();

			cout << "�߳�" << DeleteMemberQQ << "�ɹ�" << endl;
			cout << "�����������WeiChatList���˵�" << endl;
			_getch();
			_getch();
			WeiChatMenu();

		}

		else
		{
			cout << "�߳�" << DeleteMemberQQ << "�ɹ�" << endl;
			cout << "�����������WeiChatList���˵�" << endl;
			_getch();
			_getch();
			WeiChatMenu();
		}
	}
}

void WeiChatToolsBase_CHC::ShowPartyInformation()
{
	system("CLS");
	ShowPartyNoReturn();

	cout << "��������Ҫ��ѯ��Ա��Ϣ��WeiChatListȺ,������#����WeiChatList���˵�" << endl;
	string  QQPartyID;
	cin >> QQPartyID;
	if (QQPartyID == "#")
	{
		WeiChatMenu();
	}
	/*cout << "��������Ҫ��ѯ��Ϣ�ĳ�ԱWeiChatList" << endl;
	string QQPartyMemberID;
	cin >> QQPartyMemberID;*/
	int Myqq;
	int ThisQQPartyID;
	int ThisQQ;
	string ThisQQID;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	bool CheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
			{
				CheckFlag = true;
				break;
			}

		}

		if (CheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "��û�м����Ⱥ�����������������#����WeiChatList���˵�" << endl;
			cin >> QQPartyID;
			continue;
		}
	}


	system("CLS");
	bool AdminFlag = false;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
		{
			ThisQQPartyID = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()); i++)
	{
		int m = size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers());

		ThisQQID = WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()[i];//��Ⱥ�б��ȡȺ��ԱWeiChatList
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == ThisQQID)
			{
				ThisQQ = i;
				break;
			}
		}
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnAdminsID()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnAdminsID()[i] == ThisQQID)
			{
				AdminFlag = true;
				break;
			}
		}
		if (ThisQQID == WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnCreatUserID())
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:Ⱥ��" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
		else if (AdminFlag == true)
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:����Ա" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
			AdminFlag = false;
		}

		else
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:��ͨ��Ա" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
	}

	cout << endl;
	cout << "�����������WeiChatList���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowMyInformation()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "����Ϊ��ĸ�����Ϣ:" << endl;
	cout << "�ʺ�:" << WeiChatList[Myqq]->ReturnID() << endl;
	cout << "����:" << WeiChatList[Myqq]->ReturnPassWord() << endl;
	cout << "����:" << WeiChatList[Myqq]->ReturnName() << endl;
	cout << "����:" << WeiChatList[Myqq]->ReturnArea() << endl;
	cout << "ע������:" << WeiChatList[Myqq]->ReturnAge() << endl;
	cout << "����ǩ��:" << WeiChatList[Myqq]->ReturnAutograph() << endl;
	cout << endl;
	cout << "�����������΢�����˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangePassWord()
{
	system("CLS");
	cout << "�������������" << endl;
	string pw;
	string pwagin;
	cin >> pw;
	cout << "�ٴ�ȷ�����������" << endl;
	cin >> pwagin;
	while (1)
	{
		if (pw != pwagin)
		{
			cout << "�������벻��������������" << endl;
			cin >> pw;
			cout << "�ٴ�ȷ�����������" << endl;
			cin >> pwagin;
			continue;
		}
		else
		{
			break;
		}
	}

	int Myqq;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	WeiChatList[Myqq]->ChangePassWord(pw);
	SaveChange();

	cout << "�޸�����ɹ�" << endl;
	cout << "�����������QQ���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeName()
{
	system("CLS");
	string newname;
	cout << "�������������" << endl;
	cin >> newname;

	int Myqq;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	WeiChatList[Myqq]->ChangeName(newname);
	SaveChange();

	cout << "�޸����Ƴɹ�" << endl;
	cout << "�����������QQ���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeAutoGraph()
{
	system("CLS");
	string autograph;
	cout << "���������ǩ��" << endl;
	cin >> autograph;

	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}

	WeiChatList[Myqq]->ChangeAutoGraph(autograph);
	cout << "�޸ĸ���ǩ���ɹ�" << endl;
	SaveChange();

	cout << "�����������QQ���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeArea()
{
	system("CLS");
	string Area;
	cout << "������ĵ���" << endl;
	cin >> Area;

	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	WeiChatList[Myqq]->ChangeArea(Area);
	SaveChange();

	cout << "�����������QQ���˵�" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::PlayGame()
{
	GameReturnFlag = 2;
	Controller c;//����һ��Controller��

	c.Game();//������Ϸѭ��

	_getch();
}

void WeiChatToolsBase_CHC::Client()
{
	system("CLS");
	// �����׽���
	cout << "��#������QQ��ҳ" << endl;
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" ����ʧ�� socket() \n");
		exit(0);
	}

	// Ҳ�������������bind������һ�����ص�ַ
	// ����ϵͳ�����Զ�����

	// ��дԶ�̵�ַ��Ϣ
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// ע�⣬����Ҫ��д����������TCPServer�������ڻ�����IP��ַ
	// �����ļ����û��������ֱ��ʹ��127.0.0.1����
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" �������������ʧ��connect() \n");
		cout << "�����������QQ��ҳ" << endl;
		_getch();
		WeiChatMenu();
	}

	char buff[256];
	char szText[256];
	cout << "��½�������ɹ�" << endl;
	while (TRUE)
	{
		//�ӷ������˽�������
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("���ԶԷ�����Ϣ��%s\n", buff);
		}

		// ��������˷�������
		cout << "�뷢����Ϣ:" << endl;
		cin >> szText;
		if (szText[0] == '#')
		{
			WeiChatMenu();
		}
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "��ȴ��Է��ظ�" << endl;
	}

	// �ر��׽���
	::closesocket(s);
}

void WeiChatToolsBase_CHC::LinkQQ()
{
	string linkqq;
	string linkpw;
	int ThisQQ;
	int ThisWeiChat;
	system("CLS");

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			ThisWeiChat = i;
		}
			
	}



	if (WeiChatList[ThisWeiChat]->ReturnLinkedQQ() != "")
	{
		cout << "���Ѿ���QQ"<< WeiChatList[ThisWeiChat]->ReturnLinkedQQ() <<endl<<"�����������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	cout << "��������Ҫ�󶨵�QQ��" << endl;
	cin >> linkqq;

	bool CheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(QQTools.ReturnQQ()); i++)
		{
			if (QQTools.ReturnQQ()[i]->ReturnID() == linkqq)
			{
				CheckFlag = true;
				ThisQQ = i;
				break;

			}
		}

		if (CheckFlag == false)
		{
			cout << "û�д�QQ�����������������#����΢����ҳ" << endl;
			cin >> linkqq;
			if (linkqq == "#")
			{
				WeiChatMenu();
			}
			continue;
		}
		else
		{
			break;
		}
	}

	cout << "�������QQ�ŵ�����" << endl;
	cin >> linkpw;
	bool PWCheckFlag = false;
	while (1)
	{
		if (QQTools.ReturnQQ()[ThisQQ]->ReturnPassWord() == linkpw)
		{
			PWCheckFlag = true;
			break;
		}

		if(PWCheckFlag == false)
		{
			cout << "��������������������������#����΢����ҳ" << endl;
			cin >> linkpw;
			if (linkpw == "#")
			{
				WeiChatMenu();
			}
			continue;
		}
	}

	fstream LinkFile;
	string LinkFileName = "WeiChat\\" + LoginedWeiChat + "\\Links.txt";
	LinkFile.open(LinkFileName, ios::app);

	LinkFile << "QQ:" + linkqq;
	LinkFile.close();
	WeiChatList[ThisWeiChat]->ChangeLinkedQQ(linkqq);


	fstream QQLinkFile;
	string QQLinkFileName = "QQ\\" + linkqq + "\\Links.txt";
	QQLinkFile.open(QQLinkFileName,ios::app);

	QQLinkFile << "΢��:" + LoginedWeiChat;
	QQLinkFile.close();
	QQTools.ReturnQQ()[ThisQQ]->ChangeLinkedWeiChat(LoginedWeiChat);

	cout << "��QQ�ɹ�" << endl;
	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::GetLinks()
{
	system("CLS");
	int ThisWeiChat;
	fstream GetLinksFile;
	fstream CheckFile;
	string GetLinkFileName = "WeiChat\\" + LoginedWeiChat + "\\Links.txt";

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

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			ThisWeiChat = i;
		}
	}

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
		WeiChatList[ThisWeiChat]->ChangeLinkedQQ(Links[0]);
	}

}

void WeiChatToolsBase_CHC::ShowQQCommonFriends()
{
	system("CLS");
	int MyWeiChat;
	int LinkedQQ;
	int ThisWeiChat;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			MyWeiChat = i;
			break;
		}
	}

	for (int i = 0; i < size(QQTools.ReturnQQ()); i++)
	{
		if (QQTools.ReturnQQ()[i]->ReturnID() == WeiChatList[MyWeiChat]->ReturnLinkedQQ())
		{
			LinkedQQ = i;
			break;
		}
	}

	if (ReturnWeiChatList()[MyWeiChat]->ReturnLinkedQQ() == "")
	{
		cout << "��û�а�QQ�����Ȱ�QQ" << endl;
		cout << "�����������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	cout << "��󶨵�QQ��Ϊ" << WeiChatList[MyWeiChat]->ReturnLinkedQQ() << endl;
	cout << "��ʹ�QQ�Ĺ�ͬ����������" << endl;

	int FriendFlag = false;
	int CommonFriendNumber = 1;

	
	QQTools.ReturnQQ()[LinkedQQ]->GetFriends();
	int fasd = size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList());
	/*for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnFriendList()); i++)
	{*/
		for (int j = 0; j < size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()); j++)
		{

			FriendFlag = false;

			for (int k = 0; k < size(WeiChatList); k++)
			{
				WeiChatList[k]->GetLinks();
				//QQ�б����ҵ��˺���
				if (WeiChatList[k]->ReturnLinkedQQ() == QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()[j]->ReturnID())
				{
					ThisWeiChat = k;
					FriendFlag = true;
					break;
				}
			}

			if (FriendFlag == false)
			{
				continue;
			}

			for (int p = 0; p < size(WeiChatList[MyWeiChat]->ReturnFriendList()); p++)
			{
				if (WeiChatList[MyWeiChat]->ReturnFriendList()[p]->ReturnID() == WeiChatList[ThisWeiChat]->ReturnID())
				{
					cout << "��" << CommonFriendNumber << "����ͬ����" << endl;
					cout << "΢�ź�:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnID();
					cout << "����:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnFriendName();
					cout << "��ע:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnRemarks();
					cout << endl;

					CommonFriendNumber++;
					break;
				}
			}


		}

	
	/*}*/

	QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList().clear();
	QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList().shrink_to_fit();
	/*for (int i = 0; i < size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()); i++)
	{
		delete QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()[i];
	}*/

	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowQQCommonFriendsNoReturn()
{
	system("CLS");
	int MyWeiChat;
	int LinkedQQ;
	int ThisWeiChat;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			MyWeiChat = i;
			break;
		}
	}

	for (int i = 0; i < size(QQTools.ReturnQQ()); i++)
	{
		if (QQTools.ReturnQQ()[i]->ReturnID() == WeiChatList[MyWeiChat]->ReturnLinkedQQ())
		{
			LinkedQQ = i;
			break;
		}
	}

	if (ReturnWeiChatList()[MyWeiChat]->ReturnLinkedQQ() == "")
	{
		cout << "��û�а�QQ�����Ȱ�QQ" << endl;
		cout << "�����������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	cout << "��󶨵�QQ��Ϊ" << WeiChatList[MyWeiChat]->ReturnLinkedQQ() << endl;
	cout << "��ʹ�QQ�Ĺ�ͬ����������" << endl;

	int FriendFlag = false;
	int CommonFriendNumber = 1;


	QQTools.ReturnQQ()[LinkedQQ]->GetFriends();
	int fasd = size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList());
	/*for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnFriendList()); i++)
	{*/
	for (int j = 0; j < size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()); j++)
	{

		FriendFlag = false;

		for (int k = 0; k < size(WeiChatList); k++)
		{
			WeiChatList[k]->GetLinks();
			//QQ�б����ҵ��˺���
			if (WeiChatList[k]->ReturnLinkedQQ() == QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()[j]->ReturnID())
			{
				ThisWeiChat = k;
				FriendFlag = true;
				break;
			}
		}

		if (FriendFlag == false)
		{
			continue;
		}

		for (int p = 0; p < size(WeiChatList[MyWeiChat]->ReturnFriendList()); p++)
		{
			if (WeiChatList[MyWeiChat]->ReturnFriendList()[p]->ReturnID() == WeiChatList[ThisWeiChat]->ReturnID())
			{
				cout << "��" << CommonFriendNumber << "����ͬ����" << endl;
				cout << "΢�ź�:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnID();
				cout << "����:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnFriendName();
				cout << "��ע:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnRemarks();
				cout << endl;

				CommonFriendNumber++;
				break;
			}
		}


	}


	/*}*/

	QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList().clear();
	QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList().shrink_to_fit();
	/*for (int i = 0; i < size(QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()); i++)
	{
	delete QQTools.ReturnQQ()[LinkedQQ]->ReturnFriendList()[i];
	}*/
}

void WeiChatToolsBase_CHC::AddQQCommonFriend()
{
	system("CLS");
	ShowQQCommonFriendsNoReturn();

	int Myqq;
	string id;
	string name;
	bool flag = false;
	cout << "���������QQ��ͬ���ѵ�΢�ź�" << endl;
	cin >> id;

	if (id == LoginedWeiChat)
	{
		cout << "�㲻������Լ�Ϊ����" << endl;
		cout << "�����������΢����ҳ" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			Myqq = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if (id == WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID())
		{
			cout << "������Ӵ˺���,�밴���������΢����ҳ" << endl;
			_getch();
			_getch();
			WeiChatMenu();
		}
	}

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == id)
		{
			flag = true;
			name = WeiChatList[i]->ReturnName();
			cout << "��������ɹ�����ȴ��Է�ȷ��" << endl;
		}
	}

	if (flag == false)
	{
		cout << "��΢�źŻ�û��ע�ᣬ���������������΢�ź�" << endl;
		cout << "1.��������΢�ź���Ӻ���" << endl;
		cout << "2.����΢����ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AddFriend();
			break;

		case 2:
			WeiChatMenu();
			break;

		default:
			cout << "�������,�����������΢����ҳ" << endl;
			_getch();
			WeiChatMenu();
			break;
		}

	}

	string mark = "&";
	string ID = mark + id;
	if (flag)
	{
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
			{
				Myqq = i;
			}
		}
		WeiChatList[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, ID));
		WeiChatList[Myqq]->ChangeFriendsNumber(WeiChatList[Myqq]->ReturnFriendNumber() + 1);
	}
	SaveFriends();


	//�����WeiChatList�ļ�����ӱ�WeiChatList
	fstream file;
	string friendfilename = "WeiChat\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "δ��ע";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();



	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::InvitePartyMember()
{
	system("CLS");
	int MyWeiChat;
	int ThisParty;
	ShowPartyNoReturn();
	cout << "��������Ҫ������ѽ���Ⱥ��" << endl;
	string inviteparty;
	cin >> inviteparty;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			MyWeiChat = i;
		}
	}

	bool CheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnPartyList()); i++)
		{
			if (WeiChatList[MyWeiChat]->ReturnPartyList()[i]->ReturnPartyID() == inviteparty)
			{
				CheckFlag = true;
				ThisParty = i;
				break;
			}
			else
			{
				cout << "��û�м����Ⱥ�����������������#����΢����ҳ" << endl;
				cin >> inviteparty;
				if (inviteparty == "#")
				{
					WeiChatMenu();
				}
				continue;
			}
		}
		if (CheckFlag == true)
		{
			break;
		}
	}

	ShowFriendsNoReturn();
	cout << "��������Ҫ����ĺ���΢�ź�" << endl;
	string invitefriend;
	cin >> invitefriend;

	CheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnFriendList()); i++)
		{
			if (WeiChatList[MyWeiChat]->ReturnFriendList()[i]->ReturnID() == invitefriend)
			{
				CheckFlag = true;
				break;
			}
			else
			{
				cout << "��û�д˺��ѣ����������������#����΢����ҳ" << endl;
				cin >> invitefriend;
				if (invitefriend == "#")
				{
					WeiChatMenu();
				}
				continue;
			}
		}
		if (CheckFlag == true)
		{
			break;
		}
	}

	CheckFlag = false;
	while (1)//���Ⱥ���Ƿ����г�Ա
	{
		for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()) ; i++)
		{
			if (WeiChatList[MyWeiChat]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()[i] == invitefriend)
			{
				cout << "�ú������ڸ�Ⱥ��,�������������΢�źŻ�����#����΢����ҳ" << endl;
				cin >> invitefriend;
				if (invitefriend == "#")
				{
					WeiChatMenu();
				}
				continue;
			}
			else
			{
				CheckFlag = true;
				break;
			}
		}
		if (CheckFlag == true)
		{
			break;
		}
	}


	
	
	fstream InvitePartyFile;
	string InvitePartyFileName = "WeiChat\\Parties\\" + inviteparty + "\\" + inviteparty + ".txt";
	InvitePartyFile.open(InvitePartyFileName, ios::app);
	InvitePartyFile << invitefriend;
	InvitePartyFile.close();

	fstream InviteFriendFile;
	string InviteFriendFileName = "WeiChat\\" + invitefriend + "\\" + invitefriend + "PartyList.txt";
	InviteFriendFile.open(InviteFriendFileName, ios::app);
	InviteFriendFile << inviteparty;
	InviteFriendFile.close();

	
	cout << "������ѽ�Ⱥ�ɹ�" << endl;
	cout << "�����������΢����ҳ" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ShowPartyInformationNoReturn(string partyId)
{
	string  QQPartyID;
	QQPartyID = partyId;
	if (QQPartyID == "#")
	{
		WeiChatMenu();
	}
	/*cout << "��������Ҫ��ѯ��Ϣ�ĳ�ԱQQ" << endl;
	string QQPartyMemberID;
	cin >> QQPartyMemberID;*/
	int Myqq;
	int ThisQQPartyID;
	int ThisQQ;
	string ThisQQID;

	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
			break;
		}
	}

	bool CheckFlag = false;
	while (1)
	{
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
			{
				CheckFlag = true;
				break;
			}

		}

		if (CheckFlag == true)
		{
			break;
		}
		else
		{
			cout << "��û�м����Ⱥ�����������������#����QQ���˵�" << endl;
			cin >> QQPartyID;
			continue;
		}
	}


	system("CLS");
	bool AdminFlag = false;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()); i++)
	{
		if (WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() == QQPartyID)
		{
			ThisQQPartyID = i;
			break;
		}
	}

	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()); i++)
	{
		int m = size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers());

		ThisQQID = WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()[i];//��Ⱥ�б��ȡȺ��ԱQQ
		for (int i = 0; i < size(WeiChatList); i++)
		{
			if (WeiChatList[i]->ReturnID() == ThisQQID)
			{
				ThisQQ = i;
				break;
			}
		}
		for (int i = 0; i < size(WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnAdminsID()); i++)
		{
			if (WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnAdminsID()[i] == ThisQQID)
			{
				AdminFlag = true;
				break;
			}
		}
		if (ThisQQID == WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnCreatUserID())
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:Ⱥ��" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
		else if (AdminFlag == true)
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:����Ա" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
			AdminFlag = false;
		}

		else
		{
			cout << "��" << i + 1 << "����Ա��Ϣ:" << endl;
			cout << "�ʺ�:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "����:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "Ⱥ��Ա����:��ͨ��Ա" << endl;
			cout << "���ڵ���:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "����ǩ��:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
	}

	cout << endl;
}