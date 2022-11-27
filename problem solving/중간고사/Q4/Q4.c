#include <stdio.h>
#include <stdlib.h>

void testPrint(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void selectionSortNew(int A[], int left, int n)
{
	// 코드 작성 
	int temp, min;
	for (int i = left; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) 
			if (A[min] > A[j])
				min = j;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}
int main(void)
{
	int n;
	int a[100];
	int start;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &start);

	selectionSortNew(a, start, n);
	testPrint(a, n);
	return 0;
}