#include"bus.h"

DRIVER* saveDriverToFile(DRIVER *head)
{
	FILE *cfptr;
	cfptr = fopen("drivermsg.txt", "w");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}

	while (head != NULL)
	{
		fprintf(cfptr, "%s %s %s %d %s\n", head->driverNum, head->driverName,
			head->driverSex, head->driverSalary, head->carNum);
		head = head->next;
	}

	fclose(cfptr);

	return head;
}

CAR* saveCarToFile(CAR *head)
{
	FILE *cfptr;
	cfptr = fopen("carmsg.txt", "w");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}

	while (head != NULL)
	{
		fprintf(cfptr, "%s %s %s %s %s\n", head->carNum, head->plateNum,
			head->belongRoute, head->secureTime, head->isRepair);
		head = head->next;
	}

	fclose(cfptr);

	return head;
}

CARD* saveCardToFile(CARD *head)
{
	FILE *cfptr;
	cfptr = fopen("cardmsg.txt", "w");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}

	while (head != NULL)
	{
		fprintf(cfptr, "%s %s %d %s %f\n", head->cardNum, head->passengerName,
			head->passengerAge, head->cardType, head->accountBalance);
		head = head->next;
	}

	fclose(cfptr);

	return head;
}

ROUTINE* saveRoutineToFile(ROUTINE *head)
{
	FILE *cfptr;
	cfptr = fopen("routinemsg.txt", "w");
	if (cfptr == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}

	while (head != NULL)
	{
		fprintf(cfptr, "%s %d", head->routineNum, head->stops);
		for (int i = 0; i < head->stops; i++)
		{
			fprintf(cfptr, " %s %s", head->stop[i].stopNum, head->stop[i].stopName);
		}
		fprintf(cfptr, "\n");
		head = head->next;
	}

	fclose(cfptr);

	return head;
}

SALARYCAL *saveFinanceToFile(SALARYCAL *head) {
	FILE *cfptr;
	if ((cfptr = fopen("financemsg.txt", "w")) == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}
	head = head->next;
	while (head != NULL)
	{
		fprintf(cfptr, "%s %s %d %d %d\n", head->driverNum, head->driverName,
			head->leaveTime, head->extraTime, head->driverSalary);
		head = head->next;
	}
	fclose(cfptr);
	return head;
}//�ӽ��ļ�д��financemsg.txt

LEAVE *saveLeaveToFile(LEAVE *head) {
	FILE *cfptr;
	if ((cfptr = fopen("leavetimemsg.txt", "w")) == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}
	head = head->next;
	while (head != NULL)
	{
		fprintf(cfptr, "%s %s\n", head->driverNum, head->date);
		head = head->next;
	}
	fclose(cfptr);
	return head;
}//�ӽ��ļ�д��leavetimemsg.txt

LEAVE *saveExtraToFile(LEAVE *head) {
	FILE *cfptr;
	if ((cfptr = fopen("leavetimemsg.txt", "w")) == NULL)
	{
		puts("�ļ���ʧ�ܣ��������������һ���˵�...");
		getchar();
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		return head;
	}
	head = head->next;
	while (head != NULL)
	{
		fprintf(cfptr, "%s %s\n", head->driverNum, head->date);
		head = head->next;
	}
	fclose(cfptr);
	return head;
}//�ӽ��ļ�д��extratimemsg.txt
