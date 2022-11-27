#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 
int main()
{
	int n = 0;
	scanf("%d", &n);

	int nine = 9 * n;
	int dec = 1, cnt;
	int m = nine;
	int* c = (int*)malloc(sizeof(int) * nine); 
	for (cnt = 0; m > 10; cnt++) {
		dec *= 10;
		m /= 10; 
	}
	for (int i = 0; i <= cnt; i++) {
		c[i] = nine / dec; 
		nine -= (nine / dec) * dec;
		dec /= 10; 
		printf("%d ", c[i]);
	}
}