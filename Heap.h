#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>

#include "HeapNode.h"

class Heap {
	HeapNode **heapArray;
	int heapSize;
	int fIndex;

	public:
		Heap();
		void printHeap();	
		void insertElement(int ,int ,int );
		HeapNode * deleteMin();
		int getMin();
};
#endif
