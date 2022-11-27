#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
void pick(int n, int r, int picked[], int toPick);
int main()
{
	char* items[] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int picked[3];
	pick(items, 5, picked, 3, 3);
}
void pick(char* items[], int n, int* picked, int m, int toPick)
{
	int i, j, lastIndex;
	if (toPick == 0) {
		int picked_index;
		for (i = 0; i < m; i++) {
			picked_index = picked[i];
			printf("%s ", items[picked_index]);
		}
		printf("\n");
		return;
	}
	lastIndex = m - toPick - 1;

	for (i = 0; i < n; i++) {
		int flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == 1)
				flag = 1;
		if (flag == 1)
			continue;

		picked[lastIndex + 1] = i;
		pick(items, n, picked, m, toPick - 1);
	}
}