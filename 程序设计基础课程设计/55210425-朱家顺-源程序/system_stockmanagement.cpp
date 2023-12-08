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
	printf("*****        1、显示商品信息         *****\n");
	printf("*****        2、查询商品信息         *****\n");
	printf("*****        3、添加商品信息         *****\n");
	printf("*****        4、删除商品信息         *****\n");
	printf("*****        5、修改商品信息         *****\n");
	printf("*****        6、临保商品信息         *****\n");
	printf("*****        7、库存不足提醒         *****\n");
	printf("*****        8、商品价格比较         *****\n");
	printf("*****        0、保存并退出           *****\n");
	printf("*****                                *****\n");
	printf("******************************************\n");
}

struct date time()//系统时间
{
	time_t t = time(0);
	struct tm* local = localtime(&t);
	struct date date;
	date.year = local->tm_year + 1900;
	date.month = local->tm_mon + 1;
	date.day = local->tm_mday;
	return date;
};

//判断商品是否过期
int judge_time(Goods* head, Date today_time) {
	Goods* p;
	p = head;
	if (date_minus(p->in_time, today_time) < p->quality_time) {
		if (p->quality_time - date_minus(p->in_time, today_time) > time_warning)
			return 0;//未过期且不为临保
		else return 1;//未过期但为临保商品
	}
	else return 2;//已过期
}

//判断商品库存是否小于库存预警值
int judge_stock(Goods* head) {
	Goods* p;
	p = head;
	if (p->good_amount >= stock_warning)
		return 0;//库存不小于预警值
	else return 1;//库存小于预警值
}
//打印临保商品表头
void time_head() {
	printf_s("商品序号     商品名称          商品等级     出厂日期     临保时间（天）");
}

//打印临保商品信息
void time_print1(Goods* p, Date today) {
	printf_s("%-12d %-17s %-12d %d.%d.%-5d %d", p->good_id, p->name, p->good_grade, p->in_time.year, p->in_time.month, p->in_time.day, (p->quality_time) - date_minus(p->in_time, today));
}

//打印过期商品信息
void time_print2(Goods* p) {
	printf_s("%-12d %-17s %-12d %d.%d.%-5d 已过期", p->good_id, p->name, p->good_grade, p->in_time.year, p->in_time.month, p->in_time.day);
}

//临保商品提醒功能
void remind_time(Goods* head) {
	struct date local_time = time();
	Goods* p;
	int choice, flag = 1, a = 0;
	p = head->next;
	system("cls");
	printf_s("1.查询已过期商品信息。      2.查询临保商品信息\n");
	printf("\n");
	printf_s("请选择您的需求：");
	scanf_s("%d", &choice);//考虑用户输入错误格式的情况！！！！！
	while (flag == 1) {
		if (choice != 1 && choice != 2) {
			printf_s("选择有误，请重新选择。\n");
			scanf_s("%d", &choice);
		}
		else flag = 0;
	}
	system("cls");
	if (choice == 2) {
		if (p == NULL)
			printf_s("无商品信息。\n");
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
				printf_s("无临保商品。\n");
			printf("=================显示成功=================\n");
		}
	}
	else {
		if (p == NULL)
			printf_s("无商品信息。\n");
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
				printf_s("无过期商品。\n");
			printf("=================显示成功=================\n");
		}
	}
	system("pause");
	system("cls");
}

//打印库存不足商品表头
void stock_head() {
	printf_s("商品序号     商品名称          商品等级     剩余库存（斤）");
}

//打印库存不足商品信息
void stock_print(Goods* p) {
	printf_s("%-12d %-17s %-12d %.2f", p->good_id, p->name, p->good_grade, p->good_amount);
}

//库存不足提醒功能
void remind_stock(Goods* head) {
	Goods* p;
	p = head->next;
	system("cls");
	if (p == NULL)
		printf_s("无商品库存不足。");
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
		printf("=================显示成功=================\n");
	}
	system("pause");
	system("cls");
}

//打印商品信息表头
void goods_head() {
	printf_s("商品序号     商品名称          商品等级     进货价格(元/斤）    销售价格(元/斤）     商品数量（斤）     出厂日期     保质期（天）");
}

//打印商品信息
void goods_message(Goods* p) {
	printf_s("%-12d %-17s %-12d %-20.2f %-19.2f %-18.2f %d.%d.%-7d %-3d", p->good_id, p->name, p->good_grade, p->in_price, p->price, p->good_amount, p->in_time.year, p->in_time.month, p->in_time.day, p->quality_time);
}

//显示商品信息
void goods_messageshow(Goods* head) {
	system("cls");
	Goods* p;
	p = head->next;
	if (p == NULL)
		printf_s("无商品信息。\n");
	else {
		goods_head();
		printf_s("\n");
		while (p != NULL) {
			goods_message(p);
			printf("\n");
			p = p->next;
		}
		printf("\n");
		printf("=================显示成功=================\n");
	}
	system("pause");
	system("cls");
	return;
}

//查找商品信息
Goods* goods_messagesearch(Goods* head) {
	int choice, flag = 1;
	char name[20] = { 0 }, button[20] = { 0 };
	Goods* p;
	p = head->next;
	printf_s("0.退出\n");
	printf_s("1.按序号查询商品\n");
	printf_s("2.按名称查询商品\n");
	printf_s("\n");
	printf_s("请选择您的需求：\n");
	int judge = scanf("%d", &choice);
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
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf_s("\n");
				printf("=================显示成功=================\n");
				system("pause");
				system("cls");
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
				goods_head();
				printf_s("\n");
				goods_message(p);
				printf_s("\n");
				printf("=================显示成功=================\n");
				system("pause");
				system("cls");
				return p;
			}
			p = p->next;
		}
		printf_s("无该商品信息。\n");
		break;
	}
	}
	system("pause");
	system("cls");
	return NULL;
}

//读商品文件
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
		//输入商品的相关信息
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

//写商品文件
void write_goodsfile(Goods* head) {
	FILE* fp;
	Goods* p;
	p = head->next;
	if ((fp = fopen("goods.txt", "w")) == NULL) {
		printf("无法打开数据文件！\n");
		return;
	}
	while (p != NULL) {
		fprintf(fp, "%d %s %d %.2f %.2f %.2f %d %d %d %d\n", p->good_id, p->name, p->good_grade,
			p->in_price, p->price, p->good_amount, p->in_time.year, p->in_time.month, p->in_time.day, p->quality_time);
		p = p->next;
	}
	fclose(fp);
}

//添加商品信息
Goods* goods_in(Goods* head) {
	Goods* p, * q = head->next;
	int a = 0, key;
	p = head->next;
	while (q->next != NULL) {
		q = q->next;
	}
	printf("请输入需要添加的商品信息数量：\n");
	scanf("%d", &key);
	printf("请输入商品信息：\n");
	printf("商品序号     商品名称     商品等级     进货价格(元/斤）     销售价格(元/斤）     商品数量（斤）     出厂日期     保质期（天）\n");
	while (a < key) {
		p = (Goods*)malloc(sizeof(Goods));
		scanf("%d%s%d%lf%lf%lf%d%d%d%d", &p->good_id, p->name, &p->good_grade, &p->in_price, &p->price, &p->good_amount,
			&p->in_time.year, &p->in_time.month, &p->in_time.day, &p->quality_time);
		q->next = p;
		q = p;
		q->next = NULL;
		a++;
	}
	printf("=================添加成功=================\n");
	system("pause");
	system("cls");
	return head;
}

//修改商品信息
Goods* goods_edit(Goods* head) {
	Goods* p;
	int i;
	p = head;
	p = goods_messagesearch(p);

	if (p == NULL) {
		//printf("无商品记录！\n");
		return head;
	}
	else {
		printf("1.商品序号\n");
		printf("2.商品名称\n");
		printf("3.商品等级\n");
		printf("4.进货价格\n");
		printf("5.销售价格\n");
		printf("6.商品数量\n");
		printf("7.出厂日期\n");
		printf("8.商品保质期\n");
		printf("请选择您需要修改的商品数据：\n");
		scanf("%d", &i);
		switch (i) {
		case 1: {printf("请输入新的商品序号：\n"); scanf("%d", &p->good_id); }; break;
		case 2: {printf("请输入新的商品名称：\n"); scanf("%s", p->name); }; break;
		case 3: {printf("请输入新的商品等级：\n"); scanf("%d", &p->good_grade); }break;
		case 4: {printf("请输入新的商品进货价格：\n"); scanf("%lf", &p->in_price); }break;
		case 5: {printf("请输入新的商品销售价格：\n"); scanf("%lf", &p->price); }break;
		case 6: {printf("请输入新的商品数量：\n"); scanf("%lf", &p->good_amount); }break;
		case 7: {printf("请输入新的商品入库日期：\n"); scanf("%d%d%d", &p->in_time.year, &p->in_time.month, &p->in_time.day); }break;
		case 8: {printf("请输入新的商品保质期：\n"); scanf("%d", &p->quality_time); }break;
		}
		system("cls");
		goods_head();
		printf("\n");
		goods_message(p);
		printf("\n=================修改成功=================\n");
	}
	system("pause");
	system("cls");
	return head;
}


//删除商品信息
Goods* goods_delete(Goods* head) {
	Goods* p, * q;
	p = head;
	p = goods_messagesearch(p);
	q = head;
	while ((q->next != p) && (q->next != NULL))
		q = q->next;
	if (q->next == NULL)
		return head;//printf("无商品记录！\n");
	else {
		q->next = p->next;
	}
	free(p);
	printf("=================删除成功=================\n");
	system("pause");
	system("cls");
	return head;
}

//添加"促销"
Goods* edit_name(Goods* head) {
	int r;
	Goods* p = head->next;
	int a;
	struct date local_time = time();
	char b[20] = { "(促销)" };
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

//商品价格比较
void price_com(Goods* head2){
	Goods* p = head2->next;
	int i = 0;
	char a[20]={0};
	printf("请输入您需要查询的商品名称：\n");
	scanf("%s", a);
	while ((p != NULL) && (strcmp(a, p->name) != 0))p = p->next;
	system("cls");
	if (p == NULL) printf("无商品记录！");
	else {
		printf("商品名称         进货价格（斤/元）    销售价格（斤/元）\n");
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
