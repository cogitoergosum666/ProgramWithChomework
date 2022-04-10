#pragma once
#include<stdio.h>
#include<malloc.h>
#include"Lab5_conf.h"
#include"Lab5_support.h"
#include"Lab5_data.h"
/***********************************************
�ļ�����:
    Lab5_conf.cpp
��������:
    �޸�lab4��conf�ļ���Ҫ�ĺ���
ģ����ʷ:
    �ź�����2021��5��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int mode;
void EditConf() {
    conf *a;
    a = (conf*)malloc(sizeof(conf) * 1);
    LoadConf(a);
    ConfMain(a);
    free(a);
}
int LoadConf(conf *input){
    FILE* fp;
    fopen_s(&fp, "conf.ini", "r");
    if (fp == NULL) {
        printf("�����ļ���ʧ��\n");
        return 0;
    }
    fscanf_s(fp, "%s", input->filesavepath, 1000);
    fscanf_s(fp, "%s", input->filename, 1000);
    fscanf_s(fp, "%d", &input->maxvalue1, 1000);
    fscanf_s(fp, "%d", &input->minvalue1, 1000);
    fscanf_s(fp, "%d", &input->maxvalue2, 1000);
    fscanf_s(fp, "%d", &input->minvalue2, 1000);
    fscanf_s(fp, "%d", &input->recordcount1, 1000);
    fscanf_s(fp, "%d", &input->recordcount2, 1000);

    fclose(fp);
    return 1;
}
void ShowConfMenu(conf* input) {
    printf("\t***Lab4�����ļ��޸Ĳ˵�***\t\n");
    printf("�������޸�ѡ��ǰ�����ֽ����޸�,enterȷ��\n");
    printf("1.�޸�Ĭ�ϴ����ļ�·����������%s\n",input->filesavepath);
    printf("2.�޸�Ĭ�ϴ����ļ�����������%s\n",input->filename);
    printf("3.�޸�ÿ���һ���ڶ������ֵ����ޣ�������%d\n",input->maxvalue1);
    printf("4.�޸�ÿ���һ���ڶ������ֵ����ޣ�������%d\n",input->minvalue1);
    printf("5.�޸�ÿ����������ֵ����ޣ�������%d\n",input->maxvalue2);
    printf("6.�޸�ÿ����������ֵ����ޣ�������%d\n",input->minvalue2);
    printf("7.�޸���������������������ޣ�������%d\n",input->recordcount1);
    printf("8.�޸���������������������ޣ�������%d\n",input->recordcount2);
    printf("9.�޸�Lab5����ģʽ��0�����Զ�ģʽ��1�����ֶ�ģʽ������%d\n",Lab5Mode);
    printf("10.���沢�����ϼ��˵�\n");
}
int ConfMain(conf* input){
    for (int i = 0;; i++) {
        int res;
        ShowConfMenu(input);
        scanf_s("%d", &res);
        clearStdin();
        switch (res) {
        case 1:
            printf("������µ��ļ�·��:\n");
            scanf_s("%s", input->filesavepath);
            clearStdin();
            break;
        case 2:
            printf("������µ��ļ���:\n");
            scanf_s("%s", input->filename);
            clearStdin();
            break;
        case 3:
            printf("������µ�ÿ���һ���ڶ������ֵ�����:\n");
            scanf_s("%d", &input->maxvalue1);
            clearStdin();
            break;
        case 4:
            printf("������µ�ÿ���һ���ڶ������ֵ�����:\n");
            scanf_s("%d", &input->minvalue1);
            clearStdin();
            break;
        case 5:
            printf("������µ�ÿ����������ֵ�����:\n");
            scanf_s("%d", &input->maxvalue2);
            clearStdin();
            break;
        case 6:
            printf("������µ�ÿ����������ֵ�����:\n");
            scanf_s("%d", &input->minvalue2);
            clearStdin();
            break;
        case 7:
            printf("������µ���������������\n");
            scanf_s("%d", &input->recordcount1);
            clearStdin();
            break;
        case 8:
            printf("������µ���������������\n");
            scanf_s("%d", &input->recordcount2);
            clearStdin();
            break;
        case 9:
            printf("������µ�Lab5����ģʽ���ͣ�0�����Զ�ģʽ��1�����ֶ�ģʽ\n");
            scanf_s("%d", &Lab5Mode);
            clearStdin();
            break;
        case 10:
            UpdateConf(input);
            return 0;
            break;
        default:printf("��������ȷ����\n");
            break;

        }
    }
}
int UpdateConf(conf* input) {
    FILE* fp;
    fopen_s(&fp, "conf.ini", "w");
    if (fp == NULL) {
        printf("lab4�����ļ���ʧ��\n");
        return 0;
    }
    fprintf(fp,"%s\n", input->filesavepath);
    fprintf(fp,"%s\n", input->filename);
    fprintf(fp, "%d\n", input->maxvalue1);
    fprintf(fp, "%d\n", input->minvalue1);
    fprintf(fp, "%d\n", input->maxvalue2);
    fprintf(fp, "%d\n", input->minvalue2);
    fprintf(fp, "%d\n", input->recordcount1);
    fprintf(fp, "%d\n", input->recordcount2);
    fclose(fp);
    FILE* fp1;
    fopen_s(&fp1, "Lab5_conf.ini", "w");
   if (fp1 == NULL) {
        printf("lab5�����ļ���ʧ��\n");
        return 0;
   }
    fprintf(fp1, "%d\n", Lab5Mode);

    fclose(fp1);
    printf("�����ļ��Ѹ���\n");
    return 1;
}