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
	char username[8];//�û���
	char password[8];//����
	struct user *next;
}USER;

typedef struct driver{
	char driverNum[4];//˾�����
	char driverName[10];//˾������
	char driverSex[10];//˾���Ա�
	int driverSalary;//˾������
	char carNum[4];//��ʻ�������
	struct driver *next;
}DRIVER;

typedef struct car{
	char carNum[4];//�������
	char plateNum[10];//���ƺ�
	char belongRoute[4];//����·�߱��
	char secureTime[32];//��������
	char isRepair[10];//ά�����
	struct car *next;
}CAR;

typedef struct card{
	char cardNum[4];//����
	char passengerName[10];//�˿�����
	int passengerAge;//�˿�����
	char cardType[8];//��������
	float accountBalance;//�������
	struct card *next;
}CARD;

typedef struct station {
	char stopNum[4];//վ���
	char stopName[20];//վ��
}stop[50];//����վ

typedef struct routine{
	char routineNum[4];//��·���
	int stops;//վ������
	struct station stop[50];//��·�еĸ�վ��
	struct routine *next;
}ROUTINE;

typedef struct salaryCalculate {
	char driverNum[4];//˾�����
	char driverName[10];//˾������
	int leaveTime;//�������
	int extraTime;//�Ӱ�����
	int driverSalary;//˾������
	struct salaryCalculate *next;
}SALARYCAL;

typedef struct income
{
	char date[20];//����
	char routineNum[4];//·�߱��
	char carNum[4];//�������
	float incomeStat;//����
	struct income *next;
}INCOME;

typedef struct leave
{
	char date[20];//����
	char driverNum[4];//˾�����
	struct leave *next;
}LEAVE;

/*���в˵�����*/
void mainMenu();//���˵�
void infoMenu();//�鿴/�޸���Ϣ�˵�

void displayDriverMenu();//˾���˵�
void displayCarMenu();//�����˵�
void displayFinanceMenu();//����˵�
void displayCardMenu();//�����˵�
void displayRoutineMenu();//��·�˵�

void displayCommonMenu();//ͨ�ò˵�

void displayAddMenu();//ͨ������Ӳ˵�

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
void printTime();//��ӡʱ��

/*��ȡ�ļ�����*/
USER* readUserFromFile();//��ȡ�û���������Ϣ
DRIVER* readDriverFromFile();//��ȡ˾����Ϣ
DRIVER* saveDriverToFile(DRIVER *head);//��������˾����Ϣ���Ǵ��Դ�ļ�
CARD* readCardFromFile();//��ȡ������Ϣ
CARD* saveCardToFile(CARD *head);//�������ĳ�����Ϣ���Ǵ��Դ�ļ�
CAR* readCarFromFile();//��ȡ������Ϣ
CAR* saveCarToFile(CAR *head);//�������ĳ�����Ϣ���Ǵ��Դ�ļ�
ROUTINE* readRoutineFromFile();//��ȡ��·��Ϣ
ROUTINE* saveRoutineToFile(ROUTINE *head);//����������·��Ϣ���Ǵ��Դ�ļ�
INCOME* readIncomeFromFile();//��ȡ������Ϣ
SALARYCAL* readFinanceFromFile();//��ȡ������Ϣ
SALARYCAL* saveFinanceToFile(SALARYCAL *head);//�������Ĳ�����Ϣ���Դ�ļ�
LEAVE* readLeaveFromFile();//��ȡ�����Ϣ
LEAVE *saveLeaveToFile(LEAVE *head);//�������������Ϣ���Դ�ļ�
LEAVE *readExtraFromFile();//��ȡ�Ӱ���Ϣ
LEAVE *saveExtraToFile(LEAVE *head);//�������ļӰ���Ϣ���Դ�ļ�

/*��ɾ��Ĺ���*/
void addDriverMsg();
void searchDriverMsg();
void deleteDriverMsg();
void reviseDriverMsg();
void addDriverFromFile(char filename[]);//�������ļ�����˾����Ϣ��ӵ�Դ�ļ�β

void addCardMsg();
void searchCardMsg();
void deleteCardMsg();
void reviseCardMsg();
void addCardFromFile(char filename[]);//�������ļ����복����Ϣ��ӵ�Դ�ļ�β

void addCarMsg();
void searchCarMsg();
void deleteCarMsg();
void reviseCarMsg();
void addCarFromFile(char filename[]);//�������ļ����복����Ϣ��ӵ�Դ�ļ�β

void addRoutineLineMsg();//���������·
void addRoutineStopMsg();//���Ѵ��ڵ���·���һ������վ��
void searchRoutineMsg();//������·��Ϣ
void deleteRoutineLineMsg();//ɾ��������·
void deleteRoutineStopMsg();//ɾ����·�е�һ��վ��
void reviseRoutineStopMsg();//�޸�վ����Ϣ
void addRoutineFromFile(char filename[]);//�������ļ��е�����Ϣ

void leaveTime();//��������Ϣ
void extratime();//��ӼӰ���Ϣ
void addFinance();//��Ӳ�����Ϣ
void printFinance();//��ӡ������Ϣ
void printDateIncome();//���㲢��ӡĳ���ڵ�������
void printRoutineIncome();//���㲢��ӡĳ����·��������
void printCarIncome();//���㲢��ӡĳ������������
void printYearIncome();//���㲢��ӡĳ���������

/*��¼*/
void getpwd(char *pwd);//��ȡ����
void login();//��¼
void readLoginHistoryFromFile();//��ȡ��¼��¼

void simulate();//ģ������

#endif 
