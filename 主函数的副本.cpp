#include "record.h"
void show1()
{
	printf("          ******************ѧ����Ϣ����ϵͳ*************************\n");
	printf("                          1.ѧ����¼\n");
	printf("                          2.��ʦ��¼\n");
	printf("                          3.ѧ��ע���ʺ�\n");
	printf("                          4.��ʦע���ʺ�\n");
	printf("                          0.�˳�\n");
	printf("                          ��������Ӧ������\n");
	printf("          ***********************************************************\n");
}
int main(void)
{
	printf("		���ΪBUG����������\n\
		��Ҫ�ҵ�BUG��\n\
		ȥ�ɣ��Ұ�һ��ȫ�������������ѧ������ϵͳ��\n");
	printf("				����BUG�� �����.D.���ĳ�����˧\n");
	Sleep(1500);
	//system("CLS");
	char agi;
	char flag[50];
	agi = 'Y';
	while (agi=='Y') {
		show1();
		printf("��ѡ����Ҫִ����һ�������\n");
		//fflush(stdin);//������뻺��
		scanf("%s", flag);
		if (strcmp(flag, "1") == 0) agi = landinga(1);
		else if (strcmp(flag, "2") == 0) agi = landingb(2);
		else if (strcmp(flag, "3") == 0) agi = Register(3);
		else if (strcmp(flag, "4") == 0) agi = Register(4);
		else if (strcmp(flag, "0") == 0) exit(0);
		//else if (strcmp(flag, "77") == 0) Output();
		else Wrong_message();
		//switch (flag) {
		//case 1:agi=landinga(flag); break;//ѧ�� 
		//case 2:agi=landingb(flag); break;//��ʦ 
		//case 3:agi=Register(flag); break;//ѧ��ע��
		//case 4:agi=Register(flag); break;//��ʦע��		
		//case 0:exit(0); break;
		//default:printf("������������������\n"); break;
		//}
	}
	return 0;
}
void Wrong_message()
{
	printf("��⵽��;�ĺ˾۱����������򼴽��Ի٣�����\n");
	Sleep(500);
	system("CLS");
}
