#pragma once
#include<stdio.h>
#include"Lab5_support.h"
#include"Lab5_data.h"
int showMainMenu() {
	printf("\t***程序主菜单***\t\n");
	printf("\t***杜海玮制作***版权所有***\t\n");
	printf("请输入功能选项前的数字来选择该选项\n");
	printf("1.调用实验4程序生成记录文件（文本方式）\n");
	printf("2.调用实验4程序生成记录文件（二进制方式）\n");
	printf("3.读取指定数据记录文件（二维数组存储方式）\n");
	printf("4.读取指定数据记录文件（结构体数组存储方式）\n");
	printf("5.读取指定数据记录文件（指针数组存储方式）\n");
	printf("6.读取指定数据记录文件（链表存储方式）\n");
	printf("7.调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）\n");
	printf("8.调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）\n");
	printf("9.调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组存储方式）\n");
	printf("10.调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）\n");
	printf("11.调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）\n");
	printf("12.调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）\n");
	printf("13.调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）\n");
	printf("14.调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）\n");
	printf("15.重新设置配置参数程序主菜单\n");
	printf("0.退出\n");
	int input;
	scanf_s("%d",&input);
	clearStdin();
	return input;
}
void ShowLink(Node* head) {
	for (int i = 0;; i++) {
		if ( head->nextnode== NULL) {
			printf("%d,%d,%d\n", head->data.item1, head->data.item2, head->data.item3);
			break;
		}
		else {
			printf("%d,%d,%d\n", head->data.item1, head->data.item2, head->data.item3);
			head = head->nextnode;
		}
	}
}

void Show2DArray(int** array) {
	printf("展示二维数组:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", array[i][0], array[i][1], array[i][2]);
	}
}
void ShowFingerArray(DATAITEM** input) {
	printf("展示指针数组:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", input[i]->item1, input[i]->item2, input[i]->item3);
	}
}
void ShowStructArray(DATAITEM* input) {
	printf("展示结构体数组:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", input[i].item1, input[i].item2, input[i].item3);
	}
}