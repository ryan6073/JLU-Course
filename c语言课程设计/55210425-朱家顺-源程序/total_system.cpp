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
	printf("*****     1��������       *****\n");
	printf("*****     2��ǰ̨����       *****\n");
	printf("*****     3���ͻ�ϵͳ       *****\n");
	printf("*****     4��Ǯ��ϵͳ       *****\n");
	printf("*****     0���˳�ϵͳ       *****\n");
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
		printf("�������룬���������룡");
		system("pause");
		system("cls");
		showMenu();
	}
}
