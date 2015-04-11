#include <iostream>
#include <string.h>
#include "Heap.h"
#include "Disjoint.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
	Heap *minHeap = new Heap();
	char buffer[256];
	int i;
	std::cin.getline(buffer,256);
	int numNodes = atoi(strtok(buffer,"\n"));
	std::cin.getline(buffer,256);
	int numEdges = atoi(strtok(buffer,"\n"));
	Disjoint *d = new Disjoint(numNodes);
	
	Disjoint *d2 = new Disjoint(numNodes);
	for(int i = 0; i <numEdges; i++)
	{
		if(cin.eof())
			return 0;
		std::cin.getline(buffer,256);
		char *p = buffer;
		int num[3];
		int j = 0;
		while(*p && j<3)
		{
			if(isdigit(*p))
			{
				num[j] = strtol(p, &p, 10);
				j++;
			}
			else
				p++;	
		}
		minHeap->insertElement(num[2],num[0],num[1]);
	}
	
	for(int i = 0; i < numEdges; i++)
	{	
		HeapNode *node = minHeap->deleteMin();
		int node1 = node->n1;
		int node2 = node->n2;

		if(d->findDisjoint(node1) != d->findDisjoint(node2))
		{
			printf("v%d-v%d\n",node1,node2);
			d->merge(node1,node2);
		}
		delete node;
	}

	return 0;
}
