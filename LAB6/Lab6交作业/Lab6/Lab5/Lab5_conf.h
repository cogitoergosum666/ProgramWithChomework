#pragma once
typedef struct conf {
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
/***********************************************
文件名称:
    Lab5.cpp
功能描述:
    程序入口文件，存放整个工程的main函数
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年5月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
void EditConf();//修改配置参数模块主函数
int LoadConf(conf* input);//读取实验4配置文件函数
void ShowConfMenu(conf* input);//展示15号功能子菜单函数
int ConfMain(conf* input);//15号功能主函数
int UpdateConf(conf* input);//将新配置数据写入配置文件函数