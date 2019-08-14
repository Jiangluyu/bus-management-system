#include"bus.h"

void addRoutineLineMsg()
{
	ROUTINE *newMsg = NULL;//创建新数据被保存到的结点
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
	//得到最后一个结点的指针

	newMsg = (ROUTINE *)malloc(sizeof(ROUTINE));

	tail->next = newMsg;

	printf("请输入线路编号：>");
	scanf("%s", newMsg->routineNum);
	puts("");
	printf("请输入站点数量：>");
	scanf("%d", &newMsg->stops);
	puts("");
	for (int i = 0; i < newMsg->stops; i++)
	{
		printf("请输入第%d站站名：>", i+1);
		_itoa(i, newMsg->stop[i].stopNum, 10);
		scanf("%s", newMsg->stop[i].stopName);
	}
	
	newMsg->next = NULL;

	saveRoutineToFile(head->next);
	puts("添加成功！");
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

	printf("请输入线路编号：>");
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
	//寻找编号与输入相同的线路节点

	printf("请输入增加的站点数量：>");
	scanf("%d", &addStops);

	printf("请输入在第几站后增加站点：>");
	scanf("%d", &addPlaceNum);

	for (int i = 0; i < (findNode->stops-addStops+1); i++)
	{
		strcpy(findNode->stop[(findNode->stops)-i-1+addStops].stopName, findNode->stop[(findNode->stops)-i-1].stopName);
		//向后移动站名addStops个位置
		int Numtemp = atoi(findNode->stop[(findNode->stops)-i-1].stopNum);
		Numtemp += addStops;
		_itoa(Numtemp, findNode->stop[(findNode->stops)-i-1+addStops].stopNum, 10);
		//调整站名对应的顺序编号
	}
	//将第addPlace+1站以后的站点信息向后挪addStops个位置

	for (int i = 0; i < addStops; i++)
	{
		_itoa(addPlaceNum+1+i, findNode->stop[addPlaceNum+i].stopNum, 10);
		//存入第addPlaceNum+1+i个位置的编号
		printf("请输入第%d站的站名", addPlaceNum+1+i);
		scanf("%s", findNode->stop[addPlaceNum+i].stopName);
	}

	findNode->stops += addStops;
	//添加站点
	
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

	puts("添加成功！\n");
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

	printf("请输入要查找的路线编号：>");
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
		printf("路线编号  站点总数 \n");
		printf("  %s     %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
	}
	else
	{
		printf("未找到编号为%s的线路！\n", routineNumInput);
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

	printf("请输入要删除的线路编号：>");
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
		printf("路线编号  站点总数 \n");
		printf("  %s         %d\n", findNode->next->routineNum, findNode->next->stops);

		for (int i = 0; i < findNode->next->stops; i++)
		{
			printf("%s %s ", findNode->next->stop[i].stopNum, findNode->next->stop[i].stopName);
		}

		puts("确认删除？（Y为确认 其它任意键取消）");
		
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
			puts("删除成功!\n");
		}
		else
		{
			puts("已取消！\n");
		}

	}
	else
	{
		printf("未找到编号为%s的线路！\n", routineNumInput);
	}

	system("pause");
	puts("回车返回！");
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

	printf("请输入要删除的站点所在的线路编号：>");
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
		printf("路线编号  站点总数 \n");
		printf("  %s     %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		printf("请输入要删除的站点的编号：>");
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

		puts("确认删除？（Y为确认 其它任意键取消）");
		
		char RoutineStopOption = 'Y';
		getchar();
		scanf("%c", &RoutineStopOption);

		if (RoutineStopOption == 'Y')
		{
			saveRoutineToFile(headptr->next);
			puts("删除成功!\n");
		}
		else
		{
			puts("已取消！\n");
		}
	}
	else
	{
		printf("未找到编号为%s的线路\n", routineNumInput);
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

	printf("请输入要修改的站点所在的线路编号：>");
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
		printf("路线编号  站点总数 \n");
		printf("  %s       %d\n", findNode->routineNum, findNode->stops);

		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s ", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		printf("请输入要修改的站点的编号：>");
		scanf("%d", &stopNumInput);
		
		printf("请输入新的站点名称：>");
		scanf("%s", findNode->stop[stopNumInput-1].stopName);

		printf("%s %d ", findNode->routineNum, findNode->stops);
		for (int i = 0; i < findNode->stops; i++)
		{
			printf("%s %s", findNode->stop[i].stopNum, findNode->stop[i].stopName);
		}
		puts("");
		
		saveRoutineToFile(headptr->next);
		puts("修改成功!\n");
	}
	else
	{
		printf("未找到编号为%s的线路！\n", routineNumInput);
	}

	system("pause");
	getchar();
}