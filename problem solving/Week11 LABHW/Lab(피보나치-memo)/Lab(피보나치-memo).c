#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int fibo(int n);
int f[10010];
int main(void)
{
	int n;
	printf("�� ��°������ �Ǻ���ġ ����: ");
	scanf("%d", &n);
	for(int i = 0; i<n; i++) 
		printf("%d ", fibo(i)); 
	printf("\n");
}
int fibo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	if (f[n] != 0)
		return f[n];
	else
		return f[n] = (fibo(n - 1) + fibo(n - 2)) % 10009;
}