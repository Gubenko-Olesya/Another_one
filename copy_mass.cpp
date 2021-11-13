#include <stdio.h>
#include <cstdlib>


int copy_mass (int array1[], int array2[], int n)
{
	int i;
	for (i=0; i<n; i++)
		array2[i]=array1[i];
	return 0;
}
