#include "system_stockmanagement.h"
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"system_date.h"
#include"system_checkstand.h"
#pragma warning(disable:4996)
#define stock_warning 50
#define time_warning 5


void menu_stockmanagement() {
	printf("******************************************\n");
	printf("*****                                *****\n");
	printf("*****        1����ʾ��Ʒ��Ϣ         *****\n");
	printf("*****        2����ѯ��Ʒ��Ϣ         *****\n");
	printf("*****        3�������Ʒ��Ϣ         *****\n");
	printf("*****        4��ɾ����Ʒ��Ϣ         *****\n");
	printf("*****        5���޸���Ʒ��Ϣ         *****\n");
	printf("*****        6���ٱ���Ʒ��Ϣ         *****\n");
	printf("*****        7����治������         *****\n");
	printf("*****        8����Ʒ�۸�Ƚ�         *****\n");
	printf("*****        0�����沢�˳�           *****\n");
	printf("*****                                *****\n");
	printf("******************************************\n");
}

struct date time()//ϵͳʱ��
{
	time_t t = time(0);
	struct tm* local = localtime(&t);
	struct date date;
	date.year = local->tm_year + 1900;
	date.month = local->tm_mon + 1;
	date.day = local->tm_mday;
	return date;
};

//�ж���Ʒ�Ƿ����
int judge_time(Goods* head, Date today_time) {
	Goods* p;
	p = head;
	if (date_minus(p->in_time, today_time) < p->quality_time) {
		if (p->quality_time - date_minus(p->in_time, today_time) > time_warning)
			return 0;//δ�����Ҳ�Ϊ�ٱ�
		else return 1;//δ���ڵ�Ϊ�ٱ���Ʒ
	}
	else return 2;//�ѹ���
}

//�ж���Ʒ����Ƿ�С�ڿ��Ԥ��ֵ
int judge_stock(Goods* head) {
	Goods* p;
	p = head;
	if (p->good_amount >= stock_warning)
		return 0;//��治С��Ԥ��ֵ
	else return 1;//���С��Ԥ��ֵ
}
//��ӡ�ٱ���Ʒ��ͷ
void time_head() {
	printf_s("��Ʒ���     ��Ʒ����          ��Ʒ�ȼ�     ��������     �ٱ�ʱ�䣨�죩");
}

//��ӡ�ٱ���Ʒ��Ϣ
void time_print1(Goods* p, Date today) {
	printf_s("%-12d %-17s %-12d %d.%d.%-5d %d", p->good_id, p->name, p->good_grade, p->in_time.year, p->in_time.month, p->in_time.day, (p->quality_time) - date_minus(p->in_time, today));
}

//��ӡ������Ʒ��Ϣ
void time_print2(Goods* p) {
	printf_s("%-12d %-17s %-12d %d.%d.%-5d �ѹ���", p->good_id, p->name, p->good_grade, p->in_time.year, p->in_time.month, p->in_time.day);
}

//�ٱ���Ʒ���ѹ���
void remind_time(Goods* head) {
	struct date local_time = time();
	Goods* p;
	int choice, flag = 1, a = 0;
	p = head->next;
	system("cls");
	printf_s("1.��ѯ�ѹ�����Ʒ��Ϣ��      2.��ѯ�ٱ���Ʒ��Ϣ\n");
	printf("\n");
	printf_s("��ѡ����������");
	scanf_s("%d", &choice);//�����û���������ʽ���������������
	while (flag == 1) {
		if (choice != 1 && choice != 2) {
			printf_s("ѡ������������ѡ��\n");
			scanf_s("%d", &choice);
		}
		else flag = 0;
	}
	system("cls");
	if (choice == 2) {
		if (p == NULL)
			printf_s("����Ʒ��Ϣ��\n");
		else {
			while (p != NULL) {
				if (judge_time(p, local_time) == 1) {
					if (a == 0) {
						time_head();
						printf_s("\n");
					}
					time_print1(p, local_time);
					printf_s("\n");
					a++;
				}
				p = p->next;
			}
			if (a == 0)
				printf_s("���ٱ���Ʒ��\n");
			printf("=================��ʾ�ɹ�=================\n");
		}
	}
	else {
		if (p == NULL)
			printf_s("����Ʒ��Ϣ��\n");
		else {
			while (p != NULL) {
				if (judge_time(p, local_time) == 2) {
					if (a == 0) {
						time_head();
						printf_s("\n");
					}
					time_print2(p);
					printf_s("\n");
					a++;
				}
				p = p->next;
			}
			if (a == 0)
				printf_s("�޹�����Ʒ��\n");
			printf("=================��ʾ�ɹ�=================\n");
		}
	}
	system("pause");
	system("cls");
}

//��ӡ��治����Ʒ��ͷ
void stock_head() {
	printf_s("��Ʒ���     ��Ʒ����          ��Ʒ�ȼ�     ʣ���棨�");
}

//��ӡ��治����Ʒ��Ϣ
void stock_print(Goods* p) {
	printf_s("%-12d %-17s %-12d %.2f", p->good_id, p->name, p->good_grade, p->good_amount);
}

//��治�����ѹ���
void remind_stock(Goods* head) {
	Goods* p;
	p = head->next;
	system("cls");
	if (p == NULL)
		printf_s("����Ʒ��治�㡣");
	else {
		stock_head();
		printf_s("\n");
		while (p != NULL) {
			if (judge_stock(p) == 1) {
				stock_print(p);
				printf_s("\n");
			}
			p = p->next;
		}
		printf("=================��ʾ�ɹ�=================\n");
	}
	system("pause");
	system("cls");
}

//��ӡ��Ʒ��Ϣ��ͷ
void goods_head() {
	printf_s("��Ʒ���     ��Ʒ����          ��Ʒ�ȼ�     �����۸�(Ԫ/�    ���ۼ۸�(Ԫ/�     ��Ʒ�������     ��������     �����ڣ��죩");
}

//��ӡ��Ʒ��Ϣ
void goods_message(Goods* p) {
	printf_s("%-12d %-17s %-12d %-20.2f %-19.2f %-18.2f %d.%d.%-7d %-3d", p->good_id, p->name, p->good_grade, p->in_price, p->price, p->good_amount, p->in_time.year, p->in_time.month, p->in_time.day, p->quality_time);
}

//��ʾ��Ʒ��Ϣ
void goods_messageshow(Goods* head) {
	system("cls");
	Goods* p;
	p = head->next;
	if (p == NULL)
		printf_s("����Ʒ��Ϣ��\n");
	else {
		goods_head();
		printf_s("\n");
		while (p != NULL) {
			goods_message(p);
			printf("\n");
			p = p->next;
		}
		printf("\n");
		printf("=================��ʾ�ɹ�=================\n");
	}
	system("pause");
	system("cls");
	return;
}

//������Ʒ��Ϣ
Goods* goods_messagesearch(Goods* head) {
	int choice, flag = 1;
	char name[20] = { 0 }, button[20] = { 0 };
	Goods* p;
	p = head->next;
	printf_s("0.�˳�\n");
	printf_s("1.����Ų�ѯ��Ʒ\n");
	printf_s("2.�����Ʋ�ѯ��Ʒ\n");
	printf_s("\n");
	printf_s("��ѡ����������\n");
	int judge = scanf("%d", &choice);
	printf_s("\n");
	while (flag == 1) {
		if (choice != 1 && choice != 2 && choice != 0) {
			printf_s("ѡ������������ѡ��\n");
			if (judge == 0) scanf("%s", button);
			judge = scanf("%d", &choice);
		}
		else flag = 0;
	}
	switch (choice) {
	case 0:break;
	case 1: {
		printf_s("��������Ҫ��ѯ����Ʒ��ţ�\n");
		int judge = scanf_s("%d", &choice);
		if (0 == judge) {
			printf("����������������롣\n");
			scanf("%s", button);
			judge = scanf("%d", &choice);
		}
		system("cls");
		while (p != NULL) {
			if (p->good_id == choice) {
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf_s("\n");
				printf("=================��ʾ�ɹ�=================\n");
				system("pause");
				system("cls");
				return p;
			}
			p = p->next;
		}
		printf_s("�޸���Ʒ��Ϣ��\n");
		break;
	}
	case 2: {
		printf_s("��������Ҫ��ѯ����Ʒ���ƣ�\n");
		scanf_s("%s", name, 20);
		system("cls");
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf_s("\n");
				printf("=================��ʾ�ɹ�=================\n");
				system("pause");
				system("cls");
				return p;
			}
			p = p->next;
		}
		printf_s("�޸���Ʒ��Ϣ��\n");
		break;
	}
	}
	system("pause");
	system("cls");
	return NULL;
}

//����Ʒ�ļ�
Goods* read_goodsfile(FILE* fp) {
	int i = 1, w;
	Goods* head, * newgoods, * p1 = NULL;
	head = (Goods*)malloc(sizeof(Goods));
	if (head == NULL) return NULL;
	head->next = NULL;
	fseek(fp, 0, 2);
	w = ftell(fp);
	fseek(fp, 0, 0);
	while (w != ftell(fp)) {
		newgoods = (Goods*)malloc(sizeof(Goods));
		if (newgoods == NULL) return NULL;
		newgoods->next = NULL;
		//������Ʒ�������Ϣ
		fscanf(fp, "%d%s%d%lf%lf%lf%d%d%d%d\n", &newgoods->good_id, &newgoods->name, &newgoods->good_grade,
			&newgoods->in_price, &newgoods->price, &newgoods->good_amount, &newgoods->in_time.year, &newgoods->in_time.month, &newgoods->in_time.day, &newgoods->quality_time);
		if (i == 1)
			head->next = newgoods;
		else
			p1->next = newgoods;
		p1 = newgoods;
		i++;
		if (feof(fp)) break;
	}
	return head;
}

//д��Ʒ�ļ�
void write_goodsfile(Goods* head) {
	FILE* fp;
	Goods* p;
	p = head->next;
	if ((fp = fopen("goods.txt", "w")) == NULL) {
		printf("�޷��������ļ���\n");
		return;
	}
	while (p != NULL) {
		fprintf(fp, "%d %s %d %.2f %.2f %.2f %d %d %d %d\n", p->good_id, p->name, p->good_grade,
			p->in_price, p->price, p->good_amount, p->in_time.year, p->in_time.month, p->in_time.day, p->quality_time);
		p = p->next;
	}
	fclose(fp);
}

//�����Ʒ��Ϣ
Goods* goods_in(Goods* head) {
	Goods* p, * q = head->next;
	int a = 0, key;
	p = head->next;
	while (q->next != NULL) {
		q = q->next;
	}
	printf("��������Ҫ��ӵ���Ʒ��Ϣ������\n");
	scanf("%d", &key);
	printf("��������Ʒ��Ϣ��\n");
	printf("��Ʒ���     ��Ʒ����     ��Ʒ�ȼ�     �����۸�(Ԫ/�     ���ۼ۸�(Ԫ/�     ��Ʒ�������     ��������     �����ڣ��죩\n");
	while (a < key) {
		p = (Goods*)malloc(sizeof(Goods));
		scanf("%d%s%d%lf%lf%lf%d%d%d%d", &p->good_id, p->name, &p->good_grade, &p->in_price, &p->price, &p->good_amount,
			&p->in_time.year, &p->in_time.month, &p->in_time.day, &p->quality_time);
		q->next = p;
		q = p;
		q->next = NULL;
		a++;
	}
	printf("=================��ӳɹ�=================\n");
	system("pause");
	system("cls");
	return head;
}

//�޸���Ʒ��Ϣ
Goods* goods_edit(Goods* head) {
	Goods* p;
	int i;
	p = head;
	p = goods_messagesearch(p);

	if (p == NULL) {
		//printf("����Ʒ��¼��\n");
		return head;
	}
	else {
		printf("1.��Ʒ���\n");
		printf("2.��Ʒ����\n");
		printf("3.��Ʒ�ȼ�\n");
		printf("4.�����۸�\n");
		printf("5.���ۼ۸�\n");
		printf("6.��Ʒ����\n");
		printf("7.��������\n");
		printf("8.��Ʒ������\n");
		printf("��ѡ������Ҫ�޸ĵ���Ʒ���ݣ�\n");
		scanf("%d", &i);
		switch (i) {
		case 1: {printf("�������µ���Ʒ��ţ�\n"); scanf("%d", &p->good_id); }; break;
		case 2: {printf("�������µ���Ʒ���ƣ�\n"); scanf("%s", p->name); }; break;
		case 3: {printf("�������µ���Ʒ�ȼ���\n"); scanf("%d", &p->good_grade); }break;
		case 4: {printf("�������µ���Ʒ�����۸�\n"); scanf("%lf", &p->in_price); }break;
		case 5: {printf("�������µ���Ʒ���ۼ۸�\n"); scanf("%lf", &p->price); }break;
		case 6: {printf("�������µ���Ʒ������\n"); scanf("%lf", &p->good_amount); }break;
		case 7: {printf("�������µ���Ʒ������ڣ�\n"); scanf("%d%d%d", &p->in_time.year, &p->in_time.month, &p->in_time.day); }break;
		case 8: {printf("�������µ���Ʒ�����ڣ�\n"); scanf("%d", &p->quality_time); }break;
		}
		system("cls");
		goods_head();
		printf("\n");
		goods_message(p);
		printf("\n=================�޸ĳɹ�=================\n");
	}
	system("pause");
	system("cls");
	return head;
}


//ɾ����Ʒ��Ϣ
Goods* goods_delete(Goods* head) {
	Goods* p, * q;
	p = head;
	p = goods_messagesearch(p);
	q = head;
	while ((q->next != p) && (q->next != NULL))
		q = q->next;
	if (q->next == NULL)
		return head;//printf("����Ʒ��¼��\n");
	else {
		q->next = p->next;
	}
	free(p);
	printf("=================ɾ���ɹ�=================\n");
	system("pause");
	system("cls");
	return head;
}

//���"����"
Goods* edit_name(Goods* head) {
	int r;
	Goods* p = head->next;
	int a;
	struct date local_time = time();
	char b[20] = { "(����)" };
		while (p != NULL) {
			r = strlen(p->name);
			if ((int)p->name [r-1]!=41){
				a = judge_time(p, local_time);
				if (a == 1) {
					strcat(p->name, b);
					p->price = 0.8 * p->price;
				}
			}
		p = p->next;
		}
	return head;
}

//��Ʒ�۸�Ƚ�
void price_com(Goods* head2){
	Goods* p = head2->next;
	int i = 0;
	char a[20]={0};
	printf("����������Ҫ��ѯ����Ʒ���ƣ�\n");
	scanf("%s", a);
	while ((p != NULL) && (strcmp(a, p->name) != 0))p = p->next;
	system("cls");
	if (p == NULL) printf("����Ʒ��¼��");
	else {
		printf("��Ʒ����         �����۸񣨽�/Ԫ��    ���ۼ۸񣨽�/Ԫ��\n");
		while ((i < 10) && (p != NULL)) {

			if (strcmp(a, p->name) == 0) {
				i++;
				printf("%-19s%-20.2lf%.2lf\n", a, p->in_price, p->price);
			}p = p->next;
		}
	}
	system("pause");
	system("cls");
}
