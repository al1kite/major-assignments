#include <stdio.h>
#include <stdlib.h>
int matrixPath(int** m, int** M, int i, int j) {
	if (M[i][j] != 0)
		return M[i][j];
	if (i == 0 & j == 0)
		return m[i][j];
	else if (i == 0) {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, M, i, j - 1);
		return M[i][j - 1] + m[i][j];
	}
	else if (j == 0) {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, M, i - 1, j);
		return M[i - 1][j] + m[i][j]; 
	}
	else {
		if (M[i][j - 1] == 0)
			M[i][j - 1] = matrixPath(m, M, i, j - 1);
		if (M[i - 1][j] == 0)
			M[i - 1][j] = matrixPath(m, M, i - 1, j);

		return (M[i][j - 1] < M[i - 1][j] ? M[i][j - 1] : M[i - 1][j]) + m[i][j];
	}
}
int main()
{
	int** m,** M;
	int r, c;

	r = c = 4;
	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r); 
	for (int i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &m[i][j]);
	printf("%d\n", matrixPath(m, M, r - 1, c - 1));

}