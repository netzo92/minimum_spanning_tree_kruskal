#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "HeapNode.h"
Heap::Heap()
{
	int i;
	heapArray = new HeapNode*[20];
	for(i = 0; i<20;i++){
		heapArray[i] = NULL;
	}
	heapSize = 20;
	fIndex = 0;
}

	
int Heap::getMin()
{
	return heapArray[1]->val;
}


HeapNode * Heap::deleteMin()
{
	int min;
	HeapNode *heapPtr = heapArray[1];
	if(heapPtr == NULL)
		return heapPtr;

	min = heapArray[1]->val;
	if(fIndex == 1)
	{
		heapArray[1] = NULL;
		fIndex = fIndex -1;
		return heapPtr;
	}
	
	heapArray[1] = heapArray[fIndex];
	heapArray[fIndex] = NULL;
	fIndex = fIndex - 1;


	int noSwap = 0;
	int hIndex = 1;
	while(noSwap == 0)
	{
		int lval, rval;
		if(hIndex*2 > fIndex)
		{
			noSwap = 1;	
		}
		else if(hIndex*2 <= fIndex && ((hIndex*2)+1)>fIndex)
		{
			if(heapArray[hIndex]->val > heapArray[hIndex*2]->val)
			{ 
				HeapNode *tmp = heapArray[hIndex*2];
				heapArray[hIndex*2]=heapArray[hIndex];
				heapArray[hIndex] = tmp;
			}
			noSwap = 1;
		}
		else if(hIndex*2 <=fIndex &&((hIndex*2)+1)<=fIndex)
		{
			int newIndex;
			lval = heapArray[hIndex*2]->val;
			rval = heapArray[(hIndex*2)+1]->val;
			if((heapArray[hIndex]->val)>lval || (heapArray[hIndex]->val)>rval)
			{	
				if(lval>rval)
				{
					newIndex = (hIndex*2)+1;
				}
				else{
					newIndex =(hIndex*2);
				}
			
				HeapNode *tmp = heapArray[newIndex];
				heapArray[newIndex] = heapArray[hIndex];
				heapArray[hIndex] = tmp;
				hIndex = newIndex;
			}
			else
			{
				noSwap = 1;
			}

		}
	}
	return heapPtr;
}

void Heap::printHeap()
{
	int j;
	for(j = 1; j<fIndex+1;j++)
	{
		if(heapArray[j] != NULL)
		{
			if(j == fIndex)
				printf("%d", heapArray[j]->val);
			else	
				printf("%d ",heapArray[j]->val);
		}
	}
	printf("\n");
}

void Heap::insertElement(int weight, int n1, int n2)
{	
	fIndex = fIndex + 1;	
	if(fIndex >= heapSize)
	{
		int j;
		HeapNode **nHeapArray = new HeapNode*[heapSize*2];
		nHeapArray[0] = NULL;
		for(j=1;j<heapSize;j++)
			nHeapArray[j]=heapArray[j];		
		for(j=heapSize;j<(heapSize*2);j++)
			nHeapArray[j]=NULL;
		
		heapSize =  heapSize*2;
		delete heapArray;
		heapArray = nHeapArray;	
	}

	heapArray[fIndex] = new HeapNode(weight, n1, n2);
	int noSwap = 0;
	int cIndex = fIndex;
	while(noSwap == 0)
	{
		int parentIndex, parentVal,childVal;
		HeapNode *tmp;
		if(cIndex == 1)
		{
			noSwap = 1;
			break;
		}	
		
		parentIndex = (cIndex *(.5));		
		parentVal = heapArray[parentIndex]->val;
		childVal = heapArray[cIndex]->val;
		if(parentVal>childVal)
		{
			tmp = heapArray[parentIndex];	
			heapArray[parentIndex] = heapArray[cIndex];
			heapArray[cIndex] = tmp;
			cIndex = parentIndex;
		}
		else
		{
			noSwap = 1;
		}
	
	}
	return;
}
