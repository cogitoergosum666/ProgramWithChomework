/***********************************************
文件名称:
    Lab7_satus.cpp
功能描述:
    程序将根据电梯当前状态确定下一时刻电梯状态
函数参数:

返回值:
    无
模块历史:
    杜海玮于2021年6月8日创建本模块，email:20281274@bjtu.edu.cn
**********************************************/
#include"Lab7_data.h"

#include<malloc.h>


int rule(char run_state, char serve_state, char call_type1, char call_type2, int f1, int f2, int t1, int t2);
int CheckStatus() {
    if (State.run_state == 'r') {
        return 1;
    }
    else {
        return 0;
    }
}

//int Follow() {
//    int f1;//主响应指令用户楼层
//    int f2;//待响应指令用户楼层
//    int t1;//主响应指令用户目标楼层
//    int t2;//待响应指令用户目标楼层
//
//}
void CheckFollow() {
	RESPONSELISTNODE* current;
	current = ReListHeadNode.head;
	ServeListNode* currentSe;
	currentSe = SeListHeadNode.head;
	for (int n = 0; n < ReListHeadNode.list_num; n++) {
		if (rule(State.run_state, SeListHeadNode.head->serve_state, SeListHeadNode.head->user_call->call_type, current->user_call->call_type, SeListHeadNode.head->user_call->user_floor, current->user_call->user_floor, SeListHeadNode.head->user_call->user_target, current->user_call->user_target) == 1) {
			ServeListNode* newnode;
			newnode = (ServeListNode*)malloc(sizeof(SERVELISTNODE));
			currentSe->next_node = newnode;//将符合要求的指令添加到服务指令列表中
			SeListHeadNode.list_num++;
		}
	}
}
int rule(char run_state, char serve_state, char call_type1, char call_type2, int f1, int f2, int t1, int t2) {
	switch (run_state)
	{
	case 'u':
		switch (serve_state)
		{
		case 'P':
			switch (call_type1)
			{
			case 'u':
				if (call_type2 == 'u' && State.current_floor < f2) return 1;
				break;
			case 'd':
				if (call_type2 == 'd' && State.current_floor < f2 && t2 <= f1) return 1;
				break;
			default:
				break;
			}
			break;
		case 'E':
			switch (call_type1)
			{
			case 'u':
				if (call_type2 == 'u' && State.current_floor < f2) return 1;
				break;
			case 'd':
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case'd':
		switch (serve_state)
		{
		case 'P':
			switch (call_type1)
			{
			case 'u':
				if (call_type2 == 'd' && State.current_floor > f2 && t2 >= f1) return 1;
				break;
			case 'd':
				if (call_type2 == 'd' && State.current_floor > f2) return 1;
				break;
			default:
				break;
			}
			break;
		case 'E':
			switch (call_type1)
			{
			case 'u':
				break;
			case 'd':
				if (call_type2 == 'd' && State.current_floor > f2) return 1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case's':
		switch (serve_state)
		{
		case 'P':
			switch (call_type1)
			{
			case 'u':
				if (call_type2 == 'u' && State.current_floor < f1 && State.current_floor < f2) return 1;
				if (call_type2 == 'd' && State.current_floor > f1 && State.current_floor > f2 && t2 >= f1) return 1;
				break;
			case 'd':
				if (call_type2 == 'u' && State.current_floor < f1 && State.current_floor < f2 && t2 <= f1) return 1;
				if (call_type2 == 'd' && State.current_floor > f1 && State.current_floor > f2) return 1;
				break;
			default:
				break;
			}
			break;
		case 'E':
			switch (call_type1)
			{
			case 'u':
				if (call_type2 == 'u' && State.current_floor < f2) return 1;
				break;
			case 'd':
				if (call_type2 == 'd' && State.current_floor > f2) return 1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}


void GiveNextStatus() {

	switch (State.run_state) {
		for (int n = 0; n < SeListHeadNode.list_num; n++) {

		}
	}
}