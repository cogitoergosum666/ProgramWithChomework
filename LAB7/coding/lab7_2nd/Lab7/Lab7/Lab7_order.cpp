/***********************************************
�ļ�����:
    Lab7_order.cpp
��������:
    �����жϵ����Ƿ����ͬʱ��Ӧ�����û�ָ��
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��6��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
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
            ReListHeadNode.list_num++;//����ǰʱ�����ָ��ת�������Ӧָ���б�
        }
    }
}

void CheckResList() {
    if (ReListHeadNode.list_num != 0) {
        SERVELISTNODE* newnode;
        newnode = (SERVELISTNODE*)malloc(sizeof(SERVELISTNODE));
        newnode->user_call = ReListHeadNode.head->user_call;
        ReListHeadNode.head = ReListHeadNode.head->next_node;//��ָ���Ѿ�������Ӧָ���б�������Ӧָ��ָ��ͷ����ƶ�
        if (newnode->user_call->user_floor == State.current_floor) {
            newnode->serve_state = 'E';//������
        }
        else {
            newnode->serve_state = 'P';//����ǰ
        }
        //if (SeListHeadNode.head == NULL) {
            SeListHeadNode.head == newnode;
        //}
    }
}