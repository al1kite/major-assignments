#include<stdio.h>
int c[10010];
int comb(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	if (c[n] != 0)
		return c[n]; 
	else
		return c[n] = comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int c = comb(4, 2);
	printf("%d\n", c);
}