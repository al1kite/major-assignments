#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int s[5];
	int flag = 0, val;

	printf("Enter 5���� ����: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &s[i]);

	printf("Enter a key:");
	scanf("%d", &val);

	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		if (s[i] == val) {
			flag = 1;
			printf("%d�� °�� �ִ�\n", i + 1);
			break;
		}
	}
	if (flag == 0)
		printf("����\n");
}