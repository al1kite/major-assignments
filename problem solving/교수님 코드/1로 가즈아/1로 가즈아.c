# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int minOp(int n, int* M) {

    int min = n;
    int ret;

    if (n == 1)
        return 0;

    if (n % 3 == 0) {
        if (M[n / 3] == -1)
            M[n / 3] = minOp(n / 3, M);
        if (M[n / 3] < min)
            min = M[n / 3];
    }

    if (n % 2 == 0) {
        if (M[n / 2] == -1)
            M[n / 2] = minOp(n / 2, M);
        if (M[n / 2] < min)
            min = M[n / 2];
    }

    if (M[n - 1] == -1) {
        M[n - 1] = minOp(n - 1, M);
        if (M[n - 1] < min)
            min = M[n - 1];
    }
    return min + 1;

}


int main(void) {

    int n, i;
    int* M;
    scanf("%d", &n);

    M = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        M[i] = -1;
    printf("%d\n", minOp(n, M));
    free(M);
    return 0;

}