#include "bus.h"

void displayMainMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1���鿴/�޸���Ϣ                                                   *");
	puts(" *                                               ��2��ģ������ϵͳ                                                    *");
	puts(" *                                               ��3����¼��¼��ѯ                                                    *");
	puts(" *                                               ��0���˳�ϵͳ                                                        *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//���˵�

void mainMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayMainMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			infoMenu();
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			simulate();
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			readLoginHistoryFromFile();
			break;
		default:
			system("CLS");
			fflush(stdin);
			break;
		}
	}
	exit(0);
}

void displayInfoMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1��˾��                                                            *");
	puts(" *                                               ��2������                                                            *");
	puts(" *                                               ��3������                                                            *");
	puts(" *                                               ��4������                                                            *");
	puts(" *                                               ��5����·                                                            *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
    printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//�鿴/�޸Ĳ˵�

void infoMenu()
{

	char option = 'a';

	while (option != '0')
	{
		displayInfoMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			driverMenu();
			break;
		case '2':
			system("CLS");
			carMenu();
			break;
		case '3':
			system("CLS");
			financeMenu();
			break;
		case '4':
			system("CLS");
			cardMenu();
			break;
		case '5':
			system("CLS");
			routineMenu();
			break;
		case '0':
			break;
		default:
			puts("����������������룡\n");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayCommonMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//ͨ�ò˵�

void displayDriverMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1�����˾����Ϣ                                                    *");
	puts(" *                                               ��2��ɾ��˾����Ϣ                                                    *");
	puts(" *                                               ��3����ѯ˾����Ϣ                                                    *");
	puts(" *                                               ��4���޸�˾����Ϣ                                                    *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void driverMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayDriverMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			addDriverMenu();
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			deleteDriverMsg();
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			searchDriverMsg();
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			reviseDriverMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡\n");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayCarMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1����ӳ�����Ϣ                                                    *");
	puts(" *                                               ��2��ɾ��������Ϣ                                                    *");
	puts(" *                                               ��3����ѯ������Ϣ                                                    *");
	puts(" *                                               ��4���޸ĳ�����Ϣ                                                    *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void carMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayCarMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			addCarMenu();
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			deleteCarMsg();
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			searchCarMsg();
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			reviseCarMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayFinanceMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1����Ӳ�����Ϣ                                                    *");
	puts(" *                                               ��2����ӡ������Ϣ                                                    *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void financeMenu()
{
	char option = 'a';

	while (option != '0')
	{	
		displayFinanceMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			addFinanceMenu();
			system("CLS");
			break;
		case '2':
			system("CLS");
			printFinanceMenu();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayAddFinanceMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1����ӻ�����Ϣ                                                    *");
	puts(" *                                               ��2����ٵǼ�                                                        *");
	puts(" *                                               ��3���Ӱ�Ǽ�                                                        *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void addFinanceMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayAddFinanceMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			addFinance();
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			leaveTime();
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			extratime();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayPrintFinanceMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1����ӡ������Ϣ                                                    *");
	puts(" *                                               ��2����ӡ������������                                                *");
	puts(" *                                               ��3����ӡ����·������                                                *");
	puts(" *                                               ��4����ӡ������������                                                *");
	puts(" *                                               ��5����ӡ�����������                                                *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void printFinanceMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayPrintFinanceMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			printFinance();
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			printDateIncome();
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			printRoutineIncome();
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			printCarIncome();
			system("CLS");
			break;
		case '5':
			system("CLS");
			displayCommonMenu();
			printYearIncome();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}
void displayCardMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1����ӳ�����Ϣ                                                    *");
	puts(" *                                               ��2��ɾ��������Ϣ                                                    *");
	puts(" *                                               ��3����ѯ������Ϣ                                                    *");
	puts(" *                                               ��4���޸ĳ�����Ϣ                                                    *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void cardMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayCardMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			addCardMenu();
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			deleteCardMsg();
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			searchCardMsg();
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			reviseCardMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayRoutineMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1�������·��Ϣ                                                    *");
	puts(" *                                               ��2��ɾ����·��Ϣ                                                    *");
	puts(" *                                               ��3����ѯ��·��Ϣ                                                    *");
	puts(" *                                               ��4���޸���·��Ϣ                                                    *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void routineMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayRoutineMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			addRoutineKindMenu();
			break;
		case '2':
			system("CLS");
			deleteRoutineKindMenu();
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			searchRoutineMsg();
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			reviseRoutineStopMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayAddMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1���ֶ����                                                        *");
	puts(" *                                               ��2�����ļ�����                                                      *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void addDriverMenu()
{
	char option='a';

	while (option != '0')
	{	
		displayAddMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			addDriverMsg();
			system("CLS");
			break;
			
		case '2':
			system("CLS");
			displayCommonMenu();
			printf("�����뵼��������ļ�����>");
			char filename[20];
			scanf("%s", filename);
			addDriverFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void addCarMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayAddMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			addCarMsg();
			system("CLS");
			break;

		case '2':
			system("CLS");
			displayCommonMenu();
			printf("�����뵼��������ļ�����>");
			char filename[20];
			scanf("%s", filename);
			addCarFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void addCardMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayAddMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			addCardMsg();
			system("CLS");
			break;

		case '2':
			system("CLS");
			displayCommonMenu();
			printf("�����뵼��������ļ�����>");
			char filename[20];
			scanf("%s", filename);
			addCardFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayAddRoutineKindMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1�������·��                                                      *");
	puts(" *                                               ��2������·�������վ��                                              *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void addRoutineKindMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayAddRoutineKindMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			addRoutineLineMsg();
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			addRoutineStopMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayDeleteRoutineKindMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    �y �z �{ �| �} �~ ��    ��ӭʹ�ÿ��ٹ�������ϵͳv1.0  �� �~ �} �| �{ �z �y                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��ѡ��������еĲ�����                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               ��1��ɾ����·                                                        *");
	puts(" *                                               ��2��ɾ����·�е�վ��                                                *");
	puts(" *                                               ��0��������һ���˵�                                                  *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void deleteRoutineKindMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayDeleteRoutineKindMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//��ջ�����
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			deleteRoutineLineMsg();
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			deleteRoutineStopMsg();
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("����������������룡");
			system("pause");
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void printTime()
{
		time_t now;

		struct tm *tm_now;

		time(&now);

		tm_now = localtime(&now);
		printf(" *                                                %d-%d-%d %d:%d:%d                                                  *\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
}