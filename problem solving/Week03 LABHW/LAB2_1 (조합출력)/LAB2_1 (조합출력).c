#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
void pick(int n, int r, int picked[], int toPick);
int main()
{
	int picked[4];
	pick(7, 4, picked, 4);
}
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