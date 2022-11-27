#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k); 

	int* c = (int*)malloc(sizeof(int) * n); 
	int remain = 0; 
	int i = 0; 
	while (n > 0) {
		remain = n % k; 
		n /= k; 
		c[i] = remain; 
		i++; 
	}
	for (int j = 0; j < i; j++)
		printf("%d ", c[i - j - 1]); 
}
