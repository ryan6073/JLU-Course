#include<stdio.h>
#include<time.h>
#include"system_stockmanagement.h"
#include"system_checkstand.h"
#include"system_date.h"

FILE* fpodd;

void menu_moneymanagement() {
	printf("******************************************\n");
	printf("*****                                *****\n");
	printf("*****        1����ʾ������ӯ��       *****\n");
	printf("*****        2����ѯ��Ʒ��ӯ��       *****\n");
	printf("*****        3����ʾ������ӯ��       *****\n");
	printf("*****        4����ѯ��Ʒ��ӯ��       *****\n");
	printf("*****        0���˳�                 *****\n");
	printf("*****                                *****\n");
	printf("******************************************\n");
}

struct date time1()
{
	time_t t = time(0);
	struct tm* local = localtime(&t);
	struct date date;
	date.year = local->tm_year + 1900;
	date.month = local->tm_mon + 1;
	date.day = local->tm_mday;
	return date;
};

//��ӡ��Ʒӯ����ͷ
void print_head() {
	printf("��Ʒ����     ��Ʒ����          ���۶Ԫ��          ����Ԫ��");
}

//��ӡ���ϴ���ӯ����Ϣ
void print_dayplastic(Goods* head) {
	struct date local_time = time1();
	int a = 0;//��Ʒ����
	long long b = 0;//��Ʒ����
	int plasticbag1 = 0;//���ϴ�����
	int c = 0;
	double i, profit = 0, sum = 0;
	char name[20];
	double arr[2] = { 0 };
	fpodd = fopen("./odd.txt", "a+");
	rewind(fpodd);
	do {
		fscanf_s(fpodd, "����:%lld\t", &b);
		fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
		fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
		for (int m = 0; m < a; m++) {
			fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag1);
			if (b / 10000 == local_time.year * 10000 + local_time.month * 100 + local_time.day)
			{
				sum = sum + plasticbag1 * 0.1;
				profit = profit + plasticbag1 * 0.09;
			}
		}
	} while (feof(fpodd) == 0);
	printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
}

//��ӡ��Ʒ��ӯ����Ϣ
void print_daymessage(Goods* head) {
	double sum0 = 0, profit0 = 0;
	while (head != NULL) {
		struct date local_time = time1();
		int a = 0;//��Ʒ����
		int x = 0;
		long long b = 0;//��Ʒ����
		int c = 0;
		int plasticbag = 0;//���ϴ�����
		double i, profit = 0, sum = 0;
		char name[20];
		double arr[2] = { 0 };
		fpodd = fopen("./odd.txt", "a+");
		rewind(fpodd);
		do {
			fscanf_s(fpodd, "����:%lld\t", &b);
			fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
			fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
			for (int m = 0; m < a; m++) {
				fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
				if (b / 10000 == local_time.year * 10000 + local_time.month * 100 + local_time.day && head->good_id == c)
				{
					sum = sum + i - plasticbag * 0.1;
					profit = profit + i - arr[1] * head->in_price - plasticbag * 0.1;
					x = x + plasticbag;
				}
			}
		} while (feof(fpodd) == 0);
		profit0 = profit0 + profit + x * 0.09;
		sum0 = sum0 + sum + x * 0.1;
		printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
		head = head->next;
	}
	printf("��Ʒ�����۶%.2lf\n", sum0);
	printf("��Ʒ��ӯ����%.2lf\n", profit0);
}

//������ӯ��
void day_profit(Goods* head) {
	Goods* p;
	p = head->next;
	print_head();
	printf("\n");
	print_dayplastic(p);
	p = p->next;
	print_daymessage(p);
	p = p->next;
	printf("=================��ʾ�ɹ�=================\n");
	system("pause");
	system("cls");
}

//��ӡ���ϴ���ӯ����Ϣ
void print_monthplastic(Goods* head) {
	struct date local_time = time1();
	int a = 0;//��Ʒ����
	long long b = 0;//��Ʒ����
	int plasticbag = 0;//���ϴ�����
	int c = 0;
	double i, profit = 0, sum = 0;
	char name[20];
	double arr[2] = { 0 };
	fpodd = fopen("./odd.txt", "a+");
	rewind(fpodd);
	do {
		fscanf_s(fpodd, "����:%lld\t", &b);
		fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
		fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
		for (int m = 0; m < a; m++) {
			fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
			if (b / 1000000 == local_time.year * 100 + local_time.month)
			{
				sum = sum + plasticbag * 0.1;
				profit = profit + plasticbag * 0.09;
			}
		}
	} while (feof(fpodd) == 0);
	printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
}


//��ӡ��Ʒ��ӯ����Ϣ
void print_monthmessage(Goods* head) {
	double sum0 = 0, profit0 = 0;
	while (head != NULL) {
		struct date local_time = time1();
		int a = 0;//��Ʒ����
		int x = 0;
		long long b = 0;//��Ʒ����
		int c = 0;
		int plasticbag = 0;//���ϴ�����
		double i, profit = 0, sum = 0;
		char name[20];
		double arr[2] = { 0 };
		fpodd = fopen("./odd.txt", "a+");
		rewind(fpodd);
		do {
			fscanf_s(fpodd, "����:%lld\t", &b);
			fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
			fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
			for (int m = 0; m < a; m++) {
				fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
				if (b / 1000000 == local_time.year * 100 + local_time.month && head->good_id == c)
				{
					sum = sum + i - plasticbag * 0.1;
					profit = profit + i - arr[1] * head->in_price - plasticbag * 0.1;
					x = x + plasticbag;
				}
			}
		} while (feof(fpodd) == 0);
		profit0 = profit0 + profit + x * 0.09;
		sum0 = sum0 + sum + x * 0.1;
		printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
		head = head->next;
	}
	printf("��Ʒ�����۶%.2lf\n", sum0);
	printf("��Ʒ��ӯ����%.2lf\n", profit0);
}

//������ӯ��
void month_profit(Goods* head) {
	Goods* p;
	p = head->next;
	print_head();
	printf("\n");
	print_monthplastic(p);
	p = p->next;
	print_monthmessage(p);
	p = p->next;
	printf("=================��ʾ�ɹ�=================\n");
	system("pause");
	system("cls");
}

//������Ʒ
Goods* messagesearch(Goods* head) {
	int  choice, flag = 1;
	char name[20] = { 0 }, button[100] = { 0 };
	Goods* p;
	p = head->next;
	printf_s("1.����Ų�ѯ��Ʒ\n");
	printf_s("2.�����Ʋ�ѯ��Ʒ\n");
	printf_s("\n");
	printf_s("��ѡ����������\n");
	int judge = scanf_s("%d", &choice);
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
				return p;
			}
			p = p->next;
		}
		printf_s("�޸���Ʒ��Ϣ��\n");
	}
		  break;
	}
	system("cls");
	return NULL;
}

//��ѯ��Ʒ��ӯ��
void search_day(Goods* head) {
	Goods* p;
	p = messagesearch(head);
	if (p != NULL) {
		print_head();
		printf("\n");
		if (p->good_id != 1) {
			struct date local_time = time1();
			int a = 0;//��Ʒ����
			long long b = 0;//��Ʒ����
			int c = 0;
			int plasticbag = 0;//���ϴ�����
			double i, profit = 0, sum = 0;
			char name[20];
			double arr[2] = { 0 };
			fpodd = fopen("./odd.txt", "a+");
			rewind(fpodd);
			do {
				fscanf_s(fpodd, "����:%lld\t", &b);
				fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
				fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
				for (int m = 0; m < a; m++) {
					fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
					if (b / 10000 == local_time.year * 10000 + local_time.month * 100 + local_time.day && p->good_id == c)
					{
						sum = sum + i - plasticbag * 0.1;
						profit = profit + i - arr[1] * p->in_price - plasticbag * 0.1;
					}
				}
			} while (feof(fpodd) == 0);
			printf("%-13d%-18s%-22.2lf%.2lf\n", p->good_id, p->name, sum, profit);
		}
		else
			print_dayplastic(p);
		p = p->next;
		printf("=================��ʾ�ɹ�=================\n");
	}
	else printf("�޸���Ʒ��Ϣ��\n");
	system("pause");
	system("cls");
}

//��ѯ��Ʒ��ӯ��
void search_month(Goods* head) {
	Goods* p;
	p = messagesearch(head);
	if (p != NULL) {
		print_head();
		printf("\n");
		if (p->good_id != 1) {
			struct date local_time = time1();
			int a = 0;//��Ʒ����
			long long b = 0;//��Ʒ����
			int c = 0;
			int plasticbag = 0;//���ϴ�����
			double i, profit = 0, sum = 0;
			char name[20];
			double arr[2] = { 0 };
			fpodd = fopen("./odd.txt", "a+");
			rewind(fpodd);
			do {
				fscanf_s(fpodd, "����:%lld\t", &b);
				fscanf_s(fpodd, "���Ѷ�:%lf\t", &i);
				fscanf_s(fpodd, "��Ʒ����:%d\t", &a);
				for (int m = 0; m < a; m++) {
					fscanf_s(fpodd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
					if (b / 1000000 == local_time.year * 100 + local_time.month && p->good_id == c)
					{
						sum = sum + i - plasticbag * 0.1;
						profit = profit + i - arr[1] * p->in_price - plasticbag * 0.1;
					}
				}
			} while (feof(fpodd) == 0);
			printf("%-13d%-18s%-22.2lf%.2lf\n", p->good_id, p->name, sum, profit);
		}
		else
			print_monthplastic(p);
		p = p->next;
		printf("=================��ʾ�ɹ�=================\n");
	}
	else printf("�޸���Ʒ��Ϣ��\n");
	system("pause");
	system("cls");
}