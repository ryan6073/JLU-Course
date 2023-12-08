#include "system_date.h"

int leap_year(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else return 0;
}
int date_minus(Date product_time, Date today_time) {
	int minus = 0, a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 }, i, j;
	if (product_time.year > today_time.year || product_time.year == today_time.year && product_time.month > today_time.month || product_time.year == today_time.year && product_time.month == today_time.month && product_time.day > today_time.day)
		return -1;
	else {
		if (product_time.year == today_time.year) {
			if (product_time.month == today_time.month) {
				minus = today_time.day - product_time.day;
			}
			else {
				if (leap_year(product_time.year) == 1) {
					minus = minus + b[product_time.month - 1] - product_time.day + today_time.day;
					for (i = product_time.month; i < today_time.month - 1; i++) {
						minus = minus + b[i];
					}
				}
				else {
					minus = minus + a[product_time.month - 1] - product_time.day + today_time.day;
					for (i = product_time.month; i < today_time.month - 1; i++) {
						minus = minus + a[i];
					}
				}
			}
		}
		else {
			if (leap_year(product_time.year) == 1) {
				minus = minus + b[product_time.month - 1] - product_time.day;
				for (i = product_time.month; i < 12; i++)
					minus = minus + b[i];
			}
			else {
				minus = minus + a[product_time.month - 1] - product_time.day;
				for (i = product_time.month; i < 12; i++)
					minus = minus + a[i];
			}
			if (leap_year(today_time.year) == 1) {
				minus = minus + today_time.day;
				for (i = today_time.month - 2; i >= 0; i--)
					minus = minus + b[i];
			}
			else {
				minus = minus + today_time.day;
				for (i = today_time.month - 2; i >= 0; i--)
					minus = minus + a[i];
			}
			for (j = product_time.year + 1; j < today_time.year; j++) {
				if (leap_year(j) == 1) minus += 366;
				else minus += 365;
			}
		}
	}
	return minus;
}
