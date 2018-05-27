#include "record.h"
struct cipher
{
	char account[30];
	char password[30];
}cip[50];
char landinga(int flag)
{
	FILE * fp;
	char agi;
	fp = fopen(login_S, "rt+");
	agi = landing1(fp);
	return agi;
}
char landingb(int flag)
{
	FILE * fp;
	char agi;
	fp = fopen(login_T, "rt+");
	agi=landing2(fp);
	return agi;
}
char landing1(FILE * fp)
{
	char account[256];
	char agi='Y';
	char * password;
	int i, j,flag;
	int p;
	char ch;
	p = 0;
	i = 0;
	flag = 0;
	while ((fscanf(fp, "%s %s", cip[i].account, cip[i].password)) != EOF) {
		i++;
	}
	printf("%s %s\n", cip[0].account, cip[1].password);
	printf("请输入您的账号(八位数字)：\n");
	fflush(stdin);//清空输入缓存
	scanf("%s", account);
	if (Checkout_account(account) == 0) {
		Wrong_message();
		return 'Y';
	}
	//printf("%s\n",account);
	for (j = 0; j < i; j++) {
		if (strcmp(account, cip[j].account)==0) {
			flag = 1;
			printf("请输入您的密码：\n");
			password = Star_password();
			//scanf("%s", password);
			//printf("%s\n", password);
			if (strcmp(password, cip[j].password) == 0) {
				printf("\n登陆成功！十分感谢您使用本系统。\n");
				Sleep(500);
				system("CLS");
				fclose(fp);
				agi = 'Y';
				college();
				return agi;
			} else {
				//printf("密码错误！\n");
				fclose(fp);
				Wrong_message();
				return agi;
			}
			break;
		}
		else {
			//printf("账号错误!\n");
			fclose(fp);
			Wrong_message();
			return agi;
		}
	}
	if (flag == 0) {
		//printf("账号错误！\n");
		fclose(fp);
		Wrong_message();
		return agi;
	}
	//插入学生端
}
char landing2(FILE * fp)
{
	char account[256];
	char agi = 'Y';
	char * password;
	int i, j, flag;
	int p;
	char ch;
	p = 0;
	i = 0;
	flag = 0;
	while ((fscanf(fp, "%s %s", cip[i].account, cip[i].password)) != EOF) {
		i++;
	}
	printf("%s %s\n", cip[0].account, cip[1].password);
	printf("请输入您的账号(八位数字)：\n");
	fflush(stdin);//清空输入缓存
	scanf("%s", account);
	if (Checkout_account(account) == 0) {
		Wrong_message();
		return 'Y';
	}
	//printf("%s\n",account);
	for (j = 0; j < i; j++) {
		if (strcmp(account, cip[j].account) == 0) {
			flag = 1;
			printf("请输入您的密码：\n");
			password = Star_password();
			//scanf("%s", password);
			//printf("%s\n", password);
			if (strcmp(password, cip[j].password) == 0) {
				printf("\n登陆成功！十分感谢您使用本系统。\n");
				Sleep(500);
				system("CLS");
				fclose(fp);
				agi = 'Y';
				Teacher();
				return agi;
			}
			else {
				//printf("密码错误！\n");
				fclose(fp);
				Wrong_message();
				return agi;
			}
			break;
		}
		else {
			//printf("账号错误!\n");
			fclose(fp);
			Wrong_message();
			return agi;
		}
	}
	if (flag == 0) {
		//printf("账号错误！\n");
		fclose(fp);
		Wrong_message();
		return agi;
	}
	//插入学生端
}
char Register(int flag)//3 学生 4 教师
{
	FILE * fp;
	char agi='Y';
	char account[20];
	char password[50];
	int i = 0, j;
	if (flag == 3) {
		fp = fopen(login_S, "rt+");
		if (fp == NULL) {
			printf("文件打开失败\n");
			exit(0);
		}
		//fprintf(fp, "\n");
		printf("请输入您的新账号（8位数字）：\n");
		scanf("%s", account);
		if (Checkout_account(account) == 0) {
			Wrong_message();
			return 'Y';
		}
		while ((fscanf(fp, "%s %s", cip[i].account, cip[i].password)) != EOF) {
			i++;
		}
		printf("%s\n", cip[0].account);
		for (j = 0; j < i; j++) {
			if (strcmp(account, cip[j].account) == 0) {
				printf("该账号已被使用！\n");
				Wrong_message();
				return 'Y';
			}
		}
		printf("请输入您的新密码(字母或数字)：\n");
		//
		int p;
		char ch;
		p = 0;
		while ((ch = getch()) != '\r')//判断是否是回车  
		{
			if (ch == 8)//实现backspace键的功能，其中backspace键的ascii码是8  
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				if (p>0)//最多只能删到没有字符  
					p--;
			}
			if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符  
				continue;
			putchar('*');//在屏幕上打印星号  
			password[p++] = ch;//保存密码  
		}
		password[p] = 0;//结束字符串
		fprintf(fp, "\n");
		printf("%s", password);
		fprintf(fp, "%s %s", account,password);
		printf("\n恭喜您！注册成功！\n");
		Sleep(500);
		system("CLS");
		fclose(fp);
		return agi;
	}
	else {
		fp = fopen(login_T, "at+");
		if (fp == NULL) {
			printf("文件打开失败\n");
			exit(0);
		}
		//fprintf(fp, "\n");
		printf("请输入您的新账号（8位数字）：\n");
		scanf("%s", account);
		if (Checkout_account(account) == 0) {
			Wrong_message();
			return 'Y';
		}
		while ((fscanf(fp, "%s %s", cip[i].account, cip[i].password)) != EOF) {
			i++;
		}
		printf("%s\n", cip[0].account);
		for (j = 0; j < i; j++) {
			if (strcmp(account, cip[j].account) == 0) {
				printf("该账号已被使用！\n");
				Wrong_message();
				return 'Y';
			}
		}
		printf("请输入您的新密码(字母或数字)：\n");
		int p;
		char ch;
		p = 0;
		while ((ch = getch()) != '\r')//判断是否是回车  
		{
			if (ch == 8)//实现backspace键的功能，其中backspace键的ascii码是8  
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				if (p>0)//最多只能删到没有字符  
					p--;
			}
			if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符  
				continue;
			putchar('*');//在屏幕上打印星号  
			password[p++] = ch;//保存密码  
		}
		password[p] = 0;//结束字符串
		fprintf(fp, "\n");
		printf("%s", password);
		fprintf(fp, "%s %s", account, password);
		printf("\n恭喜您！注册成功！\n");
		Sleep(500);
		system("CLS");
		fclose(fp);
		return agi;
	}
}
int Checkout_account(char account[])
{
	int len;
	int i;
	len = strlen(account);
	if (len != 8) {
		return 0;
	}
	else {
		for (i = 0; i < len; i++) {
			if (!(account[i] >= '0'&&account[i] <= '9')) {
				return 0;
			}
		}
	}
	if (i == len) 
		return 1;
}
char * Star_password()
{
	char password[256];
	int p;
	char ch;
	p = 0;
	while ((ch = getch()) != '\r')//判断是否是回车  
	{
		if (ch == 8)//实现backspace键的功能，其中backspace键的ascii码是8  
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			if (p>0)//最多只能删到没有字符  
				p--;
		}
		if (!isdigit(ch) && !isalpha(ch))//判断是否是数字或字符  
			continue;
		putchar('*');//在屏幕上打印星号  
		password[p++] = ch;//保存密码  
	}
	password[p] = 0;//结束字符串
	return password;
}