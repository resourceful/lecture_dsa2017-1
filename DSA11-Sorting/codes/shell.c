#include <stdio.h>

#define MAX 21 
#define swap(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )


void incremental_insert(int list[], int first, int last, int gap);
void shellsort(int list[], int n);

int main(){
	int list[MAX] = { 57, 70, 97, 38, 63,
                      21, 85, 68, 76,  9, 
                      81, 36, 55, 79, 74, 
                      85, 16, 61, 77, 49, 
                      24 };

	int n = sizeof(list)/sizeof(list[0]);
	
	printf("unsorted list\n");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	shellsort(list, n);

	printf("sorted list\n");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

// n = number of elements in the list
void shellsort(int list[], int n){
	int i, gap;
	for (gap = n/2; gap > 0 ; gap = gap/2){
		if ( (gap%2) == 0 ) gap++;
		for (i = 0; i < gap; i++)
			incremental_insert(list, i, n-1, gap);
	}
}

void incremental_insert(int list[], int first, int last, int gap){
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap){
		key = list[i];
		for ( j = i-gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}