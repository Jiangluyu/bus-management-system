#include"bus.h"

void simulate()
{
	ROUTINE *routineHead;
	CARD *cardHead;
	CAR *carHead;

	ROUTINE *routineReset;
	CARD *cardReset;
	CAR *carReset;

	char routineNumIn[4];
	char carNumIn[4];
	char dateIn[20];

	ROUTINE *routineFindNode = NULL;
	CARD *cardFindNode = NULL;
	CAR *carFindNode = NULL;

	bool findRoutine = 0;
	bool findCar = 0;
	bool findCard = 0;

	routineHead = readRoutineFromFile();
	cardHead = readCardFromFile();
	carHead = readCarFromFile();

	routineReset = routineHead;
	cardReset = cardHead;
	carReset = carHead;

	printf("���������ڣ�>");
	scanf("%s", dateIn);
	puts("");

	printf("���������е���·��>");
	scanf("%s", routineNumIn);
	puts("");

	while (routineHead != NULL)
	{
		if (strcmp(routineHead->routineNum, routineNumIn) == 0)
		{
			routineFindNode = routineHead;
			findRoutine = 1;
			break;
		}
		routineHead = routineHead->next;
	}

	//Ѱ��ƥ�����·
	if (findRoutine == 0)
	{
		printf("δ�ҵ����Ϊ%s����·!��������˳���", routineNumIn);
		system("pause");
		exit(0);
	}

	printf("��ǰ��·�й�������>");

	while (carHead != NULL)
	{
		if (strcmp(carHead->belongRoute, routineNumIn) == 0)
		{
			printf("%s ", carHead->carNum);
			findCar = 1;
		}
		carHead = carHead->next;
	}
	//��ӡ��ѡ��·�Ĺ������
	puts("");
	printf("��ѡ����Ӫ�����ı�ţ�>");
	scanf("%s", carNumIn);
	
	carHead = carReset;
	//����ͷ�ڵ�ָ��

	while (carHead != NULL)
	{
		if (strcmp(carHead->carNum, carNumIn) == 0)
		{
			carFindNode = carHead;
			findCar = 1;
			break;
		}
		carHead = carHead->next;
	}
	//Ѱ��ƥ��ĳ���

	if (findCar == 0)
	{
		printf("δ�ҵ����Ϊ%s�ĳ���!��������˳���", carNumIn);
		system("pause");
		exit(0);
	}
	
	//���濪ʼ����	
	char input[4];
	char inputStop[4] = {'0'};

	float incomeStat = 0.0;
	for (int i = 0; i < (routineFindNode->stops-1); i++)
	{
		printf("��վΪ%s, ��һվ%s\n", routineFindNode->stop[i].stopName, routineFindNode->stop[i+1].stopName);
		printf("Ͷ��2Ԫ������2�� ˢ���������ţ� �����ϳ�����0\n");
		do {
			//printf("1->%s\n", input);
			memset(input, 0, sizeof(input));
			//printf("2->%s\n", input);
			scanf("%s", input);
			//printf("3->%s\n", input);
			if (atoi(input) == 0)
			{
				break;
			}
			if (atoi(input) == 2)
			{
				printf("Ͷ�ҳɹ���\n");
				incomeStat += 2.0;
			}
			else
			{
				cardHead = cardReset;
				findCard = 0;
				while (cardHead != NULL)
				{
					if (strcmp(cardHead->cardNum, input) == 0)
					{
						cardFindNode = cardHead;
						findCard = 1;
						break;
					}
					cardHead = cardHead->next;
				}
				//Ѱ��ƥ��ĳ���

				if (findCard == 0)
				{
					printf("δ�ҵ����Ϊ%s�ĳ���!\n", input);
				}

				else
				{
					printf("���Ϊ%s, �˿�����Ϊ%s ����Ϊ%s ˢ��ǰʣ��%.2fԪ\n", cardFindNode->cardNum, cardFindNode->passengerName, cardFindNode->cardType,
						cardFindNode->accountBalance);
					if (strcmp(cardFindNode->cardType, "��ͨ��") == 0)
					{
						if (cardFindNode->accountBalance <= 0)
						{
							printf("���㣬���³���\n");
						}
						else
						{
							cardFindNode->accountBalance -= 1.6f;
							incomeStat += 1.6f;
							printf("ˢ�������Ϊ%.2fԪ\n", cardFindNode->accountBalance);
						}
					}
					else if(strcmp(cardFindNode->cardType, "���꿨") == 0)
					{
						printf("���γ˳���ѣ�\n");
					}
					else if (strcmp(cardFindNode->cardType, "ѧ����") == 0)
					{
						if (cardFindNode->accountBalance <= 0)
						{
							printf("���㣬���³���\n");
						}
						else
						{
							cardFindNode->accountBalance -= 1.6f;
							incomeStat += 1.6f;
							printf("ˢ�������Ϊ%.2fԪ\n", cardFindNode->accountBalance);
						}
					}
				}
			}
		} while (strcmp(input, inputStop) != 0);

		printf("�������У����ս�����...\n\n");
		Sleep(1000);
	}
	memset(input, 0, sizeof(input));
	printf("�ѵ����յ�վ��лл������");
	
	printf("������������:%.2f\n", incomeStat);
	
	//д������
	FILE* cfptr;
	cfptr = fopen("incomemsg.txt", "a+");

	fprintf(cfptr, "%s %s %s %f\n", dateIn, routineNumIn, carNumIn, incomeStat);

	fclose(cfptr);

	system("pause");
	getchar();
	system("CLS");
}