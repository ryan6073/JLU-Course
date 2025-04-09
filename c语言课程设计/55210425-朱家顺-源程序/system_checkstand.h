#pragma once
#ifndef SYSTEM_QIANTAI_H
#define SYSTEM_QIANTAI_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<malloc.h>
#include<time.h>
#include<conio.h>
#include"system_stockmanagement.h"
struct goodsbuying
{
	int good_id;            //商品代号
	char name[20] = { 0 };          //商品名称
	double price;           //商品价格
	double good_amount;     //商品数量
	struct goodsbuying* next;
};
typedef struct goods Goods;
struct goodsbuying* creat();
struct date timeset();
int menu_shop(FILE* fp,struct goodsbuying* head1,struct Member* abs, Goods* head);
void shop_system(FILE* fp, struct goodsbuying* head1, struct Member* abs,  Goods* head);
void bill_system(FILE* fp,struct goodsbuying* head1, struct Member* abs,  Goods* head);
void shopsearch_system(FILE* fp,struct goodsbuying* head1, struct Member* abs,  Goods* head);
void print(const struct goodsbuying* head1, FILE* fp);
void showMenu_Member();
void research();
double billrealize(struct goodsbuying* head1,FILE* fp);
void goods_head();
void write(const struct goodsbuying* head1,long long number1, double i);
long long number();
void search(long long k);
void membership(double i,FILE *fp,struct goodsbuying* head1, struct Member* abs, long long number1,  Goods* head);
void account1(double i,FILE* fp, struct goodsbuying* head1, struct Member* abs, long long number1,  Goods* head);
void account2(double i,FILE* fp, struct goodsbuying* head1, struct Member* abs, long long number1,  Goods* head);
void destruction(FILE* fp,struct goodsbuying* head1, struct Member* abs,Goods* head);
void rewrite(const struct goodsbuying* head, long long number1);
void timeclear();
void clear(FILE* fp, const char* filename);
void recharge(FILE* fp, struct goodsbuying* head1, struct Member* abs);
void clearall();
Goods* goods_buying(Goods* head, FILE* fp, struct goodsbuying* head1, struct Member* abs);
void delete123(FILE* fp, goodsbuying* head1, struct Member* abs, Goods* head);
void shopback(struct goodsbuying* head1, Goods* head, FILE* fp);
void clearclain(goodsbuying* head1);
void bag(Goods* head,FILE* fp);
void find(struct Member* ret);
#endif



