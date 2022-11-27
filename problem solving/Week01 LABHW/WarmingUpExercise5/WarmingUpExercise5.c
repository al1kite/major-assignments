#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main(void)
{
	char s[100];
	char ch;
	int cnt = 0;

	printf("Enter a String: ");
	scanf("%s", s);
	while (getchar() != '\n');

	printf("Enter a character: ");
	scanf("%c", &ch);

	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
		if (s[i] == ch)
			cnt++;
	printf("¡®%c¡¯is appeared %d times", ch, cnt);

}