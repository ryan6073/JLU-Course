#pragma once
#ifndef SYSTEM_DATE1_H
#define SYSTEM_DATE1_H
#include<stdio.h>
typedef struct date {
	int year;
	int month;
	int day;
}Date;
int leap_year(int year);
int date_minus(Date product_time, Date today_time);
#endif;

