
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
	srand((int)time(0));//�����������
	printf("�����в�����˳������ϸ��գ�����¼���� �ļ��� ����ļ���ʽ����˳�����룬�û�����ѡ��ȫ���򲿷����������в�����\n");
	printf("����������к�׺�����ļ�����ϵͳ���Զ�������ѡ�������ļ���ʽΪ�����ļ���Ӻ�׺����\n");
	switch (argc)
	{
	case 1:getParam();
		data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
		CreatRandomData(data);
		CreateFile(data);
		break;//�û�ֻ�����˳�������������������

	case 2:inputOne(argv[1]);
		data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
		CreatRandomData(data);
		CreateFile(data);
		break;//�û����������ݼ�¼����ֵ���ļ���

	case 3:
		if (inputTwo(argv[1], argv[2]) == 1) {
			data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
			CreatRandomData(data);
			CreateFile(data);
		}
		break;//�û���������������
	
	case 4:
		if (inputThree(argv[1], argv[2], argv[3]) == 1) {
			printf("�ļ�����������Ŀ������ļ���ʽ�����룬������...\n");
			data = (DataItem*)malloc(sizeof(struct DataItem) * Stat.number);
			CreatRandomData(data);
			CreateFile(data);

		}
		break;//�û���������������

	default:printf("�������룬���ϸ��ո�ʽ���룬�����˳���\n");
		break;
	}
	

	finish = clock();
	double TheTimes;
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("�ܹ�����ʱ��:%lf��", TheTimes);
	free(data);
	//data = NULL;
}