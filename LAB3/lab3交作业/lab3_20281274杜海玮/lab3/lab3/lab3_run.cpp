
#include"lab3_fun.h"
#include"lab3_data.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>

void run(int argc, char* argv[]) {
	Stat.maxvalue1 = 200;
	Stat.maxvalue2 = 1000;
	Stat.minvalue1 = 0;
	Stat.minvalue2 = 100;
	Stat.recordcount1 = 998;
	Stat.recordcount2 = 10;
	srand((int)time(0));//�����������
	switch (argc)
	{
	case 1:getParam();
		CreatRandomData();
		CreateFile();
		break;//�û�ֻ�����˳�������������������

	case 2:inputOne(argv[1]);
		CreatRandomData();
		CreateFile();
		break;//�û����������ݼ�¼����ֵ���ļ���

	case 3:int res = inputTwo(argv[1], argv[2]);
		if (res == 1) {
			CreatRandomData();
			CreateFile();
		}
		break;

	}


}