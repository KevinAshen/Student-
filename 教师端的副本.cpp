#include "record.h"
void Show4()
{
	printf("          ******************学生信息管理系统*************************\n");
	printf("                             教师端\n");
	printf("          1.增加新的学生信息             2.删除学生信息\n");
	printf("          3.修改学生信息                 4.查询学生信息\n");
	printf("          5.输出本班成绩                 6.更新数据\n");
	printf("          7.返回上一层\n");
	printf("          请输入相应的数字\n");
	printf("          ***********************************************************\n");
}
void Teacher()
{
	char agi;
	int flag;
	char flag1[50];
	STU * head;
	head = Create();
	//Output(head);
	agi = 'Y';
	while (agi == 'Y') {
		Show4(); 
		printf("请输入您要执行的操作\n");
		scanf("%s", &flag1);
		if (strcmp(flag1, "1") == 0) flag = 1;
		else if (strcmp(flag1, "2") == 0) flag = 2;
		else if (strcmp(flag1, "3") == 0) flag = 3;
		else if (strcmp(flag1, "4") == 0) flag = 4;
		else if (strcmp(flag1, "5") == 0) flag = 5;
		else if (strcmp(flag1, "6") == 0) flag = 6;
		else if (strcmp(flag1, "7") == 0) flag = 7;
		else Wrong_message();
		switch (flag) {
			case 1:Add_student(head); break;
			case 2:Delete_student(head); break;
			case 3:Alter_student(head); break;
			case 4:Query_result(head); break;
			case 5:Rank_student(head); break;
			case 6:Update_student(head); break;
			case 7:agi = 'N'; system("CLS"); break;
			default:agi = 'Y'; break;
		}
	}
}