#pragma once

#define random(m,n) (rand()%(n-m+1)+m)

void strToNumber(char* c, int* p);
void getParam();
int check(char* c);
void inputOne(char* c);
int inputTwo(char* c1, char* c2);
void CreatRandomData(DataItem* a);
void CreateFile(DataItem*a);
void printHelp();
void clearStdin();
void FillPath(char* a);
int CheckFilePath(char* input);
void CreatDir(char* a);
int ReadConf(configinfo*input);
void inputRec(char* c, configinfo s);
int inputThree(char* c1, char* c2, char* c3);
void WriteFile(DataItem* a);