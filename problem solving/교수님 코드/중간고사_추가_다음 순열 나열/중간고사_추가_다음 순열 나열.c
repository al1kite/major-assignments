# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection_sort(int* arr, int n) {
    int i, j, max_index, temp;

    for (i = 0; i <= n; i++) {
        max_index = 0;
        for (j = 1; j < n - 1; j++)
            if (arr[max_index] < arr[j])
                max_index = j;

        temp = arr[max_index];
        arr[max_index] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}


int main() {
    int n, i, j, k, pivot;
    int* numbers;

    scanf("%d", &n);
    numbers = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    //A[n-1] < A[n-2]

    for (i = n - 1; i >= 1; i--) {
        //내림차순 sequence가 깨졌다 
        if (numbers[i] > numbers[i - 1])
            break;
    }
    if (i == 0) {
        printf("%d\n", -1);
    }

    pivot = i - 1;
    for (; i < n; i++)
        if (numbers[pivot] > numbers[i])
            break;

    j = numbers[pivot];
    numbers[pivot] = numbers[i - 1];
    numbers[i - 1] = j;

    selection_sort(&numbers[pivot + 1], n - pivot - 1);

    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

}