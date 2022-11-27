# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrixPath(int** m, int** M1, int** M2, int i, int j) {

    if (i == 0 && j == 0)
        return m[i][j];
    else if (i == 0) {
        if (M2[i][j - 1] == 0) {
            M1[i][j - 1] = matrixPath(m, M1, M2, i, j - 1);
            M2[i][j - 1] = 1;
        }
        return M1[i][j - 1] + m[i][j];
    }
    else if (j == 0) {
        if (M2[i - 1][j] == 0) {
            M1[i - 1][j] = matrixPath(m, M1, M2, i - 1, j);
            M2[i - 1][j] = 1;
        }
        return M1[i - 1][j] + m[i][j];
    }
    else {
        if (M2[i][j - 1] == 0) {
            M1[i][j - 1] = matrixPath(m, M1, M2, i, j - 1);
            M2[i][j - 1] = 1;
        }

        if (M2[i - 1][j] == 0) {
            M1[i - 1][j] = matrixPath(m, M1, M2, i - 1, j);
            M2[i - 1][j];
        }
        return ((M1[i][j - 1] < M1[i - 1][j]) ? M1[i][j - 1] : M1[i - 1][j]) + m[i][j];
    }
}


int main(void) {

    int** m;
    int** M1;
    int** M2;
    int r, c;
    int i, j;

    r = c = 4;

    m = (int**)malloc(sizeof(int*) * r);
    M1 = (int**)malloc(sizeof(int*) * r);
    M2 = (int**)malloc(sizeof(int*) * r);

    for (i = 0; i < r; i++) {
        m[i] = (int*)malloc(sizeof(int) * c);
        M1[i] = (int*)malloc(sizeof(int) * c);
        M2[i] = (int*)malloc(sizeof(int) * c);
    }

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
            M1[i][j] = 0;
            M2[i][j] = 0;
        }

    printf("%d\n", matrixPath(m, M1, M2, r - 1, c - 1));

}