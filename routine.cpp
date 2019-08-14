#include"bus.h"

void addRoutineLineMsg()
{
	ROUTINE *newMsg = NULL;//���������ݱ����浽�Ľ��
	ROUTINE *head = NULL;
	ROUTINE *tail = NULL;

	head = readRoutineFromFile();
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

	newMsg = (ROUTINE *)malloc(sizeof(ROUTINE));

	tail->next = newMsg;

	printf("��������·��ţ�>");
	scanf("%s", newMsg->routineNum);
	puts("");
	printf("������վ��������>");
	scanf("%d", &newMsg->stops);
	puts("");
	for (int i = 0; i < newMsg->stops; i++)
	{
		printf("�������%dվվ����>", i+1);
		_itoa(i, newMsg->stop[i].stopNum, 10);
		scanf("%s", newMsg->stop[i].stopName);
	}
	
	newMsg->next = NULL;

	saveRoutineToFile(head->next);
	puts("��ӳɹ���");
	system("pause");
	getchar();
}

void addRoutineStopMsg()
{
	ROUTINE *head = NULL;
	ROUTINE *findNode = NULL;
	char routineNumIn[100];
	int addStops = 0;
	int addPlaceNum = 0;

	head = readRoutineFromFile();
	findNode = head;

	printf("��������·��ţ�>");
	scanf("%s", routineNumIn);
	puts("");
	while (findNode->next != NULL)
	{
		if (strcmp(findNode->routineNum, routineNumIn) != 0)
		{
			findNode = findNode->next;
		}
		else
		{
			break;
		}
	}
	//Ѱ�ұ����������ͬ����·�ڵ�

	printf("���������ӵ�վ��������>");
	scanf("%d", &addStops);

	printf("�������ڵڼ�վ������վ�㣺>");
	scanf("%d", &addPlaceNum);

	for (int i = 0; i < (findNode->stops-addStops+1); i++)
	{
		strcpy(findNode->stop[(findNode->stops)-i-1+addStops].stopName, findNode->stop[(findNode->stops)-i-1].stopName);
		//����ƶ�վ��addStops��λ��
		int Numtemp = atoi(findNode->stop[(findNode->stops)-i-1].stopNum);
		Numtemp += addStops;
		_itoa(Numtemp, findNode->stop[(findNode->stops)-i-1+addStops].stopNum, 10);
		//����վ����Ӧ��˳����
	}
	//����addPlace+1վ�Ժ��վ����Ϣ���ŲaddStops��λ��

	for (int i = 0; i < addStops; i++)
	{
		_itoa(addPlaceNum+1+i, findNode->stop[addPlaceNum+i].stopNum, 10);
		//�����addPlaceNum+1+i��λ�õı��
		printf("�������%dվ��վ��", addPlaceNum+1+i);
		scanf("%s", findNode->stop[addPlaceNum+i].stopName);
	}

	findNode->stops += addStops;
	//���վ��
	
	/*printf("%s %d ", findNode->routineNum, findNode->stops);
	for (int i = 0; i < findNode->stops; i++)
	{
		printf("%s %s", findNode->stop[i].stopNum, findNode->stop[i].stopName);
	}
	puts("");
	findNode = findNode->next;
	printf("%s %d ", findNode->routineNum, findNode->stops);
	for (int i = 0; i < findNode->stops; i++)
	{
		printf("%s %s", findNode->stop[i].stopNum, findNode->stop[i].stopName);
	}
	puts("");*/

	/*head = head->next;
	while (head != NULL)
	{
	printf("%s %d ", head->routineNum, head->stops);
	for (int i = 0; i < head->stops; i++)
	{
	printf("%s %s", head->stop[i].stopNum, head->stop[i].stopName);
	}
	puts("");
	head = head->next;
	}*/
	saveRoutineToFile(head->next);

	puts("��ӳɹ���\n");
	system("pause");

	getchar();
}

void searchRoutineMsg()
{
	ROUTINE *findNode = NULL;
	ROUTINE *head = NULL;
	char routineNumInput[100] = {};
	bool findStatement = 0;

	head = readRoutineFromFile();

	printf("������Ҫ���ҵ�·�߱�ţ�>");
	scanf("%s", routineNumInput);

	while (head->next != NULL)
	{
		if ((strcmp(head->routineNum, routineNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("·�߱��  վ������ \n");
		printf("  %s     %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
	}
	else
	{
		printf("δ�ҵ����Ϊ%s����·��\n", routineNumInput);
	}

	system("pause");
	getchar();
}

void deleteRoutineLineMsg()
{
	ROUTINE *findNode = NULL;
	ROUTINE *head = NULL;
	ROUTINE *headptr = NULL;
	char routineNumInput[100] = {};
	bool findStatement = 0;

	head = readRoutineFromFile();
	headptr = head;

	printf("������Ҫɾ������·��ţ�>");
	scanf("%s", routineNumInput);

	while (head->next != NULL)
	{
		if ((strcmp((head->next)->routineNum, routineNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("·�߱��  վ������ \n");
		printf("  %s         %d\n", findNode->next->routineNum, findNode->next->stops);

		for (int i = 0; i < findNode->next->stops; i++)
		{
			printf("%s %s ", findNode->next->stop[i].stopNum, findNode->next->stop[i].stopName);
		}

		puts("ȷ��ɾ������YΪȷ�� ���������ȡ����");
		
		char cardOption = 'Y';
		getchar();
		scanf("%c", &cardOption);
		
		if (cardOption == 'Y')
		{
			ROUTINE *deleteMsg = NULL;
			deleteMsg = findNode->next;
			findNode->next = deleteMsg->next;
			free(deleteMsg);
			saveRoutineToFile(headptr->next);
			puts("ɾ���ɹ�!\n");
		}
		else
		{
			puts("��ȡ����\n");
		}

	}
	else
	{
		printf("δ�ҵ����Ϊ%s����·��\n", routineNumInput);
	}

	system("pause");
	puts("�س����أ�");
	getchar();
}

void deleteRoutineStopMsg()
{
	ROUTINE *findNode = NULL;
	ROUTINE *head = NULL;
	ROUTINE *headptr = NULL;
	char routineNumInput[100] = {};
	int stopNumInput;
	bool findStatement = 0;

	head = readRoutineFromFile();
	headptr = head;

	printf("������Ҫɾ����վ�����ڵ���·��ţ�>");
	scanf("%s", routineNumInput);

	while (head->next != NULL)
	{
		if ((strcmp(head->routineNum, routineNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("·�߱��  վ������ \n");
		printf("  %s     %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		printf("������Ҫɾ����վ��ı�ţ�>");
		scanf("%d", &stopNumInput);

		for (int i = 0; i < (findNode->stops - stopNumInput); i++)
		{
			strcpy(findNode->stop[stopNumInput+i-1].stopName, findNode->stop[stopNumInput+i].stopName);
		}

		findNode->stops -= 1;

		printf("%s %d ", findNode->routineNum, findNode->stops);
		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");

		puts("ȷ��ɾ������YΪȷ�� ���������ȡ����");
		
		char RoutineStopOption = 'Y';
		getchar();
		scanf("%c", &RoutineStopOption);

		if (RoutineStopOption == 'Y')
		{
			saveRoutineToFile(headptr->next);
			puts("ɾ���ɹ�!\n");
		}
		else
		{
			puts("��ȡ����\n");
		}
	}
	else
	{
		printf("δ�ҵ����Ϊ%s����·\n", routineNumInput);
	}

	system("pause");
	getchar();
}

void reviseRoutineStopMsg()
{
	ROUTINE *findNode = NULL;
	ROUTINE *head = NULL;
	ROUTINE *headptr = NULL;
	char routineNumInput[100] = {};
	int stopNumInput;
	bool findStatement = 0;

	head = readRoutineFromFile();
	headptr = head;

	printf("������Ҫ�޸ĵ�վ�����ڵ���·��ţ�>");
	scanf("%s", routineNumInput);

	while (head->next != NULL)
	{
		if ((strcmp(head->routineNum, routineNumInput) == 0))
		{
			findNode = head;
			findStatement = 1;
			break;
		}
		head = head->next;
	}

	if (findStatement == 1)
	{
		printf("·�߱��  վ������ \n");
		printf("  %s       %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		printf("������Ҫ�޸ĵ�վ��ı�ţ�>");
		scanf("%d", &stopNumInput);
		
		printf("�������µ�վ�����ƣ�>");
		scanf("%s", findNode->stop[stopNumInput-1].stopName);

		printf("%s %d ", findNode->routineNum, findNode->stops);
		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		
		saveRoutineToFile(headptr->next);
		puts("�޸ĳɹ�!\n");
	}
	else
	{
		printf("δ�ҵ����Ϊ%s����·��\n", routineNumInput);
	}

	system("pause");
	getchar();
}