#include "bus.h"
/*
char cardNum[3];//����
char passengerName[10];//�˿�����
int passengerAge;//�˿�����
char cardType[8];//��������
float accountBalance;//�������
struct card *next;
*/
void addCardMsg()
{
	CARD *newMsg = NULL;//���������ݱ����浽�Ľ��
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
	//�õ����һ������ָ��

	newMsg = (CARD *)malloc(sizeof(CARD));

	tail->next = newMsg;

	char save[100];
	printf("�����뿨�ţ�>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("�������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->cardNum, save);
	}
	puts("");
	printf("������ֿ���������>");
	scanf("%s", save);
	if (strlen(save) > 10) {
		printf("�������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->passengerName, save);
	}
	puts("");
	printf("������ֿ������䣺>");
	scanf("%d", &newMsg->passengerAge);
	if (newMsg->passengerAge > 150) {
		printf("���䲻����\n");
		system("pause");
		getchar();
		return;
	}
	puts("");
	printf("�����뿨���ͣ�>");
	scanf("%s", save);
	if ((strcmp(save, "���꿨") != 0) && (strcmp(save, "��ͨ��") != 0) && (strcmp(save, "ѧ����") != 0)) {
		printf("�������ʹ���\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->cardType, save);
	}
	puts("");
	printf("�����뿨����>");
	scanf("%f", &newMsg->accountBalance);


	newMsg->next = NULL;

	saveCardToFile(head->next);
	puts("��ӳɹ���\n");
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

	printf("������Ҫ���ҵĿ��ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("�������������\n");
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
		printf("����  �ֿ�������  �ֿ�������      ����       ���\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);
	}
	else
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������\n", cardNumInput);
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

	printf("������Ҫɾ���Ŀ��ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("�������������\n");
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
		printf("����  �ֿ�������  �ֿ�������      ����       ���\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->next->cardNum, findNode->next->passengerName,
			findNode->next->passengerAge, findNode->next->cardType, findNode->next->accountBalance);
		puts("ȷ��ɾ������YΪȷ�� ���������ȡ����");
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
			puts("ɾ���ɹ�!\n");
		}
		else
		{
			puts("��ȡ��!\n");
		}

	}
	else
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������\n", cardNumInput);
	}
	system("pause");
	puts("�س����أ�");
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

	printf("������Ҫ�޸ĵĿ��ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("�������������\n");
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
		printf("����  �ֿ�������  �ֿ�������      ����       ���\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);

		printf("�������޸ĺ�Ŀ��ţ�>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("�������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->cardNum, save);
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
			strcpy(findNode->passengerName, save);
		}
		puts("");

		printf("�������޸ĺ�����䣺>");
		scanf("%d", &findNode->passengerAge);
		if (findNode->passengerAge > 150) {
			printf("���䲻����\n");
			system("pause");
			getchar();
			return;
		}
		puts("");

		printf("�������޸ĺ�Ŀ��֣�>");
		scanf("%s", save);
		if ((strcmp(save, "���꿨") != 0) && (strcmp(save, "��ͨ��") != 0) && (strcmp(save, "ѧ����") != 0)) {
			printf("�������ʹ���\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->cardType, save);
		}
		puts("");

		printf("�������޸ĺ����>");
		scanf("%f", &findNode->accountBalance);
		puts("");

		printf("����  �ֿ�������  �ֿ�������      ����       ���\n");
		printf("%s     %s         %d         %s     %.2f\n", findNode->cardNum, findNode->passengerName,
			findNode->passengerAge, findNode->cardType, findNode->accountBalance);
		saveCardToFile(headptr->next);
		puts("");

	}
	else
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������\n", cardNumInput);
	}
	system("pause");
	getchar();
}