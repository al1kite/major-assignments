#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num, mul = 1, max = 0;  
	scanf("%d", &num); 
	int* arr = (int*)malloc(sizeof(int) * num); 
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < num; i++) {
		arr[i] += 1; 
		for (int j = 0; j < num; j++) 
			mul *= arr[j];
		if (mul > max)
			max = mul; 
		arr[i] -= 1;
		mul = 1; 
	}
	printf("%d", max); 
}