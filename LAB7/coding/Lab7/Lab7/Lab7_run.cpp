/***********************************************
文件名称:
    Lab7_run.cpp
功能描述:
    程序主控文件，存放run函数及其他需要配套的子函数，以及需要的全局变量声明
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"
#include"Lab7_call.h"
#include"Lab7_status.h"
#include"Lab7_order.h"
#include<stdio.h>
#include<Windows.h>

UserCall* CallList;
LiftSate State;
ResponseListHeadNode ReListHeadNode;
ServeListHeadNode SeListHeadNode;

int TimeStamp;//当前时间戳变量
int record;
int floor;
int run() {
    State.current_floor = 0;
    LoadData(&CallList);
    TimeStamp = 0;
    while () {
        doyouwork();
        Sleep(1000);
        TimeStamp++;
    }
    return 0;
}

void doyouwork() {//电梯仿真函数
    CheckOrder(CallList);//当前是否有新指令到来？
    if (CheckStatus()) {//电梯是否在提供服务？
        DoWork();
    }
    else {//如果没有提供服务则
        CheckResList();//检查待响应指令队列
        CheckFollow();
    }
    ViewStatus();//输出电梯当前状态
    GiveNextStatus();//根据电梯当前状态确定下一时刻初始时电梯状态(修改数据)
}
