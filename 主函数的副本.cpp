#include "record.h"
void show1()
{
	printf("          ******************学生信息管理系统*************************\n");
	printf("                          1.学生登录\n");
	printf("                          2.教师登录\n");
	printf("                          3.学生注册帐号\n");
	printf("                          4.教师注册帐号\n");
	printf("                          0.退出\n");
	printf("                          请输入相应的数字\n");
	printf("          ***********************************************************\n");
}
int main(void)
{
	printf("		想成为BUG王的男人吗？\n\
		想要我的BUG吗？\n\
		去吧，我把一切全都放在了这里——学生管理系统！\n");
	printf("				——BUG王 哥尔多.D.凯文长得贼帅\n");
	Sleep(1500);
	//system("CLS");
	char agi;
	char flag[50];
	agi = 'Y';
	while (agi=='Y') {
		show1();
		printf("请选择您要执行哪一项操作：\n");
		//fflush(stdin);//清空输入缓存
		scanf("%s", flag);
		if (strcmp(flag, "1") == 0) agi = landinga(1);
		else if (strcmp(flag, "2") == 0) agi = landingb(2);
		else if (strcmp(flag, "3") == 0) agi = Register(3);
		else if (strcmp(flag, "4") == 0) agi = Register(4);
		else if (strcmp(flag, "0") == 0) exit(0);
		//else if (strcmp(flag, "77") == 0) Output();
		else Wrong_message();
		//switch (flag) {
		//case 1:agi=landinga(flag); break;//学生 
		//case 2:agi=landingb(flag); break;//教师 
		//case 3:agi=Register(flag); break;//学生注册
		//case 4:agi=Register(flag); break;//教师注册		
		//case 0:exit(0); break;
		//default:printf("输入有误请重新输入\n"); break;
		//}
	}
	return 0;
}
void Wrong_message()
{
	printf("侦测到在途的核聚变打击！本程序即将自毁！！！\n");
	Sleep(500);
	system("CLS");
}
