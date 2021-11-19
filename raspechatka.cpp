#include <stdio.h>
#include <stdlib.h>

int raspechatka (FILE *fout, int array[], int n)//Gubenko Olesya 112
{
	int i, j, count=0, mask=1<<30;
	for(j=0; j<n; j++) {
		if(array[j]<0) {
			fprintf(fout, "1");
			++count;
		}
		else
			fprintf(fout, "0");
		for(i=2; i<33; i++) {
			if ((array[j]&mask)!=0) {
				fprintf(fout, "1");
				++count;
			}
			else
				fprintf(fout, "0");
			if ((i%4)==0)
				fprintf(fout, " ");
			mask=mask>>1;
		}
		fprintf(fout, "     %d\n", count);
		count=0;
		mask=1<<30;
	}
	return 0;
}
