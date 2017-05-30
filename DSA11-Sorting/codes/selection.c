// selection sort
#include <stdio.h>

void swap(int *x, int *y);
void selection(int list[], int size);
void printArray(int list[], int size);

int main(){
	int list[] = {30, 28, 18, 29, 48, 40};
	// get the number of items in the list
	int n = sizeof(list)/sizeof(list[0]);

	printf("initial list: \t");
	printArray(list, n);

	selection(list, n);

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


// selection sort
void selection(int list[], int size){
	int i, j, midx;
	for (i = 0; i < size-1 ; i++){
		// find the minimum element in unsorted list
		midx= i;
		for (j = i+1; j < size; j++)
			if (list[j] < list[midx])
				midx = j;
	
		// swap the minimum element with the first element
		swap(&list[midx], &list[i]);
	}
}