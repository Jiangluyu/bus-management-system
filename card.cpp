#include "bus.h"
/*
char cardNum[3];//卡号
char passengerName[10];//乘客姓名
int passengerAge;//乘客年龄
char cardType[8];//卡的类型
float accountBalance;//卡内余额
struct card *next;
*/
void addCardMsg()
{
	CARD *newMsg = NULL;//创建新数据被保存到的结点
	CARD *head = NULL;
	CARD *tail = NULL;

	head = readCardFromFile();
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
	//得到最后一个结点的指针

	newMsg = (CARD *)malloc(sizeof(CARD));

	tail->next = newMsg;

	char save[100];
	printf("请输入卡号：>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("卡号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->cardNum, save);
	}
	puts("");
	printf("请输入持卡人姓名：>");
	scanf("%s", save);
	if (strlen(save) > 10) {
		printf("姓名输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->passengerName, save);
	}
	puts("");
	printf("请输入持卡人年龄：>");
	scanf("%d", &newMsg->passengerAge);
	if (newMsg->passengerAge > 150) {
		printf("年龄不合理！\n");
		system("pause");
		getchar();
		return;
	}
	puts("");
	printf("请输入卡类型：>");
	scanf("%s", save);
	if ((strcmp(save, "老年卡") != 0) && (strcmp(save, "普通卡") != 0) && (strcmp(save, "学生卡") != 0)) {
		printf("卡的类型错误！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->cardType, save);
	}
	puts("");
	printf("请输入卡内余额：>");
	scanf("%f", &newMsg->accountBalance);


	newMsg->next = NULL;

	saveCardToFile(head->next);
	puts("添加成功！\n");
	system("pause");
	getchar();
}

void searchCardMsg()
{
	CARD *findNode = NULL;
	CARD *head = NULL;
	char cardNumInput[100] = {};
	bool findStatement = 0;

	head = readCardFromFile();

	printf("请输入要查找的卡号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("卡号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(cardNumInput, save);
	}


	while (head != NULL)
	{
		if ((strcmp(head->cardNum, cardNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("卡号  持卡人姓名  持卡人年龄      卡种       余额\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);
	}
	else
	{
		printf("未找到编号为%s的公交卡！\n", cardNumInput);
	}
	system("pause");
	getchar();
}

void deleteCardMsg()
{

	CARD *findNode = NULL;
	CARD *head = NULL;
	CARD *headptr = NULL;
	char cardNumInput[100] = {};
	bool findStatement = 0;

	head = readCardFromFile();
	headptr = head;

	printf("请输入要删除的卡号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("卡号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(cardNumInput, save);
	}

	while (head->next != NULL)
	{
		if ((strcmp((head->next)->cardNum, cardNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("卡号  持卡人姓名  持卡人年龄      卡种       余额\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->next->cardNum, findNode->next->passengerName,
			findNode->next->passengerAge, findNode->next->cardType, findNode->next->accountBalance);
		puts("确认删除？（Y为确认 其它任意键取消）");
		char cardOption = 'Y';
		getchar();
		scanf("%c", &cardOption);
		if (cardOption == 'Y')
		{
			CARD *deleteMsg = NULL;
			deleteMsg = findNode->next;
			findNode->next = deleteMsg->next;
			free(deleteMsg);
			saveCardToFile(headptr->next);
			puts("删除成功!\n");
		}
		else
		{
			puts("已取消!\n");
		}

	}
	else
	{
		printf("未找到编号为%s的公交卡！\n", cardNumInput);
	}
	system("pause");
	puts("回车返回！");
	getchar();
}

void reviseCardMsg()
{
	CARD *findNode = NULL;
	CARD *head = NULL;
	CARD *headptr = NULL;
	char cardNumInput[100] = {};
	bool findStatement = 0;

	head = readCardFromFile();
	headptr = head;

	printf("请输入要修改的卡号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("卡号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(cardNumInput, save);
	}

	while (head != NULL)
	{
		if ((strcmp(head->cardNum, cardNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("卡号  持卡人姓名  持卡人年龄      卡种       余额\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);

		printf("请输入修改后的卡号：>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("卡号输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->cardNum, save);
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
			strcpy(findNode->passengerName, save);
		}
		puts("");

		printf("请输入修改后的年龄：>");
		scanf("%d", &findNode->passengerAge);
		if (findNode->passengerAge > 150) {
			printf("年龄不合理！\n");
			system("pause");
			getchar();
			return;
		}
		puts("");

		printf("请输入修改后的卡种：>");
		scanf("%s", save);
		if ((strcmp(save, "老年卡") != 0) && (strcmp(save, "普通卡") != 0) && (strcmp(save, "学生卡") != 0)) {
			printf("卡的类型错误！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->cardType, save);
		}
		puts("");

		printf("请输入修改后的余额：>");
		scanf("%f", &findNode->accountBalance);
		puts("");

		printf("卡号  持卡人姓名  持卡人年龄      卡种       余额\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);
		saveCardToFile(headptr->next);
		puts("");

	}
	else
	{
		printf("未找到编号为%s的公交卡！\n", cardNumInput);
	}
	system("pause");
	getchar();
}