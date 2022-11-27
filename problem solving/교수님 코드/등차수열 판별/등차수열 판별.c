# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSequence(int* a, int size) {

    if (size <= 2)
        return 1;

    int diff = a[1] - a[0];
    for (int i = 0; i < size - 1; i++)
        if (a[i + 1] - a[i] != diff)
            return 0;
    return 1;
}

int main() {

    int n; int* a;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", isSequence(a, n));
    free(a);
    return 0;


}