#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char s[1000], compress[1000];
	int j = 0, cnt = 0;
	scanf("%s", &s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
			cnt++;
			i ++;
		}
		else {
			if (cnt == 0) {
				compress[j] = s[i];
			}
			else {
				compress[j] = (char)(cnt + 49);
				compress[j + 1] = s[i];
				compress[j + 2] = s[i + 1];
				j += 2;
				i++; 
			}
			cnt = 0;
			j++;
		}
	}
	for (int i = 0; i < j; i++)
		printf("%c", compress[i]);
	printf("\n%d", j);
}