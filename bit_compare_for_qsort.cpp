#include <stdio.h>
#include <stdlib.h>

int bit_compare_for_qsort(const int *a, const int *b)//Gubenko Olesya 112
{
	int i, mask=1, c_a=0, c_b;
	for (i=0;i<32;i++) {
		if ((a&mask)!=0)
			++c_a;
		mask<<=1;
	}
	mask=1;
	for (i=0;i<32;i++) {
		if ((b&mask)!=0)
			++c_b;
		mask<<=1;
	}
	if (c_a<c_b)
		return 1;
	if (c_a==c_b)
		return 0;
	if (c_a>c_b)
		return -1;
}

