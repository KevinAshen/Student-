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
	int No; //排名 
	int score[3];//分数 
	char name[50];//姓名 
	char num[20];//学号 
	char classes[20];//班级 
	double aver;//平均分
	double qort;//排序分
	struct student *next;//指针域 
};



