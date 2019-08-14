#include"bus.h"

void addDriverMsg()
{
	DRIVER *newMsg = NULL;
	DRIVER *head = NULL;
	DRIVER *tail = NULL;

	head = readDriverFromFile();
	tail = head;

	while (true)
	{
		if (tail->next == NULL)
		{
			break;
		}
		else
		{
			tail = tail->next;
		}
	}
	//得到最后一个节点的指针

	newMsg = (DRIVER *)malloc(sizeof(DRIVER));

	tail->next = newMsg;
	char save[100];
	printf("请输入司机编号：>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->driverNum, save);
	}

	puts("");
	printf("请输入司机姓名：>");
	scanf("%s", save);
	if (strlen(save) > 10) {
		printf("姓名输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->driverName, save);
	}
	puts("");
	printf("请输入司机性别：>");
	scanf("%s", newMsg->driverSex);
	if ((strcmp(newMsg->driverSex, "男") != 0) && (strcmp(newMsg->driverSex, "女") != 0)) {
		printf("司机性别输入有误！\n");
		system("pause");
		getchar();
		return;
	}
	puts("");
	printf("请输入司机工资：>");
	scanf("%d", &newMsg->driverSalary);
	puts("");
	printf("请输入司机驾驶汽车编号：>");
	scanf("%s", save);
	if (strlen(save) >9) {
		printf("汽车编号过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->carNum, save);
	}

	newMsg->next = NULL;

	saveDriverToFile(head->next);
	puts("添加成功！");
	system("pause");
	getchar();
	return;
	
}
void deleteDriverMsg() {
	DRIVER *findNode = NULL;
	DRIVER *head = NULL;
	DRIVER *headptr = NULL;
	char driverNumInput[100];
	bool findStatement = 0;

	head = readDriverFromFile();
	headptr = head;

	printf("请输入要删除司机的编号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(driverNumInput, save);
	}

	while (head->next != NULL) {
		if (strcmp(head->next->driverNum, driverNumInput) == 0)
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}
	if (findStatement == 1)
	{
		printf("编号  姓名  性别  工资  驾驶车辆编号\n");
		printf("%s  %s  %s  %d  %s\n", findNode->next->driverNum, findNode->next->driverName, 
			findNode->next->driverSex, findNode->next->driverSalary, findNode->next->carNum);
		puts("确认删除？（Y为确认 其它任意键取消）");

		char driverOption = 'Y';
		getchar();
		scanf("%c", &driverOption);
		if (driverOption == 'Y')
		{
			DRIVER *deleteMsg = NULL;
			deleteMsg = findNode->next;
			findNode->next = deleteMsg->next;
			free(deleteMsg);
			saveDriverToFile(headptr->next);
			puts("删除成功!");
		}
		else
		{
			puts("已取消！");
		}

		
	}
	else
	{
		printf("未找到编号为%s的司机！", driverNumInput);
	}
	system("pause");
	puts("回车返回！");
	getchar();
}
void searchDriverMsg()
{
	DRIVER *findNode = NULL;
	DRIVER *head = NULL;
	char driverNumInput[100];
	bool findStatement = 0;

	head = readDriverFromFile();
	printf("请输入要查询的司机编号：");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(driverNumInput, save);
	}
	while (head != NULL) {
		if (strcmp(head->driverNum, driverNumInput) == 0)
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("司机编号：%s\n", findNode->driverNum);
		printf("司机姓名：%s\n", findNode->driverName);
		printf("司机性别：%s\n", findNode->driverSex);
		printf("司机工资：%d\n", findNode->driverSalary);
		printf("司机所驾驶车辆编号：%s\n", findNode->carNum);
	}
	else {
		printf("未找到编号为%s的司机", driverNumInput);
	}
	system("pause");
	getchar();
}

void reviseDriverMsg()
{
	DRIVER *findNode = NULL;
	DRIVER *head = NULL;
	DRIVER *headptr = NULL;
	char driverNumInput[100];
	bool findStatement = 0;

	head = readDriverFromFile();
	headptr = head;

	char save[100];
	printf("请输入司机编号：>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("司机编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(driverNumInput, save);
	}

	while (head != NULL) {
		if (strcmp(head->driverNum, driverNumInput) == 0)
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}
	if (findStatement == 1)
	{
		printf("编号  姓名  性别  工资  驾驶车辆编号\n");
		printf("%s  %s  %s  %d  %s\n", findNode->driverNum, findNode->driverName, findNode->driverSex, findNode->driverSalary, findNode->carNum);

		printf("请输入修改后的编号：>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("编号输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->driverNum, save);
		}
		puts("");

		printf("请输入修改后的姓名：>");
		scanf("%s", save);
		if (strlen(save) > 10) {
			printf("姓名输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->driverName, save);
		}
		puts("");

		printf("请输入修改后的性别：>");
		scanf("%s", findNode->driverSex);
		if ((strcmp(findNode->driverSex, "男") != 0) && (strcmp(findNode->driverSex, "女") != 0)) {
			printf("司机性别输入有误！\n");
			system("pause");
			getchar();
			return;
		}
		puts("");

		printf("请输入修改后的工资：>");
		scanf("%d", &findNode->driverSalary);
		puts("");

		printf("请输入修改后驾驶车辆的编号：>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("编号输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->carNum, save);
		}
		puts("");

		printf("编号  姓名  性别  工资  驾驶车辆编号\n");
		printf("%s  %s  %s  %d      %s\n", findNode->driverNum, findNode->driverName, findNode->driverSex, findNode->driverSalary, findNode->carNum);
		saveDriverToFile(headptr->next);
		puts("修改成功！");
	}
	else
	{
		printf("未找到编号为%s的司机", driverNumInput);
	}


	system("pause");
	getchar();
}