#include <stdio.h>

#define MAX 21 
#define swap(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )


void quicksort(int list[], int n, int left, int right);
int partition(int list[], int n, int left, int right);
void printArray(int list[], int idx);

int main(){
  //	int list[MAX] = { 57, 70, 97, 38, 63,
  //                      21, 85, 68, 76,  9, 
  //                  81, 36, 55, 79, 74, 
  //                  85, 16, 61, 77, 49, 
  //                  24 };
  
  int list[] ={6, 5, 3, 1, 8, 7, 2, 4};

	int n = sizeof(list)/sizeof(list[0]);
	
	printf("unsorted list\n");
	printArray(list, n);

	quicksort(list, n, 0, n-1);

	printf("sorted list\n");
	printArray(list, n);
	return 0;
}


void quicksort(int list[], int n, int left, int right){
	if (left < right){
      	        int pivot = partition(list, n, left, right);
		quicksort(list, n, left, pivot-1);
		quicksort(list, n, pivot+1, right);
	}
}

int partition(int list[], int n, int left, int right){
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
		if (low < high) {
		        swap(list[low], list[high], temp);
			printArray(list, n);
		}
	} while (low < high);
	swap(list[left], list[high], temp);
	printArray(list, n);
	return high;
}

void printArray(int list[], int idx){
  int i;
  for (i = 0; i < idx; i++)
    printf("%d ", list[i]);
  printf("\n");
}
