#include <stdio.h>

void swap(int x, int y){
    int temp;
    printf("Inside non-pointer based swap Function\n");
    temp = y;
    y = x;
    x = temp;
    printf("Exiting non-pointer based swap Function x = %d, y = %d\n", x, y);
}

void swapp(int *x, int *y){
    int temp;
    printf("Inside pointer based swap Function\n");
    temp = *y;
    *y = *x;
    *x = temp;
    printf("Exiting pointer based swap Function x = %d, y = %d\n", *x, *y);
}

int main(){
    int x = 100, y = 200;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After swap: x = %d, y = %d\n\n", x, y);

    printf("Before swap: x = %d, y = %d\n", x, y);
    swapp(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);


    return 0;
}