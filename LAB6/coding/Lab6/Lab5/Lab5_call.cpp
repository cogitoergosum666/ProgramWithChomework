#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Lab5_support.h"
#include"Lab5_data.h"
/***********************************************
�ļ�����:
    Lab5_call.cpp
��������:
    ����lab4��������ָ���ļ�
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��5��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
/***********************************************
��������:
    ����lab4����
��������:
    �����û�����lab4
��������:
    type=0Ϊ�ı��ļ���1Ϊ�������ļ�
����ֵ:
    �޷���ֵ
ģ����ʷ:
    �ź�����2021��3��23�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int AssCommand(int type,int mode) {//type=0Ϊ�ı��ļ���1Ϊ�������ļ�,mode=0Ϊ�Զ�ģʽ��ֻ����r��mode=1Ϊ����ģʽ����Ҫ����������Ҫ��
    if (mode == 0) {
        if (type == 0) {
            system("lab3.exe r");
        }
        else {
            char path[1000];
            char name[1000];
            FILE* fp;
            fopen_s(&fp, "conf.ini", "r");
            if (fp == NULL) {
                printf("�����ļ���ʧ��\n");
                return 0;
            }
            fscanf_s(fp, "%s", path, 1000);
            fscanf_s(fp, "%s", name, 1000);

            fclose(fp);
            strcat_s(path, 1000, name);
            strcpy_s(Lab4DefaultPathDat, 1000, path);
            strcat_s(Lab4DefaultPathDat, 1000, ".dat");
            char command[2200] = "lab3.exe r ";
            strcat_s(command, 1000, path);
            char dat[10] = " d";
            strcat_s(command, 1000, dat);
            system(command);
        }
    }
    else {
        char dat[10] = " d";
        char txt[10] = " t";
        char command[2200] = "lab3.exe";
        char number[1000];
        char file[1000];
        char space[10] = " ";
        printf("������ָ��������Ŀ�������������Ŀ������r\n");
        scanf_s("%s", number,1000); clearStdin();
        printf("������ָ���ļ�����洢·�������������׺����\n");
        scanf_s("%s", file,1000); clearStdin();
        strcpy_s(UserFilePath, 1000, file);
        strcat_s(command, 1000, space);
        strcat_s(command, 1000, number);
        strcat_s(command, 1000, space);
        strcat_s(command, 1000, file);
        strcat_s(command, 1000, space);
        if (type == 0) {
            strcat_s(command, 1000, txt);
            strcat_s(UserFilePath, 1000,".txt");
        }
        else {
            strcat_s(command, 1000, dat);
            strcat_s(UserFilePath, 1000, ".dat");
        }
        system(command);
        printf("�ļ��Ѵ���\n");
    }
    return 0;
}//��װ�������
