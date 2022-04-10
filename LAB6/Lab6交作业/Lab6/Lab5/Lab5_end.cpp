#include"Lab5_data.h"
#include<io.h>
#include<direct.h>
#include<stdlib.h>
#include<stdio.h>
/***********************************************
文件名称:
    Lab5_end.cpp
功能描述:
    程序收尾文件，用于释放申请的内存以及其他结束工作
模块历史:
    杜海玮于2021年5月21日创建本模块，email:20281274@bjtu.edu.cn
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
    printf("已释放链表内存\n");
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
    printf("已释放二维数组内存\n");
}
void FreeFingerArray(DATAITEM** input) {
    for (int i = 0; i < Record; i++) {
        free(input[i]);
    }
    free(input);
    input = NULL;
    printf("已释放指针数组内存\n");
}
void FreeStructArray(DATAITEM* input) {
    free(input);
    printf("已释放结构体数组内存\n");
}