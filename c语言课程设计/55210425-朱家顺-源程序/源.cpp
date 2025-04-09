#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"system_custom.h"
#include"system_purchase.h"
#include"system_date.h"
#include"system_stockmanagement.h"
#include"system_checkstand.h"
#include"system_money.h"
#include"entry.h"


int main() {
	system("color f1");
	struct goodsbuying* head1 = creat();

	int button;

	FILE* fp1;
	fp1 = fopen("goods.txt", "r");

	FILE* fp5;
	fp5 = fopen("goods1.txt", "r");

	Goods* head;
	head = read_goodsfile(fp1);

	Goods* head2;
	head2 = read_goodsfile(fp5);

	struct Member* abs;
	abs = Member_Book();

	Manager* ab;
	ab = Manager_Book();

	while(true) {
		menu_entry();
		scanf_s("%d", &button);
		char name[10]={0};
		char phone[15] = { 0 };
		char password[20] = { 0 };
		Manager* a;
		switch (button) {
		case 0:
			printf("欢迎下次使用\n");
			system("pause");
			return 0;
		case 1:
			system("pause&cls");
			printf("请输入您的名字：  ");
			scanf_s("%s", name, 10);
			printf("请输入您的密码：  ");
			scanf_s("%s", password, 20);
			a=isExist(ab,name,password);
			if (a != NULL && strcmp(a->m_identity, "boss") == 0) {
				printf("\n登录成功！请按回车以继续");
				system("pause&cls");
				boss( abs,  ab,  fp1,  fp5,  head1,  head,  head2);
				system("cls");
				break;
			}
			else {
				printf("用户名或密码错误，请再次尝试");
				system("pause&cls");
				break;
			}
		case 2:
			system("pause&cls");
			printf("请输入您的名字：  ");
			scanf_s("%s", name, 10);
			printf("请输入您的密码：  ");
			scanf_s("%s", password, 20);
		     a = isExist(ab, name, password);
			if (a != NULL && strcmp(a->m_identity, "cashier") == 0) {
				printf("\n登录成功！请按回车以继续");
				system("pause&cls");
				cashier(abs, ab, fp1, head1, head);
				system("cls");
				break;
			}
			else {
				printf("用户名或密码错误，请再次尝试");
				system("pause&cls");
				break;
			}
		default: 
			printf("输入有误，请重新输入：\n");
			system("pause&cls");
			break;
		}
	}
}