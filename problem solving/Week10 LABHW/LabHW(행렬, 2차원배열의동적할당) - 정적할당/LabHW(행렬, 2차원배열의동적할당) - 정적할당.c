#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void readMatrix(int a[][3], int n) 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]); 
	
}
void matrixAdd(int a[][3], int b[][3], int x[][3], int n) 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];  
}
void printMatrix(int a[][3], int n)  
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
	printf("\n"); 
}
int main() 
{
	int A[3][3], B[3][3], X[3][3];

	readMatrix(A, 3);
	readMatrix(B, 3);

	printMatrix(A, 3);
	printMatrix(B, 3);

	matrixAdd(A, B, X, 3);
	printMatrix(X, 3); 
}