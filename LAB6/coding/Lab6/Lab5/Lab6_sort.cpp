#include<stdlib.h>
#include"Lab5_data.h"
int cmp(const void*a,const void*b){
	int x = (*(int**)a)[2];
	int y = (*(int**)b)[2];
	return x - y;
	//return(*(int*)a - *(int*)b);//升序
	//return (*(int*)b-*(int*)a);//降序
}
int cmpStruct(const void* a, const void* b) {
	int x = (*(DATAITEM*)a).item3;
	int y = (*(DATAITEM*)b).item3;
	return x - y;
}
int cmpFinger(const void* a, const void* b) {
	int x = (*(DATAITEM**)a)->item3;
	int y = (*(DATAITEM**)b)->item3;
	return x - y;
}
void SortArray2D(int*** input) {
	qsort(*input, Record, sizeof(*input[0]), cmp);//input加*和不加*效果一样？？为什么？
}
void SortArray1D(int** input) {
	qsort(*input, 3*Record, sizeof(input[0]), cmp);
}
void SortStructArray(DATAITEM** input) {
	qsort(*input, Record, sizeof(*input[0]), cmpStruct);
}
void SortFingerArray(DATAITEM*** input) {
	qsort(*input, Record, sizeof(*input[0]), cmpFinger);
}
void SortLink(LINKNODE** input) {
	LINKNODE* j;
	LINKNODE* k;
	j = *input;
	DATAITEM temp;
	for (int i = 0; i < Record; i++) {
		for (int w = 0; w < i; w++) {
			j = (*input)->nextnode;
		}
		for (int n = 0; n < Record - i -1; n++) {
			k = j->nextnode;
			if (j->data.item3 > k->data.item3) {
				//temp.item1 = j->data.item1;
				//temp.item2 = j->data.item2;
				//temp.item3 = j->data.item3;
				//j->data.item1 = k->data.item1;
				//j->data.item2 = k->data.item2;
				//k->data.item3 = k->data.item3;
				temp = j->data;
				j->data = k->data;
				k->data = temp;
			}
			j = k;
			k = k->nextnode;
		}
	}
}
