#pragma once

struct configinfo {
	char filesavepath[1000]; //���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
	char filename[1000]; //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
	int number; //���ڴ�����ɵļ�¼����
	int maxvalue1; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int minvalue1; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int maxvalue2; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int minvalue2; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int recordcount1; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	int recordcount2; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	char FileType;//���ڴ�������ļ���ʽ��t��ʾtxt��ʮ���ƣ���ʽ��d��ʾdat�������ƣ���ʽ
};
struct DataItem {
	int item1;
	int item2;
	int item3;
};

//FILE* fp;
int Data[1000][3];
int* RecArray;//����������ż�¼�������ļ����ı���
char FilePath[1000];
int PathForm;

struct configinfo Stat;
