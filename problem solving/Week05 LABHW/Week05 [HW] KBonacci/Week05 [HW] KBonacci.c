#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int kBonacci[10000000];
int i = 0; 
int KBonacci(int n, int k);
int main(void)
{
	int n, k;
	scanf("%d %d", &k, &n);
	for (int i = 0; i <= k; i++)
		kBonacci[i] = 1; 
	printf("%d", KBonacci(n, k));

}
int KBonacci(int n, int k)
{
	if (kBonacci[n] != 0)
		return kBonacci[n];
	else {
		for (int i = 1; i <= k; i++)
			kBonacci[n] += KBonacci(n - i, k);
		return kBonacci[n]; 
	}

}