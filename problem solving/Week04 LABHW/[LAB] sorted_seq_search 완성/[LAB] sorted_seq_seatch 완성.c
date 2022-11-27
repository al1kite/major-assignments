#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int arr[] = { 2,3,5,7,8,9 };
int sorted_seq_search(int key, int low, int high)
{
	int i;
	for (i = low; i <= high; i++)
		if (arr[i] > key)
			return -1;
		else if (arr[i] == key)
			return i;
	return -1;
}
int main(void)
{
	int key;
	scanf("%d", &key);
	printf("%d", sorted_seq_search(key, 0, 5));
}