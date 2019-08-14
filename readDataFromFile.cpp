#include "bus.h"

USER* readUserFromFile()
{
	FILE *cfptr;
	cfptr = fopen("usermsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	USER *head = NULL;
	USER *s = NULL;//工作指针
	USER *r = NULL;//工作指针

	head = (USER *)malloc(sizeof(USER));
	head->next = NULL;

	r = head;

	s = (USER *)malloc(sizeof(USER));

	while (fscanf(cfptr, "%s %s", s->username, s->password) > 0)
	{
		r->next = s;
		r = s;
		s = (USER *)malloc(sizeof(USER));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;

}
//从usermsg文件中读入数据并存入链表

DRIVER *readDriverFromFile()
{
	FILE *cfptr;
	cfptr = fopen("drivermsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	DRIVER *head = NULL;
	DRIVER *s = NULL;//工作指针
	DRIVER *r = NULL;//工作指针

	head = (DRIVER *)malloc(sizeof(DRIVER));

	head->next = NULL;

	r = head;

	s = (DRIVER *)malloc(sizeof(DRIVER));

	while (fscanf(cfptr, "%s %s %s %d %s\n", s->driverNum, s->driverName,
		s->driverSex, &s->driverSalary, s->carNum) > 0)
	{
		r->next = s;
		r = s;
		s = (DRIVER *)malloc(sizeof(DRIVER));
	}

	r->next = NULL;
	
	fclose(cfptr);

	return head;
}

CARD* readCardFromFile()
{
	FILE *cfptr;
	cfptr = fopen("cardmsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	CARD *head = NULL;
	CARD *s = NULL;//工作指针
	CARD *r = NULL;//工作指针

	head = (CARD *)malloc(sizeof(CARD));

	head->next = NULL;
	
	r = head;

	s = (CARD *)malloc(sizeof(CARD));

	while (fscanf(cfptr, "%s %s %d %s %f\n", s->cardNum, s->passengerName,
		&s->passengerAge, s->cardType, &s->accountBalance) > 0)
	{
		r->next = s;
		r = s;
		s = (CARD *)malloc(sizeof(CARD));
	}

	r->next = NULL;
	
	fclose(cfptr);

	return head;
}
//从cardmsg文件中读入数据并存入链表

CAR* readCarFromFile()
{
	FILE *cfptr;
	cfptr = fopen("carmsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	CAR *head = NULL;
	CAR *s = NULL;//工作指针
	CAR *r = NULL;//工作指针

	head = (CAR *)malloc(sizeof(CAR));

	head->next = NULL;

	r = head;

	s = (CAR *)malloc(sizeof(CAR));

	while (fscanf(cfptr, "%s %s %s %s %s\n", s->carNum, s->plateNum,
		s->belongRoute, s->secureTime, s->isRepair) > 0)
	{
		r->next = s;
		r = s;
		s = (CAR *)malloc(sizeof(CAR));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;
}
//从carmsg文件中读入数据并存入链表

ROUTINE* readRoutineFromFile()
{
	FILE *cfptr;
	cfptr = fopen("routinemsg.txt", "r");
	
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	ROUTINE *r = NULL;
	ROUTINE *s = NULL;
	ROUTINE *head = NULL;
	
	head = (ROUTINE *)malloc(sizeof(ROUTINE));

	head->next = NULL;
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

	fclose(cfptr);

	return head;
}
//从routinemsg文件中读入数据并存入链表

INCOME* readIncomeFromFile()
{
	FILE *cfptr;
	cfptr = fopen("incomemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	INCOME *head = NULL;
	INCOME *s = NULL;//工作指针
	INCOME *r = NULL;//工作指针

	head = (INCOME *)malloc(sizeof(INCOME));

	head->next = NULL;

	r = head;

	s = (INCOME *)malloc(sizeof(INCOME));

	while (fscanf(cfptr, "%s %s %s %f\n", s->date, s->routineNum,
		s->carNum, &s->incomeStat) > 0)
	{
		r->next = s;
		r = s;
		s = (INCOME *)malloc(sizeof(INCOME));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;
}
//从incomemsg文件中读入数据并存入链表

SALARYCAL *readFinanceFromFile() {
	FILE *cfptr;
	cfptr = fopen("financemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	SALARYCAL *head = NULL;
	SALARYCAL *s = NULL;//工作指针
	SALARYCAL *r = NULL;//工作指针

	head = (SALARYCAL *)malloc(sizeof(SALARYCAL));

	head->next = NULL;

	r = head;

	s = (SALARYCAL *)malloc(sizeof(SALARYCAL));

	while (fscanf(cfptr, "%s %s %d %d %d\n", s->driverNum, s->driverName,
		&s->leaveTime, &s->extraTime, &s->driverSalary) > 0)
	{
		/*printf("%s %s %d %d %d\n", s->driverNum, s->driverName,
		s->leaveTime, s->extraTime, s->driverSalary);*/
		r->next = s;
		r = s;
		s = (SALARYCAL *)malloc(sizeof(SALARYCAL));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;
} 
//从financemsg中读入数据并存入链表

LEAVE *readLeaveFromFile() {
	FILE *cfptr;
	cfptr = fopen("leavetimemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	LEAVE *head = NULL;
	LEAVE *s = NULL;//工作指针
	LEAVE *r = NULL;//工作指针

	head = (LEAVE *)malloc(sizeof(LEAVE));

	head->next = NULL;

	r = head;

	s = (LEAVE *)malloc(sizeof(LEAVE));

	while (fscanf(cfptr, "%s %s\n", s->driverNum, s->date) > 0)
	{
		r->next = s;
		r = s;
		s = (LEAVE *)malloc(sizeof(LEAVE));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;
}
//从leavetimecemsg中读入数据并存入链表

LEAVE *readExtraFromFile() {
	FILE *cfptr;
	cfptr = fopen("C:\\Users\\Administrator\\Desktop\\extratimemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("文件打开失败！");
		exit(0);
	}

	LEAVE *head = NULL;
	LEAVE *s = NULL;//工作指针
	LEAVE *r = NULL;//工作指针

	head = (LEAVE *)malloc(sizeof(LEAVE));

	head->next = NULL;

	r = head;

	s = (LEAVE *)malloc(sizeof(LEAVE));

	while (fscanf(cfptr, "%s %s\n", s->driverNum, s->date) > 0)
	{
		r->next = s;
		r = s;
		s = (LEAVE *)malloc(sizeof(LEAVE));
	}

	r->next = NULL;

	fclose(cfptr);

	return head;
} 
//从extratimecemsg中读入数据并存入链表

void readLoginHistoryFromFile()
{
	FILE *cfptr;
	cfptr = fopen("loginHistory.txt", "r");

	char c;

	while ((c = fgetc(cfptr)) != EOF) 
		if (c != '\n')
		{
			putchar(c);
		}
		else
		{
			puts("");
		}

	fclose(cfptr);
	system("pause");
	puts("回车返回！");
	getchar();
	system("CLS");
}
//从loginHistory中读入数据并存入链表