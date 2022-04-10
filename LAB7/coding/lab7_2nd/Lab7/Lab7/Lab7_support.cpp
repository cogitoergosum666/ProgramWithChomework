/***********************************************
文件名称:
    Lab7_support.cpp
功能描述:
    包含了程序所需要的辅助函数例如sleep
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"
#include<stdlib.h>
int cmpStruct(const void* a, const void* b) {
    int x = (*(UserCall*)a).call_time;
    int y = (*(UserCall*)b).call_time;
    return x - y;
}
void SortStructArray(UserCall** input,int Record) {
    qsort(*input, Record, sizeof(*input[0]), cmpStruct);
}