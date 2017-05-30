#include <stdio.h>

void insertion(int list[], int size);
void printArray(int list[], int size);

int main(){
	int list[] = {30, 28, 18, 29, 48, 40};
	// get the number of items in the list
	int n = sizeof(list)/sizeof(list[0]);

	printf("initial list: \t");
	printArray(list, n);

	insertion(list, n);

	printf("sorted list: \t");
	printArray(list, n);

	return 0;
}

void printArray(int list[], int size){
	for ( int i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}


// insertion sort
void insertion(int list[], int size){
	int i, j, key;
	for (i = 1; i < size; i++){
		key = list[i];

		// if item is greater than the key 
		// move the item in list to one position ahead
		for (j = i-1 ; j >= 0 && list[j] > key; j--)
			list[j+1] = list[j];
		list[j+1] = key;
	}
}