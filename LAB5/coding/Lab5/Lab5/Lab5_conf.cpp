#pragma once
#include<stdio.h>
#include<malloc.h>
#include"Lab5_conf.h"
#include"Lab5_support.h"
#include"Lab5_data.h"
/***********************************************
文件名称:
    Lab5_conf.cpp
功能描述:
    修改lab4的conf文件需要的函数
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
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
        printf("配置文件打开失败\n");
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
    printf("\t***Lab4配置文件修改菜单***\t\n");
    printf("请输入修改选项前的数字进行修改,enter确认\n");
    printf("1.修改默认储存文件路径，现在是%s\n",input->filesavepath);
    printf("2.修改默认储存文件名，现在是%s\n",input->filename);
    printf("3.修改每组第一个第二个数字的上限，现在是%d\n",input->maxvalue1);
    printf("4.修改每组第一个第二个数字的下限，现在是%d\n",input->minvalue1);
    printf("5.修改每组第三个数字的上限，现在是%d\n",input->maxvalue2);
    printf("6.修改每组第三个数字的下限，现在是%d\n",input->minvalue2);
    printf("7.修改随机生成数据条数的上限，现在是%d\n",input->recordcount1);
    printf("8.修改随机生成数据条数的下限，现在是%d\n",input->recordcount2);
    printf("9.修改Lab5工作模式，0代表自动模式，1代表手动模式现在是%d\n",Lab5Mode);
    printf("10.保存并返回上级菜单\n");
}
int ConfMain(conf* input){
    for (int i = 0;; i++) {
        int res;
        ShowConfMenu(input);
        scanf_s("%d", &res);
        clearStdin();
        switch (res) {
        case 1:
            printf("请键入新的文件路径:\n");
            scanf_s("%s", input->filesavepath);
            clearStdin();
            break;
        case 2:
            printf("请键入新的文件名:\n");
            scanf_s("%s", input->filename);
            clearStdin();
            break;
        case 3:
            printf("请键入新的每组第一个第二个数字的上限:\n");
            scanf_s("%d", &input->maxvalue1);
            clearStdin();
            break;
        case 4:
            printf("请键入新的每组第一个第二个数字的下限:\n");
            scanf_s("%d", &input->minvalue1);
            clearStdin();
            break;
        case 5:
            printf("请键入新的每组第三个数字的上限:\n");
            scanf_s("%d", &input->maxvalue2);
            clearStdin();
            break;
        case 6:
            printf("请键入新的每组第三个数字的下限:\n");
            scanf_s("%d", &input->minvalue2);
            clearStdin();
            break;
        case 7:
            printf("请键入新的数据条数的上限\n");
            scanf_s("%d", &input->recordcount1);
            clearStdin();
            break;
        case 8:
            printf("请键入新的数据条数的下限\n");
            scanf_s("%d", &input->recordcount2);
            clearStdin();
            break;
        case 9:
            printf("请键入新的Lab5工作模式类型，0代表自动模式，1代表手动模式\n");
            scanf_s("%d", &Lab5Mode);
            clearStdin();
            break;
        case 10:
            UpdateConf(input);
            return 0;
            break;
        default:printf("请输入正确数字\n");
            break;

        }
    }
}
int UpdateConf(conf* input) {
    FILE* fp;
    fopen_s(&fp, "conf.ini", "w");
    if (fp == NULL) {
        printf("lab4配置文件打开失败\n");
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
        printf("lab5配置文件打开失败\n");
        return 0;
   }
    fprintf(fp1, "%d\n", Lab5Mode);

    fclose(fp1);
    printf("配置文件已更新\n");
    return 1;
}