/***********************************************
�ļ�����:
    Lab7_run.cpp
��������:
    ���������ļ������run������������Ҫ���׵��Ӻ������Լ���Ҫ��ȫ�ֱ�������
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��6��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
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

int TimeStamp;//��ǰʱ�������
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

void doyouwork() {//���ݷ��溯��
    CheckOrder(CallList);//��ǰ�Ƿ�����ָ�����
    if (CheckStatus()) {//�����Ƿ����ṩ����
        DoWork();
    }
    else {//���û���ṩ������
        CheckResList();//������Ӧָ�����
        CheckFollow();
    }
    ViewStatus();//������ݵ�ǰ״̬
    GiveNextStatus();//���ݵ��ݵ�ǰ״̬ȷ����һʱ�̳�ʼʱ����״̬(�޸�����)
}
