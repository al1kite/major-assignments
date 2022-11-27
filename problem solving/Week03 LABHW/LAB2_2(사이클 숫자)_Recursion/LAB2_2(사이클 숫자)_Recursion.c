#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int get_cycle_number(int n);
int main(void)
{
	int n;
	int cnt = 1;

	scanf("%d", &n);
	printf("%d ", n);
	while (1) {
		printf("%d ", get_cycle_number(n));
		n = get_cycle_number(n);
		cnt++;
		if (n == 1)
			break;
	}
	printf("\n%d", cnt);

}
int get_cycle_number(int n)
{
	if (n % 2 == 0)
		return n / 2;
	else if (n % 2 == 1)
		return n * 3 + 1;
}