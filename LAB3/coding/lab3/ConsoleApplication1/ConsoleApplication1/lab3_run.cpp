
#include"lab3_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>


void run(int argc, char* argv[]) {
	srand((int)time(0));//设置随机种子
	int finish;
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

}