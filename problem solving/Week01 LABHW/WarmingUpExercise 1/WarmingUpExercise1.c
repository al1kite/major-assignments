#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int square(int n);
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	printf("%d", square(n));
}
int square(int n)
{
	if (n == 0)
		return 1;
	else
		return 2 * square(n - 1);
}