// malloc_ex.c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int *numbers;

    numbers = malloc(10*sizeof(int));

    for (i = 0; i < 10; i++)
        numbers[i] = i;

    for (i = 0; i < 10; i++)
        printf("Value of numbers[%d]: %d\n", i, numbers[i]);

    free(numbers);
}