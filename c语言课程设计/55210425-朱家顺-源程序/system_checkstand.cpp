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
		printf("分配内存失败！");
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
		printf("商品货号            商品名称            商品价格            商品数量\n");
		printf("%-20d%-20s%-20.2lf%-20.2lf", m->good_id, m->name, m->price, m->good_amount);
		m = m->next;
		printf("\n");
	}
	if (head1->next == NULL)
	{
		printf("无商品记录！");

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
		printf("**             1.商品购买            **\n");
		printf("**             2.购物结算            **\n");
		printf("**             3.会员充值            **\n");
		printf("**             4.购买记录查询        **\n");
		printf("**             5.清空所有记录        **\n");
		printf("**             0.退回上一界面        **\n");
		printf("***************************************\n");
		printf("\n");
		int a = -1;
		int g = scanf_s("%d", &a);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入");
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
			printf("错误输入，请重新输入！");
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
	printf("**        1.显示当前购物列表         **\n");
	printf("**        2.添加商品进入列表         **\n");
	printf("**        3.从列表中删除商品         **\n");
	printf("**        4.显示所有商品             **\n");
	printf("**        0.返回上一界面             **\n");
	printf("***************************************\n");
	printf("\n");
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
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
		printf("错误输入，请重新输入！");
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
	printf("**        1.会员支付                 **\n");
	printf("**        2.非会员支付               **\n");
	printf("***************************************\n");
	printf("请选择支付方式：");
	printf("\n");
	int a = 0;
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
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
		printf("错误输入，请重新输入！");
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
		printf("购物列表为空！");
		_getch();
	}
	if (head1->next != NULL)
	{
		double i;
		i = billrealize(head1, fp);
		long long number1 = number();
		timeclear();
		printf("***************************************\n");
		printf("**        1.需要                     **\n");
		printf("**        2.不需要                   **\n");
		printf("***************************************\n");
		printf("请选择是否需要购物袋：");
		printf("\n");
		int b;
		int g = scanf_s("%d", &b);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
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
			printf("错误输入，请重新输入！");
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
		printf("无任何会员信息,即将跳转到非会员支付界面");
		printf("\n");
		_getch();
		account2(i, fp, head1, abs, number1, head);
		return;
	}
	else
	{
		Head = Head->next;
		printf("***************************************\n");
		printf("**       请输入会员手机号码:         **\n");
		printf("***************************************\n");
		printf("\n");
		char phonenumber[15] = { 0 };
		int g = scanf_s("%s", &phonenumber, 15);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
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
				printf("**   一共消费：");
				printf("%13.2lf", i);
				printf("   元    **\n");
				printf("**     单号:");
				printf("%lld", number1);
				printf("             **\n");
				printf("***************************************\n");
				printf("\n");

				if (Head->m_balance < i)
				{
					printf_s("账户余额不足,还需支付%.2lf元\n", i - Head->m_balance);
					Head->m_balance = 0;
					saveMember(abs);

				}
				if (Head->m_balance >= i)
				{
					printf_s("已自动扣除账户金额，账户余额%.2lf元\n", Head->m_balance - i);
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
			printf("无任何会员信息!\n");
			printf("1.重新输入会员电话\n");
			printf("2.跳转到非会员支付界面\n");
			printf("\n");
			double g;
			int h = scanf_s("%lf", &g);
			while (h != 1)
			{
				scanf_s("%*[^\n]%*c");
				printf("错误输入，请重新输入！");
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
				printf("错误输入，请重新输入!");
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
	printf("**     一共消费：");
	printf("%10.2lf", i);
	printf("   元     **\n");
	printf("**      单号:");
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
	printf("**        1.进入查询界面	     **\n");
	printf("**        0.退回至上一界面	     **\n");
	printf("***************************************\n");
	printf("请选择您需要的服务:");
	printf("\n");
	int g = scanf_s("%d", &a);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
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
		printf("错误输入，请重新输入！");
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
	printf("*       请输入需要查询的单号:         *\n");
	printf("***************************************\n");
	printf("\n");
	int g = scanf_s("%lld", &k);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
		g = scanf_s("%lld", &k);
	}
	if (k <= 0)
	{
		printf("错误输入，请重新输入！\n");
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
		printf("文件打开失败!");
		exit(0);
	}

	fseek(fp_odd, 0, SEEK_END);
	while (g != NULL)
	{
		a = a + 1;
		g = g->next;
	}
	fprintf(fp_odd, "单号:%lld\t", number1);
	fprintf(fp_odd, "消费额:%.2lf\t", i);
	fprintf(fp_odd, "商品种类:%d\t", a);
	struct goodsbuying* p = head->next;
	while (p != NULL)
	{
		fprintf(fp_odd, "商品货号:%d\t", p->good_id);
		fprintf(fp_odd, "商品名称:%s\t", p->name);
		fprintf(fp_odd, "价格:%.2lf\t", p->price);
		fprintf(fp_odd, "数量:%.2lf\t", p->good_amount);
		fprintf(fp_odd, "塑料袋数量:%d\t", plasticbag);
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
	int a = 0;//商品种类
	long long b = 0;//商品单号
	int c = 0, plasticbag = 0;
	double i;
	char name[20];
	bool flag = false;
	double arr[2] = { 0 };
	fp_odd = fopen("./odd.txt", "a+");
	rewind(fp_odd);
	do {
		fscanf_s(fp_odd, "单号:%lld\t", &b);
		fscanf_s(fp_odd, "消费额:%lf\t", &i);
		fscanf_s(fp_odd, "商品种类:%d\t", &a);
		if (b == k)
		{
			printf("单号:%lld\n", k);
			printf("消费额:%.2f\n", i);
		}
		for (int i = 0; i < a; i++)
		{
			fscanf_s(fp_odd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
			if (b == k)
			{
				flag = true;
				printf("商品货号:%d\n", c);
				printf("商品名称:%s\n", name);
				printf("价格:%.2lf\n", arr[0]);
				printf("数量:%.2lf\n", arr[1]);
				printf("塑料袋数量:%d\n", plasticbag);
			}
		}
	} while (b != k && feof(fp_odd) == 0);
	if (!flag)
	{
		printf("未知单号！");
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
		printf("文件打开失败!");
		exit(0);
	}

	fseek(fp_numberwrite, 0, SEEK_END);
	while (g != NULL)
	{
		a = a + 1;
		g = g->next;
	}
	fprintf(fp_numberwrite, "单号:%lld\t", number1);
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
		fprintf(fp_time, "%d年", time.year);
		fprintf(fp_time, "%d月", time.month);
		fprintf(fp_time, "%d日", time.day);
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
	if (fopen("会员信息.txt", "a+") == NULL)
		fclose(fp);

	fopen("会员信息.txt", "a+");

	printf("请输入会员电话号码:");
	int g = scanf_s("%s", phonenum, 15);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
		g = scanf_s("%s", &phonenum, 15);
	}
	while (p != NULL)
	{
		if (strcmp(p->m_phone, phonenum) == 0)
		{
			int money;
			printf("请输入你要充值的金额:");
			int g = scanf_s("%d", &money);
			while (g != 1)
			{
				scanf_s("%*[^\n]%*c");
				printf("错误输入，请重新输入！");
				g = scanf_s("%d", &money);
			}
			p->m_balance = p->m_balance + money;
			saveMember(abs);
			printf("充值成功!");
			printf("\n");
			find(p);
			_getch();
			return;
		}

		if (p->next == NULL && strcmp(p->m_phone, phonenum) != 0)
		{
			printf("无此会员信息,即将返回到上一界面");
			_getch();
			return;
		}
		p = p->next;
	}
	printf("无此会员信息,即将返回到上一界面");
	_getch();
	return;
}
void clearall()
{
	printf("!!!  W  A  R  N  I  N  G  !!!\n");
	printf("  数据一经清除无法恢复!\n");
	printf("请输入 5 再次确认清除数据\n");
	printf("\n");
	printf("输入其他任意数字返回上一界面\n");
	int i;
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
		g = scanf_s("%d", &i);
	}
	if (i == 5)
	{
		clear(fp_odd, "odd.txt");
		clear(fp_number, "number.txt");
		clear(fp_numberwrite, "numberwrite.txt");
		printf("已清除所有数据!\n");
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
		printf("分配内存失败！");
		return NULL;
	}

	int x, i;
	Goods* p;
	bool flag = false;
	p = head->next;
	printf_s("1.按序号查找商品\n");
	printf_s("2.按名称查找商品\n");
	printf_s("0.返回上一界面\n");
	printf("\n");
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
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
		printf_s("请输入需要查询的商品名称:");
		printf("\n");
		int g = scanf_s("%s", &name, 20);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
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
				printf("请输入你需要水果的质量：(每500g)");
				printf("\n");
				int g = scanf_s("%lf", &i);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("错误输入，请重新输入！");
					g = scanf_s("%d", &i);
				}
				if (i > p->good_amount)
					printf("商品不足，请重新输入购买数量!");
				printf("\n");
				if (i <= 0)
					printf("错误输入，请重新输入!");
				printf("\n");
				if (i > 0 && i <= p->good_amount) {
					for (r = head1->next; r != NULL; r = r->next)
					{
						if (strcmp(r->name, name) == 0)
						{
							r->good_amount = r->good_amount + i;
							printf("购买成功！");
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
					printf("购买成功！");
					printf("\n");
				}
			}
			p = p->next;
		}
		if (!flag)
			printf_s("无该商品信息。");
		printf("\n");


		_getch();

		shop_system(fp, head1, abs, head);
		return NULL;
	}

	if (i == 1)
	{
		printf_s("\n");
		printf_s("请输入需要查询的商品序号：");
		printf("\n");
		int g = scanf_s("%d", &x);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
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
				printf("请输入你需要水果的质量：(每500g)");
				printf("\n");
				int g = scanf_s("%lf", &i);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("错误输入，请重新输入！");
					g = scanf_s("%lf", &i);
				}

				if (i > p->good_amount)
				{
					printf("商品不足，请重新输入购买数量!");
					printf("\n");
				}
				else if (i <= 0)
				{
					printf("错误输入，请重新输入!");
					printf("\n");
				}
				if (i > 0 && i <= p->good_amount)
				{
					for (r = head1->next; r != NULL; r = r->next)
					{
						if (r->good_id == x)
						{
							r->good_amount = r->good_amount + i;
							printf("购买成功！");
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
					printf("购买成功！");
					printf("\n");
				}
			}
			p = p->next;
		}
		if (!flag)
			printf_s("无该商品信息。");
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
	printf("1.按序号删除商品\n");
	printf("2.按名称删除商品\n");
	printf("0.返回上一界面  \n");
	printf("\n");
	int g = scanf_s("%d", &i);
	while (g != 1)
	{
		scanf_s("%*[^\n]%*c");
		printf("错误输入，请重新输入！");
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
		printf("请输入需要删除商品的序号:\n");
		printf("\n");
		int y = scanf_s("%d", &a);
		while (y != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
			y = scanf_s("%d", &a);
		}
		if (a <= 0)
		{
			printf("输入错误，请重新输入!");
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
					printf("商品货号            商品名称            商品价格            商品数量\n");
					printf("%-20d%-20s%-20.2lf%-20.2lf\n", d->good_id, d->name, d->price, d->good_amount);
					printf("请输入需要删除的数目:");
					printf("\n");
					int g = scanf_s("%lf", &n);
					while (g != 1)
					{
						scanf_s("%*[^\n]%*c");
						printf("错误输入，请重新输入！");
						g = scanf_s("%lf", &n);
					}
					if (n < 0)
					{
						printf("错误输入，请重新输入!");
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

						printf("删除成功！");
						printf("\n");
						_getch();
						delete123(fp, head1, abs, head);
						return;
					}
					if (n > d->good_amount)
					{
						printf("请输入小于购买数目的删除数量！");
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
						printf("删除成功！");
						printf("\n");
						_getch();
						shop_system(fp, head1, abs, head);
						return;
					}
				}

			}
			if (bb == false)
			{
				printf("购物车无此商品");
				_getch();
				return;
			}
		}
	}
	if (i == 2)
	{
		char name[20] = { 0 };
		printf("请输入需要删除商品的名称:\n");
		bool bbb = false;
		int g = scanf_s("%s", &name, 20);
		while (g != 1)
		{
			scanf_s("%*[^\n]%*c");
			printf("错误输入，请重新输入！");
			g = scanf_s("%s", &name, 20);
		}
		for (d = head1->next; d != NULL; d = d->next)
		{
			if (strcmp(name, d->name) == 0)
			{
				bbb = true;
				double n;
				printf("商品货号            商品名称            商品价格            商品数量\n");
				printf("%-20d%-20s%-20.2lf%-20.2lf\n", d->good_id, d->name, d->price, d->good_amount);
				printf("请输入需要删除的数目:");

				printf("\n");
				int g = scanf_s("%lf", &n);
				while (g != 1)
				{
					scanf_s("%*[^\n]%*c");
					printf("错误输入，请重新输入！");
					g = scanf_s("%lf", &n);
				}

				if (n < 0)
				{
					printf("错误输入，请重新输入!");
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
							printf("删除成功！");
							_getch();
							shop_system(fp, head1, abs, head);
							return;

						}
					}

				}
				if (n > d->good_amount)
				{
					printf("请输入小于购买数目的删除数量！");
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
					printf("删除成功！");
					printf("\n");
					_getch();
					shop_system(fp, head1, abs, head);
					return;
				}
			}
		}
		if (bbb == false)
		{
			printf("购物车无此商品");
			_getch();
			return;
		}
	}
	if (i != 1 && i != 2 && i != 0)
	{
		printf("输入错误，请重新输入!");
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
	printf("姓名：%s  \t", ret->m_name);
	printf("性别：%s  \t", ret->m_sex);
	printf("生日：%s  \t", ret->m_birth);
	printf("余额：%.2f  \t", ret->m_balance);
	printf("电话：%s  \n", ret->m_phone);
}