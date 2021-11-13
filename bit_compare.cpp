#include <stdio.h>
#include <stdlib.h>

int bit_compare(int a, int b)
{
	int i, mask=1, c_a=0, c_b;
	for (i=0;i<32;i++) {
		if ((a&mask)!=0)
			++c_a
	}
	for (i=0;i<32;i++) {
		if ((b&mask)!=0)
			++c_b
	}
	if (c_a<c_b)
		return 1;
	if (c_a==c_b)
		return 0;
	if (c_a>c_b)
		return -1;
}
