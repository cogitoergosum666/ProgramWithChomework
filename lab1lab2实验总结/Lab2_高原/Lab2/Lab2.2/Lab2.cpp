#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
int random() {
	int p;
	srand((unsigned)time(0));
	p = rand() % 90 + 10;
	return p;
}

void getParam(int Len, char* Filename) {
	Len = random();
	strcpy(Filename,"note115.txt");
};
//用于对命令行参数进行判断

//void getRecNum(int);
void getFilename(char const* argv, char* Filename) {
	strcpy(Filename,argv);
};

int strToNumber(char const* argv) {
	int ret;
	int numlen = strlen(argv);
	int i = 0;
	int sum=0;
	for (i;i < numlen;i++) {
		sum = sum + (*(argv + i) - '0') * pow(10, numlen - i - 1);
	}
	ret = sum;
	return ret;
};

int isNumber(char const* argv) {
	int jug = 0;
	if ((*argv - '0') >= 0 && (*argv - '0') <= 9) {
		jug = 1;
	}
	return jug;
};

void createFile(int* Len, char* Filename) {
	FILE* fp = NULL;
	int i = 0;
	int j = 0;
	fp = fopen(Filename, "w");
	int(* con)[3];
	con = (int (*)[3])malloc(sizeof(int) * (*Len)*3);
	for (i;i < *Len;i++) {
		con[i][0] = random();
		con[i][1] = random();
		con[i][2] = random();
	}
	fprintf(fp, "%d\n", Len);
	for (j;j < *Len;j++) {
		fprintf(fp, "%d,%d,%d\n", con[j][0], con[j][1], con[j][2]);
	}
};

int main(int argc, char const* argv[]) {
	char* Filename;
	int Len;

	switch (argc) {
	case(1): {
		Filename = (char*)malloc(sizeof(char) * 11);
		getParam(Len, Filename);
		createFile(&Len, Filename);
		break;
	}

	case(2): {
		if (isNumber(argv[1]) == 1) {
			Len = strToNumber(argv[1]);
			Filename = (char*)malloc(sizeof(char) * 11);
			strcpy(Filename, "note115.txt");
			//getRecNum(Len);
			createFile(&Len, Filename);
		}
		else {
			Filename = (char*)malloc(sizeof(char) * strlen(argv[1]));
			getFilename(argv[1], Filename);
			Len = random();
			createFile(&Len, Filename);
		}
		break;
	}

	case(3): {
		if (isNumber(argv[1]) == 1) {
			Len = strToNumber(argv[1]);
			Filename = (char*)malloc(sizeof(char) * strlen(argv[2]));
			getFilename(argv[2], Filename);
			createFile(&Len, Filename);
		}
		else {
			if (isNumber(argv[2]) == 1) {
				Len = strToNumber(argv[2]);
				getFilename(argv[1], Filename);
				createFile(&Len, Filename);
			}
			else {
				printf("参数错误");
			}
		}
		break;
	}

	default: printf("参数错误");
	}

	return 0;
}









