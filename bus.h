#ifndef _BUS_H_
#define _BUS_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>
#include <string.h>
#include<time.h>
#include<conio.h>

typedef struct user {
	char username[8];//用户名
	char password[8];//密码
	struct user *next;
}USER;

typedef struct driver{
	char driverNum[4];//司机编号
	char driverName[10];//司机姓名
	char driverSex[10];//司机性别
	int driverSalary;//司机工资
	char carNum[4];//驾驶汽车编号
	struct driver *next;
}DRIVER;

typedef struct car{
	char carNum[4];//汽车编号
	char plateNum[10];//车牌号
	char belongRoute[4];//所属路线编号
	char secureTime[32];//保险日期
	char isRepair[10];//维修情况
	struct car *next;
}CAR;

typedef struct card{
	char cardNum[4];//卡号
	char passengerName[10];//乘客姓名
	int passengerAge;//乘客年龄
	char cardType[8];//卡的类型
	float accountBalance;//卡内余额
	struct card *next;
}CARD;

typedef struct station {
	char stopNum[4];//站编号
	char stopName[20];//站名
}stop[50];//公交站

typedef struct routine{
	char routineNum[4];//线路编号
	int stops;//站点数量
	struct station stop[50];//线路中的各站点
	struct routine *next;
}ROUTINE;

typedef struct salaryCalculate {
	char driverNum[4];//司机编号
	char driverName[10];//司机姓名
	int leaveTime;//请假天数
	int extraTime;//加班天数
	int driverSalary;//司机工资
	struct salaryCalculate *next;
}SALARYCAL;

typedef struct income
{
	char date[20];//日期
	char routineNum[4];//路线编号
	char carNum[4];//车辆编号
	float incomeStat;//收入
	struct income *next;
}INCOME;

typedef struct leave
{
	char date[20];//日期
	char driverNum[4];//司机编号
	struct leave *next;
}LEAVE;

/*所有菜单函数*/
void mainMenu();//主菜单
void infoMenu();//查看/修改信息菜单

void displayDriverMenu();//司机菜单
void displayCarMenu();//车辆菜单
void displayFinanceMenu();//财务菜单
void displayCardMenu();//车辆菜单
void displayRoutineMenu();//线路菜单

void displayCommonMenu();//通用菜单

void displayAddMenu();//通用添加子菜单

void displayAddRoutineKindMenu();

void displayAddFinanceMenu();
void displayPrintFinanceMenu();

void driverMenu();
void carMenu();
void cardMenu();
void routineMenu();
void financeMenu();

void addDriverMenu();
void addCardMenu();
void addCarMenu();
void addRoutineKindMenu();
void deleteRoutineKindMenu();
void addFinanceMenu();
void printFinanceMenu();
void printTime();//打印时间

/*存取文件函数*/
USER* readUserFromFile();//读取用户名密码信息
DRIVER* readDriverFromFile();//读取司机信息
DRIVER* saveDriverToFile(DRIVER *head);//将处理后的司机信息覆盖存回源文件
CARD* readCardFromFile();//读取车卡信息
CARD* saveCardToFile(CARD *head);//将处理后的车卡信息覆盖存回源文件
CAR* readCarFromFile();//读取车辆信息
CAR* saveCarToFile(CAR *head);//将处理后的车辆信息覆盖存回源文件
ROUTINE* readRoutineFromFile();//读取线路信息
ROUTINE* saveRoutineToFile(ROUTINE *head);//将处理后的线路信息覆盖存回源文件
INCOME* readIncomeFromFile();//读取收入信息
SALARYCAL* readFinanceFromFile();//读取财务信息
SALARYCAL* saveFinanceToFile(SALARYCAL *head);//将处理后的财务信息存回源文件
LEAVE* readLeaveFromFile();//读取请假信息
LEAVE *saveLeaveToFile(LEAVE *head);//将处理后的请假信息存回源文件
LEAVE *readExtraFromFile();//读取加班信息
LEAVE *saveExtraToFile(LEAVE *head);//将处理后的加班信息存回源文件

/*增删查改功能*/
void addDriverMsg();
void searchDriverMsg();
void deleteDriverMsg();
void reviseDriverMsg();
void addDriverFromFile(char filename[]);//从其他文件导入司机信息添加到源文件尾

void addCardMsg();
void searchCardMsg();
void deleteCardMsg();
void reviseCardMsg();
void addCardFromFile(char filename[]);//从其他文件导入车卡信息添加到源文件尾

void addCarMsg();
void searchCarMsg();
void deleteCarMsg();
void reviseCarMsg();
void addCarFromFile(char filename[]);//从其他文件导入车辆信息添加到源文件尾

void addRoutineLineMsg();//添加整条线路
void addRoutineStopMsg();//向已存在的线路添加一个或多个站点
void searchRoutineMsg();//搜索线路信息
void deleteRoutineLineMsg();//删除整条线路
void deleteRoutineStopMsg();//删除线路中的一个站点
void reviseRoutineStopMsg();//修改站点信息
void addRoutineFromFile(char filename[]);//从其他文件中导入信息

void leaveTime();//添加请假信息
void extratime();//添加加班信息
void addFinance();//添加财务信息
void printFinance();//打印财务信息
void printDateIncome();//计算并打印某日期的总收入
void printRoutineIncome();//计算并打印某条线路的总收入
void printCarIncome();//计算并打印某辆车的总收入
void printYearIncome();//计算并打印某年的总收入

/*登录*/
void getpwd(char *pwd);//获取密码
void login();//登录
void readLoginHistoryFromFile();//读取登录记录

void simulate();//模拟运行

#endif 
