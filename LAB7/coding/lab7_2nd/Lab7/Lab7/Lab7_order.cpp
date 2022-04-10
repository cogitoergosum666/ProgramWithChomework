/***********************************************
文件名称:
    Lab7_order.cpp
功能描述:
    程序判断电梯是否可以同时响应其它用户指令
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"
#include<malloc.h>

int CheckOrder(UserCall* input) {
    int current = 0;
    RESPONSELISTNODE* temp;
    ReListHeadNode.list_num = 0;
    for (int n = 0+current; n < record; n++) {
        if (input[n].call_time == TimeStamp) {
            RESPONSELISTNODE* newnode;
            newnode = (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE));
            newnode->user_call = &input[n];
            if (ReListHeadNode.head == NULL) {
                ReListHeadNode.head == newnode;
                temp = newnode;
            }
            else {
                temp->next_node = newnode;
            }
            newnode->next_node == NULL;
            ReListHeadNode.tail = newnode;
            temp = newnode;
            current++;
            ReListHeadNode.list_num++;//将当前时间戳的指令转移入待响应指令列表
        }
    }
}

void CheckResList() {
    if (ReListHeadNode.list_num != 0) {
        SERVELISTNODE* newnode;
        newnode = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
        newnode->user_call = ReListHeadNode.head->user_call;
        ReListHeadNode.head = ReListHeadNode.head->next_node;//该指令已经移入响应指令列表，将待响应指令指针头向后移动
        if (newnode->user_call->user_floor == State.current_floor) {
            newnode->serve_state = 'E';//服务中
        }
        else {
            newnode->serve_state = 'P';//服务前
        }
        //if (SeListHeadNode.head == NULL) {
            SeListHeadNode.head == newnode;
        //}
    }
}