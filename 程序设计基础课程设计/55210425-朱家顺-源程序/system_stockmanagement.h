#pragma once
#ifndef SYSTEM_STOCKMANAGEMENT_H
#define SYSTEM_STOCKMANAGEMENT_H
#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"system_date.h"
#include"system_checkstand.h"
#pragma warning(disable:4996)


#define stock_warning 100
#define time_warning 7
typedef struct goods {
	int good_id;            //商品代号
	char name[99] = { 0 };          //商品名称
	int good_grade;         //商品等级
	double in_price;              //进货价格
	double price;           //商品价格 
	double good_amount;        //商品数量
	Date in_time;           //出厂时间
	int quality_time;       //保质时长
	struct goods* next;
} Goods;
void menu_stockmanagement();
int judge_time(Goods* head, Date today_time);//判断商品是否过期
int judge_stock(Goods* head);//判断商品库存是否小于库存预警值
void time_head();//打印临保商品表头
void time_print1(Goods* p, Date today);//打印临保商品信息
void time_print2(Goods* p);//打印过期商品信息
void remind_time(Goods* head);
void stock_head();//打印库存不足商品表头
void stock_print(Goods* p);//打印库存不足商品信息
void remind_stock(Goods* head);//库存不足提醒功能
void goods_head();//打印商品信息表头
void goods_message(Goods* p);//打印商品信息
void goods_messageshow(Goods* head);//显示商品信息
Goods* goods_messagesearch(Goods* head);//查找商品信息
Goods* read_goodsfile(FILE* fp);//读商品文件
void write_goodsfile(Goods* head);//写商品文件
Goods* goods_in(Goods* head);//添加商品信息
Goods* goods_edit(Goods* head);//修改商品信息
Goods* goods_delete(Goods* head);//删除商品信息
void Destory(Goods* head);//销毁链表
Goods* goods_buying(Goods* head, FILE* fp, struct goodsbuying* head1, struct Member* abs);
void delete123(FILE* fp, goodsbuying* head1, struct Member* abs);
Goods* edit_name(Goods* head);
void price_com(Goods* head);
#endif
