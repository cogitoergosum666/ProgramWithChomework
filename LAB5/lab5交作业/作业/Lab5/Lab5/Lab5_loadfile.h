#pragma once
#include"Lab5_data.h"
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
int loadTo1DArray(int mode, int type);//�������ļ����ص���ά����
int loadTo2DArray(int*** Array2D);
int loadToFingertArray(DATAITEM*** FingerArray);//�������ļ����ص�ָ������
int loadToStructArray(DATAITEM** StructArray);//�������ļ����ص��ṹ������
int loadToLink(int n);//�������ļ����ص�����
void LoadintoNode(Node* node, int n);
void initLink(Node** h, Node** t, int n);


