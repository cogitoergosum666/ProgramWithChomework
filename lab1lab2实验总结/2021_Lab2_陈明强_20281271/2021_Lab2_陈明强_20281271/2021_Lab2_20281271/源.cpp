#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//函数声明
void getParam(int*, char *);
int strToNumber(char *);
void getFileName(char *);
void getRecNum(int*);
void CreatFile(int, char*);
void clearStdin();
int isNumber(char *);
int random(int x);

/*
*函数名称：main
*函数功能：生成数据记录文件
*输入参数：argc/argv
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
*/
int main(int argc, char *argv[])
{
	int record_num=0;//设置变量保存记录条数
	char record_file[100];//设置变量保存文件名
	srand((int)time(0));//设置种子值

	switch (argc)//以argc的不同值分类讨论
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
		printf("参数错误\n"); return 0;
	}
		  break;


	default:printf("参数错误\n"); return 0;

	}

	CreatFile(record_num, record_file);//生成记录文件
	return 0;
}

/*
*函数名称：getParam
*函数功能：通过界面交互获取记
录条数及文件名参数
*输入参数：record_num/record_file
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
*/
void getParam(int*num, char*file)
{
	while (1)
	{
		printf("请输入数据记录条数，若要数据随机生成，则输入0\n");

		char inum[100];
		int num1;
		scanf_s("%s", inum, sizeof(inum));

		if (isNumber(inum) == 0)
		{
			printf("输入不合法，请重新输入\n");
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
	
	
		printf("请输入记录文件名称，若使用默认文件名，则输入 No \n");

		char filename[100];
		scanf_s("%s", filename, sizeof(filename));
		clearStdin();
		if (strcmp(filename, "No") == 0) strcpy(file, "默认文件.txt");
		else strcpy(file, filename);
	
}

/*
*函数名称：
*函数功能：将数字字符转换为整
型数字
*输入参数：argc
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
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
*函数名称：
*函数功能：通过界面交互获取记
录条数参数
*输入参数：record_num
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
*/
void getRecNum(int* num)
{
	while (1)
	{
		printf("请输入数据记录条数，若要数据随机生成，则输入0\n");

		char inum[100];
		int num1;
		scanf_s("%s", inum, sizeof(inum));

		if (isNumber(inum) == 0)
		{
			printf("输入不合法，请重新输入\n");
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
*函数名称：
*函数功能：通过界面交互获取文
件名参数
*输入参数：文件地址
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
*/
void getFileName(char* file)
{
	printf("请输入记录文件名称，若使用默认文件名，则输入 No \n");
	char filename[100];
	scanf_s("%s", filename,sizeof(filename));
	if (strcmp(filename, "No") == 0) strcpy(file, "默认文件.txt");
	else strcpy(file, filename);
}

/*
*函数名称：isNumber
*函数功能：判断字符串是否全部
为数字
*输入参数：字符串
*返回值：整形数据
*版本信息：create by chenmingqiang,2021/3/23
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
*函数名称：
*函数功能：生成不超过指定上限
的随机整数
*输入参数：x
*返回值：随机数
*版本信息：create by chenmingqiang,2021/3/23
*/
int random(int x)
{
	return rand() % x;
}

/*
*函数名称：
*函数功能：清空输入缓冲区，防
止输入缓冲区残留数
据影响后续scanf函
数执行
*输入参数：无
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
*/
void clearStdin()
{
	char s;
	while ((s=getchar()) != '\n') {};
}


/*
*函数名称：
*函数功能：生成数据记录文件
*输入参数：record_num/record_file
*返回值：无
*版本信息：create by chenmingqiang,2021/3/23
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