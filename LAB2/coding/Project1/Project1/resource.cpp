#include <stdio.h>
#include<math.h>
#include<string.h>
void strToNumber(char* c, int* p) {
    int res = 0; int j = 0;
    for (int i = strlen(c)-1; i>-1; i--) {
        
        res = (c[i] - '0') * ((int)pow(10, j)) + res;
        j ++ ;
    }
    *p = res;
}
int main(int argc, char const* argv[])
{
    static int* p;
    int b = 0;
    p = &b;

    char a[3] = { '2','9' };
    char* c = a;
    strToNumber(a,p);
    printf("%d\n", *p);
    printf("%d", strlen(a));
    return 0;
}
