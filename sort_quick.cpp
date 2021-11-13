#include <stdio.h>
#include <stdlib.h>


int quicksort(int array[], int n) {
	int pivot;
	int start[n], end[n];
	start[0] = 0;
	end[0] = n;
	int low, high, i=0;
	while (i>=0) {
		low = start[i];
		high = end[i]-1;
		//if (low < high) {
		if (bit_compare(low, high)>0) {
			pivot = array[low];
			if (i == (n-1))
				return -1;
			//while (low < high) {
			while(bit_compare(low, high)>0) {
				//while ((array[high] >= pivot) && (low < high))
				while ((bit_compare(array[high], pivot)<=0)&&(bit_compare(low, high)>0))
					--high;
				//if (low < high) {
				if (bit_compare(low, high)>0) {
					array[low]=array[high];
					++low;
				}
				//while ((array[low] <= pivot) && (low < high))
				while ((bit_compare(array[low], pivot)>=0)&&(bit_compare(low, high)>0))
					++low;
				//if (low < high) {
				if (bit_compare(low, high)>0)
					array[high] = array[low];
					--high;
				}
			}
		array[low] = pivot;
		start[i+1] = low + 1;
		end[i+1] = end[i];
		end[i] = low;
		++i;
		}
		else --i;
	}
	return 0;
}
