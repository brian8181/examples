#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // int n = 10;
    // char pa[10];
    // char* pc = &pa[0];
    // itoa(n, pc, 10);
    // printf("%s\n", pa);

    char* str = "10";
    int i = atoi(str);    
    printf("%d\n", i);

    return 0;
}