#include"bus.h"

void addCarMsg() {
	CAR *newMsg = NULL;
	CAR *head = NULL;
	CAR *tail = NULL;

	head = readCarFromFile();
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
	newMsg = (CAR*)malloc(sizeof(CAR));

	tail->next = newMsg;

	printf("请输入汽车编号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->carNum, save);
	}
	puts("");
	printf("请输入车牌号：>");
	scanf("%s", save);
	if (strlen(save) > 8) {
		printf("车牌号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->plateNum, save);
	}
	puts("");
	printf("请输入所属路线编号：>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->belongRoute, save);
	}
	puts("");
	printf("请输入保险日期：>");
	scanf("%s", save);
	if (strlen(save) > 20) {
		printf("日期输入错误！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->secureTime, save);
	}
	puts("");
	printf("请输入维修状况：>");
	scanf("%s", save);
	if ((strcmp(save, "Y") != 0) && (strcmp(save, "N") != 0)) {
		printf("维修状况添加有误！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->isRepair, save);
	}
	newMsg->next = NULL;

	saveCarToFile(head->next);

	puts("添加成功！");
	system("pause");
	getchar();

}
void searchCarMsg() {
	CAR *findNode = NULL;
	CAR *head = NULL;

	char carNumInput[100] = {};
	bool findStatement = 0;

	head = readCarFromFile();

	printf("请输入汽车编号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(carNumInput, save);
	}

	while (head != NULL)
	{
		if ((strcmp(head->carNum, carNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("编号  车牌号  所属路线编号      保险日期       维修状况\n");
		printf("%s     %s         %s         %s     %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);
	}
	else
	{
		printf("未找到编号为%s的公交车！", carNumInput);
	}
	system("pause");
	getchar();
}

void deleteCarMsg() {
	CAR *findNode = NULL;
	CAR *head = NULL;
	CAR *headptr = NULL;
	char carNumInput[100] = {};
	bool findStatement = 0;

	head = readCarFromFile();
	headptr = head;

	printf("请输入汽车编号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(carNumInput, save);
	}

	while (head->next != NULL)
	{
		if ((strcmp(head->next->carNum, carNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("编号  车牌号  所属路线编号      保险日期       维修状况\n");
		printf("%s     %s         %s         %s     %s\n", findNode->next->carNum, findNode->next->plateNum,
			findNode->next->belongRoute, findNode->next->secureTime, findNode->next->isRepair);
		puts("确认删除？（Y为确认 其它任意键取消）");
		
		char carOption = 'Y';
		
		getchar();
		scanf("%c", &carOption);
	
		if (carOption == 'Y')
		{
			CAR *deleteMsg = NULL;
			deleteMsg = findNode->next;
			findNode->next = deleteMsg->next;
			free(deleteMsg);
			saveCarToFile(headptr->next);
			puts("删除成功!");
		}
		else
		{
			puts("已取消！");
		}
	}
	else if(findStatement == 0)
	{
		printf("未找到编号为%s的公交车！", carNumInput);
	}
	system("pause");
	puts("回车返回！");
	_getch();
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
}

void reviseCarMsg() {
	CAR *findNode = NULL;
	CAR *head = NULL;
	CAR *headptr = NULL;
	char carNumInput[100] = {};
	bool findStatement = 0;

	head = readCarFromFile();
	headptr = head;

	printf("请输入汽车编号：>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("编号输入过长！\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(carNumInput, save);
	}

	while (head != NULL)
	{
		if ((strcmp(head->carNum, carNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("编号  车牌号  所属路线编号      保险日期       维修状况\n");
		printf("%s     %s         %s         %s     %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);

		printf("请输入修改后的汽车编号：>");
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

		printf("请输入修改后的车牌号：>");
		scanf("%s", save);
		if (strlen(save) > 8) {
			printf("车牌号输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->plateNum, save);
		}
		puts("");

		printf("请输入修改后的所属路线编号：>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("编号输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->belongRoute, save);
		}
		puts("");

		printf("请输入修改后的保险日期：>");
		scanf("%s", save);
		if (strlen(save) > 10) {
			printf("日期输入过长！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->secureTime, save);
		}

		printf("请输入修改后的维修状况：>");
		scanf("%s", save);
		if ((strcmp(save, "Y") != 0) && (strcmp(save, "N") != 0)) {
			printf("维修状况添加有误！\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->isRepair, save);
		}
		puts("");

		printf("编号  车牌号      所属路线编号      保险日期       维修状况\n");
		printf("%s   %s     %s         %s         %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);
		saveCarToFile(headptr->next);
		puts("修改成功！");
	}
	else
	{
		printf("未找到编号为%s的公交车！", carNumInput);
	}
	system("pause");
	getchar();
}