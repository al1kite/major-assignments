#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
int main(void)
{
	int lotto[6];
	char ch;

	printf("*** �ζ� ��ȣ ������ ***\n");
	srand(time(NULL));

	while (1) {
		for (int i = 0; i < 6; i++)
			lotto[i] = rand() % 45 + 1;
		printf("\n���� ��ȣ: ");
		for (int i = 0; i < 6; i++)
			printf("%d ", lotto[i]);
		printf("\n");

		printf("�ٽ� �����ϰڽ��ϱ�? (y/n):");
		scanf("%c", &ch);
		if (ch == 'n')
			break;

		while (getchar() != '\n');
	}

}