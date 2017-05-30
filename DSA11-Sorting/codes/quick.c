#include <stdio.h>

#define MAX 21 
#define swap(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )


void quicksort(int list[], int left, int right);
int partition(int list[], int left, int right);

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

	quicksort(list, 0, n-1);

	printf("sorted list\n");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}


void quicksort(int list[], int left, int right){
	if (left < right){
		int pivot = partition(list, left, right);
		quicksort(list, left, pivot-1);
		quicksort(list, pivot+1, right);
	}
}

int partition(int list[], int left, int right){
	int pivot, temp;
	int low, high;
	low = left;
	high = right +1;
	pivot = list[left];
	do{
		do
			low++;
		while(low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) 
			swap(list[low], list[high], temp);
	} while (low < high);
	swap(list[left], list[high], temp);
	return high;
}