#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
char* input(char name[]);
char* reverse(char name[]);
char name[100];
int main(void)
{
	input(name);
	printf("Reverse: %s", reverse(name));

}
char* input(char name[])
{
	printf("Enter your name: ");
	scanf("%s", name);

	return name;
}
char* reverse(char name[])
{
	int temp = 0;
	int cnt;
	for (cnt = 0; name[cnt] != '\0'; cnt++);

	for (int i = 0; i < cnt / 2; i++) {
		temp = name[i];
		name[i] = name[cnt - 1 - i];
		name[cnt - 1 - i] = temp;
	}
	return name;
}