#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int compare(int arr1[], int arr2[]);
int main(void)
{
	int arr1[5];
	int arr2[5];
	printf("Enter ù��° �迭: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);

	printf("Enter �ι�° �迭: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);

	if (compare(arr1, arr2) == 0)
		printf("�� ���� �迭�� �ٸ���\n");
	else
		printf("�� ���� �迭�� ����\n");
}
int compare(int arr1[], int arr2[])
{
	for (int i = 0; i < 5; i++)
		if (arr1[i] != arr2[i])
			return 0;
	return 1;
}