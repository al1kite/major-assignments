#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char s[1000];
	int count[1000];
	int j = 0, cnt = 0, max = -1;
	scanf("%s", &s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != s[i + 1]) {
			count[j] = cnt;
			cnt = 0;
			j++;
		}
		else {
			cnt++;
		}
	}
	for (int i = 0; i < j; i++)
		if (count[i] > max)
			max = count[i];
	printf("%d", max + 1);
}