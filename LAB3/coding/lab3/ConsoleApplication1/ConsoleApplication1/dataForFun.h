#pragma once

extern struct configinfo {
	char filesavepath[1000]; //���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
	char filename[1000]; //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
	int number; //���ڴ�����ɵļ�¼����
	int maxvalue1; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int minvalue1; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int maxvalue2; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int minvalue2; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int recordcount1; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	int recordcount2; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
};

extern int Rec;
extern char* FileNameArray;
extern int PathForm;
extern int Data[11][3];
extern int* RecArray;//����������ż�¼�������ļ����ı���
extern char FilePath[1000];

extern struct configinfo Stat;