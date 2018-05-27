#include "record.h"
STU * Create()
{
	FILE * fp;
	int sum;
	//struct student *head, *last, *p, *t;
	struct student *head, *last, *p;
	fp = fopen(List_S, "rt+");
	head = (struct student*)malloc(SIZE);
	last = (struct student*)malloc(SIZE);
	head->next = NULL;
	last = head;
	//void rewind(FILE *fp);
	while (!feof(fp)) {
		p = (struct student*)malloc(SIZE);
		fscanf(fp, "%s %s %s %d %d %d", p->name, p->num, p->classes, &p->score[0], &p->score[1], &p->score[2]);
		//p->aver = (double)((p->score[0] - '0') + (p->score[1] - '0') + (p->score[2] - '0')) / 3.0;
		sum = p->score[0] + p->score[1] + p->score[2];
		//printf("%d\t", sum);
		p->aver =sum / 3.0;
		//printf("%.2lf\n", p->aver);
		p->next = NULL;
		last->next = p;
		last = p;
	}
	fclose(fp);
	//p = head->next;
	//while (p->next != NULL) {
		//printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1],p->score[2]);
		//p = p->next;
	//}
	return head;
}
void Output(STU * head)
{
	STU *p;
	p = head->next;
	printf("����    ѧ��            �༶            ��Ŀһ  ��Ŀ��  ��Ŀ��\n");
	while (p!= NULL) {
		printf("%-5s\t%-10s\t%-10s\t%-5d\t%-5d\t%-5d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
		p = p->next;
	}
	//Sleep(3000);
	//system("CLS");
}
double Query_result(STU * head)
{
	char flag1[100];
	int flag;
	double aver;
	printf("��ѡ����Ҫ����\n1.��������ѯ\n2.��ѧ�Ų�ѯ\n(����1����2)\n");
	scanf("%s", flag1);
	if (strcmp(flag1, "1") == 0) flag = 1;
	else if (strcmp(flag1, "2") == 0) flag = 2;
	else {
		Wrong_message();
		flag = 3;
	}
	aver=DoQuery_result(flag,head);
	return aver;
}
double DoQuery_result(int flag,STU * head)
{
	STU *p;
	char name[20];
	char num[20];
	double aver=0;
	if (flag == 1) {
		system("CLS");
		printf("������������\n");
		//fflush(stdin);
		scanf("%s", name);
		p = head->next;
		while (p!= NULL) {
			if (strcmp(name, p->name) == 0) {
				printf("�ɼ�Ϊ��\n");
				printf("��Ŀһ��%d\n��Ŀ����%d\n��Ŀ����%d\nƽ���֣�%.2lf\n",p->score[0],p->score[1],p->score[2],p->aver);
				Sleep(700);
				system("CLS");
				aver = p->aver;
				//g->flag = flag;
				//strcpy(g->sign, name);
				break;
			}
			p = p->next;
		}
	}
	else if (flag==2)  {
		printf("������ѧ�ţ�\n");
		//fflush(stdin);
		scanf("%s", num);
		STU *p;
		p = head->next;
		while (p != NULL) {
			if (strcmp(num, p->num) == 0) {
				printf("�ɼ�Ϊ��\n");
				printf("��Ŀһ��%d\n��Ŀ����%d\n��Ŀ����%d\nƽ���֣�%.2lf\n", p->score[0], p->score[1], p->score[2], p->aver);
				Sleep(700);
				system("CLS");
				aver = p->aver;
				//g->flag = flag;
				//strcpy(g->sign, name);
				break;
			}
			p = p->next;
		}
	}
	return aver;
}
int Analysis_result(STU * head)
{
	//ƽ�������� ��֪�Լ��ǵڼ���
	//����༶ƽ���� �ó��ֱ��ƽ���ֲ����
	STU *pre, *tail, *p;
	double aver,aver1,aver2,aver3,aver4=0;
	int sum1=0, sum2=0, sum3=0;
	//double sum1, sum2, sum3;
	int rank,flag,count=0;
	char name[20];
	char num[20];
	char flag1[50];
	//Output(head);
	//p = head->next;
	//while (p->next= NULL) {
		//printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
		//p = p->next;
	//}
	p = head->next;
	while (p!= NULL) {
		//printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
		sum1 += p->score[0];
		sum2 += p->score[1];
		sum3 += p->score[2];
		aver4 += p->aver;
		count++;
		p = p->next;
	}
	//printf("%d %d %d %d\n", sum1, sum2, sum3,count);
	aver1 =(double)sum1/ count;
	aver2 =(double)sum2/ count;
	aver3 =(double)sum3/ count;
	aver4 /= count;
	//printf("%.2lf %.2lf %.2lf", aver1, aver2, aver3);
	rank = 1;
	printf("��ѡ����Ҫ����\n1.��������ѯ\n2.��ѧ�Ų�ѯ\n(����1����2)\n");
	//scanf("%d", &flag);
	scanf("%s", flag1);
	if (strcmp(flag1, "1") == 0) flag = 1;
	else if (strcmp(flag1, "2") == 0) flag = 2;
	else {
		Wrong_message();
		flag = 3;
	}
	//double aver;
	if (flag == 1) {
		system("CLS");
		printf("����������������\n");
		//fflush(stdin);
		scanf("%s", name);
		//STU *p;
		p = head->next;
		//printf("%s\n", p->name);
		while (p!= NULL) {
			if (strcmp(name, p->name) == 0) {
				printf("���ĳɼ�Ϊ��\n");
				printf("��Ŀһ��%d\t�༶ƽ����Ϊ��%.2lf\n��Ŀ����%d\t�༶ƽ����Ϊ��%.2lf\n��Ŀ����%d\t�༶ƽ����Ϊ��%.2lf\n��ƽ���֣�%.2lf\t�༶��ƽ����Ϊ��%.2lf\n", p->score[0], aver1, p->score[1], aver2, p->score[2], aver3, p->aver, aver4);
				aver = p->aver;
				//g->flag = flag;
				//strcpy(g->sign, name);
				break;
			}
			p = p->next;
		}
	}
	else if (flag==2) {
		system("CLS");
		printf("����������ѧ�ţ�\n");
		//fflush(stdin);
		scanf("%s", num);
		//STU *p;
		p = head->next;
		while (p!= NULL) {
			if (strcmp(num, p->num) == 0) {
				printf("���ĳɼ�Ϊ��\n");
				printf("��Ŀһ��%d\t�༶ƽ����Ϊ��%.2lf\n��Ŀ����%d\t�༶ƽ����Ϊ��%.2lf\n��Ŀ����%d\t�༶ƽ����Ϊ��%.2lf\n��ƽ���֣�%.2lf\t�༶��ƽ����Ϊ��%.2lf\n", p->score[0], aver1, p->score[1], aver2, p->score[2], aver3, p->aver, aver4);
				aver = p->aver;
				//g->flag = flag;
				//strcpy(g->sign, num);
				break;
			}
			p = p->next;
		}
	}
	else {
		return 0;
	}
	//Output(head);
	tail = NULL;
	pre = head;
	while ((head->next) != tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if ((p->aver)<(p->next->aver)) {
				pre->next = p->next; 
				p->next = p->next->next;  
				pre->next->next = p; 
				p = pre->next; 
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	p = head->next;
	while (p!= NULL) {
		//printf("%.2lf\n", p->aver);
		if (p->aver == aver) {
			printf("����ƽ���֣�����ȫ�������Ϊ��\n");
			printf("%d\n", rank);
			Sleep(2000);
			system("CLS");
			break;
		}
		else {
			rank++;
		}
		p = p->next;
	}
	//printf("%.2lf", p->aver);
	//printf("��Һ� ���������� %.2lf", aver);
	return 0;
}
void Add_student(STU * head)
{
	STU * p, *t;
	t = (struct student*)malloc(SIZE);
	p = head->next;
	//int score[3];//���� 
	//char name[50];//���� 
	//char num[20];//ѧ�� 
	//char classes[20];//�༶ 
	printf("��������ӵ�ѧ��������\n");
	scanf("%s",t->name);
	getchar();
	printf("��������ӵ�ѧ��ѧ�ţ�\n");
	scanf("%s", t->num);
	getchar();
	printf("��������ӵ�ѧ���༶��\n");
	scanf("%s", t->classes);
	getchar();
	printf("��������ӵ�ѧ����Ŀһ�ɼ���\n");
	scanf("%d",&t->score[0]);
	getchar();
	printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
	scanf("%d", &t->score[1]);
	getchar();
	printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
	scanf("%d", &t->score[2]);
	getchar();
	head->next = t;
	t->next = p;
	//p->next = t;
	//t->next = NULL;
	//Output(head);
	printf("��ӳɹ���");
	Sleep(500);
	system("CLS");
}
void Delete_student(STU * head)
{
	int flag,sign=0;
	char flag1;
	char flag2[50];
	char name[50], num[50];
	STU * p,* t;
	p = head->next;
	t = head;
	printf("��ѡ��\n1.ͨ������ɾ��\n2.ͨ��ѧ��ɾ��\n");
	scanf("%s", flag2);
	getchar();
	if (strcmp(flag2, "1") == 0) flag = 1;
	else if (strcmp(flag2, "2") == 0) flag = 2;
	else {
		Wrong_message();
		flag = 3;
	}
	if (flag == 1) {
		printf("������Ҫɾ����ѧ������\n");
		scanf("%s", name);
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				sign = 1;
				printf("��������������ϢΪ��\n");
				printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
				break;
			}
			else {
				p = p->next;
				t = t->next;
			}
		}
		if (sign == 0) {
			printf("���޴��ˣ��޷�ɾ��\n");
			Sleep(500);
			system("CLS");
		}
		else
		{
			t->next = p->next;
			free(p);
			printf("ɾ���ɹ���\n");
			Sleep(500);
			system("CLS");
		}
	}
	//Output(head);
	else if (flag==2) {
		printf("������Ҫɾ����ѧ��ѧ��\n");
		scanf("%s", num);
		while (p != NULL) {
			if (strcmp(num, p->num) == 0) {
				sign = 1;
				printf("��������������ϢΪ��\n");
				printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
				break;
			}
			else {
				p = p->next;
				t = t->next;
			}
		}
		if (sign == 0) {
			printf("���޴��ˣ��޷�ɾ��\n");
			Sleep(500);
			system("CLS");
		}
		else
		{
			t->next = p->next;
			free(p);
			printf("ɾ���ɹ���\n");
			Sleep(500);
			system("CLS");
		}
	}
}
void Alter_student(STU * head)
{
	int flag, sign = 0;
	char flag1;
	char flag2[50];
	char name[50], num[50];
	STU * p;
	p = head->next;
	printf("��ѡ��\n1.ͨ�������޸�\n2.ͨ��ѧ���޸�\n");
	scanf("%s", flag2);
	getchar();
	if (strcmp(flag2, "1") == 0) flag = 1;
	else if (strcmp(flag2, "2") == 0) flag = 2;
	else {
		Wrong_message();
		flag = 3;
	}
	if (flag == 1) {
		printf("������Ҫ�޸ĵ�ѧ������\n");
		scanf("%s", name);
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				sign = 1;
				printf("��������������ϢΪ��\n");
				printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
				break;
			}
			else {
				p = p->next;
			}
		}
		if (sign == 0) {
			printf("���޴��ˣ��޷��޸�\n");
			Sleep(500);
			system("CLS");
		}
		else
		{
			printf("�������޸ĵ�ѧ����Ŀһ�ɼ���\n");
			scanf("%d", &p->score[0]);
			getchar();
			printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
			scanf("%d", &p->score[1]);
			getchar();
			printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
			scanf("%d", &p->score[2]);
			getchar();
			printf("�޸ĳɹ���\n");
			Sleep(500);
			system("CLS");
		}
	}
	//Output(head);
	else if (flag==2){
		printf("������Ҫ�޸ĵ�ѧ��ѧ��\n");
		scanf("%s", num);
		while (p != NULL) {
			if (strcmp(num, p->num) == 0) {
				sign = 1;
				printf("��������������ϢΪ��\n");
				printf("%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
				break;
			}
			else {
				p = p->next;
			}
		}
		if (sign == 0) {
			printf("���޴��ˣ��޷�ɾ��\n");
			Sleep(500);
			system("CLS");
		}
		else
		{
			printf("�������޸ĵ�ѧ����Ŀһ�ɼ���\n");
			scanf("%d", &p->score[0]);
			getchar();
			printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
			scanf("%d", &p->score[1]);
			getchar();
			printf("��������ӵ�ѧ����Ŀ���ɼ���\n");
			scanf("%d", &p->score[2]);
			getchar();
			printf("�޸ĳɹ���\n");
			Sleep(500);
			system("CLS");
		}
	}
	//Output(head);
}
int Rank_student(STU * head)
{
	int i = 0, j = 0, k = 0, g = 0;
	int flag,flag2;
	char flag3[50],flag4[50];
	STU * p, *pre, *tail;
	printf("��ѡ�����ĸ��ɼ�����\n");
	printf("1.ƽ����\n2.��Ŀһ\n3.��Ŀ��\n4.��Ŀ��\n");
	scanf("%s", flag3);
	getchar();
	if (strcmp(flag3, "1") == 0) flag = 1;
	else if (strcmp(flag3, "2") == 0) flag = 2;
	else if (strcmp(flag3, "3") == 0) flag = 3;
	else if (strcmp(flag3, "4") == 0) flag = 4;
	else {
		Wrong_message();
		flag = 5;
	}
	switch (flag) {
		case 1:i = 1; break;
		case 2:j = 1; break;
		case 3:k = 1; break;
		case 4:g = 1; break;
		default: return 0; break;
	}
	system("CLS");
	printf("��ѡ�������ǽ���\n");
	printf("1.����2.����\n");
	scanf("%s", flag4);
	getchar();
	if (strcmp(flag4, "1") == 0) flag2 = 1;
	else if (strcmp(flag4, "2") == 0) flag2 = 2;
	else {
		Wrong_message();
		flag2 = 3;
		return 0;
	}
	system("CLS");
	p = head->next;
	while (p != NULL) {
		p->qort = (double)i*p->aver + j*p->score[0] + k*p->score[1] + g*p->score[2];
		p = p->next;
	}
	tail = NULL;
	pre = head;
	if (flag2 == 2) {
		while ((head->next) != tail) {
			p = head->next;
			//printf("%.2lf", p->qort);
			pre = head;
			while (p->next != tail) {
				if ((p->qort) < (p->next->qort)) {
					pre->next = p->next;
					p->next = p->next->next;
					pre->next->next = p;
					p = pre->next;
				}
				p = p->next;
				pre = pre->next;
			}
			tail = p;
		}
	}
	else if (flag2==1) {
		while ((head->next) != tail) {
			p = head->next;
			//p->qort =(double)i*p->aver + j*p->score[0] + k*p->score[1] + g*p->score[2];
			pre = head;
			while (p->next != tail) {
				if ((p->qort) > (p->next->qort)) {
					pre->next = p->next;
					p->next = p->next->next;
					pre->next->next = p;
					p = pre->next;
				}
				p = p->next;
				pre = pre->next;
			}
			tail = p;
		}
	}
	Output(head);
	return 0;
}
void Update_student(STU * head)
{
	FILE * fp;
	struct student *p;
	fp = fopen(List_S, "wt+");
	p = head->next;
	//Output(head);
	while (p != NULL) {
		fprintf(fp, "%s %s %s %d %d %d\n", p->name, p->num, p->classes, p->score[0], p->score[1], p->score[2]);
		p = p->next;
	}
	fclose(fp);
	printf("���³ɹ���");
	system("CLS");
}
