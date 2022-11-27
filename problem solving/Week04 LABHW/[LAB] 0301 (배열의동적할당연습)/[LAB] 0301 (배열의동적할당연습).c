#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
void pick(int n, int r, int picked[], int toPick);
void pick(int n, int r, int picked[], int toPick)
{
	int min, index;

	if (toPick == 0) {
		for (int i = 0; i < r; i++)
			printf("%d ", picked[i]);
		printf("\n");
	}

	index = r - toPick - 1;

	if (toPick == r)
		min = 0;
	else
		min = picked[index] + 1;

	for (int i = min; i < n; i++) {
		picked[index + 1] = i;
		pick(n, r, picked, toPick - 1);
	}

}
int main()
{
	int m, n;
	int* picked;

	scanf("%d %d", &m, &n);

	picked = (int*)malloc(sizeof(int) * m);
	pick(m, n, picked, n);

	free(picked);

	return 0;

}