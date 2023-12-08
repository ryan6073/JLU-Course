#pragma once
#ifndef SYSTEM_CUSTOM_H
#define SYSTEM_CUSTOM_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Member 
{
	char m_name[10] = { 0 };//会员信息结构体：姓名、性别、生日、会员卡余额、电话号码
	char m_sex[10] = { 0 };//性别，male,female 
	char m_birth[15] = { 0 };//生日，格式为“2022年1月1日” 
	double m_balance = 0;//会员卡余额 
	char m_phone[15] = { 0 };//会员绑定手机号 
	struct Member* next = NULL;
};
struct Member* Member_Book();
void showMenu_Member();
void AddMember(struct Member* headmember);
void showMember(struct Member* headmember);
struct Member* isExist(struct Member* headmember, char name[10]);
void deleteMember(struct Member* headmember);
void findMember(struct Member* headmember);
void modifyMember(struct Member* headmember);
void cleanMember(struct Member* headmember);
void saveMember(struct Member* pmove);//保存数据
#endif

