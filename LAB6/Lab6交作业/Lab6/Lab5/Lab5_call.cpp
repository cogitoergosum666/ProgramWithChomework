#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Lab5_support.h"
#include"Lab5_data.h"
/***********************************************
文件名称:
    Lab5_call.cpp
功能描述:
    调用lab4程序生成指定文件
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
/***********************************************
函数名称:
    调用lab4函数
功能描述:
    引导用户调用lab4
函数参数:
    type=0为文本文件，1为二进制文件
返回值:
    无返回值
模块历史:
    杜海玮于2021年3月23日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int AssCommand(int type,int mode) {//type=0为文本文件，1为二进制文件,mode=0为自动模式，只输入r，mode=1为交互模式，需要完整输入三要素
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
                printf("配置文件打开失败\n");
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
        printf("请输入指定数据条目数，随机数据条目请输入r\n");
        scanf_s("%s", number,1000); clearStdin();
        printf("请输入指定文件名与存储路径，请勿输入后缀名！\n");
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
        printf("文件已创建\n");
    }
    return 0;
}//组装命令语句
