
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
	fp = fopen("Ա����Ϣ.txt", "rb+");
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
		q->next = pointer;  //���½ڵ�ҵ�ԭβ�ڵ�֮��
		q = q->next;  //qָ��ָ���µ�β�ڵ�
	}
	q->next = NULL;//��־����Ľ��� 
	fclose(fp);
	return headmember;
}
void AddManager(Manager* headmember) {
	Manager* newmember = (Manager*)malloc(sizeof(Manager));
	if (newmember == NULL) return;
	newmember->next = NULL;
	char name[10] = { 0 };
	printf("�������½�����Ա������\n");
	scanf_s("%s", name, 10);
	strcpy_s(newmember->m_name, name);
	
	printf("�������½�����Ա���룺 \n");
	char password[20]={0};
	scanf_s("%s",password, 20);
	strcpy_s(newmember->m_password, password);

	printf("�������½�����Ա��ݣ� \nboss����cashier\n\n");
	char identity[10]={0};
	int v = 0;
	while (v == 0) {
        scanf_s("%s", identity, 10);
		if (strcmp(identity, "boss") == 0 || strcmp(identity, "cashier") == 0) {
			strcpy_s(newmember->m_identity, identity); v = 1;
		}
	    else {
		printf("����������������룺\nboss����cashier\n\n");
	    }    
	}
	

	Manager* pmove = headmember;
	while (pmove->next) {
		pmove = pmove->next;
	}
	pmove->next = newmember;
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}

void showManager(Manager* headmember) {
	if (headmember->next == NULL) {
		printf("��ǰ��¼Ϊ��\n");
	}
	else {
		Manager* pmove = headmember->next;
		while (pmove) {
			printf("������%s  \t", pmove->m_name);
			printf("��ݣ�%s  \n", pmove->m_identity);
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
	printf("������Ҫɾ���Ĺ����������� \n");
	char name[10];
	scanf_s("%s", name, 10);
	printf("������Ҫɾ���Ĺ��������룺 \n");
	char password[20];
	scanf_s("%s", password, 20);
	Manager* ret = isExist(headmember, name,password);
	if (ret == NULL) printf("���޴���\n");
	else if (ret) {
		Manager* pre = headmember;
		while (pre->next != ret) pre = pre->next;
		pre->next = ret;
		pre->next = ret->next;
		free(ret);
		printf("ɾ���ɹ�\n");
	}
	system("pause");
	system("cls");
}

void modifyManager(Manager* headmember) {
	printf("������Ҫ�޸ĵ���ϵ�������� \n");
	char name[10];
	scanf_s("%s", name, 10);
	printf("������Ҫɾ���Ĺ��������룺 \n");
	char password[20];
	scanf_s("%s", password, 20);
	Manager* ret = isExist(headmember, name,password);
	if (ret == NULL)printf("���޴���\n");
	else if (ret) {
		printf("������%s \n", ret->m_name);
		printf("��������ĺ��������    (������������-1���س�)\n");
		scanf_s("%s", name, 10);
		if (strcmp(name, "-1") > 0 || strcmp(name, "-1") < 0) strcpy_s(ret->m_name, name);
		
		printf("���룺%s \n", ret->m_password);
		printf("��������ĺ�����룺         ��������������-1���س���\n");
		char password[20]={0};
		scanf_s("%s", password, 20);
		if (strcmp(password, "-1") > 0 || strcmp(password, "-1") < 0) strcpy_s(ret->m_password, password);
	}
	system("pause");
	system("cls");

}

void saveManager(Manager* pmove)//��������
{
	FILE* fp;
	if ((fp = fopen("Ա����Ϣ.txt", "wb")) == NULL)//���ļ�����û�д��ļ������½���
	{
		printf("���ܴ򿪴��ļ�\n");//�޷��������ļ�
		exit(0);//�������г����˳�����
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
	printf("*****     1���ϰ��¼       *****\n");
	printf("*****     2��Ա����¼       *****\n");
	printf("*****     0���˳�ϵͳ       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
}
void showMenu_Manager() {
	printf("*******************************************\n");
	printf("*****                                 *****\n");
	printf("*****         1�����Ա��             *****\n");
	printf("*****         2��չʾԱ��             *****\n");
	printf("*****         3��ɾ��Ա��             *****\n");
	printf("*****         4���޸�Ա��             *****\n");
	printf("*****         0�����沢�˳�           *****\n");
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
			printf("��ӭ�´�ʹ��\n");
			system("pause");
			return;
		case 1:
			system("pause");
			system("cls");
			button = 0;
			while (true) {
				menu_stockmanagement();
				printf_s("\n��ѡ����������\n");
				scanf_s("%d", &choice1);

				system("cls");
				switch (choice1) {
				case 0:
					head = edit_name(head);
					write_goodsfile(head);
					printf("��ӭ�´�ʹ��\n");
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
				default:printf_s("ѡ������������ѡ��\n"); break;
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
					printf("========����ɹ�========\n");
					printf("��ӭ�´�ʹ��\n");
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
					printf("�Ƿ�ȷ����ջ�Ա�� ���ظ�����6��ʾȷ�ϣ�\n");
					int a;
					scanf_s("%d", &a);
					if (a == 6)  cleanMember(abs);
					else {
						printf("���ѳɹ�ȡ��\n");
						system("pause");
						system("cls");
					}
					break; }
				default:
					printf("���������������������\n");
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
				printf("\n��ѡ�����ĵ�����\n");
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
					printf("���������������������\n");
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
					printf("========����ɹ�========\n");
					printf("��ӭ�´�ʹ��\n");
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
					printf("���������������������\n");
					break;
				}
			}
			system("pause");
			break;

		default:
			printf("���������룺");
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
	printf("*****     1��������       *****\n");
	printf("*****     2��ǰ̨����       *****\n");
	printf("*****     3���ͻ�ϵͳ       *****\n");
	printf("*****     4��Ǯ��ϵͳ       *****\n");
	printf("*****     0���˳�ϵͳ       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
}
void showMenu_boss() {
	printf("*********************************\n");
	printf("*****                       *****\n");
	printf("*****     1��������       *****\n");
	printf("*****     2��ǰ̨����       *****\n");
	printf("*****     3���ͻ�ϵͳ       *****\n");
	printf("*****     4��Ǯ��ϵͳ       *****\n");
	printf("*****     5��Ա������       *****\n");
	printf("*****     0���˳�ϵͳ       *****\n");
	printf("*****                       *****\n");
	printf("*********************************\n");
}

