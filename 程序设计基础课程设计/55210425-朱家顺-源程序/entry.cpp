
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


Manager* Manager_Book()
{
	struct Manager *pointer, * q, * headmember;
	pointer = (Manager*)malloc(sizeof( Manager));
	if (pointer == NULL) return NULL;
	pointer->next = NULL;
	FILE* fp;
	headmember = pointer;
	q = pointer;
	q->next = NULL;
	fp = fopen("员工信息.txt", "rb+");
	int w;
	fseek(fp, 0, 2);
	w = ftell(fp);
	fseek(fp, 0, 0);
	while (w != ftell(fp))
	{
		pointer = (Manager*)malloc(sizeof(Manager));
		if (pointer == NULL) return NULL;
		pointer->next = NULL;
		fscanf(fp, "%s  %s  %s\n", pointer->m_name, pointer->m_password,pointer->m_identity);
		q->next = pointer;  //把新节点挂到原尾节点之后
		q = q->next;  //q指针指向新的尾节点
	}
	q->next = NULL;//标志链表的结束 
	fclose(fp);
	return headmember;
}
void AddManager(Manager* headmember) {
	Manager* newmember = (Manager*)malloc(sizeof(Manager));
	if (newmember == NULL) return;
	newmember->next = NULL;
	char name[10] = { 0 };
	printf("请输入新建管理员姓名：\n");
	scanf_s("%s", name, 10);
	strcpy_s(newmember->m_name, name);
	
	printf("请输入新建管理员密码： \n");
	char password[20]={0};
	scanf_s("%s",password, 20);
	strcpy_s(newmember->m_password, password);

	printf("请输入新建管理员身份： \nboss或者cashier\n\n");
	char identity[10]={0};
	int v = 0;
	while (v == 0) {
        scanf_s("%s", identity, 10);
		if (strcmp(identity, "boss") == 0 || strcmp(identity, "cashier") == 0) {
			strcpy_s(newmember->m_identity, identity); v = 1;
		}
	    else {
		printf("输入错误，请重新输入：\nboss或者cashier\n\n");
	    }    
	}
	

	Manager* pmove = headmember;
	while (pmove->next) {
		pmove = pmove->next;
	}
	pmove->next = newmember;
	printf("添加成功\n");
	system("pause");
	system("cls");
}

void showManager(Manager* headmember) {
	if (headmember->next == NULL) {
		printf("当前记录为空\n");
	}
	else {
		Manager* pmove = headmember->next;
		while (pmove) {
			printf("姓名：%s  \t", pmove->m_name);
			printf("身份：%s  \n", pmove->m_identity);
			pmove = pmove->next;
		}
	}

	system("pause");
	system("cls");
}

Manager* isExist(Manager* headmember, char name[10],char password[20]) {
	Manager* pmove = headmember->next;
	if (strcmp(name, "initial") == 0) return NULL;
	while (pmove) {
		if (strcmp(pmove->m_name, name) == 0&& strcmp(pmove->m_password, password) == 0)  return pmove;
		pmove = pmove->next;
	}
	return NULL;
}

void deleteManager(Manager* headmember) {
	printf("请输入要删除的管理人姓名： \n");
	char name[10];
	scanf_s("%s", name, 10);
	printf("请输入要删除的管理人密码： \n");
	char password[20];
	scanf_s("%s", password, 20);
	Manager* ret = isExist(headmember, name,password);
	if (ret == NULL) printf("查无此人\n");
	else if (ret) {
		Manager* pre = headmember;
		while (pre->next != ret) pre = pre->next;
		pre->next = ret;
		pre->next = ret->next;
		free(ret);
		printf("删除成功\n");
	}
	system("pause");
	system("cls");
}

void modifyManager(Manager* headmember) {
	printf("请输入要修改的联系人姓名： \n");
	char name[10];
	scanf_s("%s", name, 10);
	printf("请输入要删除的管理人密码： \n");
	char password[20];
	scanf_s("%s", password, 20);
	Manager* ret = isExist(headmember, name,password);
	if (ret == NULL)printf("查无此人\n");
	else if (ret) {
		printf("姓名：%s \n", ret->m_name);
		printf("请输入更改后的姓名：    (不更改请输入-1并回车)\n");
		scanf_s("%s", name, 10);
		if (strcmp(name, "-1") > 0 || strcmp(name, "-1") < 0) strcpy_s(ret->m_name, name);
		
		printf("密码：%s \n", ret->m_password);
		printf("请输入更改后的密码：         （不更改请输入-1并回车）\n");
		char password[20]={0};
		scanf_s("%s", password, 20);
		if (strcmp(password, "-1") > 0 || strcmp(password, "-1") < 0) strcpy_s(ret->m_password, password);
	}
	system("pause");
	system("cls");

}

void saveManager(Manager* pmove)//保存数据
{
	FILE* fp;
	if ((fp = fopen("员工信息.txt", "wb")) == NULL)//打开文件，若没有此文件可以新建立
	{
		printf("不能打开此文件\n");//无法建立新文件
		exit(0);//正常运行程序并退出程序
	}
	while (pmove->next != NULL)
	{
		fprintf(fp, "%10s  %20s  %10s\n", pmove->next->m_name, pmove->next->m_password, pmove->next->m_identity);
		pmove = pmove->next;
	}
	fclose(fp);
}
void menu_entry() {
	printf("*********************************\n");
	printf("*****                       *****\n");
	printf("*****     1、老板登录       *****\n");
	printf("*****     2、员工登录       *****\n");
	printf("*****     0、退出系统       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
}
void showMenu_Manager() {
	printf("*******************************************\n");
	printf("*****                                 *****\n");
	printf("*****         1、添加员工             *****\n");
	printf("*****         2、展示员工             *****\n");
	printf("*****         3、删除员工             *****\n");
	printf("*****         4、修改员工             *****\n");
	printf("*****         0、保存并退出           *****\n");
	printf("*****                                 *****\n");
	printf("*******************************************\n");
}
void boss(struct Member* abs,Manager* ab,FILE* fp1,FILE* fp5 ,struct goodsbuying* head1,Goods* head,Goods* head2) {
here:
	int button, choice1;
	int i;


	while (true) {
		showMenu_boss();
		scanf_s("%d", &button);

		switch (button) {
		case 0:
			printf("欢迎下次使用\n");
			system("pause");
			return;
		case 1:
			system("pause");
			system("cls");
			button = 0;
			while (true) {
				menu_stockmanagement();
				printf_s("\n请选择您的需求：\n");
				scanf_s("%d", &choice1);

				system("cls");
				switch (choice1) {
				case 0:
					head = edit_name(head);
					write_goodsfile(head);
					printf("欢迎下次使用\n");
					system("pause");
					system("cls");
					goto here;
				case 1:goods_messageshow(head); break;
				case 2:goods_messagesearch(head); break;
				case 3:head = goods_in(head); break;
				case 4:head = goods_delete(head); break;
				case 5:head = goods_edit(head); break;
				case 6:remind_time(head); break;
				case 7:remind_stock(head); break;
				case 8:price_com(head2); break;
				default:printf_s("选择有误，请重新选择。\n"); break;
				}
			}
			system("pause");
			break;
		case 2:
			i = menu_shop(fp1, head1, abs, head);
			system("cls");
			if (i == 0)
				goto here;
			break;
		case 3:
			system("pause");
			system("cls");
			button = 0;
			while (true) {
				showMenu_Member();
				scanf_s("%d", &button);
				switch (button) {
				case 0:
					saveMember(abs);
					printf("========保存成功========\n");
					printf("欢迎下次使用\n");
					system("pause");
					system("cls");
					goto here;
				case 1:
					AddMember(abs);
					break;
				case 2:
					showMember(abs);
					break;
				case 3:
					deleteMember(abs);
					break;
				case 4:
					findMember(abs);
					break;
				case 5:
					modifyMember(abs);
					break;
				case 6: {
					printf("是否确认清空会员表： （重复输入6表示确认）\n");
					int a;
					scanf_s("%d", &a);
					if (a == 6)  cleanMember(abs);
					else {
						printf("您已成功取消\n");
						system("pause");
						system("cls");
					}
					break; }
				default:
					printf("你的输入有误，请重新输入\n");
					break;
				}
			}
			system("pause");
			break;
		case 4:
			int choice;
			system("cls");
			while (true) {
				menu_moneymanagement();
				printf("\n请选择您的的需求\n");
				scanf("%d", &choice);
				system("cls");
				switch (choice) {
				case 1:
					day_profit(head);
					break;
				case 2:
					search_day(head);
					break;
				case 3:
					month_profit(head);
					break;
				case 4:
					search_month(head);
					break;
				case 0:goto here;
				default:
					printf("你的输入有误，请重新输入\n");
					break;
				}
			}
			system("pause");
			break;
		case 5:
			system("pause");
			system("cls");
			button = 0;
			while (true) {
				showMenu_Manager();
				scanf_s("%d", &button);
				switch (button) {
				case 0:
					saveManager(ab);
					printf("========保存成功========\n");
					printf("欢迎下次使用\n");
					system("pause");
					system("cls");
					goto here;
				case 1:
					AddManager(ab);
					break;
				case 2:
					showManager(ab);
					break;
				case 3:
					deleteManager(ab);
					break;
				case 4:
					modifyManager(ab);
					break;
				default:
					printf("你的输入有误，请重新输入\n");
					break;
				}
			}
			system("pause");
			break;

		default:
			printf("请重新输入：");
		}
	}
	system("pause");
	return;
}
void cashier(struct Member* abs, Manager* ab, FILE* fp1, struct goodsbuying* head1, Goods* head) {
here:
	int i;
	while (true) {
			i = menu_shop(fp1, head1, abs, head);
			system("cls");
			if (i == 0)	break;
	}
	system("pause");
	return;
}

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
}
void showMenu_boss() {
	printf("*********************************\n");
	printf("*****                       *****\n");
	printf("*****     1、库存管理       *****\n");
	printf("*****     2、前台收银       *****\n");
	printf("*****     3、客户系统       *****\n");
	printf("*****     4、钱流系统       *****\n");
	printf("*****     5、员工管理       *****\n");
	printf("*****     0、退出系统       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
}

