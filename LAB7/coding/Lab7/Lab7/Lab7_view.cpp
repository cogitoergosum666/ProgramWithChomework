/***********************************************
文件名称:
    Lab7_view.cpp
功能描述:
    展示信息函数用的程序
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"

#include<stdio.h>

void ViewStatus() {

    printf("电梯当前服务状态为%c，电梯当前位于%d楼，当前服务指令中有%d人\n", State.run_state, State.current_floor, SeListHeadNode.list_num);
    
}