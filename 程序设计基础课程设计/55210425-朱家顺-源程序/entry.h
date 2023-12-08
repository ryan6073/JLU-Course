#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Manager {
	char m_name[10] = { 0 };
	char m_password[20] = { 0 };
	char m_identity[10] = { 0 };
	struct Manager* next=NULL;
}Manager;
Manager* Manager_Book();
void AddManager(Manager* headmember);
void showManager(Manager* headmember);
Manager* isExist(Manager* headmember, char name[10], char password[20]);
void deleteManager(Manager* headmember);
void modifyManager(Manager* headmember);
void saveManager(Manager* pmove);
void boss(struct Member* abs, Manager* ab, FILE* fp1, FILE* fp5, struct goodsbuying* head1, Goods* head,Goods* head2);
void cashier(struct Member* abs, Manager* ab, FILE* fp1, struct goodsbuying* head1, Goods* head);
void showMenu();
void menu_entry();
void showMenu_boss();
void showMenu_Manager();