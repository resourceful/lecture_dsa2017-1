#include <stdio.h>
 
#define swap(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

void heapify(int list[], int n, int i);
void heapsort(int list[], int n);

int main()
{
	int list[] = {77, 61, 59, 48, 19, 11, 26, 15, 1, 5};
	int n = sizeof(list)/sizeof(list[0]);

	printf("unsorted list\n");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	heapsort(list, n);

	printf("sorted list\n");
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0;
}

// heapify a subtree rooted with node i 
// i: an index in list[];  n: is size of heap
void heapify(int list[], int n, int i)
{
	int temp;
	int largest = i;        // Initialize largest as root
	int left    = 2*i + 1;  // left = 2*i + 1
	int right   = 2*i + 2;  // right = 2*i + 2
 
	// If left child is larger than root
	if (left < n && list[left] > list[largest])
		largest = left;
 
	// If right child is larger than largest so far
	if (right < n && list[right] > list[largest])
		largest = right;
 
	// If largest is not root
	if (largest != i){
		swap(list[i], list[largest], temp);

	// Recursively heapify the affected sub-tree
	heapify(list, n, largest);
	}
}
 
// heap sort main body
void heapsort(int list[], int n)
{
	int temp;
	for (int i = n / 2 - 1; i >= 0; i--) // Build heap (rearrange list)
		heapify(list, n, i);
	for (int i=n-1; i>=0; i--){ // extract an element from heap
		swap(list[0], list[i], temp);  // Move current root to end
		heapify(list, i, 0); // call max heapify on the reduced heap
	}
}
