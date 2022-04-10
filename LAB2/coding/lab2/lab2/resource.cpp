/****************************************************
作者信息：
	姓名：杜海玮              学号：20281274           班级：2009           学院：计算机与信息技术学院
	 Email:20281274@bjtu.edu.cn                                      电话：13392999691
版权声明：版权由杜海玮所有，除老师外，未经允许不得拷贝本人作业
模块名称:
	生成自定义数据条目模块
摘要:
	本模块可以按照用户的需求生成指定文件名与数据条数的随机数据并写入记事本文件
其它说明:
	本模块最大支持65535条数据，如果用户不给定数据条数或文件名称，本模块将自动生成默认文件名或随机数据条数
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
****************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

#define random(x) (rand()%x)

int Rec;
char* FileNameArray;
FILE* fp;
int Data[11][3];
int finish;
int* RecArray;//声明用来存放记录条数和文件名的变量

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

void strToNumber(char* c, int *p) {//字符串转换成数字函数
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
	使用默认文件名与生成随机数据条数函数
功能描述:
	将文件名设置为默认文件名，生成随机数据条数
函数参数:
	无参数
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void getParam() {//用户只输入了程序名称用来启动程序
	static char name[20] = { "Document.txt" };
	FileNameArray = name;
	Rec = random(10);
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
	int flag = check(c);
	if (flag == 1) {
		FileNameArray = c;
		Rec = random(10);
	}
	if (flag == 0) {
		RecArray = (int*)malloc(1000 * sizeof(int));
		strToNumber(c, RecArray);
		Rec = *RecArray;
		static char name[20] = { "Document.txt" };
		FileNameArray = name;
	}
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
void printHelp();
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
/***********************************************
函数名称:
	main函数
功能描述:
	将用户输入值放入对应函数并进行相应操作
函数参数:
	命令行参数整型argc，字符串指针数组argv
返回值:
	无返回值
模块历史:
	杜海玮于2021年3月15日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int main(int argc, char* argv[])
{
	srand((int)time(0));//设置随机种子
	for (int i = 0; i < 100; i++) {
		switch (argc)
		{
		case 1:getParam();
			CreatRandomData();
			CreateFile();
			finish = 1;
			break;//用户只输入了程序名称用来启动程序

		case 2:inputOne(argv[1]);
			CreatRandomData();
			CreateFile();
			finish = 1;
			break;//用户输入了数据记录条数值或文件名

		case 3:if (inputTwo(argv[1], argv[2]) == 0) {
			CreatRandomData();
			CreateFile();
			finish = 1;
			break;
		}
			   else {

			printf("wrong input\n");
			printHelp();
			int count = 0;
			char input1[100], input2[100];
			count = scanf_s("%s", input1, 100);
			count += scanf_s("%s", input2, 100);
			clearStdin();
			argc = count + 1;
			argv[1] = input1;
			argv[2] = input2;
			break;
		}//用户输入了数据记录条数值以及文件名

		default:printf("wrong input\n");
			printHelp();
			break;
		}
		if (finish == 1) {
			printf("生成成功！");
			break;
		}
	}
	return 0;
}
void printHelp()
{
	printf("请输入文件名与生成数据条数，中间用空格隔开，请严格按照格式输入！\n");
}
