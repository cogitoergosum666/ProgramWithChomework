#pragma once

#define random(m,n) (rand()%(n-m+1)+m)

void strToNumber(char* c, int* p);
void getParam();
int check(char* c);
void inputOne(char* c);
int inputTwo(char* c1, char* c2);
void CreatRandomData();
void CreateFile();
void printHelp();
void clearStdin();
void FillPath(char* a);
int CheckFilePath(char* input);
void CreatDir(char* a);
