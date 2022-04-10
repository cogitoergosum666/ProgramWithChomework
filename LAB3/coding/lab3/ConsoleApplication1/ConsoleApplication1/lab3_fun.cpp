
#include"lab3_data.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

FILE* fp;

void clearStdin();
/***********************************************
��������:
	����û�������ļ������ļ�·��
��������:
	����û�������ļ������ļ�·����Ȼ������ṹ���Ӧ������
��������:
	�޲���
����ֵ:
	��
ģ����ʷ:
	�ź�����2021��3��29�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void FillPath(char* a) {
	char* name;
	char* name2;
	name = (char*)malloc(sizeof(char) * 100);
	name2 = (char*)malloc(sizeof(char) * 100);
	if (a[1] == ':') {
		name = strchr(a, '\\') + 1;
		strcpy_s(Stat.filename, name);
	}
	else {
		name = strchr(a, '\\');
		name2 = strchr(a, '/');
		if (name == NULL) {
			name = strchr(a, '/')+1;
		}
		else if(name2 == NULL) {
			strcpy_s(Stat.filename, a);//�û�ʹ��������·����ʽ
		}
		else {
			name = strchr(a, '\\') + 1;
		}
	}
	
	strncpy_s(Stat.filesavepath, a, strlen(a) - strlen(name) + 1);
}
/***********************************************
��������:
	����ļ�·���Ƿ�Ϸ�
��������:
	����ļ�·���Ƿ�Ϸ���Ȼ����ݽ������
��������:
	�޲���
����ֵ:
	�Ϸ�����1�����Ϸ�����0
ģ����ʷ:
	�ź�����2021��3��29�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int CheckFilePath(char* input) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ':' || input[i] == '*' || input[i] == '?' || input[i] == '\"'|| input[i] == '<' || input[i] == '>'|| input[i] == '|') {
			return 0;//�Ƿ��ַ��Ų飬���ַǷ��ַ�����0
		}
	}
	int Last4Digit = strlen(input) - 4;
	if (input[Last4Digit] == '.') {
		if (input[Last4Digit + 1] == 't'|| input[Last4Digit + 1] == 'd') {
			if (input[Last4Digit + 2] == 'x'|| input[Last4Digit + 2] == 'a') {
				if (input[Last4Digit + 3] == 't') {
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;//���ĩβ�Ƿ���.txt��.dat��ʽ��������򷵻�1�������򷵻�0
}
/***********************************************
��������:
	�ַ���ת�������ֺ���
��������:
	�������ַ���ת���ɶ�Ӧ����
��������:
	�����ת���ַ���ָ��c��Ŀ������ָ��p
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/

void strToNumber(char* c, int* p) {//�ַ���ת�������ֺ���
	int res = 0; int j = 0;
	for (int i = strlen(c) - 1; i > -1; i--) {
		res = (c[i] - '0') * ((int)pow(10, j)) + res;
		j++;
	}
	*p = res;
}
/***********************************************
��������:
	�����������
��������:
	�����û������Ƿ�Ϊ�������ַ���
��������:
	����������ַ���ָ��c
����ֵ:
	����ֵ1����Ǵ������ַ���������ֵ0���������ַ���
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/

int check(char* c) {//�û����������ݼ�¼����ֵ���ļ���
	int flag = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		if (!isdigit(c[i])) {
			flag = 1;//������ַ������ַ�����������char����Ϊ�ļ���
		}
	}
	return flag;//flagΪ1��ʾΪ��ֻ�����ֵ��ַ�����Ϊ�ļ�����flagΪ0��ʾֻ�����ֵ��ַ�����Ϊ�ļ�������
}
/***********************************************
��������:
	�û�������ʱ�ĺ���
��������:
	���û���������
��������:
	�޲���
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void getParam() {//�û�ֻ�����˳�������������������
	char input[100];
	int flag = 3;
	int res = 0;
	printf("�������¼����:\n");
	scanf_s("%s", input,100);
	clearStdin();
	flag = check(input);
	for(int i = 0;i<100;i++){
	if (flag == 0) {
		printf("��¼��������ɹ���������...\n");
		strToNumber(input,&Stat.number);
		res = 1;
	}
	else if (flag == 1) {
		if (input[0] == 'r') {
			printf("������ɼ�¼������...\n");
			Stat.number = random(10);
			res = 1;
		}
		else {
			printf("�������룬������������������������Ҫ�����������������r\n");
		}
	}
	else {
		printf("��������(����2)��������������������������Ҫ�����������������r\n");
	}
	if (res == 1) {
		break;
	}
}
	for (int j = 0; j < 100; j++) {
		printf("�������ļ��洢·����\n");
		scanf_s("%s", FilePath, 100);
		clearStdin();
		if (CheckFilePath(FilePath) == 1) {
			printf("�ļ����Ϸ���������...\n");
			FillPath(FilePath);
			res = 1;
		}
		else {
			printf("�ļ����Ƿ������ٴ�����\n");
			res = 0;
		}
		if (res == 1)break;
	}
	printf("�ļ�����������Ŀ�����룬������...\n");
	
}
/***********************************************
��������:
	�û�����һ������ʱ�ļ�������
��������:
	���û�����ֵ��鲢���ж�Ӧ����
��������:
	����������ַ���c
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void inputOne(char* c) {
	char input[1000];
	int flag = check(c);
	int res = 0;
	if (flag == 1) {//����Ϊ�ַ���
		if (CheckFilePath(FilePath) == 1) {
			printf("�ļ����Ϸ���������...\n");
			FillPath(FilePath);
		}
		else {
			for (int j = 0; j < 100; j++) {
				printf("������Ϸ��ļ��洢·����\n");
				scanf_s("%s", FilePath, 100);
				clearStdin();
				if (CheckFilePath(FilePath) == 1) {
					printf("�ļ����Ϸ���������...\n");
					FillPath(FilePath);
					res = 1;
				}
				else {
					printf("�ļ����Ƿ������ٴ�����\n");
					res = 0;
				}
				if (res == 1)break;
			}
		}
		printf("�������¼����:\n");
		scanf_s("%s", input, 100);
		clearStdin();
		int flagNumber = check(input);
		for (int i = 0; i < 100; i++) {
			if (flagNumber == 0) {
				printf("��¼��������ɹ���������...\n");
				strToNumber(input, &Stat.number);
				res = 1;
			}
			else if (flagNumber == 1) {
				if (input[0] == 'r') {
					printf("������ɼ�¼������...\n");
					Stat.number = random(10);
					res = 1;
				}
				else {
					printf("�������룬������������������������Ҫ�����������������r\n");
				}
			}
			else {
				printf("��������(����2)��������������������������Ҫ�����������������r\n");
			}
			if (res == 1) {
				break;
			}
		}
	}
	
	if (flag == 0) {
			printf("�������ļ��洢·����\n");
			scanf_s("%s", FilePath, 100);
			clearStdin();
			if (CheckFilePath(FilePath) == 1) {
				printf("�ļ����Ϸ���������...\n");
				FillPath(FilePath);
			}
			else {
				for (int j = 0; j < 100; j++) {
					printf("������Ϸ��ļ��洢·����\n");
					scanf_s("%s", FilePath);
					clearStdin();
					if (CheckFilePath(FilePath) == 1) {
						printf("�ļ����Ϸ���������...\n");
						FillPath(FilePath);
						res = 1;
					}
					else {
						printf("�ļ����Ƿ������ٴ�����\n");
						res = 0;
					}
					if (res == 1)break;
				}
			}
			int flagNumber = check(input);
			for (int i = 0; i < 100; i++) {
				if (flagNumber == 0) {
					printf("��¼��������ɹ���������...\n");
					strToNumber(input, &Stat.number);
					res = 1;
				}
				else if (flagNumber == 1) {
					if (input[0] == 'r') {
						printf("������ɼ�¼������...\n");
						Stat.number = random(10);
						res = 1;
					}
					else {
						printf("�������룬������������������������Ҫ�����������������r\n");
					}
				}
				else {
					printf("��������(����2)��������������������������Ҫ�����������������r\n");
				}
				if (res == 1) {
					break;
				}
			}
	}
	printf("�ļ�����������Ŀ�����룬������...\n");
}
/***********************************************
��������:
	�û�������������ʱ�ļ�������
��������:
	���û�����ֵ��鲢���ж�Ӧ����
��������:
	����������ַ���c1��c2
����ֵ:
	����ֵ0��ʾ����Ϸ������Խ�����һ��������ֵ1�������벻�Ϸ����޷�������һ��
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int inputTwo(char* c1, char* c2) {
	if (check(c1) == 1 && check(c2) == 0) {
		FileNameArray = c1;
		RecArray = (int*)malloc(1000 * sizeof(int));
		strToNumber(c2, RecArray);
		Rec = *RecArray;
		return 0;
	}
	if (check(c2) == 1 && check(c1) == 0) {
		FileNameArray = c2;
		RecArray = (int*)malloc(1000 * sizeof(int));
		strToNumber(c1, RecArray);
		Rec = *RecArray;
		return 0;
	}
	else {
		return 1;
	}
}
/***********************************************
��������:
	����������ݺ���
��������:
	����ָ��������������ݲ����Ŀ������
��������:
	��
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void CreatRandomData() {
	for (int i = 0; i < Rec; i++) {
		for (int j = 0; j < 3; j++) {
			Data[i][j] = random(100);
		}
	}
}
/***********************************************
��������:
	�ļ�д�뺯��
��������:
	�������������д���ļ�
��������:
	��
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void CreateFile() {
	fopen_s(&fp, FileNameArray, "w");
	if (fp == NULL) {
		printf("file opened failed");
	}
	fprintf(fp, "%d\n", Rec);
	for (int i = 0; i < Rec; i++) {
		int j = 0;
		fprintf(fp, "%d,%d,%d\n", Data[i][j], Data[i][j + 1], Data[i][j + 2]);
	}

	fclose(fp);
}
/***********************************************
��������:
	��ӡ��ʾ����
��������:
	����ʾ��Ϣ��ӡ
��������:
	��
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��20�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void printHelp() {
	printf("�������ļ��������������������м��ÿո������Ҳ����ֻ���������е�һ������һ�����ɳ���������ɡ�\n");
}
/***********************************************
��������:
	������뻺��������
��������:
	�����뻺������һ�ε��������
��������:
	��
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��23�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void clearStdin() {
	while (getchar() != '\n');
}