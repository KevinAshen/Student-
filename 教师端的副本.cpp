#include "record.h"
void Show4()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                             ��ʦ��\n");
	printf("          1.�����µ�ѧ����Ϣ             2.ɾ��ѧ����Ϣ\n");
	printf("          3.�޸�ѧ����Ϣ                 4.��ѯѧ����Ϣ\n");
	printf("          5.�������ɼ�                 6.��������\n");
	printf("          7.������һ��\n");
	printf("          ��������Ӧ������\n");
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
		printf("��������Ҫִ�еĲ���\n");
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