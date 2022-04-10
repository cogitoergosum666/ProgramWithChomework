#include"lab4_DataForFun.h"
#include"lab4_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<io.h>
#include<direct.h>

FILE* fp;
int FileFormat = 0;

void clearStdin();
/***********************************************
��������:
	�������뺯��
��������:
	���û�������������������ļ���
��������:
	�ṹ��DataItem���ͣ�fpΪȫ���ļ�ָ��
����ֵ:
	��
ģ����ʷ:
	�ź�����2021��4��20�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void WriteFile(DataItem*a) {
	if (Stat.FileType == 't') {
		fprintf(fp, "%d\n", Stat.number);
		for (int i = 0; i < Stat.number; i++) {
			fprintf(fp, "%d,%d,%d\n", a[i].item1, a[i].item2, a[i].item3);
		}
	}
	if (Stat.FileType == 'd') {
		fwrite(&Stat.number, 4, 1, fp);
		fwrite(a, 12, Stat.number, fp);
		//for (int i = 0; i < Stat.number; i++) {
			//printf( "%d,%d,%d\n", a[i].item1, a[i].item2, a[i].item3);
		//}
	}
}
/***********************************************
��������:
	�����������뺯��
��������:
	���û������������������ṹ�壬������벻��ȷ����ʾ�û��������룬ֱ��������ȷ��
��������:
	�ṹ��configinof����
����ֵ:
	��
ģ����ʷ:
	�ź�����2021��4��13�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
void inputRec(configinfo s) {
	int res = 0;
	char input[1001];
	for (int i = 0; i < 100; i++) {
	printf("��������ȷ��ʽ�ļ�¼���������������ֻ�r��r��ʾ�������������Ŀ\n");
	scanf_s("%s", input,1000);
	clearStdin();
	int flagNumber = check(input);
		if (flagNumber == 0) {
			printf("��¼��������ɹ���������...\n");
			strToNumber(input, &Stat.number);
			res = 1;
		}
		else if (flagNumber == 1) {
			if (input[0] == 'r' && input[1] == '\0') {
				printf("������ɼ�¼������...\n");
				Stat.number = random(Stat.recordcount2, Stat.recordcount1);
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
		if (i == 99) {
			printf("����ʧ��99�Σ���������");
		}
	}
}
/***********************************************
��������:
	�����ļ���ȡ����
��������:
	��ȡ����exe�ļ�ͬ��Ŀ¼�µ��ı������ļ���д������Ľṹ��
��������:
	�ṹ��configinof����
����ֵ:
	1Ϊ����ɹ���0Ϊ����ʧ��
ģ����ʷ:
	�ź�����2021��4��13�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int ReadConf(configinfo*input) {
	FILE* fp2;
	_chdir("../");
	fopen_s(&fp2,"conf.ini", "r");
	if (fp2 == NULL) {
		printf("
			
			");
		return 0;
	}
	fscanf_s(fp2, "%s", input->filesavepath,1000);
	fscanf_s(fp2, "%s", input->filename,1000);
	fscanf_s(fp2, "%d", &input->maxvalue1,1000);
	fscanf_s(fp2, "%d", &input->minvalue1,1000);
	fscanf_s(fp2, "%d", &input->maxvalue2,1000);
	fscanf_s(fp2, "%d", &input->minvalue2,1000);
	fscanf_s(fp2, "%d", &input->recordcount1,1000);
	fscanf_s(fp2, "%d", &input->recordcount2,1000);

	fclose(fp2);
	return 1;
}
/***********************************************
��������:
	�����༶�ļ�Ŀ¼����
��������:
	���༶�ļ�Ŀ¼�𼶽���
��������:
	��
����ֵ:
	�޷���ֵ
ģ����ʷ:
	�ź�����2021��3��31�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int CreateDir(char* path)
{
	char str[1000];
	char* c = path;
	int lenth = strlen(path), flag = 0;
	int i, count;             //count��¼/����\��λ��
	if (path == NULL) return 0;
	//if (PathForm == 0) return 1;
	else
	{
		if (PathForm == 1)//�������·��
		{
			strncpy_s(str, sizeof(str), path, 2);
			if (_chdir(str))//����ֵΪ0������if�����������̲�����
			{
				printf("���̲�����\n");
				return 0;
			}
			else
			{
				for (i = 0, count = 0; i < lenth; i++)
				{
					if (path[i] == '/' || path[i] == '\\')
					{
						count = i;
						strncpy_s(str, sizeof(str), path, count);//��/��\֮ǰ��·�����Ƹ�str
						if (_chdir(str))//����������򴴽�Ŀ¼
						{
							_mkdir(str);

						}
					}
				}
			}
		}
		else//�������·��
		{
			for (i = 0, count = 0; i < lenth; i++)//�ȴ���..����������䴦����ɺ��ٴ�����
			{
				if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] != '.')
				{
					_chdir("..");
					c = path + i + 2;
					flag = 1;
				}//�ҵ����Ҷ˵ġ�../��
			}
			if (flag) c++;
			strcpy_s(str, sizeof(str), c);
			lenth = strlen(str);
			for (i = 0; i < lenth; i++)
			{
				if (str[i] == '/' ) {
					str[i] = '\0';
					_mkdir(str);
					str[i] = '/';
				}
				if ( str[i] == '\\') {
					str[i] = '\0';
					_mkdir(str);
					str[i] = '\\';
				}
			}
			_chdir(str);
		}
	}
	printf("Ŀ¼�����ɹ�\n");
	return 1;
}
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
	char* def = Stat.filesavepath;
	name = (char*)malloc(sizeof(char) * 100);
	name2 = (char*)malloc(sizeof(char) * 100);
	if (a[1] == ':') {
		name = strrchr(a, '\\') + 1;
		strcpy_s(Stat.filename, name);
		strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
		PathForm = 1;//�û�ʹ�þ���·����ʽ
	}
	else {
		name = strrchr(a, '\\');
		name2 = strrchr(a, '/');
		if (name == NULL && name2 == NULL) {
			//name = strrchr(a, '/') + 1;
			strcpy_s(Stat.filename, a);
			strcpy_s(Stat.filesavepath, def);
			PathForm = 2;//�û�ʹ��������·����ʽ��ʹ��Ĭ��Ŀ¼��
		}
		else if (name2 == NULL) {
			name = strrchr(a, '\\') + 1;
			strcpy_s(Stat.filename, name);
			strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
			PathForm = 2;//�û�ʹ��ֻ����\�����·����ʽ
		}
		else if(name == NULL){
			name = strrchr(a, '/') + 1;
			strcpy_s(Stat.filename, name);
			strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
			PathForm = 2;//�û�ʹ��ֻ����/�����·����ʽ
		}
		else {
			int pos1 = 0, pos2 = 0;//pos1����\��λ�ã�pos2����/��λ��
			for (int i = 0; i < strlen(a); i++) {
				if (a[i] == '\\') {
					pos1 = i;
				}
				if (a[i] == '/') {
					pos2 = i;
				}
			}
			if (pos1 > pos2) {
				name = strrchr(a, '\\') + 1;
				strcpy_s(Stat.filename, name);
				strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
				PathForm = 2;//�û�ʹ��ֻ����\�����·����ʽ
			}
			if (pos1 < pos2) {
				name = strrchr(a, '/') + 1;
				strcpy_s(Stat.filename, name);
				strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
				PathForm = 2;//�û�ʹ��ֻ����/�����·����ʽ
			}
		}
	}


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
		if (/*input[i] == ':' || */input[i] == '*' || input[i] == '?' || input[i] == '\"' || input[i] == '<' || input[i] == '>' || input[i] == '|') {
			return 0;//�Ƿ��ַ��Ų飬���ַǷ��ַ�����0
		}
	}
	return 1;
	/*int Last4Digit = strlen(input) - 4;
	if (input[Last4Digit] == '.') {
		if (input[Last4Digit + 1] == 't' || input[Last4Digit + 1] == 'd') {
			if (input[Last4Digit + 2] == 'x' || input[Last4Digit + 2] == 'a') {
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
	*/
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
	scanf_s("%s", input, 100);
	clearStdin();
	flag = check(input);
	for (int i = 0; i < 100; i++) {
		if (flag == 0) {
			printf("��¼��������ɹ���������...\n");
			strToNumber(input, &Stat.number);
			res = 1;
		}
		else if (flag == 1) {
			if (input[0] == 'r') {
				printf("������ɼ�¼������...\n");
				Stat.number = random(Stat.recordcount2, Stat.recordcount1);
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
	printf("����ļ���ʽ�Ѱ�Ĭ�ϸ�ʽ��������txt�ļ���\n");
	/*for (int j = 0; j < 100; j++) {
		char c;
		int res3=0;
		printf("����������ļ���ʽ��t��������ı��ļ���d��������������ļ���");
		scanf_s("%c",&c);
		if (c == 't') { 
			FileFormat = 1;//�û�������ı��ļ�
			res3 = 1; 
		}
		if (c == 'd') {
			FileFormat = 2;//�û�������������ļ�
			res3 = 1;
		}
		if (c == 'u') {
			res3 = 1;//�û�ʹ��Ĭ�����ã�ͬʱ������ָ�ʽ�ļ�
		}
		if (j == 99) {
			printf("�Ѿ�����99�Σ�����ϸ�Ķ�����淶��");
		}
	}
	*/
	printf("������Ŀ���ļ���������ļ���ʽ�����룬������...\n");

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
		if (c[0] == 'r' && c[1] == '\0') {
			printf("������ɼ�¼������...\n");
			Stat.number = random(Stat.recordcount2, Stat.recordcount1);
			res = 1;
			printf("�ļ�����洢·������Ĭ�������");
		}
		else {
			inputRec(Stat);
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
		}
	}
	res = 0;
	char input2[100];
	if (flag == 0) {//����Ϊ����
		strcpy_s(input, c);
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
					Stat.number = random(Stat.recordcount2, Stat.recordcount1);
					res = 1;
				}
				else {
					inputRec(Stat);
				}
			}
			if (res == 1)break;
		}
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

	}
	printf("����ļ���ʽ�Ѱ�Ĭ�ϸ�ʽ��������txt�ļ���\n");
	printf("�ļ�����������Ŀ������ļ���ʽ�����룬������...\n");
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

	char input[1000];
	int flag = check(c1);
	int res = 0;
	int res2 = 0;
	int res3 = 0;
	if (flag == 0) {//��һ������Ϊ����
		strcpy_s(input, c1);
		for (int i = 0; i < 100; i++) {
			int flagNumber = check(input);
			if (flagNumber == 0) {
				printf("��¼��������ɹ���������...\n");
				strToNumber(input, &Stat.number);
			}
			else {
				inputRec(Stat);
			}
			if (CheckFilePath(c2) == 1) {//���ڶ��������Ƿ�Ϸ�
				printf("�ļ����Ϸ���������...\n");
				FillPath(c2);
				res = 1;
			}
			else {
				for (int j = 0; j < 100; j++) {
					printf("������Ϸ��ļ��洢·����\n");
					scanf_s("%s", FilePath, 100);
					clearStdin();
					if (CheckFilePath(FilePath) == 1) {
						printf("�ļ����Ϸ���������...\n");
						FillPath(FilePath);
						res2 = 1;
					}
					else {
						printf("�ļ����Ƿ������ٴ�����\n");
						res2 = 0;
					}
					if (res2 == 1)break;
				}
			}

			if (res == 1) {
				break;
			}
		}
	}

	else {//���ڶ��������Ƿ�Ϊ��ֵ
		printf("���벻�Ϸ��������˳�\n");
		return 0;
		}
	if (res == 1) {
		printf("�ļ�����������Ŀ�����룬������...\n");
		printf("����ļ���ʽ�Ѱ�Ĭ�ϸ�ʽ��������txt�ļ���\n");
		printf("�ļ�����������Ŀ������ļ���ʽ�����룬������...\n");
		return 1;
	}
}
/***********************************************
��������:
	�û�������������ʱ�ļ�������
��������:
	���û�����ֵ��鲢���ж�Ӧ����
��������:
	����������ַ���c1��c2��c3
����ֵ:
	����ֵ0��ʾ����Ϸ������Խ�����һ��������ֵ1�������벻�Ϸ����޷�������һ��
ģ����ʷ:
	�ź�����2021��4��15�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int inputThree(char* c1, char* c2, char* c3) {
	if (check(c1) == 0 || (c1[0] == 'r' && c1[1] == '\0')) {
		if (c1[0] != 'r') {
			int p;
			strToNumber(c1, &p);
			Stat.number = p;
		}
		else {
			Stat.number = random(Stat.recordcount2, Stat.recordcount1);
		}
		printf("������������ɹ�\n");
	}
	else {
		inputRec(Stat);
	}
	if (check(c2) == 1 && CheckFilePath(c2) == 1) {
		FillPath(c2);
		printf("�ļ�·������ɹ�\n");
	}
	else {
		char FilePath[100];
		int res2 = 0;
		for (int j = 0; j < 100; j++) {
			printf("������Ϸ��ļ��洢·����\n");
			scanf_s("%s", FilePath, 100);
			clearStdin();
			if (CheckFilePath(FilePath) == 1) {
				printf("�ļ����Ϸ���������...\n");
				FillPath(FilePath);
				res2 = 1;
			}
			else {
				printf("�ļ����Ƿ������ٴ�����\n");
				res2 = 0;
			}
			if (res2 == 1)break;
			if (j == 99) {
				printf("�Ѿ�����99�Σ������˳�");
				return 0;
			}
		}
	}
	if ((c3[0] == 't' && c3[1] == '\0') || (c3[0] == 'd' && c3[1] == '\0')) {
		Stat.FileType = c3[0];
		printf("�ļ���ʽ����ɹ�\n");
	}
	else {
		char input[100];
		int res3 = 0;
		for (int j = 0; j < 100; j++) {
			printf("��������ȷ�ļ���ʽ��t��ʾ���txt�ļ���d��ʾ����������ļ�\n");
			scanf_s("%s", input, 100);
			clearStdin();
			if ((input[0] == 't' && input[1] == '\0') || (input[0] == 'd' && input[1] == '\0')) {
				Stat.FileType = input[0];
				printf("�ļ���ʽ����ɹ�\n");
				res3 = 1;
			}
			if(res3==1){
				break;
			}
			if (j == 99) {
				printf("�Ѿ�����99�Σ������˳�");
				return 0;
			}
		}
	}
	return 1;
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
void CreatRandomData(DataItem*a) {
	for (int i = 0; i < Stat.number; i++) {
		
		a[i].item1 = random(Stat.minvalue1, Stat.maxvalue1);
			
		a[i].item2 = random(Stat.minvalue1, Stat.maxvalue1);
		if (a[i].item1 == a[i].item2) {
			for (int i = 0; i < 1000; i++) {
				a[i].item2 = random(Stat.minvalue1, Stat.maxvalue1);
				if (a[i].item1 != a[i].item2) {
					break;
				}
			}
		}
		a[i].item3 = random(Stat.minvalue2, Stat.maxvalue2);
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
void CreateFile(DataItem*a) {
	char txt[10] = ".txt";
	char dat[10] = ".dat";
	char FullPath[1000];
	int acc = _access(Stat.filesavepath, 0);
	if (acc == 0) {//Ŀ¼����
		_chdir(Stat.filesavepath);
		strcpy_s(FullPath, Stat.filesavepath);
		strcat_s(FullPath, Stat.filename);
		if (Stat.FileType == 't') {
			strcat_s(Stat.filename, txt);
		}
		if (Stat.FileType == 'd') {
			strcat_s(Stat.filename, dat);
		}
		fopen_s(&fp, Stat.filename, "w");
		if (fp == NULL) {
			printf("�ļ���ʧ��");
		}
		else {
			WriteFile(a);
		}
		
		fclose(fp);
	}
	if (acc == -1) {//Ŀ¼������
		CreateDir(Stat.filesavepath);
		_chdir(Stat.filesavepath);
		if (Stat.FileType == 't') {
			strcat_s(Stat.filename, txt);
		}
		if (Stat.FileType == 'd') {
			strcat_s(Stat.filename, dat);
		}
		fopen_s(&fp, Stat.filename, "w");
		if (fp == NULL) {
			printf("�ļ���ʧ��");
		}
		else {
			WriteFile(a);
		}
		fclose(fp);
	}
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