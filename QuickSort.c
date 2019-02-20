#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b) {
	*a += *b;
	*b = *a - *b;
	*a -= *b; 
}
int Median3(int A[], int left, int right) {
	int Center = (left + right) / 2;
	if(A[left] > A[Center])
		swap(A+left, A+Center);
	if(A[left] > A[right])
		swap(A+left, A+right);
	if(A[Center] > A[right])
		swap(A+Center, A+right);
	swap(A+Center, A+right);
	return A[right-1];
}
void Qsort(int A[], int left, int right) {
	int i, j;
	int Pivot;//枢纽数
	if(right - left >= 2) {
		Pivot = Median3(A, left, right);
		i = left; j = right-1;
		while(1) {
			while( A[++i] > Pivot);
			while( A[--j] < Pivot);
			if(i < j)
				swap(A+i, A+j); 
			else 
				break;
		}
		swap(A+i, A+right-1);
		Qsort(A, left, i-1);
		Qsort(A, i+1, right);
	}
	else {
		if(A[left] > A[right])
			swap(A+left, A+right);
	} 
}
void QuickSort(int A[], int len) {
	Qsort(A, 0, len-1);
}
int main() {
	int A[10];
	int i;
	int len = sizeof(A) / sizeof(int);
	clock_t begintime, endtime;
	srand((unsigned) time(NULL));
	for (i = 0; i < len; ++i) 
		A[i] = rand() % 1000;	

	begintime = clock();
	QuickSort(A, len);
	endtime = clock();

	for (i = 0; i < len; ++i) 
		printf("%d\n", A[i]);
	printf("Time used = %.6f\n", (double)(endtime-begintime) / CLOCKS_PER_SEC);
	return 0;
}