#include "bus.h"

void displayMainMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】查看/修改信息                                                   *");
	puts(" *                                               【2】模拟运行系统                                                    *");
	puts(" *                                               【3】登录记录查询                                                    *");
	puts(" *                                               【0】退出系统                                                        *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//主菜单

void mainMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayMainMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】司机                                                            *");
	puts(" *                                               【2】车辆                                                            *");
	puts(" *                                               【3】财务                                                            *");
	puts(" *                                               【4】车卡                                                            *");
	puts(" *                                               【5】线路                                                            *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
	puts(" *                                                                                                                    *");
    printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//查看/修改菜单

void infoMenu()
{

	char option = 'a';

	while (option != '0')
	{
		displayInfoMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！\n");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}
//通用菜单

void displayDriverMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加司机信息                                                    *");
	puts(" *                                               【2】删除司机信息                                                    *");
	puts(" *                                               【3】查询司机信息                                                    *");
	puts(" *                                               【4】修改司机信息                                                    *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！\n");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加车辆信息                                                    *");
	puts(" *                                               【2】删除车辆信息                                                    *");
	puts(" *                                               【3】查询车辆信息                                                    *");
	puts(" *                                               【4】修改车辆信息                                                    *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加财务信息                                                    *");
	puts(" *                                               【2】打印财务信息                                                    *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加基本信息                                                    *");
	puts(" *                                               【2】请假登记                                                        *");
	puts(" *                                               【3】加班登记                                                        *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】打印基本信息                                                    *");
	puts(" *                                               【2】打印按日期总收入                                                *");
	puts(" *                                               【3】打印按线路总收入                                                *");
	puts(" *                                               【4】打印按车辆总收入                                                *");
	puts(" *                                               【5】打印按年度总收入                                                *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加车卡信息                                                    *");
	puts(" *                                               【2】删除车卡信息                                                    *");
	puts(" *                                               【3】查询车卡信息                                                    *");
	puts(" *                                               【4】修改车卡信息                                                    *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加线路信息                                                    *");
	puts(" *                                               【2】删除线路信息                                                    *");
	puts(" *                                               【3】查询线路信息                                                    *");
	puts(" *                                               【4】修改线路信息                                                    *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】手动添加                                                        *");
	puts(" *                                               【2】从文件导入                                                      *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			printf("请输入导入的数据文件名：>");
			char filename[20];
			scanf("%s", filename);
			addDriverFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("输入错误！请重新输入！");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			printf("请输入导入的数据文件名：>");
			char filename[20];
			scanf("%s", filename);
			addCarFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("输入错误！请重新输入！");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			printf("请输入导入的数据文件名：>");
			char filename[20];
			scanf("%s", filename);
			addCardFromFile(filename);
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】添加新路线                                                      *");
	puts(" *                                               【2】已有路线添加新站点                                              *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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
	puts(" *                    ▂ ▃ ▄ ▅ ▆ ▇ █    欢迎使用快速公交管理系统v1.0  █ ▇ ▆ ▅ ▄ ▃ ▂                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                               请选择您想进行的操作：                                               *");
	puts(" *                                                                                                                    *");
	puts(" *                                               【1】删除线路                                                        *");
	puts(" *                                               【2】删除线路中的站点                                                *");
	puts(" *                                               【0】返回上一级菜单                                                  *");
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
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
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
			puts("输入错误！请重新输入！");
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