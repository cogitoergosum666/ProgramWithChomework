#pragma once
#include"Lab5_data.h"
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
int loadTo1DArray(int mode, int type);//将数据文件加载到二维数组
int loadTo2DArray(int*** Array2D);
int loadToFingertArray(DATAITEM*** FingerArray);//将数据文件加载到指针数组
int loadToStructArray(DATAITEM** StructArray);//将数据文件加载到结构体数组
int loadToLink(int n);//将数据文件加载到链表
void LoadintoNode(Node* node, int n);
void initLink(Node** h, Node** t, int n);


