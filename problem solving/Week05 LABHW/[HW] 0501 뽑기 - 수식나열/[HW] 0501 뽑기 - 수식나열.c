#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
void pick(char items[], int* num, int n, int* picked, int m, int toPick);
int main()
{
	int num[2];
	scanf("%d %d", &num[0], &num[1]);
	char items[] = { '+', '-' };
	int picked[2];
	pick(items, num, 2, picked, 2, 2);
}
void pick(char items[], int* num, int n, int* picked, int m, int toPick)
{
	int i, lastIndex, sum = 0;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			printf("%c%d", items[picked_index], num[i]);
			if (items[picked_index] == '-')
				sum -= num[i];
			else
				sum += num[i];
		}
		printf(" = %d", sum);
		printf("\n");
		sum = 0;
		return;
	}
	lastIndex = m - toPick - 1;

	for (i = 0; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(items, num, n, picked, m, toPick - 1);
	}
}