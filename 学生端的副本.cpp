#include "record.h"
void Show3()
{
	printf("          **********************ѧ����Ϣ����ϵͳ********************\n");
	printf("                                ѧ����\n");
	printf("                              1.�ɼ���ѯ\n");
	printf("                              2.�ɼ�����\n");
	printf("                              3.������һ��\n");
	printf("                              ��������Ӧ������\n");
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
		printf("��������Ҫִ�еĲ���\n");
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