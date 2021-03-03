#include "problem1.h"

int *bubble_prj4(FILE *fp_in) {
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);

	int i,j;
	int temp;
	for (i=0; i<SIZE-1; i++) {
		for (j=0; j< SIZE - i - 1; j++){
			if (dataset[j] > dataset[j+1]){
				temp = dataset[j+1];
				dataset[j+1] = dataset[j];
				dataset[j] = temp;
			}
		}
	}
	return dataset;
}

int *selection_prj4(FILE *fp_in) {
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);
	int i,j;
	int mininum;
	int temp;
	for (i=0; i<SIZE-1; i++) {
		mininum = i;
		for (j=i+1; j<SIZE; j++){
			if (dataset[mininum] > dataset[j])
				mininum = j;
		}
		temp = dataset[mininum];
		dataset[mininum] = dataset[i];
		dataset[i] = temp;
	}
	return dataset;
}

int *insertion_prj4(FILE *fp_in) {
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);
	int insertion;
	int i,j;
	int temp;
	for (i=1; i<SIZE; i++) {
		insertion = dataset[i];
		j = i;
		while (j > 0 && dataset[j-1] > insertion) {
			dataset[j] = dataset[j-1];
			j--;
		}
		dataset[j] = insertion;
	}
	return dataset;
}

int *heap_prj4(FILE *fp_in) {
  printf("heap");
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);
	int i,j,temp;
	for(i = 1; i < SIZE; i++){
		if(dataset[i] > dataset[(i-1)/2]){
			j = i;
			while(dataset[j] > dataset[(j-1)/2]){
				temp = dataset[j];
				dataset[j] = dataset[(j-1)/2];
				dataset[(j-1)/2] = temp;
				j = (j-1)/2;
			}
		}
	}
	int index;
	for(i = SIZE-1; i > 0 ; i--){
		temp = dataset[0];
		dataset[0] = dataset[i];
		dataset[i] = temp;
		j = 0;
		do{
			index = (2*j+1);
			if(index < (i-1) && dataset[index] < dataset[index+1] )
				index++;
			if(index < i && dataset[j] < dataset[index]){
				temp = dataset[j];
				dataset[j] = dataset[index];
				dataset[index] = temp;
			}
			j = index;
		} while(index < i);
	}
	return dataset;
}
int *merge_prj4(FILE *fp_in) {
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);
	int curr_size;
	int start;
	int mid;
	int end;
	for (curr_size = 1; curr_size <= SIZE-1; curr_size = 2*curr_size) {
		for (start = 0; start < SIZE-1; start += 2*curr_size) {
			mid = start + curr_size - 1;
			if (start + 2 * curr_size - 1 < SIZE - 1 )
				end = start + 2 * curr_size - 1;
			else
				end = SIZE - 1;
			merge(dataset, start, mid, end);
		}
	}
	return dataset;
}
void merge(int *dataset, int left, int mid, int right) {
	int size_l = mid - left + 1;
	int size_r = right - mid;
	int i,j,k;

	
	int set_l[size_l];
	int set_r[size_r];

	for (i=0;i<size_l;i++)
		set_l[i] = dataset[left+i];
	for (j=0;j<size_r;j++)
		set_r[j] = dataset[mid+1+j];
	i=0;
	j=0;
	k=left;
	while (i < size_l && j < size_r) {
		if (set_l[i] <= set_r[j]) {
			dataset[k] = set_l[i];
			i++;
		}
		else {
			dataset[k] = set_r[j];
			j++;
		}
		k++;
	}
	while (i < size_l) {
		dataset[k] = set_l[i];
		i++;
		k++;
	}
	while (j < size_r) {
		dataset[k] = set_r[j];
		j++;
		k++;
	}
}

int *quick_prj4(FILE *fp_in) {
	int *dataset = (int*)malloc(sizeof(int)*SIZE);
	if (dataset == NULL) {
		printf("Mem alloc fail\n");
		return NULL;
	}
	fread(dataset, sizeof(int), SIZE, fp_in);
	int low;
	int high;
	int pivot;
	int stack[SIZE];
	int top = -1;
	low = 0;
	high = SIZE-1;
	srand((unsigned int)time(NULL));
	stack[++top] = low;
	stack[++top] = high;
	while (0 <= top ) {
		high = stack[top--];
		low = stack[top--];
		pivot = partition(dataset, low, high);
		if (low+1 < pivot) {
			stack[++top] = low;
			stack[++top] = pivot-1;
		}
		if (pivot < high-1) {
			stack[++top] = pivot+1;
			stack[++top] = high;
		}
	}
	return dataset;
}
int partition(int *dataset, int low, int high) {
	int pivot = (int)rand() % (high-low+1) + low;
	int temp;

	temp = dataset[low];
	dataset[low] = dataset[pivot];
	dataset[pivot] = temp;

	int left = low;
	int right = high+1;
	pivot = dataset[low];
	do{
		do{
			left++;
		}while(left <= high && dataset[left] < pivot);
		do{
			right--;
		}while(low <= right && dataset[right] > pivot);
		if(left < right){
			temp = dataset[left];
			dataset[left] = dataset[right];
			dataset[right] = temp;
		}
	}while(left < right);
	temp = dataset[low];
	dataset[low] = dataset[right];
	dataset[right] = temp;
	return right;
}
