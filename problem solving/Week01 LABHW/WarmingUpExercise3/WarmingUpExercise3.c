#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int total(int n);
int main(void)
{
	int num;
	int j;

	while (1) {
		printf("Input a number(-1 for exit): ");
		scanf("%d", &num);

		if (num == -1)
			break;
		printf("1부터 %d까지의 합은 %d\n", num, total(num));

	}
}
int total(int n)
{
	int total = 0;
	for (int i = 1; i < n + 1; i++) {
		total += i;
	}
	return total;
}