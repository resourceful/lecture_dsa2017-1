// null_pointer.c
#include <stdio.h>

int main(){
    int *pNum = NULL, Num=103;
    if (pNum == '\0') 
        pNum = &Num;
    else
        *pNum = 100;
    printf("pNum %d", (int)*pNum);
    return 0;
}