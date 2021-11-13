#include <stdio.h>
#include <stdlib.h>

int sort_change(int array1[], int SIZE)
{
	int i, j, min, ind_min, buf;
	for(i=0; i<SIZE; i++) {
		min=array1[i];
		ind_min=i;
		for(j=(i+1); j<SIZE; j++) {
			if (array1[j]<min) {
				min=array1[j];
				ind_min=j;
			}
		}
		buf=array1[i];
		array1[i]=min;
		array1[ind_min]=buf;
	}
	return 0;
}
