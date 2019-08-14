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

	printf("请输入日期：>");
	scanf("%s", dateIn);
	puts("");

	printf("请输入运行的线路：>");
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

	//寻找匹配的线路
	if (findRoutine == 0)
	{
		printf("未找到编号为%s的线路!按任意键退出！", routineNumIn);
		system("pause");
		exit(0);
	}

	printf("当前线路有公交车：>");

	while (carHead != NULL)
	{
		if (strcmp(carHead->belongRoute, routineNumIn) == 0)
		{
			printf("%s ", carHead->carNum);
			findCar = 1;
		}
		carHead = carHead->next;
	}
	//打印所选线路的公车编号
	puts("");
	printf("请选择运营公车的编号：>");
	scanf("%s", carNumIn);
	
	carHead = carReset;
	//重置头节点指针

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
	//寻找匹配的车辆

	if (findCar == 0)
	{
		printf("未找到编号为%s的车辆!按任意键退出！", carNumIn);
		system("pause");
		exit(0);
	}
	
	//下面开始运行	
	char input[4];
	char inputStop[4] = {'0'};

	float incomeStat = 0.0;
	for (int i = 0; i < (routineFindNode->stops-1); i++)
	{
		printf("本站为%s, 下一站%s\n", routineFindNode->stop[i].stopName, routineFindNode->stop[i+1].stopName);
		printf("投币2元请输入2， 刷卡请输入编号， 结束上车输入0\n");
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
				printf("投币成功！\n");
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
				//寻找匹配的车卡

				if (findCard == 0)
				{
					printf("未找到编号为%s的车卡!\n", input);
				}

				else
				{
					printf("编号为%s, 乘客姓名为%s 卡种为%s 刷卡前剩余%.2f元\n", cardFindNode->cardNum, cardFindNode->passengerName, cardFindNode->cardType,
						cardFindNode->accountBalance);
					if (strcmp(cardFindNode->cardType, "普通卡") == 0)
					{
						if (cardFindNode->accountBalance <= 0)
						{
							printf("余额不足，请下车！\n");
						}
						else
						{
							cardFindNode->accountBalance -= 1.6f;
							incomeStat += 1.6f;
							printf("刷卡后余额为%.2f元\n", cardFindNode->accountBalance);
						}
					}
					else if(strcmp(cardFindNode->cardType, "老年卡") == 0)
					{
						printf("本次乘车免费！\n");
					}
					else if (strcmp(cardFindNode->cardType, "学生卡") == 0)
					{
						if (cardFindNode->accountBalance <= 0)
						{
							printf("余额不足，请下车！\n");
						}
						else
						{
							cardFindNode->accountBalance -= 1.6f;
							incomeStat += 1.6f;
							printf("刷卡后余额为%.2f元\n", cardFindNode->accountBalance);
						}
					}
				}
			}
		} while (strcmp(input, inputStop) != 0);

		printf("车辆运行，请握紧扶手...\n\n");
		Sleep(1000);
	}
	memset(input, 0, sizeof(input));
	printf("已到达终点站！谢谢乘坐！");
	
	printf("本次运行收入:%.2f\n", incomeStat);
	
	//写入数据
	FILE* cfptr;
	cfptr = fopen("incomemsg.txt", "a+");

	fprintf(cfptr, "%s %s %s %f\n", dateIn, routineNumIn, carNumIn, incomeStat);

	fclose(cfptr);

	system("pause");
	getchar();
	system("CLS");
}