#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//��������
void getParam(int*, char *);
int strToNumber(char *);
void getFileName(char *);
void getRecNum(int*);
void CreatFile(int, char*);
void clearStdin();
int isNumber(char *);
int random(int x);

/*
*�������ƣ�main
*�������ܣ��������ݼ�¼�ļ�
*���������argc/argv
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
int main(int argc, char *argv[])
{
	int record_num=0;//���ñ��������¼����
	char record_file[100];//���ñ��������ļ���
	srand((int)time(0));//��������ֵ

	switch (argc)//��argc�Ĳ�ֵͬ��������
	{
	case 1: getParam(&record_num, record_file); break;

	case 2: if ((isNumber(argv[1])))
	{
		record_num = strToNumber(argv[1]);
		getFileName(record_file);
	}
		  else 
	{ 
		getRecNum(&record_num);
		strcpy(record_file, argv[1]); 
	}
		  break;

	case 3:if ((isNumber(argv[1])))
	{
		record_num = strToNumber(argv[1]);
		strcpy(record_file, argv[2]);
	}
		  else if ((isNumber(argv[2])))
	{
		record_num = strToNumber(argv[2]);
		strcpy(record_file, argv[1]);
	}
		  else
	{
		printf("��������\n"); return 0;
	}
		  break;


	default:printf("��������\n"); return 0;

	}

	CreatFile(record_num, record_file);//���ɼ�¼�ļ�
	return 0;
}

/*
*�������ƣ�getParam
*�������ܣ�ͨ�����潻����ȡ��
¼�������ļ�������
*���������record_num/record_file
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
void getParam(int*num, char*file)
{
	while (1)
	{
		printf("���������ݼ�¼��������Ҫ����������ɣ�������0\n");

		char inum[100];
		int num1;
		scanf_s("%s", inum, sizeof(inum));

		if (isNumber(inum) == 0)
		{
			printf("���벻�Ϸ�������������\n");
			continue;
		}
		else
		{
			num1 = strToNumber(inum);
			if (num1 == 0) *num = random(100);
			else *num = num1;
			break;
		}
	}
	
	
		printf("�������¼�ļ����ƣ���ʹ��Ĭ���ļ����������� No \n");

		char filename[100];
		scanf_s("%s", filename, sizeof(filename));
		clearStdin();
		if (strcmp(filename, "No") == 0) strcpy(file, "Ĭ���ļ�.txt");
		else strcpy(file, filename);
	
}

/*
*�������ƣ�
*�������ܣ��������ַ�ת��Ϊ��
������
*���������argc
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
int strToNumber(char* argv)
{
	int res=0,i;
	for (i = 0; *(argv + i) != '\0'; i++)
	{
		res=*(argv + i) - '0' + res * 10;
	}
	return res;
}

/*
*�������ƣ�
*�������ܣ�ͨ�����潻����ȡ��
¼��������
*���������record_num
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
void getRecNum(int* num)
{
	while (1)
	{
		printf("���������ݼ�¼��������Ҫ����������ɣ�������0\n");

		char inum[100];
		int num1;
		scanf_s("%s", inum, sizeof(inum));

		if (isNumber(inum) == 0)
		{
			printf("���벻�Ϸ�������������\n");
			continue;
		}
		else
		{
			num1 = strToNumber(inum);
			if (num1 == 0) *num = random(100);
			else *num = num1;
			break;
		}
	}
}

/*
*�������ƣ�
*�������ܣ�ͨ�����潻����ȡ��
��������
*����������ļ���ַ
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
void getFileName(char* file)
{
	printf("�������¼�ļ����ƣ���ʹ��Ĭ���ļ����������� No \n");
	char filename[100];
	scanf_s("%s", filename,sizeof(filename));
	if (strcmp(filename, "No") == 0) strcpy(file, "Ĭ���ļ�.txt");
	else strcpy(file, filename);
}

/*
*�������ƣ�isNumber
*�������ܣ��ж��ַ����Ƿ�ȫ��
Ϊ����
*����������ַ���
*����ֵ����������
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
int isNumber(char* str)
{
	int i = 0;
	int flag = 1;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) - '0') < 0|| (*(str + i) - '0')>9)
		{
			flag = 0; break;
		}
		i++;
	}
	if (flag == 0) return 0;
	else return 1;
}

/*
*�������ƣ�
*�������ܣ����ɲ�����ָ������
���������
*���������x
*����ֵ�������
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
int random(int x)
{
	return rand() % x;
}

/*
*�������ƣ�
*�������ܣ�������뻺��������
ֹ���뻺����������
��Ӱ�����scanf��
��ִ��
*�����������
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
void clearStdin()
{
	char s;
	while ((s=getchar()) != '\n') {};
}


/*
*�������ƣ�
*�������ܣ��������ݼ�¼�ļ�
*���������record_num/record_file
*����ֵ����
*�汾��Ϣ��create by chenmingqiang,2021/3/23
*/
void CreatFile(int record_num, char* record_file)
{
	FILE* fp;
	int narr[100][3];
	fp = fopen(record_file, "w");
	if (fp == NULL)
	{
		printf("can't open");
		exit(0);
	}
	int i, j;
	for (i = 0; i < record_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			narr[i][j] = random(100);
		}
	}
	fprintf(fp, "%d\n", record_num);
	for (i = 0; i < record_num; i++)
	{
		for (j = 0; j < 3; j++)
		{
			fprintf(fp, "%d ",narr[i][j] );
		}
		fprintf(fp, "\n");
	}
	
	fclose(fp);
}