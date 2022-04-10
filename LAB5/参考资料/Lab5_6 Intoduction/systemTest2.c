//systemTest2.c

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i;
	char tmp[80];
	strcpy(tmp, "helloArgc.exe  ");
	for(i=1; i<argc; i++)
	{
		strcat(tmp, argv[i]);
		strcat(tmp, " "); 
	}
		
	system(tmp);
	
}