/***********************************************
�ļ�����:
    Lab7_satus.cpp
��������:
    ���򽫸��ݵ��ݵ�ǰ״̬ȷ����һʱ�̵���״̬
��������:

����ֵ:
    ��
ģ����ʷ:
    �ź�����2021��6��8�մ�����ģ�飬email:20281274@bjtu.edu.cn
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
//    int f1;//����Ӧָ���û�¥��
//    int f2;//����Ӧָ���û�¥��
//    int t1;//����Ӧָ���û�Ŀ��¥��
//    int t2;//����Ӧָ���û�Ŀ��¥��
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
			currentSe->next_node = newnode;//������Ҫ���ָ����ӵ�����ָ���б���
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