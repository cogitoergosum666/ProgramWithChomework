#pragma once
#include<stdio.h>
#include"Lab5_support.h"
#include"Lab5_data.h"
int showMainMenu() {
	printf("\t***�������˵�***\t\n");
	printf("\t***�ź�������***��Ȩ����***\t\n");
	printf("�����빦��ѡ��ǰ��������ѡ���ѡ��\n");
	printf("1.����ʵ��4�������ɼ�¼�ļ����ı���ʽ��\n");
	printf("2.����ʵ��4�������ɼ�¼�ļ��������Ʒ�ʽ��\n");
	printf("3.��ȡָ�����ݼ�¼�ļ������򣨶�ά����洢��ʽ��\n");
	printf("4.��ȡָ�����ݼ�¼�ļ������򣨽ṹ������洢��ʽ��\n");
	printf("5.��ȡָ�����ݼ�¼�ļ�������ָ������洢��ʽ��\n");
	printf("6.��ȡָ�����ݼ�¼�ļ�����������洢��ʽ��\n");
	printf("7.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ�������ά���鷽ʽ�洢��\n");
	printf("8.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("9.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("10.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ��������ı���ʽ���������ʽ�洢��\n");
	printf("11.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�������ά���鷽ʽ�洢��\n");
	printf("12.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ������ṹ�����鷽ʽ�洢��\n");
	printf("13.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�����ָ�����鷽ʽ�洢��\n");
	printf("14.����ʵ��4�������ݼ�¼�ļ�����ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ���������ʽ�洢��\n");
	printf("15.�����������ò����������˵�\n");
	printf("0.�˳�\n");
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
	printf("չʾ��ά����:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", array[i][0], array[i][1], array[i][2]);
	}
}
void ShowFingerArray(DATAITEM** input) {
	printf("չʾָ������:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", input[i]->item1, input[i]->item2, input[i]->item3);
	}
}
void ShowStructArray(DATAITEM* input) {
	printf("չʾ�ṹ������:\n");
	for (int i = 0; i < Record; i++) {
		printf("%d,%d,%d\n", input[i].item1, input[i].item2, input[i].item3);
	}
}