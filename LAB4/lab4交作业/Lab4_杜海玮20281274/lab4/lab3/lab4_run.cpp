
#include"lab4_data.h"
#include"lab4_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<time.h>

void run(int argc, char* argv[]) {
	long start, finish;
	start = clock();
	struct DataItem* data;
	data = (DataItem*)malloc(sizeof(struct DataItem) * 10);
	ReadConf(&Stat);
	
	Stat.FileType = 't';
	srand((int)time(0));//设置随机种子
	printf("命令行参数的顺序必须严格按照：‘记录条数 文件名 输出文件格式’的顺序输入，用户可以选择全部或部分输入命令行参数。\n");
	printf("请勿输入带有后缀名的文件名，系统将自动根据您选择的输出文件格式为您的文件添加后缀名。\n");
	switch (argc)
	{
	case 1:getParam();
		data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
		CreatRandomData(data);
		CreateFile(data);
		break;//用户只输入了程序名称用来启动程序

	case 2:inputOne(argv[1]);
		data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
		CreatRandomData(data);
		CreateFile(data);
		break;//用户输入了数据记录条数值或文件名

	case 3:
		if (inputTwo(argv[1], argv[2]) == 1) {
			data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
			CreatRandomData(data);
			CreateFile(data);
		}
		break;//用户输入了两个参数
	
	case 4:
		if (inputThree(argv[1], argv[2], argv[3]) == 1) {
			printf("文件名、数据条目与输出文件格式已输入，生成中...\n");
			data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
			CreatRandomData(data);
			CreateFile(data);

		}
		break;//用户输入了三个参数

	default:printf("错误输入，请严格按照格式输入，程序退出。\n");
		break;
	}
	

	finish = clock();
	double TheTimes;
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("总共消耗时间:%lf秒", TheTimes);
	free(data);
	//data = NULL;
}