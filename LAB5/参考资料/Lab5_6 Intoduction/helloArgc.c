//helloArgc.c

#include <stdio.h>

void main(int argc, char *argv[])
{
	int i;
	for(i=0; i<argc; i++)
		printf("%s\n", argv[i]);
}