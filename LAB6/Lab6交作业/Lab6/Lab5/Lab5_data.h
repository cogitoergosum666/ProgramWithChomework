#pragma once
//
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
struct DATAITEM {
    int item1;
    int item2;
    int item3;
};

typedef struct LINKNODE {
    DATAITEM data;
    LINKNODE* nextnode;
}Node;

extern int* Array1D;
//一维数组

extern int** Array2D;
//二维数组

extern DATAITEM* StructArray;
//结构体数组首指针

extern DATAITEM** FingerArray;
//指针数组首指针

extern LINKNODE* LinkHead;
//链表头指针
extern LINKNODE* LinkTail;

extern char UserFilePath[1000];
extern char LabDefaultPath[1000];
extern int Record;
extern char Lab4DefaultPathDat[1000];
extern int Lab5Mode;