/***********************************************
�ļ�����:
    Lab7_call.cpp
��������:
    ����lab4�����������ݱ�����ĳ���
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��6��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"
#include<stdio.h>
#include<malloc.h>
#include"Lab7_support.h"

int LoadData(UserCall** input){//��ȡԭʼ�����ļ�����usercall�ṹ�壬
    FILE* fp;
    fopen_s(&fp, "DataSet.txt", "r");
    if (fp == NULL) {
        printf("�����ļ���ʧ��\n");
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