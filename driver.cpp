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
	//�õ����һ���ڵ��ָ��

	newMsg = (DRIVER *)malloc(sizeof(DRIVER));

	tail->next = newMsg;
	char save[100];
	printf("������˾����ţ�>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->driverNum, save);
	}

	puts("");
	printf("������˾��������>");
	scanf("%s", save);
	if (strlen(save) > 10) {
		printf("�������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->driverName, save);
	}
	puts("");
	printf("������˾���Ա�>");
	scanf("%s", newMsg->driverSex);
	if ((strcmp(newMsg->driverSex, "��") != 0) && (strcmp(newMsg->driverSex, "Ů") != 0)) {
		printf("˾���Ա���������\n");
		system("pause");
		getchar();
		return;
	}
	puts("");
	printf("������˾�����ʣ�>");
	scanf("%d", &newMsg->driverSalary);
	puts("");
	printf("������˾����ʻ������ţ�>");
	scanf("%s", save);
	if (strlen(save) >9) {
		printf("������Ź�����\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->carNum, save);
	}

	newMsg->next = NULL;

	saveDriverToFile(head->next);
	puts("��ӳɹ���");
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

	printf("������Ҫɾ��˾���ı�ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
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
		printf("���  ����  �Ա�  ����  ��ʻ�������\n");
		printf("%s  %s  %s  %d  %s\n", findNode->next->driverNum, findNode->next->driverName, 
			findNode->next->driverSex, findNode->next->driverSalary, findNode->next->carNum);
		puts("ȷ��ɾ������YΪȷ�� ���������ȡ����");

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
			puts("ɾ���ɹ�!");
		}
		else
		{
			puts("��ȡ����");
		}

		
	}
	else
	{
		printf("δ�ҵ����Ϊ%s��˾����", driverNumInput);
	}
	system("pause");
	puts("�س����أ�");
	getchar();
}
void searchDriverMsg()
{
	DRIVER *findNode = NULL;
	DRIVER *head = NULL;
	char driverNumInput[100];
	bool findStatement = 0;

	head = readDriverFromFile();
	printf("������Ҫ��ѯ��˾����ţ�");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
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
		printf("˾����ţ�%s\n", findNode->driverNum);
		printf("˾��������%s\n", findNode->driverName);
		printf("˾���Ա�%s\n", findNode->driverSex);
		printf("˾�����ʣ�%d\n", findNode->driverSalary);
		printf("˾������ʻ������ţ�%s\n", findNode->carNum);
	}
	else {
		printf("δ�ҵ����Ϊ%s��˾��", driverNumInput);
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
	printf("������˾����ţ�>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("˾��������������\n");
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
		printf("���  ����  �Ա�  ����  ��ʻ�������\n");
		printf("%s  %s  %s  %d  %s\n", findNode->driverNum, findNode->driverName, findNode->driverSex, findNode->driverSalary, findNode->carNum);

		printf("�������޸ĺ�ı�ţ�>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->driverNum, save);
		}
		puts("");

		printf("�������޸ĺ��������>");
		scanf("%s", save);
		if (strlen(save) > 10) {
			printf("�������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->driverName, save);
		}
		puts("");

		printf("�������޸ĺ���Ա�>");
		scanf("%s", findNode->driverSex);
		if ((strcmp(findNode->driverSex, "��") != 0) && (strcmp(findNode->driverSex, "Ů") != 0)) {
			printf("˾���Ա���������\n");
			system("pause");
			getchar();
			return;
		}
		puts("");

		printf("�������޸ĺ�Ĺ��ʣ�>");
		scanf("%d", &findNode->driverSalary);
		puts("");

		printf("�������޸ĺ��ʻ�����ı�ţ�>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->carNum, save);
		}
		puts("");

		printf("���  ����  �Ա�  ����  ��ʻ�������\n");
		printf("%s  %s  %s  %d      %s\n", findNode->driverNum, findNode->driverName, findNode->driverSex, findNode->driverSalary, findNode->carNum);
		saveDriverToFile(headptr->next);
		puts("�޸ĳɹ���");
	}
	else
	{
		printf("δ�ҵ����Ϊ%s��˾��", driverNumInput);
	}


	system("pause");
	getchar();
}