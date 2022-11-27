#include<stdio.h>
int comb(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	else
		return comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int c = comb(4, 2);
	printf("%d\n", c);
}