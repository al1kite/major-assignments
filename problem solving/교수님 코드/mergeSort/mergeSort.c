# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//A[p...q] ~ A[q+1...r]
void merge(int* A, int p, int q, int r, int* B) {

    int i = p;
    int j = q + 1;
    int t = 0;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            B[t] = A[i];
            i++;
        }
        else {
            B[t] = A[j];
            j++;
        }
        t++;
    }
    if (i > q) {
        for (; j <= r; j++) {
            B[t] = A[j];
            t++;
        }
    }
    else {
        for (; i <= q; i++) {
            B[t] = A[i];
        }
    }
    t = 0;
    for (i = p; i <= r; i++) {
        A[i] = B[t];
        t++;
    }
    free(B);
}
void mergeSort(int* A, int p, int r, int* B) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q, B);
        mergeSort(A, q + 1, r, B);
        merge(A, p, q, r, B);
    }
}

int main(void) {

    int* A, * B;
    int n, i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int) * n);
    B = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    mergeSort(A, 0, n - 1, B);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    free(B);
    return 0;
}