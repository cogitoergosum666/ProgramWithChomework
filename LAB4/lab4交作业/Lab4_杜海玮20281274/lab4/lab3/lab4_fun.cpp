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
函数名称:
	数据输入函数
功能描述:
	将用户输入的数据条数输入文件。
函数参数:
	结构体DataItem类型，fp为全局文件指针
返回值:
	无
模块历史:
	杜海玮于2021年4月20日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void WriteFile(DataItem*a) {
	if (Stat.FileType == 't') {
		fopen_s(&fp, Stat.filename, "w");
		if (fp == NULL) {
			printf("文件打开失败");
		}
		else {
			fprintf(fp, "%d\n", Stat.number);
			for (int i = 0; i < Stat.number; i++) {
				fprintf(fp, "%d,%d,%d\n", a[i].item1, a[i].item2, a[i].item3);
			}
			fclose(fp);
		}
	}
	if (Stat.FileType == 'd') {
		fopen_s(&fp, Stat.filename, "wb+");
		if (fp == NULL) {
			printf("文件打开失败");
		}
		else {
			fwrite(&Stat.number, 4, 1, fp);
			fwrite(a, 4, 4*Stat.number, fp);
//			for (int i = 0; i < Stat.number; i++) {
//				printf("%d,%d,%d\n", a[i].item1, a[i].item2, a[i].item3);
//			}
			fclose(fp);
		}
	}
}
/***********************************************
函数名称:
	数据条数输入函数
功能描述:
	将用户输入的数据条数输入结构体，如果输入不正确则提示用户重新输入，直到输入正确。
函数参数:
	结构体configinof类型
返回值:
	无
模块历史:
	杜海玮于2021年4月13日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void inputRec(configinfo s) {
	int res = 0;
	char input[1001];
	for (int i = 0; i < 100; i++) {
	printf("请输入正确格式的记录条数，请输入数字或r，r表示随机生成数据条目\n");
	scanf_s("%s", input,1000);
	clearStdin();
	int flagNumber = check(input);
		if (flagNumber == 0) {
			printf("记录条数输入成功，生成中...\n");
			strToNumber(input, &Stat.number);
			res = 1;
		}
		else if (flagNumber == 1) {
			if (input[0] == 'r' && input[1] == '\0') {
				printf("随机生成记录条数中...\n");
				Stat.number = random(Stat.recordcount2, Stat.recordcount1);
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
		if (i == 99) {
			printf("输入失败99次，即将跳出");
		}
	}
}
/***********************************************
函数名称:
	配置文件读取函数
功能描述:
	读取程序exe文件同名目录下的文本配置文件并写入输入的结构体
函数参数:
	结构体configinof类型
返回值:
	1为输入成功，0为输入失败
模块历史:
	杜海玮于2021年4月13日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int ReadConf(configinfo*input) {
	FILE* fp2;
	//_chdir("../");
	fopen_s(&fp2,"conf.ini", "r");
	if (fp2 == NULL) {
		printf("文件打开失败");
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
函数名称:
	创建多级文件目录函数
功能描述:
	将多级文件目录逐级建立
函数参数:
	无
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月31日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int CreateDir(char* path)
{
	char str[1000];
	char* c = path;
	int lenth = strlen(path), flag = 0;
	int i, count;             //count记录/或者\的位置
	if (path == NULL) return 0;
	//if (PathForm == 0) return 1;
	else
	{
		if (PathForm == 1)//处理绝对路径
		{
			strncpy_s(str, sizeof(str), path, 2);
			if (_chdir(str))//返回值为0，符合if条件，即磁盘不存在
			{
				printf("磁盘不存在\n");
				return 0;
			}
			else
			{
				for (i = 0, count = 0; i < lenth; i++)
				{
					if (path[i] == '/' || path[i] == '\\')
					{
						count = i;
						strncpy_s(str, sizeof(str), path, count);//将/或\之前的路径复制给str
						if (_chdir(str))//如果不存在则创建目录
						{
							_mkdir(str);

						}
					}
				}
			}
		}
		else//处理相对路径
		{
			for (i = 0, count = 0; i < lenth; i++)//先处理..的情况，将其处理完成后再处理别的
			{
				if (path[i] == '.' && path[i + 1] == '.' && path[i + 2] != '.')
				{
					_chdir("..");
					c = path + i + 2;
					flag = 1;
				}//找到最右端的“../”
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
	printf("目录创建成功\n");
	return 1;
}
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
	char* def = Stat.filesavepath;
	name = (char*)malloc(sizeof(char) * 100);
	name2 = (char*)malloc(sizeof(char) * 100);
	if (a[1] == ':') {
		name = strrchr(a, '\\') + 1;
		strcpy_s(Stat.filename, name);
		strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
		PathForm = 1;//用户使用绝对路径形式
	}
	else {
		name = strrchr(a, '\\');
		name2 = strrchr(a, '/');
		if (name == NULL && name2 == NULL) {
			//name = strrchr(a, '/') + 1;
			strcpy_s(Stat.filename, a);
			strcpy_s(Stat.filesavepath, def);
			PathForm = 2;//用户使用最简相对路径形式（使用默认目录）
		}
		else if (name2 == NULL) {
			name = strrchr(a, '\\') + 1;
			strcpy_s(Stat.filename, name);
			strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
			PathForm = 2;//用户使用只含有\的相对路径形式
		}
		else if(name == NULL){
			name = strrchr(a, '/') + 1;
			strcpy_s(Stat.filename, name);
			strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
			PathForm = 2;//用户使用只含有/的相对路径形式
		}
		else {
			int pos1 = 0, pos2 = 0;//pos1代表\的位置，pos2代表/的位置
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
				PathForm = 2;//用户使用只含有\的相对路径形式
			}
			if (pos1 < pos2) {
				name = strrchr(a, '/') + 1;
				strcpy_s(Stat.filename, name);
				strncpy_s(Stat.filesavepath, sizeof(Stat.filesavepath), a, strlen(a) - strlen(name));
				PathForm = 2;//用户使用只含有/的相对路径形式
			}
		}
	}


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
		if (/*input[i] == ':' || */input[i] == '*' || input[i] == '?' || input[i] == '\"' || input[i] == '<' || input[i] == '>' || input[i] == '|') {
			return 0;//非法字符排查，出现非法字符返回0
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
	else return 0;//检查末尾是否是.txt或.dat格式，如果是则返回1，不是则返回0
	*/
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
	scanf_s("%s", input, 100);
	clearStdin();
	flag = check(input);
	for (int i = 0; i < 100; i++) {
		if (flag == 0) {
			printf("记录条数输入成功，生成中...\n");
			strToNumber(input, &Stat.number);
			res = 1;
		}
		else if (flag == 1) {
			if (input[0] == 'r') {
				printf("随机生成记录条数中...\n");
				Stat.number = random(Stat.recordcount2, Stat.recordcount1);
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
	printf("输出文件格式已按默认格式输出（输出txt文件）\n");
	/*for (int j = 0; j < 100; j++) {
		char c;
		int res3=0;
		printf("请输入输出文件格式，t代表输出文本文件，d代表输出二进制文件，");
		scanf_s("%c",&c);
		if (c == 't') { 
			FileFormat = 1;//用户想输出文本文件
			res3 = 1; 
		}
		if (c == 'd') {
			FileFormat = 2;//用户想输出二进制文件
			res3 = 1;
		}
		if (c == 'u') {
			res3 = 1;//用户使用默认设置（同时输出两种格式文件
		}
		if (j == 99) {
			printf("已经尝试99次，请仔细阅读输入规范！");
		}
	}
	*/
	printf("数据条目、文件名、输出文件格式已输入，生成中...\n");

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
		if (!strcmp(c,"r")) {             //c[0] == 'r' && c[1] == '\0'
			printf("随机生成记录条数中...\n");
			Stat.number = random(Stat.recordcount2, Stat.recordcount1);
			res = 1;
			printf("文件名与存储路径将按默认名输出");
		}
		else {
			inputRec(Stat);
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
		}
	}
	res = 0;
	char input2[100];
	if (flag == 0) {//输入为数字
		strcpy_s(input, c);
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
					Stat.number = random(Stat.recordcount2, Stat.recordcount1);
					res = 1;
				}
				else {
					inputRec(Stat);
				}
			}
			if (res == 1)break;
		}
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

	}
	printf("输出文件格式已按默认格式输出（输出txt文件）\n");
	printf("文件名、数据条目与输出文件格式已输入，生成中...\n");
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

	char input[1000];
	int flag = check(c1);
	int res = 0;
	int res2 = 0;
	int res3 = 0;
	if (flag == 0) {//第一个输入为数字
		strcpy_s(input, c1);
		for (int i = 0; i < 100; i++) {
			int flagNumber = check(input);
			if (flagNumber == 0) {
				printf("记录条数输入成功，生成中...\n");
				strToNumber(input, &Stat.number);
			}
			else {
				inputRec(Stat);
			}
			if (CheckFilePath(c2) == 1) {//检查第二个参数是否合法
				printf("文件名合法，生成中...\n");
				FillPath(c2);
				res = 1;
			}
			else {
				for (int j = 0; j < 100; j++) {
					printf("请输入合法文件存储路径：\n");
					scanf_s("%s", FilePath, 100);
					clearStdin();
					if (CheckFilePath(FilePath) == 1) {
						printf("文件名合法，生成中...\n");
						FillPath(FilePath);
						res2 = 1;
					}
					else {
						printf("文件名非法，请再次输入\n");
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

	else {//检查第二个参数是否为数值
		printf("输入不合法，程序退出\n");
		return 0;
		}
	if (res == 1) {
		printf("文件名与数据条目已输入，生成中...\n");
		printf("输出文件格式已按默认格式输出（输出txt文件）\n");
		printf("文件名、数据条目与输出文件格式已输入，生成中...\n");
		return 1;
	}
}
/***********************************************
函数名称:
	用户输入三个数据时的鉴定函数
功能描述:
	将用户输入值检查并进行对应操作
函数参数:
	输入待鉴定字符串c1，c2，c3
返回值:
	返回值0表示输入合法，可以进行下一步，返回值1代表输入不合法，无法进行下一步
模块历史:
	杜海玮于2021年4月15日创建本模块，email:20281274@bjtu.edu.cn
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
		printf("数据条数输入成功\n");
	}
	else {
		inputRec(Stat);
	}
	if (check(c2) == 1 && CheckFilePath(c2) == 1) {
		FillPath(c2);
		printf("文件路径输入成功\n");
	}
	else {
		char FilePath[100];
		int res2 = 0;
		for (int j = 0; j < 100; j++) {
			printf("请输入合法文件存储路径：\n");
			scanf_s("%s", FilePath, 100);
			clearStdin();
			if (CheckFilePath(FilePath) == 1) {
				printf("文件名合法，生成中...\n");
				FillPath(FilePath);
				res2 = 1;
			}
			else {
				printf("文件名非法，请再次输入\n");
				res2 = 0;
			}
			if (res2 == 1)break;
			if (j == 99) {
				printf("已经尝试99次，程序退出");
				return 0;
			}
		}
	}
	if ((c3[0] == 't' && c3[1] == '\0') || (c3[0] == 'd' && c3[1] == '\0')) {
		Stat.FileType = c3[0];
		printf("文件格式输入成功\n");
	}
	else {
		char input[100];
		int res3 = 0;
		for (int j = 0; j < 100; j++) {
			printf("请输入正确文件格式，t表示输出txt文件，d表示输出二进制文件\n");
			scanf_s("%s", input, 100);
			clearStdin();
			if ((input[0] == 't' && input[1] == '\0') || (input[0] == 'd' && input[1] == '\0')) {
				Stat.FileType = input[0];
				printf("文件格式输入成功\n");
				res3 = 1;
			}
			if(res3==1){
				break;
			}
			if (j == 99) {
				printf("已经尝试99次，程序退出");
				return 0;
			}
		}
	}
	return 1;
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
void CreateFile(DataItem*a) {
	char txt[10] = ".txt";
	char dat[10] = ".dat";
	char FullPath[1000];
	int acc = _access(Stat.filesavepath, 0);
	if (acc == 0) {//目录存在
		_chdir(Stat.filesavepath);
		strcpy_s(FullPath, Stat.filesavepath);
		strcat_s(FullPath, Stat.filename);
		if (Stat.FileType == 't') {
			strcat_s(Stat.filename, txt);
		}
		if (Stat.FileType == 'd') {
			strcat_s(Stat.filename, dat);
		}
		
		
//		else {
			WriteFile(a);
//		}
		
		//fclose(fp);
	}
	if (acc == -1) {//目录不存在
		CreateDir(Stat.filesavepath);
		_chdir(Stat.filesavepath);
		if (Stat.FileType == 't') {
			strcat_s(Stat.filename, txt);
		}
		if (Stat.FileType == 'd') {
			strcat_s(Stat.filename, dat);
		}
		//fopen_s(&fp, Stat.filename, "w");
//		if (fp == NULL) {
//			printf("文件打开失败");
//		}
//		else {
			WriteFile(a);
//		}
		//fclose(fp);
	}
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