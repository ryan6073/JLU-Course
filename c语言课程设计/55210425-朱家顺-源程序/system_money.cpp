#include<stdio.h>
#include<time.h>
#include"system_stockmanagement.h"
#include"system_checkstand.h"
#include"system_date.h"

FILE* fpodd;

void menu_moneymanagement() {
	printf("******************************************\n");
	printf("*****                                *****\n");
	printf("*****        1、显示当日总盈亏       *****\n");
	printf("*****        2、查询商品日盈亏       *****\n");
	printf("*****        3、显示当月总盈亏       *****\n");
	printf("*****        4、查询商品月盈亏       *****\n");
	printf("*****        0、退出                 *****\n");
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

//打印商品盈亏表头
void print_head() {
	printf("商品代号     商品名称          销售额（元）          利润（元）");
}

//打印塑料袋日盈亏信息
void print_dayplastic(Goods* head) {
	struct date local_time = time1();
	int a = 0;//商品种类
	long long b = 0;//商品单号
	int plasticbag1 = 0;//塑料袋数量
	int c = 0;
	double i, profit = 0, sum = 0;
	char name[20];
	double arr[2] = { 0 };
	fpodd = fopen("./odd.txt", "a+");
	rewind(fpodd);
	do {
		fscanf_s(fpodd, "单号:%lld\t", &b);
		fscanf_s(fpodd, "消费额:%lf\t", &i);
		fscanf_s(fpodd, "商品种类:%d\t", &a);
		for (int m = 0; m < a; m++) {
			fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag1);
			if (b / 10000 == local_time.year * 10000 + local_time.month * 100 + local_time.day)
			{
				sum = sum + plasticbag1 * 0.1;
				profit = profit + plasticbag1 * 0.09;
			}
		}
	} while (feof(fpodd) == 0);
	printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
}

//打印商品日盈亏信息
void print_daymessage(Goods* head) {
	double sum0 = 0, profit0 = 0;
	while (head != NULL) {
		struct date local_time = time1();
		int a = 0;//商品种类
		int x = 0;
		long long b = 0;//商品单号
		int c = 0;
		int plasticbag = 0;//塑料袋数量
		double i, profit = 0, sum = 0;
		char name[20];
		double arr[2] = { 0 };
		fpodd = fopen("./odd.txt", "a+");
		rewind(fpodd);
		do {
			fscanf_s(fpodd, "单号:%lld\t", &b);
			fscanf_s(fpodd, "消费额:%lf\t", &i);
			fscanf_s(fpodd, "商品种类:%d\t", &a);
			for (int m = 0; m < a; m++) {
				fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
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
	printf("商品总销售额：%.2lf\n", sum0);
	printf("商品总盈亏：%.2lf\n", profit0);
}

//当日总盈亏
void day_profit(Goods* head) {
	Goods* p;
	p = head->next;
	print_head();
	printf("\n");
	print_dayplastic(p);
	p = p->next;
	print_daymessage(p);
	p = p->next;
	printf("=================显示成功=================\n");
	system("pause");
	system("cls");
}

//打印塑料袋月盈亏信息
void print_monthplastic(Goods* head) {
	struct date local_time = time1();
	int a = 0;//商品种类
	long long b = 0;//商品单号
	int plasticbag = 0;//塑料袋数量
	int c = 0;
	double i, profit = 0, sum = 0;
	char name[20];
	double arr[2] = { 0 };
	fpodd = fopen("./odd.txt", "a+");
	rewind(fpodd);
	do {
		fscanf_s(fpodd, "单号:%lld\t", &b);
		fscanf_s(fpodd, "消费额:%lf\t", &i);
		fscanf_s(fpodd, "商品种类:%d\t", &a);
		for (int m = 0; m < a; m++) {
			fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
			if (b / 1000000 == local_time.year * 100 + local_time.month)
			{
				sum = sum + plasticbag * 0.1;
				profit = profit + plasticbag * 0.09;
			}
		}
	} while (feof(fpodd) == 0);
	printf("%-13d%-18s%-22.2lf%.2lf\n", head->good_id, head->name, sum, profit);
}


//打印商品月盈亏信息
void print_monthmessage(Goods* head) {
	double sum0 = 0, profit0 = 0;
	while (head != NULL) {
		struct date local_time = time1();
		int a = 0;//商品种类
		int x = 0;
		long long b = 0;//商品单号
		int c = 0;
		int plasticbag = 0;//塑料袋数量
		double i, profit = 0, sum = 0;
		char name[20];
		double arr[2] = { 0 };
		fpodd = fopen("./odd.txt", "a+");
		rewind(fpodd);
		do {
			fscanf_s(fpodd, "单号:%lld\t", &b);
			fscanf_s(fpodd, "消费额:%lf\t", &i);
			fscanf_s(fpodd, "商品种类:%d\t", &a);
			for (int m = 0; m < a; m++) {
				fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
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
	printf("商品总销售额：%.2lf\n", sum0);
	printf("商品总盈亏：%.2lf\n", profit0);
}

//当月总盈亏
void month_profit(Goods* head) {
	Goods* p;
	p = head->next;
	print_head();
	printf("\n");
	print_monthplastic(p);
	p = p->next;
	print_monthmessage(p);
	p = p->next;
	printf("=================显示成功=================\n");
	system("pause");
	system("cls");
}

//查找商品
Goods* messagesearch(Goods* head) {
	int  choice, flag = 1;
	char name[20] = { 0 }, button[100] = { 0 };
	Goods* p;
	p = head->next;
	printf_s("1.按序号查询商品\n");
	printf_s("2.按名称查询商品\n");
	printf_s("\n");
	printf_s("请选择您的需求：\n");
	int judge = scanf_s("%d", &choice);
	printf_s("\n");
	while (flag == 1) {
		if (choice != 1 && choice != 2 && choice != 0) {
			printf_s("选择有误，请重新选择。\n");
			if (judge == 0) scanf("%s", button);
			judge = scanf("%d", &choice);
		}
		else flag = 0;
	}
	switch (choice) {
	case 0:break;
	case 1: {
		printf_s("请输入需要查询的商品序号：\n");
		int judge = scanf_s("%d", &choice);
		if (0 == judge) {
			printf("输入错误，请重新输入。\n");
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
		printf_s("无该商品信息。\n");
		break;
	}
	case 2: {
		printf_s("请输入需要查询的商品名称：\n");
		scanf_s("%s", name, 20);
		system("cls");
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				return p;
			}
			p = p->next;
		}
		printf_s("无该商品信息。\n");
	}
		  break;
	}
	system("cls");
	return NULL;
}

//查询商品日盈亏
void search_day(Goods* head) {
	Goods* p;
	p = messagesearch(head);
	if (p != NULL) {
		print_head();
		printf("\n");
		if (p->good_id != 1) {
			struct date local_time = time1();
			int a = 0;//商品种类
			long long b = 0;//商品单号
			int c = 0;
			int plasticbag = 0;//塑料袋数量
			double i, profit = 0, sum = 0;
			char name[20];
			double arr[2] = { 0 };
			fpodd = fopen("./odd.txt", "a+");
			rewind(fpodd);
			do {
				fscanf_s(fpodd, "单号:%lld\t", &b);
				fscanf_s(fpodd, "消费额:%lf\t", &i);
				fscanf_s(fpodd, "商品种类:%d\t", &a);
				for (int m = 0; m < a; m++) {
					fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
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
		printf("=================显示成功=================\n");
	}
	else printf("无该商品信息！\n");
	system("pause");
	system("cls");
}

//查询商品月盈亏
void search_month(Goods* head) {
	Goods* p;
	p = messagesearch(head);
	if (p != NULL) {
		print_head();
		printf("\n");
		if (p->good_id != 1) {
			struct date local_time = time1();
			int a = 0;//商品种类
			long long b = 0;//商品单号
			int c = 0;
			int plasticbag = 0;//塑料袋数量
			double i, profit = 0, sum = 0;
			char name[20];
			double arr[2] = { 0 };
			fpodd = fopen("./odd.txt", "a+");
			rewind(fpodd);
			do {
				fscanf_s(fpodd, "单号:%lld\t", &b);
				fscanf_s(fpodd, "消费额:%lf\t", &i);
				fscanf_s(fpodd, "商品种类:%d\t", &a);
				for (int m = 0; m < a; m++) {
					fscanf_s(fpodd, "商品货号:%d\t商品名称:%s\t价格:%lf\t数量:%lf\t塑料袋数量:%d\t", &c, &name, 20, &arr[0], &arr[1], &plasticbag);
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
		printf("=================显示成功=================\n");
	}
	else printf("无该商品信息！\n");
	system("pause");
	system("cls");
}