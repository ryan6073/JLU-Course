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
	fp = fopen("��Ա��Ϣ.txt", "rb+");
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
		q->next = pointer;  //���½ڵ�ҵ�ԭβ�ڵ�֮��
		q = q->next;  //qָ��ָ���µ�β�ڵ�
	}
	q->next = NULL;//��־����Ľ��� 
	fclose(fp);
	return headmember;
}
void showMenu_Member() {
	printf("*******************************************\n");
	printf("*****                                 *****\n");
	printf("*****         1����ӻ�Ա             *****\n");
	printf("*****         2��չʾ��Ա             *****\n");
	printf("*****         3��ɾ����Ա             *****\n");
	printf("*****         4�����һ�Ա             *****\n");
	printf("*****         5���޸Ļ�Ա             *****\n");
	printf("*****         6����ջ�Ա             *****\n");
	printf("*****         0�����沢�˳�           *****\n");
	printf("*****                                 *****\n");
	printf("*******************************************\n");
}
void AddMember(struct Member* headmember) {
	struct Member* newmember = (struct Member*)malloc(sizeof(struct Member));
	if (newmember == NULL) return;
	newmember->next = NULL;
	char name[10] = { 0 };
	printf("�������½���ϵ��������\n");
	scanf_s("%s", name, 10);
	strcpy_s(newmember->m_name, name);
	int sex = 0;
	printf("�������½���ϵ���Ա� \n");
	printf("1:����    2:Ů��\n");
	scanf_s("%d", &sex);
	while (sex != 1 && sex != 2) {
		printf("�����������Ա� \n");
		printf("1:����    2:Ů��\n");
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
	printf("���������밴��2022��1��1�ա��ĸ�ʽ����\n");
	printf("�������½���ϵ�����գ� \n");
	char birth[15];
	scanf_s("%s", birth, 15);
	strcpy_s(newmember->m_birth, birth);
	printf("�������½���ϵ�˵绰�� \n");
	char phone[15];
	struct Member* p1 = headmember;
	scanf_s("%s", phone, 15);
	while (p1->next != NULL) {
        if (strcmp(p1->m_phone, phone) == 0) {
			printf("�绰�������������������: \n");
			printf("�������½���ϵ�˵绰��  \n");
			scanf_s("%s", phone, 15);
			p1 = headmember;
		}
		p1 = p1->next;
	}
	strcpy_s(newmember->m_phone, phone);
	printf("������Ҫ��ֵ����Ǯ��");
	scanf_s("%lf", &newmember->m_balance);
	struct Member* pmove = headmember;
	while (pmove->next) {
		pmove = pmove->next;
	}
	pmove->next = newmember;
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}

void showMember(struct Member* headmember) {
	if (headmember->next == NULL) {
		printf("��ǰ��¼Ϊ��\n");
	}
	else {
		struct Member* pmove = headmember->next;
		while (pmove) {
			printf("������%s  \t", pmove->m_name);
			printf("�Ա�%s  \t", pmove->m_sex);
			printf("���գ�%s  \t", pmove->m_birth);
			printf("�绰��%s  \t", pmove->m_phone);
			printf("��%.2f  \n", pmove->m_balance);
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
	printf("������Ҫɾ������ϵ�������� \n");
	char name[10];
	scanf_s("%s", name, 10);
	struct Member* ret = isExist(headmember, name);
	if (ret == NULL) printf("���޴���\n");
	else if (ret) {
		struct Member* pre = headmember;
		while (pre->next != ret) pre = pre->next;
		pre->next = ret;
		pre->next = ret->next;
		free(ret);
		printf("ɾ���ɹ�\n");
	}
	system("pause");
	system("cls");
}
void findMember(struct Member* headmember) {
	printf("������Ҫ���ҵ���ϵ�������� \n");
	char name[10];
	scanf_s("%s", name, 10);
	struct Member* ret = isExist(headmember, name);
	if (ret == NULL) printf("���޴���\n");
	else if (ret) {
		printf("������%s  \t", ret->m_name);
		printf("�Ա�%s  \t", ret->m_sex);
		printf("���գ�%s  \t", ret->m_birth);
		printf("�绰��%s  \t", ret->m_phone);
		printf("��%.2f  \n", ret->m_balance);
	}
	system("pause");
	system("cls");
}

void modifyMember(struct Member* headmember) {
	printf("������Ҫ�޸ĵ���ϵ�������� \n");
	char Name[10]={0};
	scanf_s("%s", Name, 10);
	struct Member* ret = isExist(headmember, Name);
	if (ret == NULL)printf("���޴���\n");
	else if (ret) {
		int de=0;
		printf("0�������޸�\t1������\t2���Ա�\t3������\t4���绰\n��������Ҫ�޸ĵ�ѡ�\t");
		scanf_s("%d", &de);
		int sex = 0;
		char phone[15]={0};
		char birth[15]={0};
		char name[10] = { 0 };
		while (de != 0) {
		switch (de) {
		case 1:
             printf("������%s \n", ret->m_name);
		     printf("��������ĺ��������    (������������-1���س�)\n");
		     scanf_s("%s", name, 10);
		     if (strcmp(name, "-1") > 0 || strcmp(name, "-1") < 0) strcpy_s(ret->m_name, name);
			 printf("�޸ĳɹ�����������������\n0�������޸�\t1������\t2���Ա�\t3������\t4���绰\n��������Ҫ�޸ĵ�ѡ�\t");
			 scanf_s("%d", &de);
			 break;
		case 2:
			
		     printf("�Ա�%s \n", ret->m_sex);
		     printf("��������ĺ���Ա� (������������-1���س�)\n");
		     printf("1:����    2:Ů��\n");
		     scanf_s("%d", &sex);
		     while (sex != 1 && sex != 2 && sex != -1) {
			     printf("������������ĺ���Ա� (������������-1���س�)\n");
			     printf("1:����    2:Ů��\n");
			     scanf_s("%d", &sex);
		      }
		     if (sex == 1) strcpy_s(ret->m_sex, "male");
		     else if (sex == 2) strcpy_s(ret->m_sex, "female");
			 printf("�޸ĳɹ�����������������\n0�������޸�\t1������\t2���Ա�\t3������\t4���绰\n��������Ҫ�޸ĵ�ѡ�\t");
			 scanf_s("%d", &de);
			 break;
		case 3:
		     
		     printf("���գ�%s \n", ret->m_birth);
		     printf("��������ĺ����գ� ��������������-1���س���\n");
		     scanf_s("%s", birth, 15);
		     if (strcmp(birth, "-1") > 0 || strcmp(birth, "-1") < 0) strcpy_s(ret->m_birth, birth);
			 printf("�޸ĳɹ�����������������\n0�������޸�\t1������\t2���Ա�\t3������\t4���绰\n��������Ҫ�޸ĵ�ѡ�\t");
			 scanf_s("%d", &de);
			 break;
		case 4:
			printf("�绰��%s \n", ret->m_phone);
			printf("��������ĺ�ĵ绰��         ��������������-1���س���\n");
			scanf_s("%s", phone, 15);
			if (strcmp(phone, "-1") > 0 || strcmp(phone, "-1") < 0) strcpy_s(ret->m_phone, phone);
			printf("�޸ĳɹ�����������������\n0�������޸�\t1������\t2���Ա�\t3������\t4���绰\n��������Ҫ�޸ĵ�ѡ�\t");
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
		printf("ͨѶ¼Ϊ��");
	}
	else {
		while (pmove) {
			struct Member* pre = pmove;
			pmove = pmove->next;
			free(pre);
		}
		printf("ͨѶ¼�����\n");
	}
	system("pause");
	system("cls");
}
void saveMember(struct Member* pmove)//��������
{
	FILE* fp;
	if ((fp = fopen("��Ա��Ϣ.txt", "wb")) == NULL)//���ļ�����û�д��ļ������½���
	{
		printf("���ܴ򿪴��ļ�\n");//�޷��������ļ�
		exit(0);//�������г����˳�����
	}
	while (pmove->next != NULL)
	{
		fprintf(fp, "%10s  %10s  %15s  %.2f  %15s\n", pmove->next->m_name, pmove->next->m_sex, pmove->next->m_birth, pmove->next->m_balance, pmove->next->m_phone);
		pmove = pmove->next;
	}
	fclose(fp);
}