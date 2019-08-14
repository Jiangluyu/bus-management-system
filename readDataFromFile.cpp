#include "bus.h"

USER* readUserFromFile()
{
	FILE *cfptr;
	cfptr = fopen("usermsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	USER *head = NULL;
	USER *s = NULL;//����ָ��
	USER *r = NULL;//����ָ��

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
//��usermsg�ļ��ж������ݲ���������

DRIVER *readDriverFromFile()
{
	FILE *cfptr;
	cfptr = fopen("drivermsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	DRIVER *head = NULL;
	DRIVER *s = NULL;//����ָ��
	DRIVER *r = NULL;//����ָ��

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
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	CARD *head = NULL;
	CARD *s = NULL;//����ָ��
	CARD *r = NULL;//����ָ��

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
//��cardmsg�ļ��ж������ݲ���������

CAR* readCarFromFile()
{
	FILE *cfptr;
	cfptr = fopen("carmsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	CAR *head = NULL;
	CAR *s = NULL;//����ָ��
	CAR *r = NULL;//����ָ��

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
//��carmsg�ļ��ж������ݲ���������

ROUTINE* readRoutineFromFile()
{
	FILE *cfptr;
	cfptr = fopen("routinemsg.txt", "r");
	
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
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
//��routinemsg�ļ��ж������ݲ���������

INCOME* readIncomeFromFile()
{
	FILE *cfptr;
	cfptr = fopen("incomemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	INCOME *head = NULL;
	INCOME *s = NULL;//����ָ��
	INCOME *r = NULL;//����ָ��

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
//��incomemsg�ļ��ж������ݲ���������

SALARYCAL *readFinanceFromFile() {
	FILE *cfptr;
	cfptr = fopen("financemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	SALARYCAL *head = NULL;
	SALARYCAL *s = NULL;//����ָ��
	SALARYCAL *r = NULL;//����ָ��

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
//��financemsg�ж������ݲ���������

LEAVE *readLeaveFromFile() {
	FILE *cfptr;
	cfptr = fopen("leavetimemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	LEAVE *head = NULL;
	LEAVE *s = NULL;//����ָ��
	LEAVE *r = NULL;//����ָ��

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
//��leavetimecemsg�ж������ݲ���������

LEAVE *readExtraFromFile() {
	FILE *cfptr;
	cfptr = fopen("C:\\Users\\Administrator\\Desktop\\extratimemsg.txt", "r");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ�");
		exit(0);
	}

	LEAVE *head = NULL;
	LEAVE *s = NULL;//����ָ��
	LEAVE *r = NULL;//����ָ��

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
//��extratimecemsg�ж������ݲ���������

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
	puts("�س����أ�");
	getchar();
	system("CLS");
}
//��loginHistory�ж������ݲ���������