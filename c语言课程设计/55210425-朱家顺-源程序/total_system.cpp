#include "total_system.h"
#include"system_custom.h"
#include"system_purchase.h"
#include"system_date.h"
#include"system_stockmanagement.h"
#include"system_qiantai.h"
#include"total_system.h"
void showMenu() {
	printf("*********************************\n");
	printf("*****                       *****\n");
	printf("*****     1、库存管理       *****\n");
	printf("*****     2、前台收银       *****\n");
	printf("*****     3、客户系统       *****\n");
	printf("*****     4、钱流系统       *****\n");
	printf("*****     0、退出系统       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
	int i;
	scanf_s("%d", &i);
	if (i == 1)
	{
		menu_stockmanagement();
	}
	if (i == 2)
	{
		menu_shop();
	}
	if (i == 3)
	{
		showMenu_Member();
	}
	if (i == 4)
	{

	}
	if (i == 0)
	{
		exit(0);
	}
	if (i != 1 && i != 2 && i != 3 && i != 4 && i != 0)
	{
		printf("错误输入，请重新输入！");
		system("pause");
		system("cls");
		showMenu();
	}
}
