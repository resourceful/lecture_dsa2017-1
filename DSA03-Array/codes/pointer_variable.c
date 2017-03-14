// pointer_variable.c
#include <stdio.h>

int main(){
    int nNum, *pNum;

    nNum = 10;
    pNum = &nNum;

    printf("nNum = %d, &nNum = %d \n", nNum, (int)&nNum);
    printf("pNum = %d, pNum = %d, &pNum = %d \n", 
                           *pNum, (int)pNum, (int)&pNum);
}