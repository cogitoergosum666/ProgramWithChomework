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
    int CurOrder = 0;
    ReListHeadNode.list_num = 0;
    for (int n = CurOrder; n < record; n++) {
        if (input[n].call_time == TimeStamp) {
            ResponseListNode* newnode;
            newnode = (ResponseListNode*)malloc(sizeof(ResponseListNode));
            newnode->user_call = &input[n];
            if (ReListHeadNode.head == NULL) {//ͷָ��Ϊ��
                ReListHeadNode.head == newnode;
            }
            else {//�Ѿ���������ڵ�
                ReListHeadNode.tail->next_node = newnode;
                ReListHeadNode.tail = newnode;//β��ָ���ƶ�������ӵĽڵ���
            }
            newnode->next_node == NULL;
            CurOrder++;
            ReListHeadNode.list_num++;//����ǰʱ�����ָ��ת�������Ӧָ���б�
        }
    }
}

void CheckResList() {
    if (ReListHeadNode.list_num != 0) {
        ServeListNode* newnode;
        newnode = (ServeListNode*)malloc(sizeof(ServeListNode));
        newnode->user_call = ReListHeadNode.head->user_call;
        ReListHeadNode.head = ReListHeadNode.head->next_node;//��ָ���Ѿ�������Ӧָ���б�������Ӧָ��ָ��ͷ����ƶ�
        if (newnode->user_call->user_floor == State.current_floor) {
            newnode->serve_state = 'E';//������
        }
        else {
            newnode->serve_state = 'P';//����ǰ
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