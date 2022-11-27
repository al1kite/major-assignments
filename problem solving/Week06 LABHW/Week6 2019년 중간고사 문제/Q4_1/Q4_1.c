#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
void pick(char items[], int* a, int n, int* picked, int m, int toPick, int N);
int temp;
int main()
{
	int num = 0, N = 0;
	scanf("%d %d", &num, &N);

	int* a = (int*)malloc(sizeof(int) * num);
	if (a == NULL) { return 0; }
	for (int i = 0; i < num; i++)
		a[i] = i + 1;

	char items[] = { '+', '-' };
	int* picked = (int*)malloc(sizeof(int) * num);
	pick(items, a, 2, picked, num, num, N);
	printf("%d", temp);
}
void pick(char items[], int* a, int n, int* picked, int m, int toPick, int N)
{
	int i, j = 0, lastIndex, smallest, sum = 0;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			//printf("%c%d", items[picked_index], a[j]);
			if (items[picked_index] == '-')
				sum -= a[j++];
			else
				sum += a[j++];
		}
		//printf(" = %d", sum);
		if (sum == N)
			temp = 1;

		//printf("\n");
		sum = 0;
		j = 0;
		return;
	}

	lastIndex = m - toPick - 1;

	for (i = 0; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, a, n, picked, m, toPick - 1, N);
	}
}