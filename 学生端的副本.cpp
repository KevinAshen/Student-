#include "record.h"
void Show3()
{
	printf("          **********************学生信息管理系统********************\n");
	printf("                                学生端\n");
	printf("                              1.成绩查询\n");
	printf("                              2.成绩分析\n");
	printf("                              3.返回上一层\n");
	printf("                              请输入相应的数字\n");
	printf("          ********************************************************\n");
}
void college()
{
	char agi;
	int flag;
	char flag1[50];
	STU * head;
	head=Create();
	//Output(head);
	agi = 'Y';
	while (agi == 'Y') {
		Show3();
		printf("请输入您要执行的操作\n");
		scanf("%s", &flag1);
		if (strcmp(flag1, "1") == 0) flag = 1;
		else if (strcmp(flag1, "2") == 0) flag = 2;
		else if (strcmp(flag1, "3") == 0) flag = 3;
		else Wrong_message();
		switch (flag) {
			case 1:Query_result(head); break;
			case 2:Analysis_result(head); break;
			case 3:agi = 'N'; system("CLS"); break;
			default:system("CLS"); break;
		}
	}
}