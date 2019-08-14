#include "bus.h"

void printDateIncome()
{
	INCOME *head;
	INCOME *headptr;
	INCOME *findDateNode;

	char dateIn[20] = {};
	float dateIncome = 0.0;
	bool findDateStatement = 0;

	head = readIncomeFromFile();
	headptr = head;

	printf("������Ҫ��ѯ�����ڣ�>(��2018-08-01)");
	scanf("%s", dateIn);

	while (head != NULL)
	{
		if (strcmp(head->date, dateIn) == 0)
		{
			findDateStatement = 1;
			findDateNode = head;
			dateIncome += findDateNode->incomeStat;
		}
		head = head->next;
	}

	if (findDateStatement == 0)
	{
		printf("δ�ҵ�����Ϊ%s�����룬������������ڸ�ʽ�Ƿ���ȷ��\n", dateIn);
	}

	else
	{
		printf("%s��������Ϊ%.2f\n", dateIn, dateIncome);
	}

	system("pause");
	getchar();
}

void printRoutineIncome()
{
	INCOME *head;
	INCOME *headptr;
	INCOME *findRoutineNode;

	char routineIn[20] = {};
	float routineIncome = 0.0;
	bool findRoutineStatement = 0;

	head = readIncomeFromFile();
	headptr = head;

	printf("������Ҫ��ѯ����·��>(��001)");
	scanf("%s", routineIn);

	while (head!= NULL)
	{
		if (strcmp(head->routineNum, routineIn) == 0)
		{
			findRoutineStatement = 1;
			findRoutineNode = head;
			routineIncome += findRoutineNode->incomeStat;
		}
		head = head->next;
	}

	if (findRoutineStatement == 0)
	{
		printf("δ�ҵ���·���Ϊ%s�����룬�����������·��Ÿ�ʽ�Ƿ���ȷ��\n", routineIn);
	}

	else
	{
		printf("%s����·��������Ϊ%.2f\n", routineIn, routineIncome);
	}

	system("pause");
	getchar();
}

void printCarIncome()
{
	INCOME *head;
	INCOME *headptr;
	INCOME *findCarNode;

	char carIn[20] = {};
	float carIncome = 0.0;
	bool findCarStatement = 0;

	head = readIncomeFromFile();
	headptr = head;

	printf("������Ҫ��ѯ�ĳ�����ţ�>(��001)");
	scanf("%s", carIn);

	while (head != NULL)
	{
		if (strcmp(head->carNum, carIn) == 0)
		{
			findCarStatement = 1;
			findCarNode = head;
			carIncome += findCarNode->incomeStat;
		}
		head = head->next;
	}

	if (findCarStatement == 0)
	{
		printf("δ�ҵ��������Ϊ%s�����룬��������ĳ�����Ÿ�ʽ�Ƿ���ȷ��\n", carIn);
	}

	else
	{
		printf("%s�ų���������Ϊ%.2f\n", carIn, carIncome);
	}

	system("pause");
	getchar();
}

void printYearIncome()
{
	INCOME *head;
	INCOME *headptr;
	INCOME *findYearNode;

	char yearIn[20] = {};
	char yearTemp[20] = {};
	float yearIncome = 0.0;
	bool findYearStatement = 0;

	head = readIncomeFromFile();
	headptr = head;

	printf("������Ҫ��ѯ����ݣ�>(��2018)");
	scanf("%s", yearIn);

	while (head->next != NULL)
	{
		strncpy(yearTemp, head->date, 4);
		if (strcmp(yearTemp, yearIn) == 0)
		{
			findYearStatement = 1;
			findYearNode = head;
			yearIncome += findYearNode->incomeStat;
		}
		head = head->next;
	}

	if (findYearStatement == 0)
	{
		printf("δ�ҵ�%s������룬�����������ݸ�ʽ�Ƿ���ȷ��\n", yearIn);
	}

	else
	{
		printf("%s���������Ϊ%.2f\n", yearIn, yearIncome);
	}

	system("pause");
	getchar();
}

void leaveTime()
{
	char drivernumber[5];
	printf("������˾����ţ�>");
	scanf("%s", drivernumber);
	SALARYCAL *head;
	SALARYCAL *save;
	head = readFinanceFromFile();
	save = head; 
	head = head->next;
	int flag = 0;
	while (head != NULL) {
		if (strcmp(drivernumber, head->driverNum) == 0) {
			flag = 1;
			break;
		}
		head = head->next;
	}	
	//�ж�financemsg���Ƿ���ڸ�˾����� 
	if (flag == 0) {
		printf("�����ڸñ��˾��");
	}
	if (flag == 1) {
		printf("����ƥ���˾��\n");
		LEAVE *headptr;
		LEAVE *saveptr;
		headptr = readLeaveFromFile();
		saveptr = headptr;
		headptr = headptr->next;
		char date[20];
		int flagptr = 0;
		printf("��������Ҫ��ٵ����ڣ�>(��1999-01-01)");
		scanf("%s", date);
		while (headptr != NULL) {
			if (strcmp(drivernumber, headptr->driverNum) == 0 && strcmp(date, headptr->date) == 0) {
				printf("�������");
				system("pause");
				flagptr = 1;
				break;
			}
			headptr = headptr->next;
		}
		if (flagptr == 0) {
			printf("��ٳɹ�");
			system("pause");
			head->leaveTime++;
			saveFinanceToFile(save);
			saveLeaveToFile(saveptr);
		}
	}
}

void extratime()
{
	char drivernumber[5];
	printf("������˾����ţ�>");
	scanf("%s", drivernumber);
	SALARYCAL *head;
	SALARYCAL *save;
	head = readFinanceFromFile();
	save = head;
	head = head->next;
	int flag = 0;
	while (head != NULL) {
		if (strcmp(drivernumber, head->driverNum) == 0) {
			flag = 1;
			break;
		}
		head = head->next;
	}	//�ж�financemsg���Ƿ���ڸ�˾����� 
	if (flag == 0) {
		printf("�����ڸñ��˾��");
	}
	if (flag == 1) {
		printf("����ƥ���˾��\n");
		LEAVE *headptr;
		LEAVE *saveptr;
		headptr = readLeaveFromFile();
		saveptr = headptr;
		headptr = headptr->next;
		char date[20];
		int flagptr = 0;
		printf("��������Ҫ�Ӱ�����ڣ�>(��1999-01-01)");
		scanf("%s", date);
		while (headptr != NULL) {
			if (strcmp(drivernumber, headptr->driverNum) == 0 && strcmp(date, headptr->date) == 0) {
				printf("�Ѽӹ���");
				system("pause");
				flagptr = 1;
				break;
			}
			headptr = headptr->next;
		}
		if (flagptr == 0) {
			printf("�ɹ���ӼӰ�");
			system("pause");
			head->leaveTime++;
			saveFinanceToFile(save);
			saveLeaveToFile(saveptr);
		}
	}
}

void addFinance()
{
	char driverNum[100];
	char driverName[100];
	int leaveTime;
	int extraTime;
	int driverSalary;
	printf("������˾����ţ�>");
	scanf("%s", driverNum);
	printf("������˾��������>");
	scanf("%s", driverName);
	printf("���������ʱ�䣺>");
	scanf("%d", &leaveTime);
	printf("������Ӱ�ʱ�䣺>");
	scanf("%d", &extraTime);
	printf("������ʵ�ʹ��ʣ�>");
	scanf("%d", &driverSalary);
	FILE *cfptr;
	cfptr = fopen("financemsg.txt", "a+");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}
	fprintf(cfptr, "%s %s %d %d %d\n", driverNum, driverName, leaveTime, extraTime, driverSalary);
	fclose(cfptr);
	printf("������");
	system("pause");
	getchar();
	
}

void printFinance()
{
	printf("������˾����ţ�>");
	char drivernumber[100];
	scanf("%s", drivernumber);
	SALARYCAL *head;
	SALARYCAL *save;
	head = readFinanceFromFile();
	save = head;
	head = head->next;
	int flag = 0;
	while (head != NULL) {
		if (strcmp(drivernumber, head->driverNum) == 0) {
			flag = 1;
			break;
		}
		head = head->next;
	}	
	//�ж�financemsg���Ƿ���ڸ�˾����� 
	if (flag == 0) {
		printf("�����ڸñ��˾��");
		
	}
	else {
		head->driverSalary = 5000 + 200 * head->extraTime - 100 * head->leaveTime;
		printf("˾�����    ˾������    ���ʱ��    �Ӱ�ʱ��    ����\n");
		printf("%s         %s         %d           %d          %d", head->driverNum, head->driverName, head->leaveTime, head->extraTime, head->driverSalary);
	
	}
	
	system("pause");
	getchar();
}
