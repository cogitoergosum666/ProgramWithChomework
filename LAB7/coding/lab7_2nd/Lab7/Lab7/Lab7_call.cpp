/***********************************************
文件名称:
    Lab7_call.cpp
功能描述:
    调用lab4函数生成数据表并排序的程序
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"
#include<stdio.h>
#include<malloc.h>
#include"Lab7_support.h"

int LoadData(UserCall** input){//读取原始数据文件进入usercall结构体，
    FILE* fp;
    fopen_s(&fp, "DataSet.txt", "r");
    if (fp == NULL) {
        printf("数据文件打开失败\n");
        return -1;
    }
    int rec = 1;
    fscanf_s(fp, "%d", &rec);
    record = rec;
    *input = (USERCALL*)malloc(sizeof(UserCall)*rec);
    for (int n = 0; n < rec; n++) {
        fscanf_s(fp, "%d,%d,%d", &(*input)[n].user_floor, &(*input)[n].user_target, &(*input)[n].call_time);
        if ((*input)[n].user_floor > (*input)[n].user_target) {
            (*input)[n].call_type == 'D';
        }
        else {
            (*input)[n].call_type == 'U';
        }
    }
    fclose(fp);
    SortStructArray(input, rec);
}