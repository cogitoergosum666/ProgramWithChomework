#pragma once
//
/***********************************************
�ļ�����:
    Lab5.cpp
��������:
    ���ʵ��5��������Ľṹ������������������ȫ�ֱ�������
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��5��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
struct DATAITEM {
    int item1;
    int item2;
    int item3;
};

typedef struct LINKNODE {
    DATAITEM data;
    LINKNODE* nextnode;
}Node;

extern int* Array1D;
//һά����

extern int** Array2D;
//��ά����

extern DATAITEM* StructArray;
//�ṹ��������ָ��

extern DATAITEM** FingerArray;
//ָ��������ָ��

extern LINKNODE* LinkHead;
//����ͷָ��
extern LINKNODE* LinkTail;

extern char UserFilePath[1000];
extern char LabDefaultPath[1000];
extern int Record;
extern char Lab4DefaultPathDat[1000];
extern int Lab5Mode;