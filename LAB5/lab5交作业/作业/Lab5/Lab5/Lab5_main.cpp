
/***********************************************
文件名称:
    Lab5_main.cpp
功能描述:
    程序主控文件，存放run函数及其他需要配套的子函数
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab5_main.h"
#include"Lab5_view.h"
#include"Lab5_call.h"
#include"Lab5_loadfile.h"
#include"Lab5_data.h"
#include"Lab5_end.h"
#include"Lab5_conf.h"
#include<stdio.h>
#include<io.h>
#include<direct.h>
#include<string.h>
#include<stdlib.h>

int* Array1D;
//一维数组，定义方式不唯一

int** Array2D;
//二维数组

DATAITEM* StructArray;
//结构体数组首指针

DATAITEM** FingerArray;
//指针数组首指针

LINKNODE* LinkHead;
//链表头指针
LINKNODE* LinkTail;
//链表尾指针

char UserFilePath[1000];
char LabDefaultPath[1000];
char Lab4DefaultPathDat[1000];
int Record;
int Lab5Mode;
int run() {
    if (sysCheck() == 0) {
        printf("系统自检失败，正在退出...\n");
        return 0;
    }//返回0检查错误，返回1检查通过继续
    
    else {
        printf("系统自检通过，正在初始化...\n");

        for (int i = 0; i < 100; i++) {
            int mode = 0;
            mode = sysInit();//系统初始化函数
            if (mode == -1) {
                printf("配置文件打开失败，已启动自动模式\n");
                mode = 0;
            }
            if (mode == 0) {
                printf("当前正在运行的是自动模式\n");
            }
            if (mode == 1) {
                printf("当前正在运行的是交互模式\n");
            }
            int res = showMainMenu();
            switch (res) {
            case 1:AssCommand(0,mode);
                break;//调用实验4程序生成记录文件（文本方式）
            case 2:AssCommand(1, mode);
                break;//调用实验4程序生成记录文件（二进制方式）
            case 3:loadTo1DArray(2,0);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;//读取指定数据记录文件（二维数组存储方式）
            case 4:loadTo1DArray(2,0);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//读取指定数据记录文件（结构体数组存储方式）
            case 5:loadTo1DArray(2,0);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//读取指定数据记录文件（指针数组存储方式）
            case 6:loadTo1DArray(2,0);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//读取指定数据记录文件（链表存储方式）
            case 7:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;
                //调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）
            case 8:AssCommand(0, mode);
                loadTo1DArray(mode, 0);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）
            case 9:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组存储方式）
            case 10:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）
            case 11:AssCommand(1, mode);
                loadTo1DArray(mode,1);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）
            case 12:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）
            case 13:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）
            case 14:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//调用实验4生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）
            case 15:
                EditConf();
                break;//重新设置配置参数
            case 0://退出
                return 0;
            default :
                printf("请输入正确数字序号选项\n");
                continue;//提示错误信息，继续循环
            }
            system("pause");
        }
    }
    return 1;
}
/***********************************************
函数名称:
    系统初始化函数
功能描述:
    加载程序配置文件，确定以自动模式还是交互模式运行
函数参数:
    无
返回值:
    0为自动模式，1为手动模式，-1为打开失败，默认为自动模式
模块历史:
    杜海玮于2021年5月9日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int sysInit() {
    FILE* fp;
    fopen_s(&fp, "conf.ini", "r");
    if (fp == NULL) {
        printf("Lab4配置文件打开失败\n");
        return -1;
    }
    else {
        char path1[1000];
        char file1[1000];
        fscanf_s(fp, "%s", path1,1000);
        fscanf_s(fp, "%s", file1,1000);
        strcpy_s(LabDefaultPath, 1000, path1);
        strcat_s(LabDefaultPath, 1000, file1);
        strcat_s(LabDefaultPath, 2000, ".txt");
        printf("已读取Lab4默认存储文件位置\n");
        fclose(fp);
    }
    
    int mode1=0;
    fopen_s(&fp, "Lab5_conf.ini", "r");
    if (fp == NULL) {
        printf("Lab5配置文件打开失败\n");
        return -1;
    }
    else {
        fscanf_s(fp, "%d", &mode1,1000);
        Lab5Mode = mode1;
        fclose(fp);
        return mode1;
        
    }
}
/***********************************************
函数名称:
    系统自检函数
功能描述:
    检查系统必备的配置文件与lab4执行文件是否就位
函数参数:
    无
返回值:
    0为要素未就绪，1为准备完毕
模块历史:
    杜海玮于2021年5月9日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
int sysCheck() {
    if(_access("lab3.exe",0))return 0;
    if (_access("Lab5_conf.ini", 0))return 0;
    if (_access("conf.ini", 0))return 0;
    _chdir("Lab5");
    return 1;
}