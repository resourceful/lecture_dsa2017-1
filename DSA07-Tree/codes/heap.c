#include <stdio.h>

#define MAX_ELEMENT 200

typedef struct {
	int key; // may include other fields
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType *h){
	h->heap_size = 0;
}

// add item to the heap
void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size); // increase the heap

	// traverse to the top of the max heap tree
	// if item is lareger than the parent's item (heap[i/2].key)
	while((i != 1) && (item.key > h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item; // add new node to the heap
}

element delete_max_heap(HeapType *h){
	int parent, child;
	element item, temp;

	item = h->heap[1]; // take the max value from the heap
	temp = h->heap[(h->heap_size)--]; // reduce the heap size

	// initial position
	parent = 1;
	child = 2;

	while( child <= h->heap_size ){ // within the heap
		// loop until counted number of child is less the the heap size
		// find the larger key in the heap
		if( ( child < h->heap_size ) &&
            ( h->heap[child].key ) < h->heap[child+1].key )
			child++;

		// if found key is smaller than the last key in the tree 
		// take the last key
		if( temp.key >= h->heap[child].key )
			break;

		// take the child and advance
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2; // increase the position
	}

	h->heap[parent] = temp;
	// return the deleted value
	return item;
}

int main(){
	element e1 = {10}, e2 = {5}, e3 = {30};
	element e4 = {15}, e5 = {25}, e6 = {39};
	element max;

	HeapType heap;
	init(&heap);

	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, e4);
	insert_max_heap(&heap, e5);
	insert_max_heap(&heap, e6);

	max = delete_max_heap(&heap);
	printf("< %d > \n", max.key);
	max = delete_max_heap(&heap);
	printf("< %d > \n", max.key);
	max = delete_max_heap(&heap);
	printf("< %d > \n", max.key);

	return 0;
}