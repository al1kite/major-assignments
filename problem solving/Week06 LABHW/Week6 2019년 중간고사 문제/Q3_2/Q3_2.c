/*#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void solution(int n, int* three);
int main(void)
{
	int n;
	scanf("%d", &n);
	int* three = (int*)malloc(sizeof(int) * n * 100);
	solution(n, three);
	printf("%d", three[n - 1]);

}
void solution(int n, int* three)
{
	int j = 0;
	for (int i = 0; i < n; i++) {
		int th = ((i + 1) * 3);
		int thr = th;
		int cnt = 0;
		int deci = 1;

		for (int i = 0; thr > 10; i++) {
			deci *= 10;
			thr /= 10;
			cnt++;
		}

		while (th > 0) {
			if (th < 10)
				three[i + j] = th;
			else
				three[i + j] = th / deci;
			if (th > 10)
				j++;
			if (th % 10 == 0 && (th/10) % 10 == 0) {
				j += cnt;
				break;
			}
			else
				th %= deci;
			deci /= 10;

		}

	}
}*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int solution(int n) {
	int ret = 0;

	while (n != 0) {
		n = n / 10;
		ret++;
	}
	return ret;
}

int main() {
	int n;
	int i;
	int m;
	int number;

	scanf("%d", &n);

	for (i = 3; ; i = i + 3) {
		m = solution(i);
		if (n - m <= 0)
			break;
		else
			n = n - m;
	}
	number = i;
	for (i = 0; i < m - n; i++)
		number = number / 10;

	printf("%d\n", number % 10);
	return 0;
}