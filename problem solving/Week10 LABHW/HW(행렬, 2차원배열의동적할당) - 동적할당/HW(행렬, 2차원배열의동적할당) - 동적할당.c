#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void readMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &a[i][j]);

}
void matrixDouble(int** a, int** b, int** x, int r, int c, int e)
{
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			for (int k = 0; k < e; k++) 
				x[i][j] += a[i][k] * b[k][j]; 
		
}
void matrixTransposed(int** a, int** ta, int r, int c)
{
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			ta[i][j] = a[j][i]; 

}
void printMatrix(int** a, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%3d ", a[i][j]);
		printf("\n"); 
	}
	printf("\n");
}
int main()
{
	int** A, ** C, ** X, ** TA;  
	int r_a, c_a, r_c, c_c;

	printf("Enter 행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &r_a, &c_a);
	printf("Enter 행렬 C의 행과 열의 개수<C의 행은 %d이어야>: ", c_a); //c_a == r_c
	scanf("%d %d", &r_c, &c_c); 

	A = (int**)malloc(sizeof(int*) * r_a); 
	TA = (int**)malloc(sizeof(int*) * c_a); 
	C = (int**)malloc(sizeof(int*) * r_c); 
	X = (int**)malloc(sizeof(int*) * r_a);

	for (int i = 0; i < r_a; i++) {
		A[i] = (int*)malloc(sizeof(int*) * c_a);  
		X[i] = (int*)malloc(sizeof(int*) * c_c);
	}
	for (int i = 0; i < r_c; i++) {
		C[i] = (int*)malloc(sizeof(int*) * c_c);
		TA[i] = (int*)malloc(sizeof(int*) * r_a);
	}

	for (int i = 0; i < r_a; i++) 
		for (int j = 0; j < c_c; j++)
			X[i][j] = 0;
	
	printf("%d x %d 행렬 A 입력: \n", r_a, c_a);  
	readMatrix(A, r_a, c_a);
	printf("%d x %d 행렬 C 입력: \n",r_c, c_c); 
	readMatrix(C, r_c, c_c); 

	matrixDouble(A, C, X, r_a, c_c, r_c);   
	printf("행렬곱: \n"); 
	printMatrix(X, r_a, c_c); 

	matrixTransposed(A, TA, r_a, c_a); 
	printf("전치행렬: \n"); 
	printMatrix(TA, c_a, r_a); 

	for (int i = 0; i < r_a; i++) {
		free(A[i]);
		free(X[i]);
	}
	for (int i = 0; i < r_c; i++) {
		free(C[i]);
		free(TA[i]); 
	}

	free(A);
	free(C); 
	free(X);
	free(TA);
}