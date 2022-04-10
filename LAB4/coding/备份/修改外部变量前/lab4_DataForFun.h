#pragma once

extern struct configinfo {
	char filesavepath[1000]; //用于存放数据记录文件的存储目录
	char filename[1000]; //用于存储数据记录文件的文件名信息
	int number; //用于存放生成的记录条数
	int maxvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
	int minvalue1; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
	int maxvalue2; //用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
	int minvalue2; //用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
	int recordcount1; //用于存放数据记录文件需要随机生成记录条数时条数值的上限
	int recordcount2; //用于存放数据记录文件需要随机生成记录条数时条数值的下限
};


extern int PathForm;
extern int Data[11][3];
extern int* RecArray;//声明用来存放记录条数和文件名的变量
extern char FilePath[1000];

extern struct configinfo Stat;

