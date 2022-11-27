#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int get_cycle_number(int n);
int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_cycle_number(n));

}
int get_cycle_number(int n)
{
	int cnt = 1;
	printf("%d ", n);
	while (1) {
		if (n % 2 == 0) {
			n = n / 2;
			printf("%d ", n);
			cnt++;
		}
		else if (n == 1)
			break;
		else if (n % 2 == 1) {
			n = n * 3 + 1;
			printf("%d ", n);
			cnt++;
		}
	}
	printf("\n");
	return cnt;
}