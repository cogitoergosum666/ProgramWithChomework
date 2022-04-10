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
    int CurOrder = 0;
    ReListHeadNode.list_num = 0;
    for (int n = CurOrder; n < record; n++) {
        if (input[n].call_time == TimeStamp) {
            ResponseListNode* newnode;
            newnode = (ResponseListNode*)malloc(sizeof(ResponseListNode));
            newnode->user_call = &input[n];
            if (ReListHeadNode.head == NULL) {//头指针为空
                ReListHeadNode.head == newnode;
            }
            else {//已经有了链表节点
                ReListHeadNode.tail->next_node = newnode;
                ReListHeadNode.tail = newnode;//尾部指针移动到新添加的节点上
            }
            newnode->next_node == NULL;
            CurOrder++;
            ReListHeadNode.list_num++;//将当前时间戳的指令转移入待响应指令列表
        }
    }
}

void CheckResList() {
    if (ReListHeadNode.list_num != 0) {
        ServeListNode* newnode;
        newnode = (ServeListNode*)malloc(sizeof(ServeListNode));
        newnode->user_call = ReListHeadNode.head->user_call;
        ReListHeadNode.head = ReListHeadNode.head->next_node;//该指令已经移入响应指令列表，将待响应指令指针头向后移动
        if (newnode->user_call->user_floor == State.current_floor) {
            newnode->serve_state = 'E';//服务中
        }
        else {
            newnode->serve_state = 'P';//服务前
        }
        if (SeListHeadNode.head == NULL) {
            SeListHeadNode.head = newnode;
        }
        else {
            SeListHeadNode.tail->next_node = newnode;
            SeListHeadNode.tail = newnode;
        }
        SeListHeadNode.list_num++;
    }
}