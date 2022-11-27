#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
int main()
{
	int n, num = 0, sum = 0, k;
	scanf("%d", &n);
	int three = n / 3;
	for (int i = 0; i <= three; i++) {
		k = n - i * 3;
		num = k / 2; 
		sum += num + 1;

	}
	printf("%d", sum); 

}