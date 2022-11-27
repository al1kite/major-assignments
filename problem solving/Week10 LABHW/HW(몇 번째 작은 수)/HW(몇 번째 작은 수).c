#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int* A, int p, int r) {
	int i, j, t; 
	i = p - 1;

	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t; 
		}
	}
	i++;
	t = A[i];
	A[i] = A[r];
	A[r] = t;
	return i;
}
int rank(int* A, int p, int r, int i) {
	int q;
	int ranking;

	q = partition(A, p, r);
	ranking = q - p + 1;

	if (i == rank)
		return A[q];
	else if (i < ranking)
		return select(A, p, q - 1, i);
	else
		return select(A, q + 1, r, i - ranking); 
}
int select(int* A, int p, int r, int i) {
	int q = partition(A, p, r);
	int rank = q - p + 1;
	if (i == rank)
		return A[q];
	else if (i < rank)
		return select(A, p, q - 1, i);
	else
		return select(A, q + 1, r, i); 
} 
int main() {
	int* A;
	int n, i, rank;
	printf("Enter the number of numbers: "); 
	scanf("%d", &n);
	printf("몇번째로 작은 수: "); 
	scanf("%d", &rank); 

	A = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i] = rand() % 1000;
		printf("%d ", A[i]); 
	} printf("\n"); 
	printf("%d번째로 작은 수는 %d\n",rank, select(A, 0, n - 1, rank));   
	free(A);
	return 0; 
}