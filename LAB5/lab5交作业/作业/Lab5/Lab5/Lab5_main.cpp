
/***********************************************
�ļ�����:
    Lab5_main.cpp
��������:
    ���������ļ������run������������Ҫ���׵��Ӻ���
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��5��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab5_main.h"
#include"Lab5_view.h"
#include"Lab5_call.h"
#include"Lab5_loadfile.h"
#include"Lab5_data.h"
#include"Lab5_end.h"
#include"Lab5_conf.h"
#include<stdio.h>
#include<io.h>
#include<direct.h>
#include<string.h>
#include<stdlib.h>

int* Array1D;
//һά���飬���巽ʽ��Ψһ

int** Array2D;
//��ά����

DATAITEM* StructArray;
//�ṹ��������ָ��

DATAITEM** FingerArray;
//ָ��������ָ��

LINKNODE* LinkHead;
//����ͷָ��
LINKNODE* LinkTail;
//����βָ��

char UserFilePath[1000];
char LabDefaultPath[1000];
char Lab4DefaultPathDat[1000];
int Record;
int Lab5Mode;
int run() {
    if (sysCheck() == 0) {
        printf("ϵͳ�Լ�ʧ�ܣ������˳�...\n");
        return 0;
    }//����0�����󣬷���1���ͨ������
    
    else {
        printf("ϵͳ�Լ�ͨ�������ڳ�ʼ��...\n");

        for (int i = 0; i < 100; i++) {
            int mode = 0;
            mode = sysInit();//ϵͳ��ʼ������
            if (mode == -1) {
                printf("�����ļ���ʧ�ܣ��������Զ�ģʽ\n");
                mode = 0;
            }
            if (mode == 0) {
                printf("��ǰ�������е����Զ�ģʽ\n");
            }
            if (mode == 1) {
                printf("��ǰ�������е��ǽ���ģʽ\n");
            }
            int res = showMainMenu();
            switch (res) {
            case 1:AssCommand(0,mode);
                break;//����ʵ��4�������ɼ�¼�ļ����ı���ʽ��
            case 2:AssCommand(1, mode);
                break;//����ʵ��4�������ɼ�¼�ļ��������Ʒ�ʽ��
            case 3:loadTo1DArray(2,0);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;//��ȡָ�����ݼ�¼�ļ�����ά����洢��ʽ��
            case 4:loadTo1DArray(2,0);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//��ȡָ�����ݼ�¼�ļ����ṹ������洢��ʽ��
            case 5:loadTo1DArray(2,0);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//��ȡָ�����ݼ�¼�ļ���ָ������洢��ʽ��
            case 6:loadTo1DArray(2,0);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//��ȡָ�����ݼ�¼�ļ�������洢��ʽ��
            case 7:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;
                //����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ı���ʽ�������ά���鷽ʽ�洢��
            case 8:AssCommand(0, mode);
                loadTo1DArray(mode, 0);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ı���ʽ������ṹ�����鷽ʽ�洢��
            case 9:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ı���ʽ�����ָ������洢��ʽ��
            case 10:AssCommand(0, mode);
                loadTo1DArray(mode,0);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ����ı���ʽ���������ʽ�洢��
            case 11:AssCommand(1, mode);
                loadTo1DArray(mode,1);
                loadTo2DArray(&Array2D);
                Show2DArray(Array2D);
                FreeArray2D(Array2D);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������Ʒ�ʽ�������ά���鷽ʽ�洢��
            case 12:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToStructArray(&StructArray);
                ShowStructArray(StructArray);
                FreeStructArray(StructArray);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������Ʒ�ʽ������ṹ�����鷽ʽ�洢��
            case 13:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToFingertArray(&FingerArray);
                ShowFingerArray(FingerArray);
                FreeFingerArray(FingerArray);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������Ʒ�ʽ�����ָ�����鷽ʽ�洢��
            case 14:AssCommand(1, mode);
                loadTo1DArray(mode, 1);
                loadToLink(Record);
                ShowLink(LinkHead);
                FreeLink(LinkHead, LinkTail);
                FreeArray1D(Array1D);
                break;//����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������Ʒ�ʽ���������ʽ�洢��
            case 15:
                EditConf();
                break;//�����������ò���
            case 0://�˳�
                return 0;
            default :
                printf("��������ȷ�������ѡ��\n");
                continue;//��ʾ������Ϣ������ѭ��
            }
            system("pause");
        }
    }
    return 1;
}
/***********************************************
��������:
    ϵͳ��ʼ������
��������:
    ���س��������ļ���ȷ�����Զ�ģʽ���ǽ���ģʽ����
��������:
    ��
����ֵ:
    0Ϊ�Զ�ģʽ��1Ϊ�ֶ�ģʽ��-1Ϊ��ʧ�ܣ�Ĭ��Ϊ�Զ�ģʽ
ģ����ʷ:
    �ź�����2021��5��9�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int sysInit() {
    FILE* fp;
    fopen_s(&fp, "conf.ini", "r");
    if (fp == NULL) {
        printf("Lab4�����ļ���ʧ��\n");
        return -1;
    }
    else {
        char path1[1000];
        char file1[1000];
        fscanf_s(fp, "%s", path1,1000);
        fscanf_s(fp, "%s", file1,1000);
        strcpy_s(LabDefaultPath, 1000, path1);
        strcat_s(LabDefaultPath, 1000, file1);
        strcat_s(LabDefaultPath, 2000, ".txt");
        printf("�Ѷ�ȡLab4Ĭ�ϴ洢�ļ�λ��\n");
        fclose(fp);
    }
    
    int mode1=0;
    fopen_s(&fp, "Lab5_conf.ini", "r");
    if (fp == NULL) {
        printf("Lab5�����ļ���ʧ��\n");
        return -1;
    }
    else {
        fscanf_s(fp, "%d", &mode1,1000);
        Lab5Mode = mode1;
        fclose(fp);
        return mode1;
        
    }
}
/***********************************************
��������:
    ϵͳ�Լ캯��
��������:
    ���ϵͳ�ر��������ļ���lab4ִ���ļ��Ƿ��λ
��������:
    ��
����ֵ:
    0ΪҪ��δ������1Ϊ׼�����
ģ����ʷ:
    �ź�����2021��5��9�մ�����ģ�飬email:20281274@bjtu.edu.cn
**********************************************/
int sysCheck() {
    if(_access("lab3.exe",0))return 0;
    if (_access("Lab5_conf.ini", 0))return 0;
    if (_access("conf.ini", 0))return 0;
    _chdir("Lab5");
    return 1;
}