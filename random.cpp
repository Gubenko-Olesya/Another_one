#include <stdlib.h>
#include <stdio.h>

int random (int array1[], int n) //Gubenko Olesya 112
//funksiya generiruet tcelochislenniy massiv i dubliruet ego (poluchaem dva odinakovikh sgenerirovannih massiva
{
	int i;
	for (i=0; i<n; i++) {
		array1[i]=rand();
	}
	return 0;
}
