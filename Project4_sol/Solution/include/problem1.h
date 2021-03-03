#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30000	//size of list sorted

int *bubble_prj4(FILE *fp_in);
int *selection_prj4(FILE *fp_in);
int *insertion_prj4(FILE *fp_in);

int *heap_prj4(FILE *fp_in);

int *merge_prj4(FILE *fp_in);
void merge(int *dataset, int left, int mid, int right);

int *quick_prj4(FILE *fp_in);
int partition(int *dataset, int left, int right);
