#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main(void)
{
	int sum = 0; 
	char str[1000];
	scanf("%s", &str); 
	int s = strlen(str); 

	if (atoi(&str[s - 1]) % 2 != 0)
		printf("0");
	else
		printf("1");

	for (int i = 0; i < s; i++)
		sum += str[i] - 48; 
	if (sum % 3 == 0)
		printf("1");
	else
		printf("0");

	if ((atoi(&str[s - 1]) + atoi(&str[s - 2]) * 10) % 4 == 0)
		printf("1");
	else
		printf("0");

	if (atoi(&str[s - 1]) == 0 || atoi(&str[s - 1]) == 5)
		printf("1");
	else
		printf("0"); 

}