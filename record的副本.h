#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#define login_S "studentlogin.txt"
#define login_T "teacherlogin.txt"
#define List_S "studentlist.txt"
#define SIZE sizeof(struct student)
typedef struct student STU;
typedef struct sign SIGN;
void Help(void);
char landinga(int flag);
char landingb(int flag);
char landing1(FILE * fp);
char landing2(FILE * fp);
char Register(int flag);
void college();
void Teacher();
double Query_result(STU * head);
STU * Create();
void Output(STU * head);
double DoQuery_result(int flag,STU * head);
int Analysis_result(STU * head);
void Add_student(STU * head);
void Delete_student(STU * head);
void Alter_student(STU * head);
int Rank_student(STU * head);
void Update_student(STU * head);
void Wrong_message();
int Checkout_account(char account[]);
char * Star_password();
struct student
{
	int No; //���� 
	int score[3];//���� 
	char name[50];//���� 
	char num[20];//ѧ�� 
	char classes[20];//�༶ 
	double aver;//ƽ����
	double qort;//�����
	struct student *next;//ָ���� 
};



