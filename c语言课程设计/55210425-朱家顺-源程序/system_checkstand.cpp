#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<conio.h>
#include<malloc.h>
#include<time.h>
#include"system_checkstand.h"
#include"system_custom.h"
#include"system_stockmanagement.h"
#define num 5
#pragma warning(disable:4996)
static const char* odd_file = "./odd.txt";
static const char* numberwrite_file = "./numberwrite.txt";
static const char* number_file = "./number.txt";
static const char* time_file = "./time.txt";
FILE* fp_time;
FILE* fp_odd;
FILE* fp_number;
FILE* fp_numberwrite;
int plasticbag = 0;
struct date timeset()
{
	time_t t = time(0);
	struct tm* local = localtime(&t);
	struct date date;
	date.year = local->tm_year + 1900;
	date.month = local->tm_mon + 1;
	date.day = local->tm_mday;
	return date;
};
struct goodsbuying* creat()
{
	struct	goodsbuying* head1 = (struct goodsbuying*)malloc(sizeof(goodsbuying));
	if (head1 == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return NULL;
	}
	head1->next = NULL;
	return head1;
}

double billrealize(struct goodsbuying* head1, FILE* fp)
{
	double a = 0;
	double b = 0, c = 0;
	struct goodsbuying* s = head1->next;
	while (s != NULL)
	{
		b = s->price;
		c = s->good_amount;
		a = a + b * c;
		s = s->next;
	}
	return a;
}
void print(const struct goodsbuying* head1, FILE* fp)
{
	struct goodsbuying* m = head1->next;
	while (m != NULL)
	{
		printf("��Ʒ����            ��Ʒ����            ��Ʒ�۸�            ��Ʒ����\n");
		printf("%-20d%-20s%-20.2lf%-20.2lf", m->good_id, m->name, m->price, m->good_amount);
		m = m->next;
		printf("\n");
	}
	if (head1->next == NULL)
	{
		printf("����Ʒ��¼��");

	}
	_getch();
	return;
}


int menu_shop(FILE* fp, struct goodsbuying* head1, struct Member* abs, Goods* head)
{
	while (1)
	{
		system("cls");
		printf("***************************************\n");
		printf("**             1.��Ʒ����            **\n");
		printf("**             2.�������            **\n");
		printf("**             3.��Ա��ֵ            **\n");
		printf("**             4.�����¼��ѯ        **\n");
		printf("**             5.������м�¼        **\n");
		printf("**             0.�˻���һ����        **\n");
		printf("***************************************\n");
		printf("\n");
		int a = -1;
		int g = scanf_s("%d", &a);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬����������");
			g = scanf_s("%d", &a);
		}

		if (a == 0)
		{
			shopback(head1, head, fp);
			clearclain(head1);
			return 0;
		}
		if (a == 1)
		{
			shop_system(fp, head1, abs, head);


		}
		if (a == 2)
		{
			bill_system(fp, head1, abs, head);


		}
		if (a == 3)
		{
			recharge(fp, head1, abs);


		}
		if (a == 4)
		{
			shopsearch_system(fp, head1, abs, head);

		}
		if (a == 5)
		{
			clearall();

		}
		if (a != 1 && a != 2 && a != 3 && a != 4 && a != 0 && a != 5)
		{
			printf("�������룬���������룡");
			system("pause");
			system("cls");
			menu_shop(fp, head1, abs, head);
		}

	}
	return 0;
}

void shop_system(FILE* fp, struct goodsbuying* head1, struct Member* abs, Goods* head)
{
	system("cls");
	int a = 0;
	printf("***************************************\n");
	printf("**        1.��ʾ��ǰ�����б�         **\n");
	printf("**        2.�����Ʒ�����б�         **\n");
	printf("**        3.���б���ɾ����Ʒ         **\n");
	printf("**        4.��ʾ������Ʒ             **\n");
	printf("**        0.������һ����             **\n");
	printf("***************************************\n");
	printf("\n");
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &a);
	}

	if (a == 1)
	{
		print(head1, fp);

	}
	if (a == 2)
	{

		goods_buying(head, fp, head1, abs);
	}
	if (a == 3)
	{
		delete123(fp, head1, abs, head);
	}
	if (a == 0)
	{
		return;
	}
	if (a == 4)
	{
		goods_messageshow(head);
		shop_system(fp, head1, abs, head);
	}
	if (a != 1 && a != 2 && a != 0 && a != 3 && a != 4)
	{
		printf("�������룬���������룡");
		printf("\n");
		system("pause");
		system("cls");

		shop_system(fp, head1, abs, head);

	}
	return;
}
void membership(double i, FILE* fp, struct goodsbuying* head1, struct Member* abs, long long number1, Goods* head)
{
	printf("***************************************\n");
	printf("**        1.��Ա֧��                 **\n");
	printf("**        2.�ǻ�Ա֧��               **\n");
	printf("***************************************\n");
	printf("��ѡ��֧����ʽ��");
	printf("\n");
	int a = 0;
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &a);
	}
	if (a == 1)
	{
		account1(i, fp, head1, abs, number1, head);
	}
	if (a == 2)
	{
		account2(i, fp, head1, abs, number1, head);
	}
	if (a != 1 && a != 2)
	{
		printf("�������룬���������룡");
		printf("\n");
		system("pause");
		system("cls");
		membership(i, fp, head1, abs, number1, head);
		return;
	}
	return;
}

void bill_system(FILE* fp, struct goodsbuying* head1, struct Member* abs, Goods* head)
{
	if (head1->next == NULL)
	{
		printf("�����б�Ϊ�գ�");
		_getch();
	}
	if (head1->next != NULL)
	{
		double i;
		i = billrealize(head1, fp);
		long long number1 = number();
		timeclear();
		printf("***************************************\n");
		printf("**        1.��Ҫ                     **\n");
		printf("**        2.����Ҫ                   **\n");
		printf("***************************************\n");
		printf("��ѡ���Ƿ���Ҫ�������");
		printf("\n");
		int b;
		int g = scanf_s("%d", &b);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			g = scanf_s("%d", &b);
		}
		if (b == 1)
		{
			i = i + 0.1;
			plasticbag = 1;
			bag(head, fp);
		}
		if (b != 1 && b != 2)
		{
			printf("�������룬���������룡");
			printf("\n");
			system("pause");
			system("cls");
			bill_system(fp, head1, abs, head);
		}
		membership(i, fp, head1, abs, number1, head);
	}
	return;
}

void account1(double i, FILE* fp, struct goodsbuying* head1, struct Member* abs, long long number1, Goods* head)
{
	struct date timecmp = timeset();
	struct Member* Head = abs;
	bool f = false;
	if (Head->next == NULL)
	{
		printf("���κλ�Ա��Ϣ,������ת���ǻ�Ա֧������");
		printf("\n");
		_getch();
		account2(i, fp, head1, abs, number1, head);
		return;
	}
	else
	{
		Head = Head->next;
		printf("***************************************\n");
		printf("**       �������Ա�ֻ�����:         **\n");
		printf("***************************************\n");
		printf("\n");
		char phonenumber[15] = { 0 };
		int g = scanf_s("%s", &phonenumber, 15);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			g = scanf_s("%s", &phonenumber, 15);
		}
		while (Head != NULL)
		{

			if (strcmp(phonenumber, Head->m_phone) == 0)
			{
				f = true;
				int a;
				int arr[3];
				i = i * 0.95;
				struct date p = timeset();
				char biryear[4], birmonth[2], birday[2];
				for (a = 0; a < 4; a++)
				{
					biryear[a] = Head->m_birth[a];
				}
				for (a = 6; a <= 7; a++)
				{
					birmonth[a - 6] = Head->m_birth[a];
				}
				for (a = 10; a <= 11; a++)
				{
					birday[a - 10] = Head->m_birth[a];
				}
				arr[0] = atoi(biryear);
				arr[1] = atoi(birmonth);
				arr[2] = atoi(birday);
				printf("\n");
				find(Head);
				printf("\n");
				_getch();
				if (arr[0] == timecmp.year && arr[1] == timecmp.month && arr[2] == timecmp.day)
				{
					i = i * 0.8;
				}

				printf("***************************************\n");
				printf("**                                   **\n");
				printf("**   һ�����ѣ�");
				printf("%13.2lf", i);
				printf("   Ԫ    **\n");
				printf("**     ����:");
				printf("%lld", number1);
				printf("             **\n");
				printf("***************************************\n");
				printf("\n");

				if (Head->m_balance < i)
				{
					printf_s("�˻�����,����֧��%.2lfԪ\n", i - Head->m_balance);
					Head->m_balance = 0;
					saveMember(abs);

				}
				if (Head->m_balance >= i)
				{
					printf_s("���Զ��۳��˻����˻����%.2lfԪ\n", Head->m_balance - i);
					Head->m_balance = Head->m_balance - i;
					saveMember(abs);

				}
				rewrite(head1, number1);
				write(head1, number1, i);
				system("pause");
				destruction(fp, head1, abs, head);
				system("cls");
				return;

			}

			Head = Head->next;
		}
		if (!f)
		{
			printf("���κλ�Ա��Ϣ!\n");
			printf("1.���������Ա�绰\n");
			printf("2.��ת���ǻ�Ա֧������\n");
			printf("\n");
			double g;
			int h = scanf_s("%lf", &g);
			while (h != 1)
			{
				scanf_s("%*[^\n]%*c");
				printf("�������룬���������룡");
				h = scanf_s("%lf", &g);
			}

			if (g == 1)
			{
				account1(i, fp, head1, abs, number1, head);
				return;
			}
			else if (g == 2)
			{
				account2(i, fp, head1, abs, number1, head);
				return;
			}
			else
			{
				printf("�������룬����������!");
				printf("\n");
				system("pause");
				system("cls");
				return;
			}
		}
	}

	return;
}


void account2(double i, FILE* fp, struct goodsbuying* head1, struct Member* abs, long long number1, Goods* head)
{
	printf("***************************************\n");
	printf("**                                   **\n");
	printf("**     һ�����ѣ�");
	printf("%10.2lf", i);
	printf("   Ԫ     **\n");
	printf("**      ����:");
	printf("%lld", number1);
	printf("            **\n");
	printf("***************************************\n");
	printf("\n");
	system("pause");

	rewrite(head1, number1);
	write(head1, number1, i);
	destruction(fp, head1, abs, head);
	system("cls");

	return;


}

void destruction(FILE* fp, struct goodsbuying* head1, struct Member* abs, Goods* head)
{
	goodsbuying* p = head1->next;
	while (p->next)
	{
		goodsbuying* temp = p;
		p = p->next;
		free(temp);
	}
	free(p);
	head1->next = NULL;

	return;

}


void shopsearch_system(FILE* fp, struct goodsbuying* head1, struct Member* abs, Goods* head)
{
	int a;
	printf("***************************************\n");
	printf("**        1.�����ѯ����	     **\n");
	printf("**        0.�˻�����һ����	     **\n");
	printf("***************************************\n");
	printf("��ѡ������Ҫ�ķ���:");
	printf("\n");
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &a);
	}
	if (a == 0)
	{
		menu_shop(fp, head1, abs, head);
	}
	if (a == 1)
	{
		research();
	}
	if (a != 1 && a != 0)
	{
		printf("�������룬���������룡");
		printf("\n");
		system("pause");
		system("cls");
		shopsearch_system(fp, head1, abs, head);

	}return;
}
void research()
{
	long long k;
	printf("***************************************\n");
	printf("*       ��������Ҫ��ѯ�ĵ���:         *\n");
	printf("***************************************\n");
	printf("\n");
	int g = scanf_s("%lld", &k);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%lld", &k);
	}
	if (k <= 0)
	{
		printf("�������룬���������룡\n");
		_getch();
		system("cls");
		research();
	}
	search(k);
}
void write(const struct goodsbuying* head, long long number1, double i)
{
	int a = 0;
	char file[20] = { 0 };
	struct goodsbuying* g = head->next;
	fp_odd = fopen("./odd.txt", "a+");
	if (fp_odd == (FILE*)0)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}

	fseek(fp_odd, 0, SEEK_END);
	while (g != NULL)
	{
		a = a + 1;
		g = g->next;
	}
	fprintf(fp_odd, "����:%lld\t", number1);
	fprintf(fp_odd, "���Ѷ�:%.2lf\t", i);
	fprintf(fp_odd, "��Ʒ����:%d\t", a);
	struct goodsbuying* p = head->next;
	while (p != NULL)
	{
		fprintf(fp_odd, "��Ʒ����:%d\t", p->good_id);
		fprintf(fp_odd, "��Ʒ����:%s\t", p->name);
		fprintf(fp_odd, "�۸�:%.2lf\t", p->price);
		fprintf(fp_odd, "����:%.2lf\t", p->good_amount);
		fprintf(fp_odd, "���ϴ�����:%d\t", plasticbag);
		fprintf(fp_odd, "\n");
		p = p->next;
	}

	fclose(fp_odd);
	plasticbag = 0;
	return;
}
long long number()
{
	struct date t = timeset();
	long long year1 = t.year;
	long long month1 = t.month;
	long long day1 = t.day;
	long long number2 = year1 * 100000000 + month1 * 1000000 + day1 * 10000 + 1;
	fp_number = fopen("./number.txt", "a+");
	rewind(fp_number);
	long long a = number2;
	fscanf_s(fp_number, "%lld", &a);
	fclose(fp_number);
	fp_number = fopen("./number.txt", "w+");
	fprintf(fp_number, "%lld", a + 1);
	fclose(fp_number);
	return a;
}
void search(long long k)
{
	int a = 0;//��Ʒ����
	long long b = 0;//��Ʒ����
	int c = 0, plasticbag = 0;
	double i;
	char name[20];
	bool flag = false;
	double arr[2] = { 0 };
	fp_odd = fopen("./odd.txt", "a+");
	rewind(fp_odd);
	do {
		fscanf_s(fp_odd, "����:%lld\t", &b);
		fscanf_s(fp_odd, "���Ѷ�:%lf\t", &i);
		fscanf_s(fp_odd, "��Ʒ����:%d\t", &a);
		if (b == k)
		{
			printf("����:%lld\n", k);
			printf("���Ѷ�:%.2f\n", i);
		}
		for (int i = 0; i < a; i++)
		{
			fscanf_s(fp_odd, "��Ʒ����:%d\t��Ʒ����:%s\t�۸�:%lf\t����:%lf\t���ϴ�����:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
			if (b == k)
			{
				flag = true;
				printf("��Ʒ����:%d\n", c);
				printf("��Ʒ����:%s\n", name);
				printf("�۸�:%.2lf\n", arr[0]);
				printf("����:%.2lf\n", arr[1]);
				printf("���ϴ�����:%d\n", plasticbag);
			}
		}
	} while (b != k && feof(fp_odd) == 0);
	if (!flag)
	{
		printf("δ֪���ţ�");
	}
	fclose(fp_odd);
	_getch();
	return;
}
void rewrite(const struct goodsbuying* head, long long number1)
{
	int a = 0;
	char file[20] = { 0 };
	struct goodsbuying* g = head->next;
	fp_numberwrite = fopen("./numberwrite.txt", "a+");
	if (fp_numberwrite == (FILE*)0)
	{
		printf("�ļ���ʧ��!");
		exit(0);
	}

	fseek(fp_numberwrite, 0, SEEK_END);
	while (g != NULL)
	{
		a = a + 1;
		g = g->next;
	}
	fprintf(fp_numberwrite, "����:%lld\t", number1);
	fclose(fp_numberwrite);
	return;
}
void timeclear()
{
	long long number25;
	struct date time = timeset();
	long long newtime = time.year * 10000 + time.month * 100 + time.day;
	if (fopen("number.txt", "a+") == NULL)
		fclose(fp_number);

	fp_number = fopen("number.txt", "a+");
	fscanf_s(fp_number, "%lld", &number25);
	number25 = number25 / 10000;
	if (number25 == newtime)
	{
		return;
	}

	else
	{
		clear(fp_number, "number.txt");
		fclose(fp_time);
		fp_number = fopen("./number.txt", "w+");
		fprintf(fp_time, "%d��", time.year);
		fprintf(fp_time, "%d��", time.month);
		fprintf(fp_time, "%d��", time.day);
		fclose(fp_time);
		return;
	}
}
void clear(FILE* fp, const char* filename)
{
	if (fopen(filename, "a+") == NULL)
		fclose(fp);
	fp = fopen(filename, "w+");
	fprintf(fp, "");
	fclose(fp);
}
void recharge(FILE* fp, struct goodsbuying* head1, struct Member* abs)
{
	struct Member* p = abs->next;
	char phonenum[15] = { 0 };
	if (fopen("��Ա��Ϣ.txt", "a+") == NULL)
		fclose(fp);

	fopen("��Ա��Ϣ.txt", "a+");

	printf("�������Ա�绰����:");
	int g = scanf_s("%s", phonenum, 15);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%s", &phonenum, 15);
	}
	while (p != NULL)
	{
		if (strcmp(p->m_phone, phonenum) == 0)
		{
			int money;
			printf("��������Ҫ��ֵ�Ľ��:");
			int g = scanf_s("%d", &money);
			while (g != 1)
			{
				scanf_s("%*[^\n]%*c");
				printf("�������룬���������룡");
				g = scanf_s("%d", &money);
			}
			p->m_balance = p->m_balance + money;
			saveMember(abs);
			printf("��ֵ�ɹ�!");
			printf("\n");
			find(p);
			_getch();
			return;
		}

		if (p->next == NULL && strcmp(p->m_phone, phonenum) != 0)
		{
			printf("�޴˻�Ա��Ϣ,�������ص���һ����");
			_getch();
			return;
		}
		p = p->next;
	}
	printf("�޴˻�Ա��Ϣ,�������ص���һ����");
	_getch();
	return;
}
void clearall()
{
	printf("!!!  W  A  R  N  I  N  G  !!!\n");
	printf("  ����һ������޷��ָ�!\n");
	printf("������ 5 �ٴ�ȷ���������\n");
	printf("\n");
	printf("���������������ַ�����һ����\n");
	int i;
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &i);
	}
	if (i == 5)
	{
		clear(fp_odd, "odd.txt");
		clear(fp_number, "number.txt");
		clear(fp_numberwrite, "numberwrite.txt");
		printf("�������������!\n");
		system("pause");
		return;
	}
	else
		return;
}

Goods* goods_buying(Goods* head, FILE* fp, goodsbuying* head1, struct Member* abs) {
	char name[20] = { 0 };
	struct goodsbuying* s = (goodsbuying*)malloc(sizeof(goodsbuying));
	struct goodsbuying* r = head1->next;
	if (s == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�");
		return NULL;
	}

	int x, i;
	Goods* p;
	bool flag = false;
	p = head->next;
	printf_s("1.����Ų�����Ʒ\n");
	printf_s("2.�����Ʋ�����Ʒ\n");
	printf_s("0.������һ����\n");
	printf("\n");
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &i);
	}
	if (i == 0)
	{
		shop_system(fp, head1, abs, head);
		return NULL;
	}
	if (i != 0 && i != 1 && i != 2)
	{
		goods_buying(head, fp, head1, abs);
		return NULL;
	}
	if (i == 2)
	{
		char name[20] = { 0 };
		printf_s("\n");
		printf_s("��������Ҫ��ѯ����Ʒ����:");
		printf("\n");
		int g = scanf_s("%s", &name, 20);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			g = scanf_s("%s", &name, 20);
		}
		while (p != NULL)
		{
			if (strcmp(p->name, name) == 0)
			{
				double i;
				flag = true;
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf("\n");
				printf("����������Ҫˮ����������(ÿ500g)");
				printf("\n");
				int g = scanf_s("%lf", &i);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("�������룬���������룡");
					g = scanf_s("%d", &i);
				}
				if (i > p->good_amount)
					printf("��Ʒ���㣬���������빺������!");
				printf("\n");
				if (i <= 0)
					printf("�������룬����������!");
				printf("\n");
				if (i > 0 && i <= p->good_amount) {
					for (r = head1->next; r != NULL; r = r->next)
					{
						if (strcmp(r->name, name) == 0)
						{
							r->good_amount = r->good_amount + i;
							printf("����ɹ���");
							printf("\n");
							p->good_amount = p->good_amount - i;
							if (fopen("goods.txt", "a+") == NULL)
								fclose(fp);

							write_goodsfile(head);

							_getch();
							shop_system(fp, head1, abs, head);
							return NULL;
						}
					}

					s->good_id = p->good_id;
					strcpy_s(s->name, 20, p->name);
					s->price = p->price;
					s->good_amount = i;
					p->good_amount = p->good_amount - s->good_amount;
					s->next = head1->next;
					head1->next = s;
					if (fopen("goods.txt", "a+") == NULL)
						fclose(fp);
					write_goodsfile(head);
					printf("����ɹ���");
					printf("\n");
				}
			}
			p = p->next;
		}
		if (!flag)
			printf_s("�޸���Ʒ��Ϣ��");
		printf("\n");


		_getch();

		shop_system(fp, head1, abs, head);
		return NULL;
	}

	if (i == 1)
	{
		printf_s("\n");
		printf_s("��������Ҫ��ѯ����Ʒ��ţ�");
		printf("\n");
		int g = scanf_s("%d", &x);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			g = scanf_s("%d", &x);
		}
		while (p != NULL)
		{
			if (p->good_id == x)
			{
				double i;
				flag = true;
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf("\n");
				printf("����������Ҫˮ����������(ÿ500g)");
				printf("\n");
				int g = scanf_s("%lf", &i);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("�������룬���������룡");
					g = scanf_s("%lf", &i);
				}

				if (i > p->good_amount)
				{
					printf("��Ʒ���㣬���������빺������!");
					printf("\n");
				}
				else if (i <= 0)
				{
					printf("�������룬����������!");
					printf("\n");
				}
				if (i > 0 && i <= p->good_amount)
				{
					for (r = head1->next; r != NULL; r = r->next)
					{
						if (r->good_id == x)
						{
							r->good_amount = r->good_amount + i;
							printf("����ɹ���");
							printf("\n");
							p->good_amount = p->good_amount - i;
							if (fopen("goods.txt", "a+") == NULL)
								fclose(fp);
							write_goodsfile(head);

							_getch();
							shop_system(fp, head1, abs, head);
							return NULL;
						}
					}

					s->good_id = p->good_id;
					strcpy_s(s->name, 20, p->name);
					s->price = p->price;
					s->good_amount = i;
					p->good_amount = p->good_amount - s->good_amount;
					s->next = head1->next;
					head1->next = s;
					if (fopen("goods.txt", "a+") == NULL)
						fclose(fp);
					write_goodsfile(head);
					printf("����ɹ���");
					printf("\n");
				}
			}
			p = p->next;
		}
		if (!flag)
			printf_s("�޸���Ʒ��Ϣ��");
		printf("\n");


		_getch();
		shop_system(fp, head1, abs, head);
		return NULL;
	}
}
void delete123(FILE* fp, goodsbuying* head1, struct Member* abs, Goods* head)
{
	int i;
	struct goodsbuying* d = head1->next;
	struct goods* p = head->next;
	system("cls");
	printf("1.�����ɾ����Ʒ\n");
	printf("2.������ɾ����Ʒ\n");
	printf("0.������һ����  \n");
	printf("\n");
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("�������룬���������룡");
		g = scanf_s("%d", &i);
	}
	if (i == 0)
	{
		shop_system(fp, head1, abs, head);
		return;
	}
	if (i == 1)
	{
		int a;
		printf("��������Ҫɾ����Ʒ�����:\n");
		printf("\n");
		int y = scanf_s("%d", &a);
		while (y != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			y = scanf_s("%d", &a);
		}
		if (a <= 0)
		{
			printf("�����������������!");
			printf("\n");
		}
		while (a > 0)
		{
			bool bb = false;
			for (d = head1->next; d != NULL; d = d->next)
			{
				if (a == d->good_id)
				{
					bb = true;
					double n;
					printf("��Ʒ����            ��Ʒ����            ��Ʒ�۸�            ��Ʒ����\n");
					printf("%-20d%-20s%-20.2lf%-20.2lf\n", d->good_id, d->name, d->price, d->good_amount);
					printf("��������Ҫɾ������Ŀ:");
					printf("\n");
					int g = scanf_s("%lf", &n);
					while (g != 1)
					{
						scanf_s("%*[^\n]%*c");
						printf("�������룬���������룡");
						g = scanf_s("%lf", &n);
					}
					if (n < 0)
					{
						printf("�������룬����������!");
						printf("\n");
						_getch();
						return;
					}
					if (n >= 0 && n <= d->good_amount)
					{
						d->good_amount = d->good_amount - n;
						for (p = head->next; p->next != NULL; p = p->next)
						{
							if (p->good_id == a)
							{
								p->good_amount = p->good_amount + n;
								if (fopen("goods.txt", "a+") == NULL)
									fclose(fp);
								write_goodsfile(head);
								break;
							}
						}

						printf("ɾ���ɹ���");
						printf("\n");
						_getch();
						delete123(fp, head1, abs, head);
						return;
					}
					if (n > d->good_amount)
					{
						printf("������С�ڹ�����Ŀ��ɾ��������");
						printf("\n");
						_getch();
						return;
					}
					if (n = d->good_amount)
					{
						struct goodsbuying* pmove;
						for (pmove = head1; pmove->next->good_id == a; pmove->next != NULL)
						{
							struct goodsbuying* temp = pmove->next;
							pmove->next = pmove->next->next;
							free(temp);
						}
						for (p = head->next; p->good_id == a; p = p->next)
						{
							p->good_amount = p->good_amount + n;
							if (fopen("goods.txt", "a+") == NULL)
								fclose(fp);
							write_goodsfile(head);

						}
						printf("ɾ���ɹ���");
						printf("\n");
						_getch();
						shop_system(fp, head1, abs, head);
						return;
					}
				}

			}
			if (bb == false)
			{
				printf("���ﳵ�޴���Ʒ");
				_getch();
				return;
			}
		}
	}
	if (i == 2)
	{
		char name[20] = { 0 };
		printf("��������Ҫɾ����Ʒ������:\n");
		bool bbb = false;
		int g = scanf_s("%s", &name, 20);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("�������룬���������룡");
			g = scanf_s("%s", &name, 20);
		}
		for (d = head1->next; d != NULL; d = d->next)
		{
			if (strcmp(name, d->name) == 0)
			{
				bbb = true;
				double n;
				printf("��Ʒ����            ��Ʒ����            ��Ʒ�۸�            ��Ʒ����\n");
				printf("%-20d%-20s%-20.2lf%-20.2lf\n", d->good_id, d->name, d->price, d->good_amount);
				printf("��������Ҫɾ������Ŀ:");

				printf("\n");
				int g = scanf_s("%lf", &n);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("�������룬���������룡");
					g = scanf_s("%lf", &n);
				}

				if (n < 0)
				{
					printf("�������룬����������!");
					printf("\n");
					return;
				}
				if (n >= 0 && n < d->good_amount)
				{
					d->good_amount = d->good_amount - n;

					for (p = head->next; p->next != NULL; p = p->next)
					{
						if (strcmp(p->name, name) == 0)
						{
							p->good_amount = p->good_amount + n;
							if (fopen("goods.txt", "a+") == NULL)
								fclose(fp);
							write_goodsfile(head);
							printf("ɾ���ɹ���");
							_getch();
							shop_system(fp, head1, abs, head);
							return;

						}
					}

				}
				if (n > d->good_amount)
				{
					printf("������С�ڹ�����Ŀ��ɾ��������");
					printf("\n");
					_getch();
					return;
				}
				if (n = d->good_amount)
				{
					struct goodsbuying* pmove;
					if (pmove == NULL)
						return;
					for (pmove = head1; strcmp(pmove->next->name, d->name) == 0; pmove->next != NULL)
					{
						struct goodsbuying* temp = pmove->next;
						pmove->next = pmove->next->next;
						free(temp);
					}
					printf("ɾ���ɹ���");
					printf("\n");
					_getch();
					shop_system(fp, head1, abs, head);
					return;
				}
			}
		}
		if (bbb == false)
		{
			printf("���ﳵ�޴���Ʒ");
			_getch();
			return;
		}
	}
	if (i != 1 && i != 2 && i != 0)
	{
		printf("�����������������!");
		printf("\n");
		_getch();
		delete123(fp, head1, abs, head);
		return;
	}

}
void shopback(struct goodsbuying* head1, Goods* head, FILE* fp)
{
	struct goodsbuying* p1;
	Goods* p2;
	for (p1 = head1->next; p1 != NULL; p1 = p1->next)
	{
		for (p2 = head->next; p2 != NULL; p2 = p2->next)
		{
			if (p1->good_id == p2->good_id)
			{
				p2->good_amount = p1->good_amount + p2->good_amount;
			}
		}

	}
	if (fopen("goods.txt", "a+") == NULL)
		fclose(fp);
	write_goodsfile(head);
	return;
}
void clearclain(goodsbuying* head1) {
	struct goodsbuying* p, * q1, * q2;
	p = head1;
	q1 = p->next;
	if (q1 == NULL) return;
	q2 = q1->next;
	while (q1->next) {
		free(q1);
		q1 = q2;
		q2 = q2->next;
	}
	return;
}

void bag(Goods* head, FILE* fp)
{
	struct goods* p = head->next;
	p->good_amount = p->good_amount - 1;
	if (fopen("goods.txt", "a+") == NULL)
		fclose(fp);

	write_goodsfile(head);
}
void find(struct Member* ret) {
	printf("������%s  \t", ret->m_name);
	printf("�Ա�%s  \t", ret->m_sex);
	printf("���գ�%s  \t", ret->m_birth);
	printf("��%.2f  \t", ret->m_balance);
	printf("�绰��%s  \n", ret->m_phone);
}