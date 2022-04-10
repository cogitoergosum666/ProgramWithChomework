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

#pragma once
#include"Lab5_data.h"
#include"Lab5_support.h"
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"Lab5_loadfile.h"

/***********************************************
��������:
    �������ļ����ؽ���ȫ�ֶ�ά���麯��
��������:
    ���û�ָ��λ�û���ϼ�������λ�õ������ļ����ؽ���ά����
��������:
    mode����0Ϊ�Զ�ģʽ����ȡʵ��4 conf.ini��Ĭ�ϴ���λ�õ������ļ���
    1Ϊ�Զ�ģʽ�����ܴ����UserFilePathȫ�ֱ�������ȡ��·���µ������ļ�
    2Ϊ�ֶ���ȡģʽ�����û�������Ҫ��ȡ���ļ�·������ȡ��·���µ������ļ�
    type 0Ϊ�ı���ȡģʽ��type 1Ϊ�����ƶ�ȡģʽ
����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��5��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int loadTo1DArray(int mode,int type) {//�������ļ����ص���ά����
    if (mode == 0) {//�Զ�ģʽ����ȡĬ�ϴ洢λ�õ������ļ�
        
        
            if (type == 0) {
                FILE* fp;
                fopen_s(&fp, LabDefaultPath, "r");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                int rec = 1;
                fscanf_s(fp, "%d", &rec);
                Record = rec;
                Array1D = (int*)malloc(rec * 12);
                int j = 0;
                for (int n = 0; n < rec; n++) {
                    fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                    j = j + 3;
                }
                fclose(fp);
            }
            else {
                FILE* fp;
                fopen_s(&fp, Lab4DefaultPathDat, "rb");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                int* rec;
                rec = (int*)malloc(4);
                fread(rec, 4, 1, fp);
                Record = *rec;
                int j = 0;
                int a; int b; int c;
 //               a = (int*)malloc(4);
 //               b = (int*)malloc(4);
 //               c = (int*)malloc(4);
                Array1D = (int*)malloc(sizeof(int)*(*rec)*3);
                for (int i = 0; i < *rec; i++) {
                    fread(&a, 4, 1, fp);
                    fread(&b, 4, 1, fp);
                    fread(&c, 4, 1, fp);
                    Array1D[j] = a; Array1D[j + 1] = b; Array1D[j + 2] = c;
                    j = j + 3;
                }
                /*
                DATAITEM* x;
                x = (DATAITEM*)malloc(sizeof(DATAITEM) * (*rec));
                fread(x, sizeof(DATAITEM), *rec, fp);
                for (int i = 0; i < *rec; i++) {
                    Array1D[j] = x[i].item1; Array1D[j + 1] = x[i].item2; Array1D[j + 2] = x[i].item3;
                    j = j + 3;
                }
                */
                fclose(fp);
            }
            //printf("��������Ĭ��λ�õ������ļ�������ά����\n");
        
    }
    else if (mode == 1) {//�Զ�ģʽ����ȡ�û�֮ǰ�����ļ�ʱ�����·���������ļ�
        FILE* fp;

        
            if (type == 0) {
                fopen_s(&fp, UserFilePath, "r");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                else {
                    int rec = 1;
                    fscanf_s(fp, "%d", &rec);
                    Record = rec;
                    Array1D = (int*)malloc(rec * 12);
                    int j = 0;
                    for (int n = 0; n < rec; n++) {
                        fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
            else {
                fopen_s(&fp, UserFilePath, "rb");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                else {
                    int* rec;
                    rec = (int*)malloc(12);
                    fread(rec, 4, 1, fp);
                    Record = *rec;
                    int j = 0;
                    int* a; int* b; int* c;
                    a = (int*)malloc(12);
                    b = (int*)malloc(12);
                    c = (int*)malloc(12);
                    Array1D = (int*)malloc((*rec) * 12);
                    for (int i = 0; i < *rec; i++) {
                        fread(a, 4, 1, fp);
                        fread(b, 4, 1, fp);
                        fread(c, 4, 1, fp);
                        Array1D[j] = *a; Array1D[j + 1] = *b; Array1D[j + 2] = *c;
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
           // printf("���������û�ָ��λ�õ������ļ��������ά����\n");
        
    }
    else {//����ģʽ����ȡ�û�ָ��λ�õ������ļ�
        FILE* fp;
        char path[1000];
        printf("���������ȡ�ļ�λ��:\n");
        scanf_s("%s", path,1000);
        clearStdin();

     
            char* temp = strrchr(path, '.');
            if (!strcmp(".txt",temp)) {
                fopen_s(&fp, path, "r");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                else {
                    int rec = 1;
                    fscanf_s(fp, "%d", &rec);
                    Record = rec;
                    Array1D = (int*)malloc(rec * 12);
                    int j = 0;
                    for (int n = 0; n < rec; n++) {
                        fscanf_s(fp, "%d,%d,%d", &Array1D[j], &Array1D[j + 1], &Array1D[j + 2]);
                        j = j + 3;
                    }
                    fclose(fp);
                }
                //printf("���������û�ָ��λ�õ������ļ��������ά����\n");
            }
            else if (!strcmp(".dat", temp)) {
                fopen_s(&fp, path, "rb");
                if (fp == NULL) {
                    printf("�����ļ���ʧ��\n");
                    return -1;
                }
                else {
                    int* rec;
                    rec = (int*)malloc(12);
                    fread(rec, 4, 1, fp);
                    Array1D = (int*)malloc(*rec * 12);
                    Record = *rec;
                    int j = 0;
                    int* a; int* b; int* c;
                    a = (int*)malloc(12);
                    b = (int*)malloc(12);
                    c = (int*)malloc(12);
                    for (int i = 0; i < *rec; i++) {
                        fread(a, 4, 1, fp);
                        fread(b, 4, 1, fp);
                        fread(c, 4, 1, fp);
                        Array1D[j] = *a; Array1D[j + 1] = *b; Array1D[j + 2] = *c;
                        j = j + 3;
                    }
                    fclose(fp);
                }
            }
        
    }

}
int loadTo2DArray(int*** Array2D) {
    *Array2D = (int**)malloc(sizeof(int*) * Record);
    int j = 0;
    for (int i = 0; i < Record; i++) {
        (*Array2D)[i] = (int*)malloc(sizeof(int) * 3);
        (*Array2D)[i][j%3] = Array1D[j];
        (*Array2D)[i][(j + 1) % 3] = Array1D[j + 1];
        (*Array2D)[i][(j + 2) % 3] = Array1D[j + 2];
        j = j + 3;
    }
    printf("�����Ѿ������ά����\n");
    return 0;
}
int loadToFingertArray(DATAITEM*** FingerArray) {
    int j = 0;
    *FingerArray = (DATAITEM**)malloc(sizeof(DATAITEM*) * Record);
    for (int i = 0; i < Record; i++) {
        (*FingerArray)[i] = (DATAITEM*)malloc(sizeof(DATAITEM) * 3);
        (*FingerArray)[i]->item1 = Array1D[j];
        (*FingerArray)[i]->item2 = Array1D[j + 1];
        (*FingerArray)[i]->item3 = Array1D[j + 2];
        j = j + 3;
    }
    printf("�����Ѿ�����ָ������\n");
    return 0;
};//�������ļ����ص�ָ������
int loadToStructArray(DATAITEM** StructArray) {
    int j = 0;
    *StructArray = (DATAITEM*)malloc(sizeof(DATAITEM) * Record);
    for(int i=0;i<Record;i++){
        //(*StructArray)[i] = (DATAITEM)malloc(sizeof(DATAITEM) * 3);
        (*StructArray)[i].item1 = Array1D[j];
        (*StructArray)[i].item2 = Array1D[j + 1];
        (*StructArray)[i].item3 = Array1D[j + 2];
        j = j + 3;
    }
    printf("�����Ѿ�����ṹ������\n");
    return 0;
}//�������ļ����ص��ṹ������
int loadToLink(int n) {
    //int n = 10;
    Node *head, * tail;
    head = NULL;
    tail = NULL;
    initLink(&head, &tail, n);
    LinkHead = head;
    LinkTail = tail;
    printf("�����Ѿ���������\n");
    return 0;
}//�������ļ����ص�������
void initLink(Node** h, Node** t, int n) {
    Node* new_node;
    for (int i = 0; i < n; i++) {
        new_node = (Node*)malloc(sizeof(Node));
        LoadintoNode(new_node,i);
        if (*h == NULL) {
            *h = new_node;
            *t = *h;
            new_node->nextnode = NULL;
        }
        else {
            (*t)->nextnode = new_node;
            (*t) = (*t)->nextnode;
            (*t)->nextnode = NULL;
        }
    }
}
void LoadintoNode(Node* node,int n) {
    n = n * 3;
    node->data.item1 = Array1D[n];
    node->data.item2 = Array1D[n+1];
    node->data.item3 = Array1D[n+2];
}