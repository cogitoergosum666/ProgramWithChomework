#include"Lab5_data.h"
#include<io.h>
#include<direct.h>
#include<stdlib.h>
#include<stdio.h>
/***********************************************
�ļ�����:
    Lab5_end.cpp
��������:
    ������β�ļ��������ͷ�������ڴ��Լ�������������
ģ����ʷ:
    �ź�����2021��5��21�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/

void FreeLink(Node* head, Node* tail) {
    Node* temp1;
    Node* temp2;
    temp1 = head;
    temp2 = head->nextnode;
    for (int n = 0;; n++) {
        free(temp1);
        temp1 = temp2;
        temp2 = temp1->nextnode;
        if (temp2 == NULL)break;
    }
    printf("���ͷ������ڴ�\n");
}
void FreeArray1D(int* array) {
    free(array);
}
void FreeArray2D(int** input) {
    /*for (int i = 0; i < Record; i++) {
        free(input[i]);
    }*/
    free(input);
    input = NULL;
    printf("���ͷŶ�ά�����ڴ�\n");
}
void FreeFingerArray(DATAITEM** input) {
    for (int i = 0; i < Record; i++) {
        free(input[i]);
    }
    free(input);
    input = NULL;
    printf("���ͷ�ָ�������ڴ�\n");
}
void FreeStructArray(DATAITEM* input) {
    free(input);
    printf("���ͷŽṹ�������ڴ�\n");
}