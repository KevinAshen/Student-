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
	printf("�����������˺�(��λ����)��\n");
	fflush(stdin);//������뻺��
	scanf("%s", account);
	if (Checkout_account(account) == 0) {
		Wrong_message();
		return 'Y';
	}
	//printf("%s\n",account);
	for (j = 0; j < i; j++) {
		if (strcmp(account, cip[j].account)==0) {
			flag = 1;
			printf("�������������룺\n");
			password = Star_password();
			//scanf("%s", password);
			//printf("%s\n", password);
			if (strcmp(password, cip[j].password) == 0) {
				printf("\n��½�ɹ���ʮ�ָ�л��ʹ�ñ�ϵͳ��\n");
				Sleep(500);
				system("CLS");
				fclose(fp);
				agi = 'Y';
				college();
				return agi;
			} else {
				//printf("�������\n");
				fclose(fp);
				Wrong_message();
				return agi;
			}
			break;
		}
		else {
			//printf("�˺Ŵ���!\n");
			fclose(fp);
			Wrong_message();
			return agi;
		}
	}
	if (flag == 0) {
		//printf("�˺Ŵ���\n");
		fclose(fp);
		Wrong_message();
		return agi;
	}
	//����ѧ����
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
	printf("�����������˺�(��λ����)��\n");
	fflush(stdin);//������뻺��
	scanf("%s", account);
	if (Checkout_account(account) == 0) {
		Wrong_message();
		return 'Y';
	}
	//printf("%s\n",account);
	for (j = 0; j < i; j++) {
		if (strcmp(account, cip[j].account) == 0) {
			flag = 1;
			printf("�������������룺\n");
			password = Star_password();
			//scanf("%s", password);
			//printf("%s\n", password);
			if (strcmp(password, cip[j].password) == 0) {
				printf("\n��½�ɹ���ʮ�ָ�л��ʹ�ñ�ϵͳ��\n");
				Sleep(500);
				system("CLS");
				fclose(fp);
				agi = 'Y';
				Teacher();
				return agi;
			}
			else {
				//printf("�������\n");
				fclose(fp);
				Wrong_message();
				return agi;
			}
			break;
		}
		else {
			//printf("�˺Ŵ���!\n");
			fclose(fp);
			Wrong_message();
			return agi;
		}
	}
	if (flag == 0) {
		//printf("�˺Ŵ���\n");
		fclose(fp);
		Wrong_message();
		return agi;
	}
	//����ѧ����
}
char Register(int flag)//3 ѧ�� 4 ��ʦ
{
	FILE * fp;
	char agi='Y';
	char account[20];
	char password[50];
	int i = 0, j;
	if (flag == 3) {
		fp = fopen(login_S, "rt+");
		if (fp == NULL) {
			printf("�ļ���ʧ��\n");
			exit(0);
		}
		//fprintf(fp, "\n");
		printf("�������������˺ţ�8λ���֣���\n");
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
				printf("���˺��ѱ�ʹ�ã�\n");
				Wrong_message();
				return 'Y';
			}
		}
		printf("����������������(��ĸ������)��\n");
		//
		int p;
		char ch;
		p = 0;
		while ((ch = getch()) != '\r')//�ж��Ƿ��ǻس�  
		{
			if (ch == 8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8  
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				if (p>0)//���ֻ��ɾ��û���ַ�  
					p--;
			}
			if (!isdigit(ch) && !isalpha(ch))//�ж��Ƿ������ֻ��ַ�  
				continue;
			putchar('*');//����Ļ�ϴ�ӡ�Ǻ�  
			password[p++] = ch;//��������  
		}
		password[p] = 0;//�����ַ���
		fprintf(fp, "\n");
		printf("%s", password);
		fprintf(fp, "%s %s", account,password);
		printf("\n��ϲ����ע��ɹ���\n");
		Sleep(500);
		system("CLS");
		fclose(fp);
		return agi;
	}
	else {
		fp = fopen(login_T, "at+");
		if (fp == NULL) {
			printf("�ļ���ʧ��\n");
			exit(0);
		}
		//fprintf(fp, "\n");
		printf("�������������˺ţ�8λ���֣���\n");
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
				printf("���˺��ѱ�ʹ�ã�\n");
				Wrong_message();
				return 'Y';
			}
		}
		printf("����������������(��ĸ������)��\n");
		int p;
		char ch;
		p = 0;
		while ((ch = getch()) != '\r')//�ж��Ƿ��ǻس�  
		{
			if (ch == 8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8  
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				if (p>0)//���ֻ��ɾ��û���ַ�  
					p--;
			}
			if (!isdigit(ch) && !isalpha(ch))//�ж��Ƿ������ֻ��ַ�  
				continue;
			putchar('*');//����Ļ�ϴ�ӡ�Ǻ�  
			password[p++] = ch;//��������  
		}
		password[p] = 0;//�����ַ���
		fprintf(fp, "\n");
		printf("%s", password);
		fprintf(fp, "%s %s", account, password);
		printf("\n��ϲ����ע��ɹ���\n");
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
	while ((ch = getch()) != '\r')//�ж��Ƿ��ǻس�  
	{
		if (ch == 8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8  
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			if (p>0)//���ֻ��ɾ��û���ַ�  
				p--;
		}
		if (!isdigit(ch) && !isalpha(ch))//�ж��Ƿ������ֻ��ַ�  
			continue;
		putchar('*');//����Ļ�ϴ�ӡ�Ǻ�  
		password[p++] = ch;//��������  
	}
	password[p] = 0;//�����ַ���
	return password;
}