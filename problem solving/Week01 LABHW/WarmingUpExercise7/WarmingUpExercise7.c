#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int echo(int n[], int cnt);
int reverse(int n[], int cnt);
int print(int n[], int cnt);
int n[5];
int main(void)
{
	int cnt = sizeof(n) / sizeof(int);
	echo(n, cnt);
	print(n, cnt);
	reverse(n, cnt);
	print(n, cnt);

}
int echo(int n[], int cnt)
{
	for (int i = 0; i < cnt; i++)
		scanf("%d", &n[i]);
}
int reverse(int n[], int cnt)
{
	int temp = 0;
	for (int i = 0; i < cnt / 2; i++) {
		temp = n[i];
		n[i] = n[cnt - 1 - i];
		n[cnt - 1 - i] = temp;
	}
}
int print(int n[], int cnt)
{
	for (int i = 0; i < cnt; i++)
		printf("%d ", n[i]);
	printf("\n");
}