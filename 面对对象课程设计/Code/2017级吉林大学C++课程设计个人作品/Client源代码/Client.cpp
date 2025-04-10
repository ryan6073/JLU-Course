// Client.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Initsock.h"
#include <iostream>
CInitSock initSock; // 初始化Winsock库
using namespace std;

int main()
{
	// 创建套节字
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" 创建失败 socket() \n");
		return 0;
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
		printf(" 连接失败connect() \n");
		return 0;
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
			printf("接收到数据：%s\n", buff);
		}

		// 向服务器端发送数据
		cout << "请发送消息:" << endl;
		cin >> szText;
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "请等待对方回复" << endl;
	}

	// 关闭套节字
	::closesocket(s);
    return 0;
}

