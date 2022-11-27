#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
int cnt = 0, k = 0;
void pick(int items[], int* a, int n, int* picked, int m, int toPick);
int isSequence(int* a, int size);
int* b;
int c[999];
int main()
{
	int num = 0, N = 0;
	scanf("%d", &num);

	int* a = (int*)malloc(sizeof(int) * num);
	if (a == NULL) { return 0; }
	for (int i = 0; i < num; i++)
		scanf("%d", &a[i]);
	b = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		b[i] = a[i];

	int items[] = { -1, +1, 0 };
	int* picked = (int*)malloc(sizeof(int) * num);
	pick(items, a, 3, picked, num, num);

	int min = 999;
	for (int i = 0; i < k; i++) {
		if (c[i] < min)
			min = c[i];
	}
	if (min == 999)
		printf("-1");
	else
		printf("%d", min);


}
void pick(int items[], int* a, int n, int* picked, int m, int toPick)
{
	int i, j = 0, lastIndex;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			if (items[picked_index] == -1) {
				a[j] -= 1;
				cnt++;
			}
			else if (items[picked_index] == 1) {
				a[j] += 1;
				cnt++;
			}
			j++;
		}

		if (isSequence(a, m) == 1) {
			c[k] = cnt;
			k++;
		}
		j = 0;
		cnt = 0;
		for (int i = 0; i < m; i++)
			a[i] = b[i];
		return;
	}

	lastIndex = m - toPick - 1;

	for (i = 0; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, a, n, picked, m, toPick - 1);
	}
}
int isSequence(int* a, int size)
{
	int same = a[1] - a[0];
	for (int i = 0; i < size - 1; i++) {
		if (a[i + 1] - a[i] != same)
			return 0;
	}
	return 1;
}