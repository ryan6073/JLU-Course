#pragma once
#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
public:

	Date();

	void ShowDate();

	/*bool ChechBirthday();*/

	string &ReturnDate() 
	{
		YearMonthDay = year + '.' + month + '.' + day;
		return YearMonthDay;
	}

	string &ReturnYear() { return year; }

	string &ReturnMonth() { return month; }

	string &ReturnDay() { return day; }

	

protected:

	string year, month, day;

private:

	string YearMonthDay;

};

#endif