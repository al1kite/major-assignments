#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int* a;
int flag, count;  
void pick(int* items, int n, int* picked, int m, int toPick);
int main()
{
	int n, m;
	scanf("%d %d", &n, &m); 

	int* items = (int*)malloc(sizeof(int) * n);
	a = (int*)malloc(sizeof(int) * n); 

	for (int i = 0; i < n; i++)
		items[i] = i + 1; 
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]); 

	int* picked = (int*)malloc(sizeof(int) * m);
	pick(items, n, picked, m, m);
}
void pick(int* items, int n, int* picked, int m, int toPick)
{
	int i, lastIndex, smallest, cnt = 0; 
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			if (items[picked_index] == a[i])
				cnt++; 
			if (flag == 1) {
				printf("%d ", items[picked_index]);
				if (i == m - 1)
					flag = 0; 
			}
		}
		if (cnt == m)
			flag = 1;  
		return;
	}
	lastIndex = m - toPick - 1;
	if (toPick == m)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;
	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}