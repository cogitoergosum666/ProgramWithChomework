
#include"lab3_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<malloc.h>


void run(int argc, char* argv[]) {
	srand((int)time(0));//�����������
	int finish;
	for (int i = 0; i < 100; i++) {
		switch (argc)
		{
		case 1:getParam();
			CreatRandomData();
			CreateFile();
			finish = 1;
			break;//�û�ֻ�����˳�������������������

		case 2:inputOne(argv[1]);
			CreatRandomData();
			CreateFile();
			finish = 1;
			break;//�û����������ݼ�¼����ֵ���ļ���

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
		}//�û����������ݼ�¼����ֵ�Լ��ļ���

		default:printf("wrong input\n");
			printHelp();
			break;
		}
		if (finish == 1) {
			printf("���ɳɹ���");
			break;
		}
	}

}