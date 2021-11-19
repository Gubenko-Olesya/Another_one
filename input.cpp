#include <stdio.h>
#include <stdlib.h>

int input (int array[], int n)//Gubenko Olesya 112
{
	int i;
	FILE *IN;
	IN = fopen("input_data.txt", "r");
	if (IN == NULL) {
		printf("File not opened.\n");
		return -1;
	}
	for (i=0; i<n; i++) {
		if ((fscanf (IN, "%d", &array[i])!=1)||(array[i]<0)) {
			printf ("Not enough numbers in the file or invalid number format.\n");
			fclose(IN);
			return -1;
		}
	}
	fclose(IN);
	return 0;
}
