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
			printf("��ӭ�´�ʹ��\n");
			system("pause");
			return 0;
		case 1:
			system("pause&cls");
			printf("�������������֣�  ");
			scanf_s("%s", name, 10);
			printf("�������������룺  ");
			scanf_s("%s", password, 20);
			a=isExist(ab,name,password);
			if (a != NULL && strcmp(a->m_identity, "boss") == 0) {
				printf("\n��¼�ɹ����밴�س��Լ���");
				system("pause&cls");
				boss( abs,  ab,  fp1,  fp5,  head1,  head,  head2);
				system("cls");
				break;
			}
			else {
				printf("�û���������������ٴγ���");
				system("pause&cls");
				break;
			}
		case 2:
			system("pause&cls");
			printf("�������������֣�  ");
			scanf_s("%s", name, 10);
			printf("�������������룺  ");
			scanf_s("%s", password, 20);
		     a = isExist(ab, name, password);
			if (a != NULL && strcmp(a->m_identity, "cashier") == 0) {
				printf("\n��¼�ɹ����밴�س��Լ���");
				system("pause&cls");
				cashier(abs, ab, fp1, head1, head);
				system("cls");
				break;
			}
			else {
				printf("�û���������������ٴγ���");
				system("pause&cls");
				break;
			}
		default: 
			printf("�����������������룺\n");
			system("pause&cls");
			break;
		}
	}
}