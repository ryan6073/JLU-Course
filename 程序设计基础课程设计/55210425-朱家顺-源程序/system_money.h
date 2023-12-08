#pragma once
#ifndef SYSTEM_MONEY_H
#define SYSTEM_MONEY_H
#include<stdio.h>
#include<time.h>
#include"system_stockmanagement.h"
#include"system_checkstand.h"
void menu_moneymanagement();
void day_profit(Goods* head);
void print_head();
void print_daymessage(Goods* head);
struct date time1();
void print_monthmessage(Goods* head);
void month_profit(Goods* head);
void search_day(Goods* head);
void search_month(Goods* head);
Goods* messagesearch(Goods* head);
#endif