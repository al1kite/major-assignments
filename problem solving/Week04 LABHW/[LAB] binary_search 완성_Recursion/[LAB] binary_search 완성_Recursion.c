#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
int list[] = { 2,3,5,7,8,9 };
int search_binary(int key, int low, int high)
{
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])
			return search_binary(key, low, middle - 1);
		else
			return search_binary(key, middle + 1, high);
		return -1;
	}
}
int main(void)
{
	int key;

	scanf("%d", &key);
	printf("%d\n", search_binary(key, 0, sizeof(list) / sizeof(int) - 1));
}