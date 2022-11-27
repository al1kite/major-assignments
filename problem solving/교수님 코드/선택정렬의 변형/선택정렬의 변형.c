# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int n) {
    int i, j, max_index, temp;

    for (i = 0; i < n - 1; i++) {
        max_index = 0;
        for (j = 1; j < n - i; j++)
            if (arr[max_index] < arr[j])
                max_index = j;
        temp = arr[max_index];
        arr[max_index] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void selectionSortNew(int A[], int left, int n) {
    selection_sort(&A[left], n - left);
}

void testPrint(int* a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {

    int* rand_array;
    int n, i, k;

    scanf("%d", &n);

    rand_array = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        scanf("%d", &rand_array[i]);
    }

    scanf("%d", &k);
    selectionSortNew(rand_array, k, n);
    testPrint(rand_array, n);

}