#include <stdio.h>
#include <stdlib.h>
#include "Disjoint.h"
#include <cmath>

Disjoint::Disjoint(int numNode)
{
	int i;
	array = new int[numNode + 1];
	array[0] = 0;
	for(i = 1; i<(numNode+1);i++){
		array[i] = -1;
	}
}

int Disjoint::findDisjoint(int x)
{
	if(array[x] < 0)
		return x;
	else
		return findDisjoint(array[x]);
}
	
void Disjoint::merge(int e1, int e2)
{
	int p1 = findDisjoint(e1);
	int p2 = findDisjoint(e2);
	if(p1 != p2)
	{
		if(array[p1] <= array[p2])
		{
			array[p1] = array[p2] + array[p1];
			array[p2] = p1;
		}
		else
		{ 		
			array[p2] = array[p1] + array[p2];
			array[p1] = p2;
		}
	}
}

