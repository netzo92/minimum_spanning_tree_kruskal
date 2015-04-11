#ifndef DISJOINT_H
#define DISJOINT_H

#include <stdlib.h>
#include <stdio.h>


class Disjoint {
	int *array;
	
	public:
		Disjoint(int );
		int findDisjoint(int );	
		void merge(int , int );
};
#endif
