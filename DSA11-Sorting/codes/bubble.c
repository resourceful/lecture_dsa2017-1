// Unoptimized and Optimized implementation of bubble sort
#include <stdio.h>

void swap(int *x, int *y);
void bubble_unoptimized(int list[], int size);
void bubble(int list[], int size);
void printArray(int list[], int size);

int main(){
	int list[] = {30, 28, 18, 29, 48, 40};
	// get the number of items in the list
	int n = sizeof(list)/sizeof(list[0]);

	printf("initial list: \t");
	printArray(list, n);

//	bubble_unoptimized(list, n);
	bubble(list, n);

	printf("sorted list: \t");
	printArray(list, n);

	return 0;
}

void swap(int *x, int *y){ // swap the two value
	int temp = *x;
	*x = *y;
	*y = temp;
}


void printArray(int list[], int size){
	for ( int i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}


// unoptimized bubble sort with worst case of O(n^2)
void bubble_unoptimized(int list[], int size){
	int i, j;
	for (i = 0; i < size-1; i++)
		for (j = 0; j < size-i-1; j++) // skip sorted items in the list
			if (list[j] > list[j+1])
				swap(&list[j], &list[j+1]);
}

// optimzed bubble sort
void bubble(int list[], int size){
	int i, j;
	int swapped = 1; 
	// loop until no two elements were swapped by inner loop
	for (i = size-1; swapped > 0; i--){
		swapped = 0;
		for (j = 0; j < i; j++)
			if (list[j] > list[j+1]){
				swap(&list[j], &list[j+1]);
				swapped = 1;
			}
	}
}