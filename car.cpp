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

	printf("������������ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->carNum, save);
	}
	puts("");
	printf("�����복�ƺţ�>");
	scanf("%s", save);
	if (strlen(save) > 8) {
		printf("���ƺ����������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->plateNum, save);
	}
	puts("");
	printf("����������·�߱�ţ�>");
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->belongRoute, save);
	}
	puts("");
	printf("�����뱣�����ڣ�>");
	scanf("%s", save);
	if (strlen(save) > 20) {
		printf("�����������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->secureTime, save);
	}
	puts("");
	printf("������ά��״����>");
	scanf("%s", save);
	if ((strcmp(save, "Y") != 0) && (strcmp(save, "N") != 0)) {
		printf("ά��״���������\n");
		system("pause");
		getchar();
		return;
	}
	else {
		strcpy(newMsg->isRepair, save);
	}
	newMsg->next = NULL;

	saveCarToFile(head->next);

	puts("��ӳɹ���");
	system("pause");
	getchar();

}
void searchCarMsg() {
	CAR *findNode = NULL;
	CAR *head = NULL;

	char carNumInput[100] = {};
	bool findStatement = 0;

	head = readCarFromFile();

	printf("������������ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
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
		printf("���  ���ƺ�  ����·�߱��      ��������       ά��״��\n");
		printf("%s     %s         %s         %s     %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);
	}
	else
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������", carNumInput);
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

	printf("������������ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
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
		printf("���  ���ƺ�  ����·�߱��      ��������       ά��״��\n");
		printf("%s     %s         %s         %s     %s\n", findNode->next->carNum, findNode->next->plateNum,
			findNode->next->belongRoute, findNode->next->secureTime, findNode->next->isRepair);
		puts("ȷ��ɾ������YΪȷ�� ���������ȡ����");
		
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
			puts("ɾ���ɹ�!");
		}
		else
		{
			puts("��ȡ����");
		}
	}
	else if(findStatement == 0)
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������", carNumInput);
	}
	system("pause");
	puts("�س����أ�");
	_getch();
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
}

void reviseCarMsg() {
	CAR *findNode = NULL;
	CAR *head = NULL;
	CAR *headptr = NULL;
	char carNumInput[100] = {};
	bool findStatement = 0;

	head = readCarFromFile();
	headptr = head;

	printf("������������ţ�>");
	char save[100];
	scanf("%s", save);
	if (strlen(save) > 3) {
		printf("������������\n");
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
		printf("���  ���ƺ�  ����·�߱��      ��������       ά��״��\n");
		printf("%s     %s         %s         %s     %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);

		printf("�������޸ĺ��������ţ�>");
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

		printf("�������޸ĺ�ĳ��ƺţ�>");
		scanf("%s", save);
		if (strlen(save) > 8) {
			printf("���ƺ����������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->plateNum, save);
		}
		puts("");

		printf("�������޸ĺ������·�߱�ţ�>");
		scanf("%s", save);
		if (strlen(save) > 3) {
			printf("������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->belongRoute, save);
		}
		puts("");

		printf("�������޸ĺ�ı������ڣ�>");
		scanf("%s", save);
		if (strlen(save) > 10) {
			printf("�������������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->secureTime, save);
		}

		printf("�������޸ĺ��ά��״����>");
		scanf("%s", save);
		if ((strcmp(save, "Y") != 0) && (strcmp(save, "N") != 0)) {
			printf("ά��״���������\n");
			system("pause");
			getchar();
			return;
		}
		else {
			strcpy(findNode->isRepair, save);
		}
		puts("");

		printf("���  ���ƺ�      ����·�߱��      ��������       ά��״��\n");
		printf("%s   %s     %s         %s         %s\n", findNode->carNum, findNode->plateNum,
			findNode->belongRoute, findNode->secureTime, findNode->isRepair);
		saveCarToFile(headptr->next);
		puts("�޸ĳɹ���");
	}
	else
	{
		printf("δ�ҵ����Ϊ%s�Ĺ�������", carNumInput);
	}
	system("pause");
	getchar();
}