// codes/array_address.c
#include <stdio.h>

void print1(int *ptr,int rows) { 
    int i;
    printf("Address\t\tContents\n"); 
    for(i=0;i<rows;i++)
        printf("%8u\t%5d\n",  (unsigned int)ptr+i,  *(ptr+i)); 
    printf("\n");
}

int main() {
  int one[] = {0, 1, 2, 3, 4};
  print1(one, 5);
  return 0;
}