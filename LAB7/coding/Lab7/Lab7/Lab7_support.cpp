/***********************************************
�ļ�����:
    Lab7_support.cpp
��������:
    �����˳�������Ҫ�ĸ�����������sleep
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��6��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
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