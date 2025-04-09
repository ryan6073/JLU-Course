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
	int good_id;            //��Ʒ����
	char name[99] = { 0 };          //��Ʒ����
	int good_grade;         //��Ʒ�ȼ�
	double in_price;              //�����۸�
	double price;           //��Ʒ�۸� 
	double good_amount;        //��Ʒ����
	Date in_time;           //����ʱ��
	int quality_time;       //����ʱ��
	struct goods* next;
} Goods;
void menu_stockmanagement();
int judge_time(Goods* head, Date today_time);//�ж���Ʒ�Ƿ����
int judge_stock(Goods* head);//�ж���Ʒ����Ƿ�С�ڿ��Ԥ��ֵ
void time_head();//��ӡ�ٱ���Ʒ��ͷ
void time_print1(Goods* p, Date today);//��ӡ�ٱ���Ʒ��Ϣ
void time_print2(Goods* p);//��ӡ������Ʒ��Ϣ
void remind_time(Goods* head);
void stock_head();//��ӡ��治����Ʒ��ͷ
void stock_print(Goods* p);//��ӡ��治����Ʒ��Ϣ
void remind_stock(Goods* head);//��治�����ѹ���
void goods_head();//��ӡ��Ʒ��Ϣ��ͷ
void goods_message(Goods* p);//��ӡ��Ʒ��Ϣ
void goods_messageshow(Goods* head);//��ʾ��Ʒ��Ϣ
Goods* goods_messagesearch(Goods* head);//������Ʒ��Ϣ
Goods* read_goodsfile(FILE* fp);//����Ʒ�ļ�
void write_goodsfile(Goods* head);//д��Ʒ�ļ�
Goods* goods_in(Goods* head);//�����Ʒ��Ϣ
Goods* goods_edit(Goods* head);//�޸���Ʒ��Ϣ
Goods* goods_delete(Goods* head);//ɾ����Ʒ��Ϣ
void Destory(Goods* head);//��������
Goods* goods_buying(Goods* head, FILE* fp, struct goodsbuying* head1, struct Member* abs);
void delete123(FILE* fp, goodsbuying* head1, struct Member* abs);
Goods* edit_name(Goods* head);
void price_com(Goods* head);
#endif
