#include<iostream>
#include"Date.h"
#include<time.h>
#include "stdafx.h"
#include<string>
using namespace std;


Date::Date()
{
	/*int p = rand()*rand();*/
	char charYear[128];
	char charMonth[128];
	char charDay[128];
	/*itoa(p, temp, 10);*/
	/*ID = string(temp);*/

	int intYear, intMonth, intDay;

	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	intYear = t_tm->tm_year+1900;
	intMonth = t_tm->tm_mon + 1;
	intDay = t_tm->tm_mday;

	itoa(intYear, charYear, 10);
	year = string(charYear);
	itoa(intMonth, charMonth, 10);
	month = string(charMonth);
	itoa(intDay, charDay, 10);
	day = string(charDay);
}

void Date::ShowDate()
{
	cout << "×¢²áÈÕÆÚ:" << endl;
	cout << year << "." << month << "." << day << endl;
	
}

//bool Date::ChechBirthday()
//{
//	time_t timer;
//	time(&timer);
//	tm* t_tm = localtime(&timer);
//	if (t_tm->tm_mon + 1 == month)
//		return true;
//	else
//		return false;
//}
