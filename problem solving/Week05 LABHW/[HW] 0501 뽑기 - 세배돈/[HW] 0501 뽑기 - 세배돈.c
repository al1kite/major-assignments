#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
int money;
void pick(int items[], int n, int* picked, int m, int toPick);
int main()
{
	int items[] = { 1000, 5000, 10000, 0 };
	scanf("%d", &money);
	int n = money / 1000;
	int* picked = (int*)malloc(sizeof(int) * n);
	pick(items, 4, picked, n, n);
}
void pick(int items[], int n, int* picked, int m, int toPick)
{
	int i, lastIndex, smallest, sum = 0;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			sum += items[picked_index];
		}
		if (sum == money) {
			for (i = 0; i < m; i++) {
				picked_index = picked[i];
				if (items[picked_index] != 0)
					printf("%d ", items[picked_index]);
			}
			printf("\n");
		}
		return;
	}
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex];
	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}