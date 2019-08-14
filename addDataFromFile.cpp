#include"bus.h"

void addDriverFromFile(char filename[])
{
	DRIVER *head = NULL;
	DRIVER *headptr = NULL;

	head = readDriverFromFile();
	headptr = head;

	while (true)
	{
		if (head->next != NULL)
		{
			head = head->next;
		}
		else
		{
			break;
		}
		
	}
	//得到尾节点

	FILE *cfptr;
	cfptr = fopen(filename, "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！按任意键返回上一级菜单...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		return;
	}

	DRIVER *s = NULL;
	DRIVER *r = NULL;

	r = head;
	s = (DRIVER *)malloc(sizeof(DRIVER));

	while (fscanf(cfptr, "%s %s %s %d %s", s->driverNum, s->driverName, s->driverSex, &s->driverSalary, s->carNum) > 0)
	{
		r->next = s;
		r = s;
		s = (DRIVER *)malloc(sizeof(DRIVER));
	}

	r->next = NULL;

	fclose(cfptr);

	saveDriverToFile(headptr->next);
	printf("导入成功！\n");
	system("pause");
	getchar();
}

void addCarFromFile(char filename[])
{
	CAR *head = NULL;
	CAR *headptr = NULL;

	head = readCarFromFile();
	headptr = head;

	while (true)
	{
		if (head->next != NULL)
		{
			head = head->next;
		}
		else
		{
			break;
		}

	}
	//得到尾节点

	FILE *cfptr;
	cfptr = fopen(filename, "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！按任意键返回上一级菜单...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		return;
	}

	CAR *s = NULL;
	CAR *r = NULL;

	r = head;
	s = (CAR *)malloc(sizeof(CAR));

	while (fscanf(cfptr, "%s %s %s %s %s", s->carNum, s->plateNum, s->belongRoute, s->secureTime, s->isRepair) > 0)
	{
		r->next = s;
		r = s;
		s = (CAR *)malloc(sizeof(CAR));
	}

	r->next = NULL;

	fclose(cfptr);

	saveCarToFile(headptr->next);
	printf("导入成功！\n");
	system("pause");
	getchar();
}

void addCardFromFile(char filename[])
{
	CARD *head = NULL;
	CARD *headptr = NULL;

	head = readCardFromFile();
	headptr = head;

	while (true)
	{
		if (head->next != NULL)
		{
			head = head->next;
		}
		else
		{
			break;
		}

	}
	//得到尾节点

	FILE *cfptr;
	cfptr = fopen(filename, "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！按任意键返回上一级菜单...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		return;
	}

	CARD *s = NULL;
	CARD *r = NULL;

	r = head;
	s = (CARD *)malloc(sizeof(CARD));

	while (fscanf(cfptr, "%s %s %d %s %f", s->cardNum, s->passengerName, &s->passengerAge, s->cardType, &s->accountBalance) > 0)
	{
		r->next = s;
		r = s;
		s = (CARD *)malloc(sizeof(CARD));
	}

	r->next = NULL;

	fclose(cfptr);

	saveCardToFile(headptr->next);
	printf("导入成功！\n");
	system("pause");
	getchar();
}

void addRoutineFromFile(char filename[])
{
	ROUTINE *head = NULL;
	ROUTINE *headptr = NULL;

	head = readRoutineFromFile();
	headptr = head;

	while (true)
	{
		if (head->next != NULL)
		{
			head = head->next;
		}
		else
		{
			break;
		}

	}
	//得到尾节点

	FILE *cfptr;
	cfptr = fopen(filename, "r");
	if(cfptr == NULL)
	{
		puts("文件打开失败！按任意键返回上一级菜单...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		return;
	}

	ROUTINE *s = NULL;
	ROUTINE *r = NULL;

	r = head;

	s = (ROUTINE *)malloc(sizeof(ROUTINE));
	while (fscanf(cfptr, "%s %d ", s->routineNum, &s->stops) > 0)
	{
		for (int i = 0; i < s->stops; i++)
		{
			fscanf(cfptr, "%s %s ", s->stop[i].stopNum, s->stop[i].stopName);
		}
		r->next = s;
		r = s;
		s = (ROUTINE *)malloc(sizeof(ROUTINE));
	}

	r->next = NULL;

	fclose(cfptr);

	saveRoutineToFile(headptr->next);
	printf("导入成功！\n");
	system("pause");
	getchar();
}