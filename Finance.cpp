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

	printf("请输入要查询的日期：>(如2018-08-01)");
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
		printf("未找到日期为%s的收入，请检查输入的日期格式是否正确！\n", dateIn);
	}

	else
	{
		printf("%s的总收入为%.2f\n", dateIn, dateIncome);
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

	printf("请输入要查询的线路：>(如001)");
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
		printf("未找到线路编号为%s的收入，请检查输入的线路编号格式是否正确！\n", routineIn);
	}

	else
	{
		printf("%s号线路的总收入为%.2f\n", routineIn, routineIncome);
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

	printf("请输入要查询的车辆编号：>(如001)");
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
		printf("未找到车辆编号为%s的收入，请检查输入的车辆编号格式是否正确！\n", carIn);
	}

	else
	{
		printf("%s号车的总收入为%.2f\n", carIn, carIncome);
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

	printf("请输入要查询的年份：>(如2018)");
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
		printf("未找到%s年的收入，请检查输入的年份格式是否正确！\n", yearIn);
	}

	else
	{
		printf("%s年的总收入为%.2f\n", yearIn, yearIncome);
	}

	system("pause");
	getchar();
}

void leaveTime()
{
	char drivernumber[5];
	printf("请输入司机编号：>");
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
	//判断financemsg中是否存在该司机编号 
	if (flag == 0) {
		printf("不存在该编号司机");
	}
	if (flag == 1) {
		printf("正在匹配该司机\n");
		LEAVE *headptr;
		LEAVE *saveptr;
		headptr = readLeaveFromFile();
		saveptr = headptr;
		headptr = headptr->next;
		char date[20];
		int flagptr = 0;
		printf("请输入需要请假的日期：>(如1999-01-01)");
		scanf("%s", date);
		while (headptr != NULL) {
			if (strcmp(drivernumber, headptr->driverNum) == 0 && strcmp(date, headptr->date) == 0) {
				printf("已请过假");
				system("pause");
				flagptr = 1;
				break;
			}
			headptr = headptr->next;
		}
		if (flagptr == 0) {
			printf("请假成功");
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
	printf("请输入司机编号：>");
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
	}	//判断financemsg中是否存在该司机编号 
	if (flag == 0) {
		printf("不存在该编号司机");
	}
	if (flag == 1) {
		printf("正在匹配该司机\n");
		LEAVE *headptr;
		LEAVE *saveptr;
		headptr = readLeaveFromFile();
		saveptr = headptr;
		headptr = headptr->next;
		char date[20];
		int flagptr = 0;
		printf("请输入需要加班的日期：>(如1999-01-01)");
		scanf("%s", date);
		while (headptr != NULL) {
			if (strcmp(drivernumber, headptr->driverNum) == 0 && strcmp(date, headptr->date) == 0) {
				printf("已加过班");
				system("pause");
				flagptr = 1;
				break;
			}
			headptr = headptr->next;
		}
		if (flagptr == 0) {
			printf("成功添加加班");
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
	printf("请输入司机编号：>");
	scanf("%s", driverNum);
	printf("请输入司机姓名：>");
	scanf("%s", driverName);
	printf("请输入请假时间：>");
	scanf("%d", &leaveTime);
	printf("请输入加班时间：>");
	scanf("%d", &extraTime);
	printf("请输入实际工资：>");
	scanf("%d", &driverSalary);
	FILE *cfptr;
	cfptr = fopen("financemsg.txt", "a+");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}
	fprintf(cfptr, "%s %s %d %d %d\n", driverNum, driverName, leaveTime, extraTime, driverSalary);
	fclose(cfptr);
	printf("添加完成");
	system("pause");
	getchar();
	
}

void printFinance()
{
	printf("请输入司机编号：>");
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
	//判断financemsg中是否存在该司机编号 
	if (flag == 0) {
		printf("不存在该编号司机");
		
	}
	else {
		head->driverSalary = 5000 + 200 * head->extraTime - 100 * head->leaveTime;
		printf("司机编号    司机姓名    请假时长    加班时长    工资\n");
		printf("%s         %s         %d           %d          %d", head->driverNum, head->driverName, head->leaveTime, head->extraTime, head->driverSalary);
	
	}
	
	system("pause");
	getchar();
}
