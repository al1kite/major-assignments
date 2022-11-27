# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n, m;
    int i;
    int* A;

    //크기 1~n, m개
    scanf("%d %d", &n, &m);

    A = (int*)malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
        scanf("%d", &A[i]);

    //7, 6, 5, 4 보다 작은 것이 튀어나오면 중지하자
    for (i = 0; i < m; i++)
        if (A[m - i - 1] < n - i)
            break;

    i = m - i - 1;
    if (i == -1) {
        printf("-1\n");
        return 0;
    }

    //우선 하나 증가시켜줌
    A[i]++;
    i++;

    //직전의 있는 값 + 1
    for (; i < m; i++)
        A[i] = A[i - 1] + 1;

    for (i = 0; i < m; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;

}