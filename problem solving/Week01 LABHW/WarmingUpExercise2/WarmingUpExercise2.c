#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int isPrime(int x);
int main(void)
{
	int N = 30, j;

	for (j = 2; j <= N; j++) {
		if (isPrime(j) == 1)
			printf("%d ", j);
	}

	return 0;
}
int isPrime(int x)
{
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}