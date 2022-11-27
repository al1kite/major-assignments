#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, k = 0, d = 0, cnt = 0;
	scanf("%d", &n); 
	while (n > 0) {
		for (int i = 0; i < n; i++) {
			d = i * i;
			if (d > n) {
				k = i - 1;
				break;
			}
		}
		n -= d;
		cnt++;
	}
	printf("%d", &cnt); 
}