// Server.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "InitSock.h"
#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include<conio.h>
#include<windows.h>
CInitSock initSock; // 初始化Winsock库
using namespace std;


int main()
{
	// 创建套节字
	SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		printf("创建socket()失败 \n");
		return 0;
	}

	// 填充sockaddr_in结构
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(4567);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;

	// 绑定这个套节字到一个本地地址
	if (::bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("绑定IP地址失败bind() \n");
		return 0;
	}

	// 进入监听模式
	if (::listen(sListen, 2) == SOCKET_ERROR)
	{
		printf("Failed listen() \n");
		return 0;
	}

	// 循环接受客户的连接请求
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	SOCKET sClient = 0;
	char szText[] = " TCP Server Demo! \r\n";
	cout << "服务器创建成功" << endl;
	while (sClient == 0)
	{
		// 接受一个新连接
		sClient = ::accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);
		if (sClient == INVALID_SOCKET)
		{
			printf("接受失败accept()");
		}


		printf("欢迎登陆：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
		cout << "请发送消息:" << endl;
		continue;
	}

	while (TRUE)
	{
		// 向客户端发送数据
		gets_s(szText);
		::send(sClient, szText, strlen(szText), 0);
		cout << "请等待对方回复" << endl;
		// 从客户端接收数据
		char buff[256];
		int nRecv = ::recv(sClient, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf(" 接收到数据：%s\n", buff);
		}
		cout << "请回复对方:" << endl;
	}

	// 关闭同客户端的连接
	::closesocket(sClient);

	// 关闭监听套节字
	::closesocket(sListen);

	return 0;
    return 0;
}

