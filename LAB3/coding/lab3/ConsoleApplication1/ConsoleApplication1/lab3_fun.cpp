
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
函数名称:
	拆分用户输入的文件名和文件路径
功能描述:
	拆分用户输入的文件名和文件路径，然后填入结构体对应变量中
函数参数:
	无参数
返回值:
	无
模块历史:
	杜海玮于2021年3月29日创建本模块，email:20281274@bjtu.edu.cn
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
			strcpy_s(Stat.filename, a);//用户使用最简相对路径形式
		}
		else {
			name = strchr(a, '\\') + 1;
		}
	}
	
	strncpy_s(Stat.filesavepath, a, strlen(a) - strlen(name) + 1);
}
/***********************************************
函数名称:
	检查文件路径是否合法
功能描述:
	检查文件路径是否合法，然后根据结果返回
函数参数:
	无参数
返回值:
	合法返回1，不合法返回0
模块历史:
	杜海玮于2021年3月29日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int CheckFilePath(char* input) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ':' || input[i] == '*' || input[i] == '?' || input[i] == '\"'|| input[i] == '<' || input[i] == '>'|| input[i] == '|') {
			return 0;//非法字符排查，出现非法字符返回0
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
	else return 0;//检查末尾是否是.txt或.dat格式，如果是则返回1，不是则返回0
}
/***********************************************
函数名称:
	字符串转换成数字函数
功能描述:
	将数字字符串转换成对应数字
函数参数:
	输入待转换字符串指针c，目标整型指针p
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/

void strToNumber(char* c, int* p) {//字符串转换成数字函数
	int res = 0; int j = 0;
	for (int i = strlen(c) - 1; i > -1; i--) {
		res = (c[i] - '0') * ((int)pow(10, j)) + res;
		j++;
	}
	*p = res;
}
/***********************************************
函数名称:
	输入鉴定函数
功能描述:
	鉴定用户输入是否为纯数字字符串
函数参数:
	输入待鉴定字符串指针c
返回值:
	返回值1代表非纯数字字符串，返回值0代表数字字符串
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/

int check(char* c) {//用户输入了数据记录条数值或文件名
	int flag = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		if (!isdigit(c[i])) {
			flag = 1;//如果出现非数字字符，则所检查的char数组为文件名
		}
	}
	return flag;//flag为1表示为不只有数字的字符串，为文件名。flag为0表示只有数字的字符串，为文件条数。
}
/***********************************************
函数名称:
	用户无输入时的函数
功能描述:
	让用户输入数据
函数参数:
	无参数
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void getParam() {//用户只输入了程序名称用来启动程序
	char input[100];
	int flag = 3;
	int res = 0;
	printf("请输入记录条数:\n");
	scanf_s("%s", input,100);
	clearStdin();
	flag = check(input);
	for(int i = 0;i<100;i++){
	if (flag == 0) {
		printf("记录条数输入成功，生成中...\n");
		strToNumber(input,&Stat.number);
		res = 1;
	}
	else if (flag == 1) {
		if (input[0] == 'r') {
			printf("随机生成记录条数中...\n");
			Stat.number = random(10);
			res = 1;
		}
		else {
			printf("错误输入，请重新输入数据条数，若需要随机生成数据请输入r\n");
		}
	}
	else {
		printf("错误输入(类型2)，请重新输入数据条数，若需要随机生成数据请输入r\n");
	}
	if (res == 1) {
		break;
	}
}
	for (int j = 0; j < 100; j++) {
		printf("请输入文件存储路径：\n");
		scanf_s("%s", FilePath, 100);
		clearStdin();
		if (CheckFilePath(FilePath) == 1) {
			printf("文件名合法，生成中...\n");
			FillPath(FilePath);
			res = 1;
		}
		else {
			printf("文件名非法，请再次输入\n");
			res = 0;
		}
		if (res == 1)break;
	}
	printf("文件名与数据条目已输入，生成中...\n");
	
}
/***********************************************
函数名称:
	用户输入一个数据时的鉴定函数
功能描述:
	将用户输入值检查并进行对应操作
函数参数:
	输入待鉴定字符串c
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void inputOne(char* c) {
	char input[1000];
	int flag = check(c);
	int res = 0;
	if (flag == 1) {//输入为字符串
		if (CheckFilePath(FilePath) == 1) {
			printf("文件名合法，生成中...\n");
			FillPath(FilePath);
		}
		else {
			for (int j = 0; j < 100; j++) {
				printf("请输入合法文件存储路径：\n");
				scanf_s("%s", FilePath, 100);
				clearStdin();
				if (CheckFilePath(FilePath) == 1) {
					printf("文件名合法，生成中...\n");
					FillPath(FilePath);
					res = 1;
				}
				else {
					printf("文件名非法，请再次输入\n");
					res = 0;
				}
				if (res == 1)break;
			}
		}
		printf("请输入记录条数:\n");
		scanf_s("%s", input, 100);
		clearStdin();
		int flagNumber = check(input);
		for (int i = 0; i < 100; i++) {
			if (flagNumber == 0) {
				printf("记录条数输入成功，生成中...\n");
				strToNumber(input, &Stat.number);
				res = 1;
			}
			else if (flagNumber == 1) {
				if (input[0] == 'r') {
					printf("随机生成记录条数中...\n");
					Stat.number = random(10);
					res = 1;
				}
				else {
					printf("错误输入，请重新输入数据条数，若需要随机生成数据请输入r\n");
				}
			}
			else {
				printf("错误输入(类型2)，请重新输入数据条数，若需要随机生成数据请输入r\n");
			}
			if (res == 1) {
				break;
			}
		}
	}
	
	if (flag == 0) {
			printf("请输入文件存储路径：\n");
			scanf_s("%s", FilePath, 100);
			clearStdin();
			if (CheckFilePath(FilePath) == 1) {
				printf("文件名合法，生成中...\n");
				FillPath(FilePath);
			}
			else {
				for (int j = 0; j < 100; j++) {
					printf("请输入合法文件存储路径：\n");
					scanf_s("%s", FilePath);
					clearStdin();
					if (CheckFilePath(FilePath) == 1) {
						printf("文件名合法，生成中...\n");
						FillPath(FilePath);
						res = 1;
					}
					else {
						printf("文件名非法，请再次输入\n");
						res = 0;
					}
					if (res == 1)break;
				}
			}
			int flagNumber = check(input);
			for (int i = 0; i < 100; i++) {
				if (flagNumber == 0) {
					printf("记录条数输入成功，生成中...\n");
					strToNumber(input, &Stat.number);
					res = 1;
				}
				else if (flagNumber == 1) {
					if (input[0] == 'r') {
						printf("随机生成记录条数中...\n");
						Stat.number = random(10);
						res = 1;
					}
					else {
						printf("错误输入，请重新输入数据条数，若需要随机生成数据请输入r\n");
					}
				}
				else {
					printf("错误输入(类型2)，请重新输入数据条数，若需要随机生成数据请输入r\n");
				}
				if (res == 1) {
					break;
				}
			}
	}
	printf("文件名与数据条目已输入，生成中...\n");
}
/***********************************************
函数名称:
	用户输入两个数据时的鉴定函数
功能描述:
	将用户输入值检查并进行对应操作
函数参数:
	输入待鉴定字符串c1，c2
返回值:
	返回值0表示输入合法，可以进行下一步，返回值1代表输入不合法，无法进行下一步
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
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
函数名称:
	生成随机数据函数
功能描述:
	生成指定数量的随机数据并填充目标数组
函数参数:
	无
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void CreatRandomData() {
	for (int i = 0; i < Rec; i++) {
		for (int j = 0; j < 3; j++) {
			Data[i][j] = random(100);
		}
	}
}
/***********************************************
函数名称:
	文件写入函数
功能描述:
	将随机数据数组写入文件
函数参数:
	无
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
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
函数名称:
	打印提示函数
功能描述:
	将提示信息打印
函数参数:
	无
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月20日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void printHelp() {
	printf("请输入文件名与生成数据条数，中间用空格隔开，也可以只输入两者中的一个，另一个将由程序随机生成。\n");
}
/***********************************************
函数名称:
	清空输入缓冲区函数
功能描述:
	将输入缓冲区上一次的输入清除
函数参数:
	无
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月23日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void clearStdin() {
	while (getchar() != '\n');
}