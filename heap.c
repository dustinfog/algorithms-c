#include <stdlib.h>
#include "heap.h"

heap *heapNew(int capacity, int (*compare)(int a, int b)) {
    heap *h = malloc(sizeof (heap) + capacity);
    h->capacity = capacity;
    h->compare = compare;
    h->used = 0;

    return h;
}

void heapFree(heap *h) {
    free(h);
}

int heapPut(heap *h, int value) {
    int index = h->used;
    
    if (h->used == h->capacity) {
        return 0;
    }

    while (index != 0) {
        int parentIndex = (index - 1) / 2;
	int parentValue = h->data[parentIndex];
        if (h->compare(value, parentValue) <= 0) {
            break;
        }
        h->data[index] = parentValue;
	index = parentIndex;
    }

    h->data[index] = value;
    h->used++;

    return 1;
}

int heapPop(heap *h, int *value) {
    int index = 0, tail;
    if (h->used == 0) {
	return 0;
    }
    
    *value = h->data[index];

    tail = h->data[-- h->used];
    
    while(index < h->used)
    {
       int leftIndex = index * 2 + 1;
       int rightIndex = leftIndex + 1;
       int nextIndex;
       if (leftIndex >= h->used) {
	   break;
       }
       
       if (rightIndex < h->used) {
	   nextIndex = h->compare(h->data[leftIndex], h->data[rightIndex]) > 0 ? leftIndex : rightIndex;
       } else {
	   nextIndex = leftIndex;
       }

       if (h->compare(tail, h->data[nextIndex]) > 0) {
	   break;
       }

       h->data[index] = h->data[nextIndex];
       index = nextIndex;
    }

    h->data[index] = tail;
    
    return 1;
}

int maxCallback(int a, int b) {
    return a - b;
}

int minCallback(int a, int b) {
    return b - a;
}