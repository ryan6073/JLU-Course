#include "system_custom.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Member* Member_Book() 
{
	struct Member* pointer, * q, * headmember;
	pointer = (struct Member*)malloc(sizeof(struct Member));
	if (pointer == NULL) return NULL;
	pointer->next = NULL;
	FILE* fp;
	headmember = pointer;
	q = pointer;
	q->next = NULL;
	fp = fopen("会员信息.txt", "rb+");
	int w;
	fseek(fp, 0, 2);
	w = ftell(fp);
	fseek(fp, 0, 0);
	while (w != ftell(fp))
	{
		pointer = (struct Member*)malloc(sizeof(struct Member));
		if (pointer == NULL) return NULL;
		pointer->next = NULL;
		fscanf(fp, "%s  %s  %s  %lf  %s\n", pointer->m_name, pointer->m_sex, pointer->m_birth, &pointer->m_balance, pointer->m_phone);
		q->next = pointer;  //把新节点挂到原尾节点之后
		q = q->next;  //q指针指向新的尾节点
	}
	q->next = NULL;//标志链表的结束 
	fclose(fp);
	return headmember;
}
void showMenu_Member() {
	printf("*******************************************\n");
	printf("*****                                 *****\n");
	printf("*****         1、添加会员             *****\n");
	printf("*****         2、展示会员             *****\n");
	printf("*****         3、删除会员             *****\n");
	printf("*****         4、查找会员             *****\n");
	printf("*****         5、修改会员             *****\n");
	printf("*****         6、清空会员             *****\n");
	printf("*****         0、保存并退出           *****\n");
	printf("*****                                 *****\n");
	printf("*******************************************\n");
}
void AddMember(struct Member* headmember) {
	struct Member* newmember = (struct Member*)malloc(sizeof(struct Member));
	if (newmember == NULL) return;
	newmember->next = NULL;
	char name[10] = { 0 };
	printf("请输入新建联系人姓名：\n");
	scanf_s("%s", name, 10);
	strcpy_s(newmember->m_name, name);
	int sex = 0;
	printf("请输入新建联系人性别： \n");
	printf("1:男性    2:女性\n");
	scanf_s("%d", &sex);
	while (sex != 1 && sex != 2) {
		printf("请重新输入性别： \n");
		printf("1:男性    2:女性\n");
		scanf_s("%d", &sex);
	}
	if (sex == 1) {
		char SEX[5] = "male";
		strcpy_s(newmember->m_sex, SEX);
	}
	else if (sex == 2) {
		char SEX[7] = "female";
		strcpy_s(newmember->m_sex, SEX);
	}
	printf("生日输入请按“2022年1月1日”的格式输入\n");
	printf("请输入新建联系人生日： \n");
	char birth[15];
	scanf_s("%s", birth, 15);
	strcpy_s(newmember->m_birth, birth);
	printf("请输入新建联系人电话： \n");
	char phone[15];
	struct Member* p1 = headmember;
	scanf_s("%s", phone, 15);
	while (p1->next != NULL) {
        if (strcmp(p1->m_phone, phone) == 0) {
			printf("电话号输入错误，请重新输入: \n");
			printf("请输入新建联系人电话：  \n");
			scanf_s("%s", phone, 15);
			p1 = headmember;
		}
		p1 = p1->next;
	}
	strcpy_s(newmember->m_phone, phone);
	printf("请问您要充值多少钱：");
	scanf_s("%lf", &newmember->m_balance);
	struct Member* pmove = headmember;
	while (pmove->next) {
		pmove = pmove->next;
	}
	pmove->next = newmember;
	printf("添加成功\n");
	system("pause");
	system("cls");
}

void showMember(struct Member* headmember) {
	if (headmember->next == NULL) {
		printf("当前记录为空\n");
	}
	else {
		struct Member* pmove = headmember->next;
		while (pmove) {
			printf("姓名：%s  \t", pmove->m_name);
			printf("性别：%s  \t", pmove->m_sex);
			printf("生日：%s  \t", pmove->m_birth);
			printf("电话：%s  \t", pmove->m_phone);
			printf("余额：%.2f  \n", pmove->m_balance);
			pmove = pmove->next;
		}
	}

	system("pause");
	system("cls");
}

struct Member* isExist(struct Member* headmember, char name[10]) {
    struct Member* pmove = headmember->next;

	while (pmove) {
		if (strcmp(pmove->m_name, name) == 0)  return pmove;
		pmove = pmove->next;
	}
	return NULL;
}

void deleteMember(struct Member* headmember) {
	printf("请输入要删除的联系人姓名： \n");
	char name[10];
	scanf_s("%s", name, 10);
	struct Member* ret = isExist(headmember, name);
	if (ret == NULL) printf("查无此人\n");
	else if (ret) {
		struct Member* pre = headmember;
		while (pre->next != ret) pre = pre->next;
		pre->next = ret;
		pre->next = ret->next;
		free(ret);
		printf("删除成功\n");
	}
	system("pause");
	system("cls");
}
void findMember(struct Member* headmember) {
	printf("请输入要查找的联系人姓名： \n");
	char name[10];
	scanf_s("%s", name, 10);
	struct Member* ret = isExist(headmember, name);
	if (ret == NULL) printf("查无此人\n");
	else if (ret) {
		printf("姓名：%s  \t", ret->m_name);
		printf("性别：%s  \t", ret->m_sex);
		printf("生日：%s  \t", ret->m_birth);
		printf("电话：%s  \t", ret->m_phone);
		printf("余额：%.2f  \n", ret->m_balance);
	}
	system("pause");
	system("cls");
}

void modifyMember(struct Member* headmember) {
	printf("请输入要修改的联系人姓名： \n");
	char Name[10]={0};
	scanf_s("%s", Name, 10);
	struct Member* ret = isExist(headmember, Name);
	if (ret == NULL)printf("查无此人\n");
	else if (ret) {
		int de=0;
		printf("0：无需修改\t1：姓名\t2：性别\t3：生日\t4：电话\n请输入需要修改的选项：\t");
		scanf_s("%d", &de);
		int sex = 0;
		char phone[15]={0};
		char birth[15]={0};
		char name[10] = { 0 };
		while (de != 0) {
		switch (de) {
		case 1:
             printf("姓名：%s \n", ret->m_name);
		     printf("请输入更改后的姓名：    (不更改请输入-1并回车)\n");
		     scanf_s("%s", name, 10);
		     if (strcmp(name, "-1") > 0 || strcmp(name, "-1") < 0) strcpy_s(ret->m_name, name);
			 printf("修改成功！请继续输入操作：\n0：无需修改\t1：姓名\t2：性别\t3：生日\t4：电话\n请输入需要修改的选项：\t");
			 scanf_s("%d", &de);
			 break;
		case 2:
			
		     printf("性别：%s \n", ret->m_sex);
		     printf("请输入更改后的性别： (不更改请输入-1并回车)\n");
		     printf("1:男性    2:女性\n");
		     scanf_s("%d", &sex);
		     while (sex != 1 && sex != 2 && sex != -1) {
			     printf("请重新输入更改后的性别： (不更改请输入-1并回车)\n");
			     printf("1:男性    2:女性\n");
			     scanf_s("%d", &sex);
		      }
		     if (sex == 1) strcpy_s(ret->m_sex, "male");
		     else if (sex == 2) strcpy_s(ret->m_sex, "female");
			 printf("修改成功！请继续输入操作：\n0：无需修改\t1：姓名\t2：性别\t3：生日\t4：电话\n请输入需要修改的选项：\t");
			 scanf_s("%d", &de);
			 break;
		case 3:
		     
		     printf("生日：%s \n", ret->m_birth);
		     printf("请输入更改后生日： （不更改请输入-1并回车）\n");
		     scanf_s("%s", birth, 15);
		     if (strcmp(birth, "-1") > 0 || strcmp(birth, "-1") < 0) strcpy_s(ret->m_birth, birth);
			 printf("修改成功！请继续输入操作：\n0：无需修改\t1：姓名\t2：性别\t3：生日\t4：电话\n请输入需要修改的选项：\t");
			 scanf_s("%d", &de);
			 break;
		case 4:
			printf("电话：%s \n", ret->m_phone);
			printf("请输入更改后的电话：         （不更改请输入-1并回车）\n");
			scanf_s("%s", phone, 15);
			if (strcmp(phone, "-1") > 0 || strcmp(phone, "-1") < 0) strcpy_s(ret->m_phone, phone);
			printf("修改成功！请继续输入操作：\n0：无需修改\t1：姓名\t2：性别\t3：生日\t4：电话\n请输入需要修改的选项：\t");
			scanf_s("%d", &de);
			break;
		default: break;
		}
		}

		


	}
	system("pause");
	system("cls");

}
void cleanMember(struct Member* headmember) 
{
	struct Member* pmove = headmember->next;
	headmember->next = NULL;
	if (pmove == NULL) {
		printf("通讯录为空");
	}
	else {
		while (pmove) {
			struct Member* pre = pmove;
			pmove = pmove->next;
			free(pre);
		}
		printf("通讯录已清空\n");
	}
	system("pause");
	system("cls");
}
void saveMember(struct Member* pmove)//保存数据
{
	FILE* fp;
	if ((fp = fopen("会员信息.txt", "wb")) == NULL)//打开文件，若没有此文件可以新建立
	{
		printf("不能打开此文件\n");//无法建立新文件
		exit(0);//正常运行程序并退出程序
	}
	while (pmove->next != NULL)
	{
		fprintf(fp, "%10s  %10s  %15s  %.2f  %15s\n", pmove->next->m_name, pmove->next->m_sex, pmove->next->m_birth, pmove->next->m_balance, pmove->next->m_phone);
		pmove = pmove->next;
	}
	fclose(fp);
}