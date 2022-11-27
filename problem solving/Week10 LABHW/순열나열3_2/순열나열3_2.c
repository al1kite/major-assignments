#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void testPrint(int* a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void selectionSortNew(int A[], int left, int n) {
    // 코드 작성
    int i, j, temp = 0, min;

    for (i = left; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (A[min] > A[j])
                min = j;
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}
int main(void) {
    int i, n, pivot, temp, max = 0, index = -1, cnt = 0;
    int a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (max < a[i])
            max = a[i];
    }

    for (i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1])
            break;
        cnt++; 
    }
    if (i == n - 1)
        pivot = n - 2;
    else
        pivot = i;

    for (int i = pivot + 1; i < n; i++) {
        if (a[pivot] < a[i] && a[i] <= max)
            index = i;
        max = a[i];
    }
    temp = a[pivot];
    a[pivot] = a[index];
    a[index] = temp;

    if (cnt == n - 1)
        printf("-1");
    else {
        selectionSortNew(a, pivot + 1, n);
        testPrint(a, n);
    }

    return 0;
}