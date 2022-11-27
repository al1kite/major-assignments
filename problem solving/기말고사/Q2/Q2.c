#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	long long int n, num = 0, k = 0, t = 0;
	scanf("%lld", &n);
	for (int i = 1; i < n + 1; i++) {
		t = i;
		while (t > 0) {
			t = t / 10;
			k++;
		}
		num += k;
		k = 0;
	}
	printf("%lld", num);
}