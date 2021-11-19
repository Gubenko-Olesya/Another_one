#include <stdlib.h>
#include <stdio.h>
#include "my_functions.h"

int check_array(int array[], int n) //Gubenko Olesya 112
//funksiya proveryaet, otsortirovalsya li massiv
{
	int i;
	for (i=0; i<(n-1); i++)
	{
		if (bit_compare(array[i], array[i+1])==-1)
		//if (array[i]>array[i+1])
			return -1;
	}
	return 0;
}
