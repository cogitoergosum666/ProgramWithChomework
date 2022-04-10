/***********************************************
文件名称:
    Lab5.cpp
功能描述:
    存放实验5程序所需的结构体声明、常量声明及全局变量声明
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/

#pragma once
#include"Lab5_data.h"
#include"Lab5_support.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"Lab5_loadfile.h"

/***********************************************
函数名称:
    将数据文件加载进入全局二维数组函数
功能描述:
    将用户指定位置或从上级传进来位置的数据文件加载进二维数组
函数参数:
    mode参数0为自动模式，读取实验4 conf.ini中默认储存位置的数据文件。
    1为自动模式，接受传入的UserFilePath全局变量，读取该路径下的数据文件
    2为手动读取模式，由用户输入需要读取的文件路径，读取该路径下的数据文件
    type 0为文本读取模式，type 1为二进制读取模式
返回值:
    无
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int loadTo1DArray(int mode,int type) {//将数据文件加载到二维数组
    if (mode == 0) {//自动模式，读取默认存储位置的数据文件
        
        
            if (type == 0) {
                FILE* fp;
                fopen_s(&fp, LabDefaultPath, "r");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                int rec = 1;
                fscanf_s(fp, "%d", &rec);
                Record = rec;
                Array1D = (int*)malloc(rec * 12);
                int j = 0;
                for (int n = 0; n < rec; n++) {
                    fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                    j = j + 3;
                }
                fclose(fp);
            }
            else {
                FILE* fp;
                fopen_s(&fp, Lab4DefaultPathDat, "rb");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                int* rec;
                rec = (int*)malloc(4);
                fread(rec, 4, 1, fp);
                Record = *rec;
                int j = 0;
                int a; int b; int c;
 //               a = (int*)malloc(4);
 //               b = (int*)malloc(4);
 //               c = (int*)malloc(4);
                Array1D = (int*)malloc(sizeof(int)*(*rec)*3);
                for (int i = 0; i < *rec; i++) {
                    fread(&a, 4, 1, fp);
                    fread(&b, 4, 1, fp);
                    fread(&c, 4, 1, fp);
                    Array1D[j] = a; Array1D[j + 1] = b; Array1D[j + 2] = c;
                    j = j + 3;
                }
                /*
                DATAITEM* x;
                x = (DATAITEM*)malloc(sizeof(DATAITEM) * (*rec));
                fread(x, sizeof(DATAITEM), *rec, fp);
                for (int i = 0; i < *rec; i++) {
                    Array1D[j] = x[i].item1; Array1D[j + 1] = x[i].item2; Array1D[j + 2] = x[i].item3;
                    j = j + 3;
                }
                */
                fclose(fp);
            }
            //printf("数据已由默认位置的数据文件加载入维数组\n");
        
    }
    else if (mode == 1) {//自动模式，读取用户之前创建文件时输入的路径的数据文件
        FILE* fp;

        
            if (type == 0) {
                fopen_s(&fp, UserFilePath, "r");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                else {
                    int rec = 1;
                    fscanf_s(fp, "%d", &rec);
                    Record = rec;
                    Array1D = (int*)malloc(rec * 12);
                    int j = 0;
                    for (int n = 0; n < rec; n++) {
                        fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
            else {
                fopen_s(&fp, UserFilePath, "rb");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                else {
                    int* rec;
                    rec = (int*)malloc(12);
                    fread(rec, 4, 1, fp);
                    Record = *rec;
                    int j = 0;
                    int* a; int* b; int* c;
                    a = (int*)malloc(12);
                    b = (int*)malloc(12);
                    c = (int*)malloc(12);
                    Array1D = (int*)malloc((*rec) * 12);
                    for (int i = 0; i < *rec; i++) {
                        fread(a, 4, 1, fp);
                        fread(b, 4, 1, fp);
                        fread(c, 4, 1, fp);
                        Array1D[j] = *a; Array1D[j + 1] = *b; Array1D[j + 2] = *c;
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
           // printf("数据已由用户指定位置的数据文件加载入二维数组\n");
        
    }
    else {//交互模式，读取用户指定位置的数据文件
        FILE* fp;
        char path[1000];
        printf("请输入待读取文件位置:\n");
        scanf_s("%s", path,1000);
        clearStdin();

     
            char* temp = strrchr(path, '.');
            if (!strcmp(".txt",temp)) {
                fopen_s(&fp, path, "r");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                else {
                    int rec = 1;
                    fscanf_s(fp, "%d", &rec);
                    Record = rec;
                    Array1D = (int*)malloc(rec * 12);
                    int j = 0;
                    for (int n = 0; n < rec; n++) {
                        fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                        j = j + 3;
                    }
                    fclose(fp);
                }
                //printf("数据已由用户指定位置的数据文件加载入二维数组\n");
            }
            else if (!strcmp(".dat", temp)) {
                fopen_s(&fp, path, "rb");
                if (fp == NULL) {
                    printf("数据文件打开失败\n");
                    return -1;
                }
                else {
                    int* rec;
                    rec = (int*)malloc(12);
                    fread(rec, 4, 1, fp);
                    Array1D = (int*)malloc(*rec * 12);
                    Record = *rec;
                    int j = 0;
                    int* a; int* b; int* c;
                    a = (int*)malloc(12);
                    b = (int*)malloc(12);
                    c = (int*)malloc(12);
                    for (int i = 0; i < *rec; i++) {
                        fread(a, 4, 1, fp);
                        fread(b, 4, 1, fp);
                        fread(c, 4, 1, fp);
                        Array1D[j] = *a; Array1D[j + 1] = *b; Array1D[j + 2] = *c;
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
        
    }

}
int loadTo2DArray(int*** Array2D) {
    *Array2D = (int**)malloc(sizeof(int*) * Record);
    int j = 0;
    for (int i = 0; i < Record; i++) {
        (*Array2D)[i] = (int*)malloc(sizeof(int) * 3);
        (*Array2D)[i][j%3] = Array1D[j];
        (*Array2D)[i][(j + 1) % 3] = Array1D[j + 1];
        (*Array2D)[i][(j + 2) % 3] = Array1D[j + 2];
        j = j + 3;
    }
    printf("数据已经载入二维数组\n");
    return 0;
}
int loadToFingertArray(DATAITEM*** FingerArray) {
    int j = 0;
    *FingerArray = (DATAITEM**)malloc(sizeof(DATAITEM*) * Record);
    for (int i = 0; i < Record; i++) {
        (*FingerArray)[i] = (DATAITEM*)malloc(sizeof(DATAITEM) * 3);
        (*FingerArray)[i]->item1 = Array1D[j];
        (*FingerArray)[i]->item2 = Array1D[j + 1];
        (*FingerArray)[i]->item3 = Array1D[j + 2];
        j = j + 3;
    }
    printf("数据已经载入指针数组\n");
    return 0;
};//将数据文件加载到指针数组
int loadToStructArray(DATAITEM** StructArray) {
    int j = 0;
    *StructArray = (DATAITEM*)malloc(sizeof(DATAITEM) * Record);
    for(int i=0;i<Record;i++){
        //(*StructArray)[i] = (DATAITEM)malloc(sizeof(DATAITEM) * 3);
        (*StructArray)[i].item1 = Array1D[j];
        (*StructArray)[i].item2 = Array1D[j + 1];
        (*StructArray)[i].item3 = Array1D[j + 2];
        j = j + 3;
    }
    printf("数据已经载入结构体数组\n");
    return 0;
}//将数据文件加载到结构体数组
int loadToLink(int n) {
    //int n = 10;
    Node *head, * tail;
    head = NULL;
    tail = NULL;
    initLink(&head, &tail, n);
    LinkHead = head;
    LinkTail = tail;
    printf("数据已经载入链表\n");
    return 0;
}//将数据文件加载到链表中
void initLink(Node** h, Node** t, int n) {
    Node* new_node;
    for (int i = 0; i < n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        LoadintoNode(new_node,i);
        if (*h == NULL) {
            *h = new_node;
            *t = *h;
            new_node->nextnode = NULL;
        }
        else {
            (*t)->nextnode = new_node;
            (*t) = (*t)->nextnode;
            (*t)->nextnode = NULL;
        }
    }
}
void LoadintoNode(Node* node,int n) {
    n = n * 3;
    node->data.item1 = Array1D[n];
    node->data.item2 = Array1D[n+1];
    node->data.item3 = Array1D[n+2];
}