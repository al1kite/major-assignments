#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
void pick(int items[], int n, int* picked, int m, int toPick);
int main()
{
	int items[] = { 0,1,2,3 };
	int picked[4], n;
	scanf("%d", &n);
	pick(items, 4, picked, n, n);
}
void pick(int items[], int n, int* picked, int m, int toPick)
{
	int i, lastIndex, smallest;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			printf("%d", items[picked_index]);
		}
		printf("\n");
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