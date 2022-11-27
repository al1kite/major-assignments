#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	long long int n, num = 0;
	scanf("%lld", &n);

	while (n > 0) {
		n = n / 10;
		num++;
	}
	printf("%lld", num);
}