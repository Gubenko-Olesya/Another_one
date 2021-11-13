//programma zapolnyaet massiv chislami ot 1 do 100
//sortiruet ih v poryadke vozrastaniya dvumya sposobami - obmenami i s pomoshiu qsort
//zameryaet vremya, potrachenoe na sortirovki
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "my_functions.h"

#define SIZE 200

int main(void) //Gubenko Olesya 112
{
	int i, a, array1[SIZE], array2[SIZE], array3[SIZE];
	double time_change, time_quick, time_qsort, start, end;
	FILE *input_data, *s_change, *s_quick, *s_qsort;
	printf("Programma zapolnyaet massiv chislami ot 1 do 100, sortiruet ih v poryadke vozrastaniya dvumya sposobami - obmenami i s pomoshiu qsort i zameryaet vremya, potrachenoe na sortirovki.\n");
	//generiruem massiv ili schitivaem massiv is faila
	printf ("If you want to randomize an array press 1, if you want to export the array from the file press 2.\n");
	if ((scanf("%d", &a) !=1)||(a<1)||(a>2))  {
		printf("Unexpectable error, please try again.\n");
		return -1;
	}
	if (a==1) {
		random(array1, SIZE);
		//esli massiv bil sgenerirovan, raspechativaem ego v file
		input_data = fopen("input_data.txt", "w");
		if (input_data == NULL) {
			printf("File input_data.txt is not opened.\n");
			return -1;
		}
		for (i=0; i<SIZE; i++) {
			fprintf (input_data, "%d ", array1[i]);
			if (((i+1)%10)==0)
				fprintf(input_data, "\n");
		}
		fclose(input_data);
	}
	if (a==2)
	{
		if ((input (array1, SIZE))!=0)
		return -1;
	}
	//kopiruem massiv
	copy_mass(array1, array2, SIZE);
	copy_mass(array1, array3, SIZE);
	//proizvodim sortirovku obmenami i zameryaem vremya
	start = clock();
	sort_change(array1, SIZE);
	end = clock();
	time_change = ((end-start)/CLOCKS_PER_SEC);
	//proizvodim sortirovku QUICKSORT i zameryaem vremya
	start = clock();
	quicksort(array2, SIZE);
	end = clock();
	time_quick = ((end-start)/CLOCKS_PER_SEC);
	//proizvodim sortirovku s pomoshiu bibliotechnoi funksii i zameryaem vremya
	start = clock();
	qsort(array3, SIZE, sizeof(int), (int(*)(const void *, const void *))compare);
	end = clock();
	time_qsort = ((end-start)/CLOCKS_PER_SEC);
	//proveryaem chto vse otsortirovalos
	if ((check_array(array1, SIZE))==(-1)) {
		printf("Array hasn't been sorted while doing sort_change.\n");
		return -1;
	}
	if ((check_array(array2, SIZE))==(-1)) {
		printf("Array hasn't been sorted while doing quicksort.\n");
		return -1;
	}
	if ((check_array(array3, SIZE))==(-1)) {
		printf("Array hasn't been sorted while doing sort_qsort.\n");
		return -1;
	}
	//raspechativaem resultaty sortirovok v files
	s_change = fopen("array_sorted_change.txt", "w");
	if (s_change == NULL) {
		printf("File array_sorted_change.txt is not opened.\n");
		return -1;
	}
	for (i=0; i<SIZE; i++) {
		fprintf (s_change, "%d ", array1[i]);
		if (((i+1)%10)==0)
			fprintf(s_change, "\n");
	}
	fclose(s_change);
	s_quick = fopen("array_sorted_quick.txt", "w");
	if (s_quick == NULL) {
		printf("File array_sorted_quick.txt is not opened.\n");
		return -1;
	}
	for (i=0; i<SIZE; i++) {
		fprintf (s_quick, "%d ", array2[i]);
		if (((i+1)%10)==0)
			fprintf(s_quick, "\n");
	}
	fclose(s_quick);
	s_qsort = fopen("array_sorted_qsort.txt", "w");
	if (s_qsort == NULL) {
		printf("File array_sorted_qsort.txt is not opened.\n");
		return -1;
	}
	for (i=0; i<SIZE; i++) {
		fprintf (s_qsort, "%d ", array3[i]);
		if (((i+1)%10)==0)
			fprintf(s_qsort, "\n");
	}
	fclose(s_qsort);
	//vivodim vremya
	printf("Number of elements: %d,\nTime sort_change: %lf,\nTime sort_quick: %lf,\nTime sort_qsort: %lf.\n", SIZE, time_change, time_quick, time_qsort);
	return 0;
}
