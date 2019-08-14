#include"bus.h"
void getpwd(char *pwd) {
	char ch = 0;
	int i = 0;
	while (i<8) {
		ch = _getch();
		if (ch == '\r') { //�س���������
			printf("\n");
			break;
		}
		if (ch == '\b' && i>0) { //����ɾ����
			i--;
			printf("\b \b");
		}
		else if (isprint(ch)) { //����ɴ�ӡ�ַ�
			pwd[i] = ch;
			printf("*");
			i++;
		}
	}
	pwd[i] = 0;
}
void login()
{
	char userName[8] = {};
	char passWord[8] = {};
	int j = 0;
	printf("�������û�����>");
	scanf("%s", userName);
	printf("\n");
	printf("���������룺>");
	getpwd(passWord);
	readUserFromFile();

	USER *head = readUserFromFile();

	USER *findNode = head->next;

	USER *save;

	bool loginStatement = 1;

	save = findNode;

	while (findNode != NULL)
	{
		if ((strcmp(findNode->username, userName) == 0) && (strcmp(findNode->password, passWord) == 0))
		{
			loginStatement = 0;
			break;
		}
		findNode = findNode->next;
	}
	for (int i = 0; i < 3; i++) {
		if (loginStatement == 0)
		{
			printf("��¼�ɹ���\n");
			break;
			/*FILE *cfptr;
			cfptr = fopen("loginHistory.txt", "a+");

			time_t now;
			struct tm *tm_now;
			time(&now);
			tm_now = localtime(&now);
			fprintf(cfptr,"%d-%d-%d %d:%d:%d  %s\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec, userName);
			fclose(cfptr);
			*/
		}
		else
		{
			printf("�û���������������ٴ�����(������%d�λ���)��\n", 2 - i);
			puts("");
			if (i == 2) {
				exit(0);
			}
			printf("�������û�����>");
			scanf("%s", userName);
			printf("\n");
			printf("���������룺>");
			getpwd(passWord);
			findNode = save;
			while (findNode != NULL)
			{
				if ((strcmp(findNode->username, userName) == 0) && (strcmp(findNode->password, passWord) == 0))
				{
					loginStatement = 0;
					break;
				}
				findNode = findNode->next;
			}
		}
	}
	system("pause");
	getchar();
	system("CLS");
}