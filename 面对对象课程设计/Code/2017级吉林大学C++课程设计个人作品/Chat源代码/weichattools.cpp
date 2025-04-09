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
	cout << "请选择你所需的功能" << endl;
	SetCursorPosition(15, 16);
	cout << "1.登陆微信" << endl;
	SetCursorPosition(15, 17);
	cout << "2.注册微信" << endl;
	SetCursorPosition(15, 18);
	cout << "3.查看已注册微信" << endl;
	SetCursorPosition(15, 19);
	cout << "4.返回上一级菜单" << endl;
	SetCursorPosition(15, 20);
	cout << "你的选择:" << endl;
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

	cout << "按任意键返回" << endl;
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
	cout << "输入你要登陆的微信:" << endl;
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
			cout << "没有该微信号，请重新输入或按#返回主菜单" << endl;
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
			/*cout << "按任意键返回" << endl;
			_getch();
			_getch();
			Menu();*/
		}
	}
	//if (flag != true)
	//{
	//	cout << "没有该WeiChatList号，请先申请" << endl;
	//	cout << "按任意键返回" << endl;
	//	_getch();
	//	Menu();
	//}
	cout << "请输入该微信的密码" << endl;
	cin >> PassWord;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() == PassWord)
		{
			LoginedWeiChat = ID;
			GetFriends();//获取好友
			GetParty();//获取群
			GetLinks();//获取绑定
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用微信" << endl;
			_getch();
			WeiChatMenu();
			break;
		}
		else if (WeiChatList[i]->ReturnID() == ID && WeiChatList[i]->ReturnPassWord() != PassWord)
		{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码,或输入#返回主菜单" << endl;
			cin >> PassWord;
			if (PassWord == "#")
			{
				Menu();
			}
			while (1)
			{
				if (WeiChatList[i]->ReturnPassWord() == PassWord)
				{
					cout << "登陆成功" << endl;
					cout << "按任意键开始使用WeiChatList" << endl;
					_getch();
					_getch();
					WeiChatMenu();
				}
				else
				{
					cout << "密码输入错误" << endl;
					cout << "请重新输入密码,或输入#返回主菜单" << endl;
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
			cout << "登陆成功" << endl;
			cout << "按任意键开始使用WeiChatList" << endl;
			_getch();
			_getch();
			WeiChatMenu();
			break;
			}
			else
			{
			cout << "密码输入错误" << endl;
			cout << "请重新输入密码" << endl;
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
		cout << "微信号:" << WeiChat[i]->ReturnID() << endl;
		cout << "微龄:" << WeiChat[i]->ReturnAge() << endl;
		cout << "微信密码:" << WeiChat[i]->ReturnPassWord() << endl;
		cout << "微信名称:" << WeiChat[i]->ReturnName() << endl;
		cout << "所在地区:" << WeiChat[i]->ReturnArea() << endl;
		cout << "个性签名:" << WeiChat[i]->ReturnAutograph() << endl;
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

	cout << "按任意键返回" << endl;
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
	cout << "欢迎使用微信" << endl;
	cout << "你的微信号为:" << LoginedWeiChat << endl;
	cout << "请选择使用的功能" << endl;
	cout << "1.好友功能" << endl;
	cout << "2.群功能" << endl;
	cout << "3.游戏功能" << endl;
	cout << "4.聊天功能" << endl;
	cout << "5.个人资料" << endl;
	cout << "6.绑定其他服务" << endl;
	cout << "0.返回主菜单" << endl;
	//cout << "1.进入聊天室聊天" << endl;
	//cout << "2.添加WeiChatList好友" << endl;
	//cout << "3,查看WeiChatList好友" << endl;
	//cout << "4.创建WeiChatList群" << endl;
	//cout << "5.加入WeiChatList群" << endl;
	//cout << "6.查看自己所有WeiChatList群" << endl;
	//cout << "7.管理WeiChatList群" << endl;
	//cout << "8.删除WeiChatList好友" << endl;
	//cout << "9.小游戏" << endl;
	//cout << "10.查看好友申请" << endl;
	//cout << "11.添加群管理员" << endl;
	//cout << "0.返回主菜单" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		/*Client();*/
		cout << "请选择使用的好友功能" << endl;
		cout << "1.添加好友" << endl;
		cout << "2.显示所有好友" << endl;
		cout << "3.删除好友" << endl;
		cout << "4.查看好友申请" << endl;
		cout << "5.查看好友资料" << endl;
		cout << "6.修改好友备注" << endl;
		cout << "7.查看QQ共同好友" << endl;
		cout << "8.添加QQ共同好友" << endl;
		cout << "0.返回微信主菜单" << endl;
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

		cout << "请选择使用的群功能" << endl;
		/*cout << "1.加入微信群" << endl;*/
		cout << "1.退出微信群" << endl;
		cout << "2.创建微信群" << endl;
		cout << "3.查看已加入的微信群" << endl;
		/*cout << "5.查看入群申请" << endl;*/
		/*cout << "6.添加WeiChatList群管理员" << endl;*/
		cout << "4.踢出群成员" << endl;
		cout << "5.查看群成员信息" << endl;
		cout << "6.邀请好友进群" << endl;
		cout << "0.返回主菜单" << endl;
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
		cout << "请选择玩的游戏" << endl;
		cout << "1.贪吃蛇" << endl;
		cout << "0.返回微信主菜单" << endl;
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
		cout << "请选择使用的聊天功能" << endl;
		cout << "1.进入聊天室" << endl;
		cout << "0.返回微信主菜单" << endl;
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
		cout << "请选择所需的资料功能" << endl;
		cout << "1.查看个人资料" << endl;
		cout << "2.修改密码" << endl;
		cout << "3.修改名称" << endl;
		cout << "4.修改签名" << endl;
		cout << "5.修改所在地" << endl;
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
		cout << "请选择所需功能:" << endl;
		cout << "1.绑定QQ" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			LinkQQ();
			break;
		default:
			cout << "选择错误，按任意键返回WeiChatList主菜单" << endl;
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
	cout << "请输入添加好友的微信号" << endl;
	cin >> id;

	if (id == LoginedWeiChat)
	{
		cout << "你不能添加自己为好友" << endl;
		cout << "按任意键返回微信主页" << endl;
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
			cout << "你已添加此好友,请按任意键返回微信主页" << endl;
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
			cout << "好友申请成功，请等待对方确认" << endl;
		}
	}

	if (flag == false)
	{
		cout << "该微信号还没有注册，按任意键重新输入微信号" << endl;
		cout << "1.重新输入微信号添加好友" << endl;
		cout << "2.返回微信主页" << endl;
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
			cout << "输入错误,按任意键返回微信主页" << endl;
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


	//向好友WeiChatList文件中添加本WeiChatList
	fstream file;
	string friendfilename = "WeiChat\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "未备注";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();

	cout << "按任意键返回微信主页" << endl;
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
		file.open(filename, ios::trunc | ios::out);//清空文件内容
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
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//判断添加好友标记
		{
			friendsnum--;
		}
	}

	cout << "你有" << friendsnum << "个好友" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "第" << friends + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}

	cout << "按任意键返回WeiChatList主页" << endl;
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
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//判断添加好友标记
		{
			friendsnum--;
		}
	}

	cout << "你有" << friendsnum << "个好友" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "第" << friends + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}
}

void WeiChatToolsBase_CHC::CreatParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i<1000000; i++) //加强WeiChatList群号生成随机性
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p, temp, 10);
	string ID;
	/*cin >> ID;*/
	ID = string(temp);
	cout << "你的群号为:" << ID << endl;
	WeiChatparty = ID;
	cout << "请输入群名称" << endl;
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


	//每个WeiChatList都有自己的群列表
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
	cout << "按任意键返回微信主页" << endl;
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
	file << "★" << endl;
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



	//获取群成员
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


		//BUG修复
		QQPartyMemberFileContent.clear();
		QQPartyMemberFileContent.shrink_to_fit();
		QQPartyMemberFile.close();
	}




	//获取群管理员WeiChatList
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

	//显示所有好友
	int Myqq;
	for (int i = 0; i < size(WeiChatList); i++)
	{
		if (WeiChatList[i]->ReturnID() == LoginedWeiChat)
		{
			Myqq = i;
		}
	}
	cout << "你有" << WeiChatList[Myqq]->ReturnFriendNumber() << "个好友" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnFriendNumber(); i++)
	{
		cout << "第" << i + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "微信号:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}


	//删除本WeiChatList中的好友
	string qq;
	cout << "请输入想删除好友的微信号" << endl;
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
		cout << "你没有此好友" << endl;
		cout << "1.重新输入微信号" << endl;
		cout << "2.返回微信主页" << endl;
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
			WeiChatList[Myqq]->ReturnFriendList().resize(num - 1);//重新设置好友容器大小
			WeiChatList[Myqq]->ChangeFriendsNumber(num - 1);
		}
	}

	/*SaveFriends();*/
	//删除本WeiChatList中的好友WeiChatList
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
	int m = content1.find(qq);//找到好友WeiChatList文件中本WeiChatList的位置
	for (int i = m; i < (m + word); i++)
	{
		content1.erase(content1.begin() + m);//删除
	}
	myqqfile.close();
	myqqfile.open(myqqfilename, ios::trunc | ios::out);
	myqqfile << content1;
	myqqfile.close();



	//删除好友WeiChatList文件中的本WeiChatList
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
			//if (temp[i] < 0 || temp[i] > 127)//中文字符占两个字节
			//{
			//	words++;
			//}
		}
		content.push_back('\n');
		words++;
	}

	m = content.find(LoginedWeiChat);//找到好友WeiChatList文件中本WeiChatList的位置
	for (int i = m; i < (m + words); i++)
	{
		content.erase(content.begin() + m);//删除
	}
	outfile.close();

	outfile.open(friendqqfilename, ios::trunc | ios::out);
	outfile << content;
	outfile.close();

	cout << "删除好友成功" << endl;
	cout << "按任意键返回微信主页" << endl;
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
	while (myqqfile.get(c))//获取申请人WeiChat
	{
		if (c == '^')
		{
			line++;
			flag = true;
			continue;
		}

		if (line == 1) //获取申请加好友的人WeiChat号
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
		cout << "没有好友申请" << endl;
		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	myqqfile.close();
	fdqq = temp;
	/*string myqqfilename = "WeiChat\\" + LoginedWeiChat + "\\" + LoginedWeiChat + "Friendlist.txt";*/
	friendqqfilename = "WeiChat\\" + fdqq + "\\" + fdqq + "Friendlist.txt";

	//temp.pop_back();
	cout << "你是否同意" << temp << "的好友申请?" << endl;
	cout << "1.同意" << endl;
	cout << "2.拒绝" << endl;

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
			//	content.push_back(msg[i]);//读取文件内容
			//}


			//content.push_back('\n');

		}
		myaceptcontent.pop_back();
		/*content.pop_back();
		content.shrink_to_fit();*/


		//for (int i = 0; i < size(content); i++)//将未加入标记删除
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

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容

															/*myqqfile << content;*/
		for (int i = 0; i < size(myaceptcontent); i++)
		{
			myqqfile << myaceptcontent[i] << endl;
		}

		/*cout << "确认申请成功" << endl;*/

		myqqfile.close();





		friendqqfile.open(friendqqfilename);

		while (!friendqqfile.eof())//获取好友文件内容
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

		//for (int i = 0; i < size(contentfriend); i++)//删除好友文件中的标记
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

		friendqqfile.open(friendqqfilename, ios::out | ios::trunc);//清空好友文件内容
																   //friendqqfile << contentfriend;//重新写入删除标记后的好友文件内容
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
		cout << "确认申请成功" << endl;
		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "你已拒绝该请求" << endl;

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
			//	content.push_back(msg[i]);//读取文件内容
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
		//			content.erase(content.begin() + n); //删除申请人WeiChat


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

		myqqfile.open(myqqfilename, ios::out | ios::trunc); //清空原有文件内容
															/*myqqfile << content;*/

		for (int i = 0; i < size(myqqfilecontent); i++)
		{
			myqqfile << myqqfilecontent[i] << endl;
		}
		myqqfile.close();





		//删除好友文件中的WeiChat
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
			//	contentfriend.push_back(msgfriend[i]);//读取文件内容
			//}

			//contentfriend.push_back('\n');
		}
		friendfilecontent.pop_back();
		friendqqfile.close();
		/*contentfriend.pop_back();
		contentfriend.shrink_to_fit();
		friendqqfile.close();*/

		//for (int i = 0; i < size(contentfriend); i++) //删除好友文件中的本WeiChat
		//{
		//	if (contentfriend[i] == '&')
		//	{

		//		n = i;

		//		while (1)
		//		{
		//			contentfriend.erase(contentfriend.begin() + n); //删除申请人WeiChat

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

		friendqqfile.open(friendqqfilename, ios::out, ios::trunc);//清空原有内容
																  /*friendqqfile << contentfriend;*/

		for (int i = 0; i < size(friendfilecontent); i++)
		{
			friendqqfile << friendfilecontent[i] << endl;
		}
		friendqqfile.close();





		cout << "按任意键返回WeiChat主页" << endl;
		_getch();
		WeiChatMenu();
		break;
	}
}

void WeiChatToolsBase_CHC::ShowFriendInformation()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "请输入你想查询的好友WeiChatList号，或输入#返回WeiChatList主菜单" << endl;
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
			cout << "你没有此好友，请重新输入或输入#返回WeiChatList主菜单" << endl;
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

	cout << "以下为此好友信息" << endl;
	cout << "帐号:" << WeiChatList[friendid]->ReturnID() << endl;
	cout << "姓名:" << WeiChatList[friendid]->ReturnName() << endl;
	cout << "备注:" << WeiChatList[Myqq]->ReturnFriendList()[friendremarks]->ReturnRemarks() << endl;
	cout << "个性签名:" << WeiChatList[friendid]->ReturnAutograph() << endl;
	cout << "所在地区:" << WeiChatList[friendid]->ReturnArea() << endl;

	cout << endl;

	cout << "按任意键返回WeiChatList主菜单" << endl;
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
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')//判断添加好友标记
		{
			friendsnum--;
		}
	}

	cout << "你有" << friendsnum << "个好友" << endl;
	int friends = 0;
	for (int i = 0; i < size(WeiChatList[Myqq]->ReturnFriendList()); i++)
	{
		if ((WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '&' || (WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID()[0]) == '^')
		{
			continue;
		}
		cout << "第" << friends + 1 << "位好友" << endl;
		cout << "姓名:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "WeiChatList:" << WeiChatList[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
		friends++;
	}
}

void WeiChatToolsBase_CHC::ChangeFriendRemarks()
{
	system("CLS");
	ShowFriendNoReturn();
	cout << "请输入你想查询的好友WeiChatList号，或输入#返回WeiChatList主菜单" << endl;
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
			cout << "你没有此好友，请重新输入或输入#返回WeiChatList主菜单" << endl;
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



	cout << "请输入你想修改的备注" << endl;
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

	cout << "修改备注成功" << endl;
	cout << "按任意键返回WeiChatList主菜单" << endl;
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
	cout << "你共有" << WeiChatList[Myqq]->ReturnPartyNumber() << "个群" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "第" << i + 1 << "个群" << endl;
		cout << "群号:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "群名称:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "群主:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "按任意键返回WeiChatList主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::AgreeMember()
{
	system("CLS");
	ShowPartyNoReturn();
	cout << "请输入要管理的群号" << endl;
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
		cout << "没有此群,请重新输入或返回微信主页" << endl;
		cout << "1.重新输入" << endl;
		cout << "2.返回WeiChatList主页" << endl;
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
		if (line == 2) //获取群主WeiChatList号
		{
			temp.push_back(c);
		}

	}
	string OwnerQQ = temp;

	/*temp.pop_back(); *///删除末尾\n


						 //获取群管理员WeiChatList
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
		cout << "群主你好，欢迎查看入群申请" << endl;

	}
	else if (Adminflag == true)
	{
		cout << "管理员你好，欢迎查看入群申请" << endl;
	}
	else
	{
		cout << "你不是该群的群主或管理员,无法管理该群" << endl;
		cout << "按任意键返回WeiChatList主页" << endl;
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
		//if (line == 1) //获取申请入群的人WeiChatList号
		//{
		//	temp.push_back(c);
		//	//temp.clear();//清除■
		//	line++;
		//}
		if (line == 1)
		{
			temp.push_back(c);
		}

	}

	if (flag == false)
	{
		cout << "没有加群申请" << endl;
		cout << "按任意键返回WeiChatList主页" << endl;
		_getch();
		WeiChatMenu();
	}
	//}
	outfile.close();
	temp.pop_back();
	cout << "你是否同意" << temp << "入群?" << endl;
	cout << "1.同意" << endl;
	cout << "2.拒绝" << endl;
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
				msg.push_back(ch[i]);//读取文件内容
			}


			msg.push_back('\n');

		}



		for (int i = 0; i < size(msg); i++)//将未加入标记删除
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

		outfile.open(filename, ios::out, ios::trunc); //清空原有文件内容

		outfile << msg;

		cout << "确认申请成功" << endl;

		outfile.close();

		outfile.open(filename1, ios::app);

		outfile << id << endl;

		cout << "按任意键返回WeiChatList主页" << endl;
		_getch();
		WeiChatMenu();

		break;


	default:

		cout << "你已拒绝该请求" << endl;
		outfile.open(filename);

		while (!outfile.eof())
		{

			char ch[1000];

			outfile.getline(ch, 1000);
			for (int i = 0; i < strlen(ch); i++)
			{
				msg.push_back(ch[i]);//读取文件内容
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
					msg.erase(msg.begin() + n); //删除申请人WeiChatList


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

		outfile.open(filename, ios::out, ios::trunc);//清空原有内容

		outfile << msg;

		outfile.close();

		cout << "按任意键返回WeiChatList主页" << endl;
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
	cout << "你共有" << WeiChatList[Myqq]->ReturnPartyNumber() << "个群" << endl;
	for (int i = 0; i < WeiChatList[Myqq]->ReturnPartyNumber(); i++)
	{
		cout << "第" << i + 1 << "个群" << endl;
		cout << "群号:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "群名称:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "群主:" << WeiChatList[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	
}

void WeiChatToolsBase_CHC::AddPartyMember()
{
	system("CLS");
	cout << "请输入你想加入的群" << endl;
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
			cout << "你已添加此群" << endl;
			cout << "按任意键返回QQ主页" << endl;
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
		cout << "没有此群，按任意键返回微信主页" << endl;
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
	cout << "申请入群成功,请等待群主同意" << endl;
	cout << "按任意键返回WeiChatList主页" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::QuitParty()
{
	bool flag = false;
	int Myqq, select;
	string partyid;
	cout << "请输入你想退出的微信群" << endl;
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
		cout << "你没有加入此群" << endl;
		cout << "请选择重新输入或返回微信主菜单" << endl;
		cout << "1.重新输入微信群" << endl;
		cout << "2.返回微信主菜单" << endl;
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


	//向本WeiChatList群列表中删除该群
	fstream myqqpartylistfile;
	string temp;//读取文件每行内容
	string content;//保存文件所有内容
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
	content.pop_back();//删除多余\n
	myqqpartylistfile.close();

	myqqpartylistfile.open(myqqpartylistfilename, ios::out | ios::trunc);
	myqqpartylistfile << content;
	myqqpartylistfile.close();



	//从本群列表中删除此WeiChatList
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
	partycontent.pop_back();//删除末尾\n
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
		cout << "退出群" << partyid << "成功" << endl;
		cout << "按任意键返回WeiChatList主菜单" << endl;
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


	cout << "退出群" << partyid << "成功" << endl;
	cout << "按任意键返回WeiChatList主菜单" << endl;

	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::DeletePartyMember()
{
	system("CLS");
	ShowPartyNoReturn();
	cout << "请输入要管理的群号" << endl;
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
		cout << "没有此群,请重新输入或返回WeiChatList主页" << endl;
		cout << "1.重新输入" << endl;
		cout << "2.返回WeiChatList主页" << endl;
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



	//获取群主WeiChatList
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
		if (line == 2) //获取群主WeiChatList号
		{
			temp.push_back(c);
		}

	}
	/*temp.pop_back(); *///删除末尾\n
	PartyOwner = temp;//群主WeiChatList


					  //获取群管理员WeiChatList
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



	//判断是否是管理员或群主
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
		cout << "群主你好，欢迎来到群成员管理" << endl;
		/*cout << "你不是该群的群主或管理员,无法管理该群" << endl;
		cout << "按任意键返回WeiChatList主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();*/
	}
	else if (Adminflag == true)
	{
		cout << "管理员你好，欢迎来到群成员管理" << endl;
	}
	else
	{
		cout << "你不是该群的群主或管理员,无法管理该群" << endl;
		cout << "按任意键返回WeiChatList主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	outfile.close();
	temp.clear();




	//获取群成员
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
		cout << "你为此群群主可以踢出除你外的任何人" << endl;
		Ownerflag = true;
	}
	else
	{
		cout << "你为此群管理员，可以踢出除群主和管理员以外的人" << endl;
		Adminflag = true;
	}


	ShowPartyInformationNoReturn(id);
	cout << "请输入要踢出的成员微信号" << endl;
	string DeleteMemberQQ;
	cin >> DeleteMemberQQ;


	//检查输入WeiChatList是否是群主或是自己
	bool checkflag = false;//检查是否有此成员
						   /*if (DeleteMemberQQ == PartyOwner|| DeleteMemberQQ == LoginedWeiChat)
						   {*/
						   /*cout << "无法踢出群主或自己，请重新输入" << endl;
						   cin >> DeleteMemberQQ;*/
	while (1)
	{
		if (DeleteMemberQQ == PartyOwner || DeleteMemberQQ == LoginedWeiChat)
		{
			cout << "无法踢出群主或自己，请重新输入" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

		for (int i = 0; i < size(PartyMember); i++)//检查是否有此成员
		{
			if (DeleteMemberQQ == PartyMember[i])
			{
				checkflag = true;
				break;
			}
		}

		if (checkflag == false)
		{
			cout << "没有此成员请重新输入" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

		if (Adminflag == true)//如果本账号是管理员则检查踢出成员是否是管理员
		{
			for (int i = 0; i < size(AdminQQ); i++)
			{
				if (AdminQQ[i] == DeleteMemberQQ)
				{
					cout << "管理员不能踢出其他管理员,请重新输入" << endl;
					cin >> DeleteMemberQQ;
					continue;
				}
			}
		}


		//检查是否是群主或自己
		if (DeleteMemberQQ != PartyOwner && DeleteMemberQQ != LoginedWeiChat)
		{
			break;
		}
		else
		{
			cout << "无法踢出群主或自己，请重新输入" << endl;
			cin >> DeleteMemberQQ;
			continue;
		}

	}
	/*}*/



	//从该成员群列表中删除此群
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



	//从本群成员列表中删除此成员
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



	//如果该成员是管理员则从管理员列表中删除该WeiChatList
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

			cout << "踢出" << DeleteMemberQQ << "成功" << endl;
			cout << "按任意键返回WeiChatList主菜单" << endl;
			_getch();
			_getch();
			WeiChatMenu();

		}

		else
		{
			cout << "踢出" << DeleteMemberQQ << "成功" << endl;
			cout << "按任意键返回WeiChatList主菜单" << endl;
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

	cout << "请输入你要查询成员信息的WeiChatList群,或输入#返回WeiChatList主菜单" << endl;
	string  QQPartyID;
	cin >> QQPartyID;
	if (QQPartyID == "#")
	{
		WeiChatMenu();
	}
	/*cout << "请输入你要查询信息的成员WeiChatList" << endl;
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
			cout << "你没有加入此群，请重新输入或输入#返回WeiChatList主菜单" << endl;
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

		ThisQQID = WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()[i];//从群列表获取群成员WeiChatList
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
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:群主" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
		else if (AdminFlag == true)
		{
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:管理员" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
			AdminFlag = false;
		}

		else
		{
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:普通成员" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
	}

	cout << endl;
	cout << "按任意键返回WeiChatList主菜单" << endl;
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
	cout << "以下为你的个人信息:" << endl;
	cout << "帐号:" << WeiChatList[Myqq]->ReturnID() << endl;
	cout << "密码:" << WeiChatList[Myqq]->ReturnPassWord() << endl;
	cout << "姓名:" << WeiChatList[Myqq]->ReturnName() << endl;
	cout << "地区:" << WeiChatList[Myqq]->ReturnArea() << endl;
	cout << "注册日期:" << WeiChatList[Myqq]->ReturnAge() << endl;
	cout << "个性签名:" << WeiChatList[Myqq]->ReturnAutograph() << endl;
	cout << endl;
	cout << "按任意键返回微信主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangePassWord()
{
	system("CLS");
	cout << "输入你的新密码" << endl;
	string pw;
	string pwagin;
	cin >> pw;
	cout << "再次确认你的新密码" << endl;
	cin >> pwagin;
	while (1)
	{
		if (pw != pwagin)
		{
			cout << "两次密码不符，请重新输入" << endl;
			cin >> pw;
			cout << "再次确认你的新密码" << endl;
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

	cout << "修改密码成功" << endl;
	cout << "按任意键返回QQ主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeName()
{
	system("CLS");
	string newname;
	cout << "输入你的新名字" << endl;
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

	cout << "修改名称成功" << endl;
	cout << "按任意键返回QQ主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeAutoGraph()
{
	system("CLS");
	string autograph;
	cout << "输入你的新签名" << endl;
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
	cout << "修改个新签名成功" << endl;
	SaveChange();

	cout << "按任意键返回QQ主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::ChangeArea()
{
	system("CLS");
	string Area;
	cout << "输入你的地区" << endl;
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

	cout << "按任意键返回QQ主菜单" << endl;
	_getch();
	_getch();
	WeiChatMenu();
}

void WeiChatToolsBase_CHC::PlayGame()
{
	GameReturnFlag = 2;
	Controller c;//声明一个Controller类

	c.Game();//整个游戏循环

	_getch();
}

void WeiChatToolsBase_CHC::Client()
{
	system("CLS");
	// 创建套节字
	cout << "按#键返回QQ主页" << endl;
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" 创建失败 socket() \n");
		exit(0);
	}

	// 也可以在这里调用bind函数绑定一个本地地址
	// 否则系统将会自动安排

	// 填写远程地址信息
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// 注意，这里要填写服务器程序（TCPServer程序）所在机器的IP地址
	// 如果你的计算机没有联网，直接使用127.0.0.1即可
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" 连接聊天服务器失败connect() \n");
		cout << "按任意键返回QQ主页" << endl;
		_getch();
		WeiChatMenu();
	}

	char buff[256];
	char szText[256];
	cout << "登陆服务器成功" << endl;
	while (TRUE)
	{
		//从服务器端接收数据
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("来自对方的消息：%s\n", buff);
		}

		// 向服务器端发送数据
		cout << "请发送消息:" << endl;
		cin >> szText;
		if (szText[0] == '#')
		{
			WeiChatMenu();
		}
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "请等待对方回复" << endl;
	}

	// 关闭套节字
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
		cout << "你已经绑定QQ"<< WeiChatList[ThisWeiChat]->ReturnLinkedQQ() <<endl<<"按任意键返回微信主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}
	cout << "请输入你要绑定的QQ号" << endl;
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
			cout << "没有此QQ，请重新输入或输入#返回微信主页" << endl;
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

	cout << "请输入此QQ号的密码" << endl;
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
			cout << "密码输入错误，请重新输入或输入#返回微信主页" << endl;
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

	QQLinkFile << "微信:" + LoginedWeiChat;
	QQLinkFile.close();
	QQTools.ReturnQQ()[ThisQQ]->ChangeLinkedWeiChat(LoginedWeiChat);

	cout << "绑定QQ成功" << endl;
	cout << "按任意键返回微信主页" << endl;
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
		cout << "你没有绑定QQ，请先绑定QQ" << endl;
		cout << "按任意键返回微信主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	cout << "你绑定的QQ号为" << WeiChatList[MyWeiChat]->ReturnLinkedQQ() << endl;
	cout << "你和此QQ的共同好友有如下" << endl;

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
				//QQ列表中找到此好友
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
					cout << "第" << CommonFriendNumber << "个共同好友" << endl;
					cout << "微信号:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnID();
					cout << "姓名:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnFriendName();
					cout << "备注:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnRemarks();
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

	cout << "按任意键返回微信主页" << endl;
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
		cout << "你没有绑定QQ，请先绑定QQ" << endl;
		cout << "按任意键返回微信主页" << endl;
		_getch();
		_getch();
		WeiChatMenu();
	}

	cout << "你绑定的QQ号为" << WeiChatList[MyWeiChat]->ReturnLinkedQQ() << endl;
	cout << "你和此QQ的共同好友有如下" << endl;

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
			//QQ列表中找到此好友
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
				cout << "第" << CommonFriendNumber << "个共同好友" << endl;
				cout << "微信号:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnID();
				cout << "姓名:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnFriendName();
				cout << "备注:" << WeiChatList[MyWeiChat]->ReturnFriendList()[j]->ReturnRemarks();
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
	cout << "请输入添加QQ共同好友的微信号" << endl;
	cin >> id;

	if (id == LoginedWeiChat)
	{
		cout << "你不能添加自己为好友" << endl;
		cout << "按任意键返回微信主页" << endl;
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
			cout << "你已添加此好友,请按任意键返回微信主页" << endl;
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
			cout << "好友申请成功，请等待对方确认" << endl;
		}
	}

	if (flag == false)
	{
		cout << "该微信号还没有注册，按任意键重新输入微信号" << endl;
		cout << "1.重新输入微信号添加好友" << endl;
		cout << "2.返回微信主页" << endl;
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
			cout << "输入错误,按任意键返回微信主页" << endl;
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


	//向好友WeiChatList文件中添加本WeiChatList
	fstream file;
	string friendfilename = "WeiChat\\" + id + "\\" + id + "Friendlist.txt";
	string remarks = "未备注";
	file.open(friendfilename, ios::app);
	file << "^" << WeiChatList[Myqq]->ReturnID() << endl;
	file << WeiChatList[Myqq]->ReturnName() << endl;
	file << remarks << endl;
	file << " " << endl;
	file.close();



	cout << "按任意键返回微信主页" << endl;
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
	cout << "请输入你要邀请好友进的群号" << endl;
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
				cout << "你没有加入此群，请重新输入或输入#返回微信主页" << endl;
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
	cout << "请输入你要邀请的好友微信号" << endl;
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
				cout << "你没有此好友，请重新输入或输入#返回微信主页" << endl;
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
	while (1)//检测群中是否已有成员
	{
		for (int i = 0; i < size(WeiChatList[MyWeiChat]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()) ; i++)
		{
			if (WeiChatList[MyWeiChat]->ReturnPartyList()[ThisParty]->ReturnPartyMembers()[i] == invitefriend)
			{
				cout << "该好友已在该群中,请重新输入好友微信号或输入#返回微信主页" << endl;
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

	
	cout << "邀请好友进群成功" << endl;
	cout << "按任意键返回微信主页" << endl;
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
	/*cout << "请输入你要查询信息的成员QQ" << endl;
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
			cout << "你没有加入此群，请重新输入或输入#返回QQ主菜单" << endl;
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

		ThisQQID = WeiChatList[Myqq]->ReturnPartyList()[ThisQQPartyID]->ReturnPartyMembers()[i];//从群列表获取群成员QQ
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
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:群主" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
		else if (AdminFlag == true)
		{
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:管理员" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
			AdminFlag = false;
		}

		else
		{
			cout << "第" << i + 1 << "个成员信息:" << endl;
			cout << "帐号:" << WeiChatList[ThisQQ]->ReturnID() << endl;
			cout << "姓名:" << WeiChatList[ThisQQ]->ReturnName() << endl;
			cout << "群成员属性:普通成员" << endl;
			cout << "所在地区:" << WeiChatList[ThisQQ]->ReturnArea() << endl;
			cout << "个性签名:" << WeiChatList[ThisQQ]->ReturnAutograph() << endl;
			cout << endl;
		}
	}

	cout << endl;
}