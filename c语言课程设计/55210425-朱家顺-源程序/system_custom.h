#pragma once
#ifndef SYSTEM_CUSTOM_H
#define SYSTEM_CUSTOM_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Member 
{
	char m_name[10] = { 0 };//��Ա��Ϣ�ṹ�壺�������Ա����ա���Ա�����绰����
	char m_sex[10] = { 0 };//�Ա�male,female 
	char m_birth[15] = { 0 };//���գ���ʽΪ��2022��1��1�ա� 
	double m_balance = 0;//��Ա����� 
	char m_phone[15] = { 0 };//��Ա���ֻ��� 
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
void saveMember(struct Member* pmove);//��������
#endif

