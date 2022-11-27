# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pick(int* items, int n, int* bucket, int bucketSize, int k, int* num1, int* num2) {

    int i, lastIndex, smallest, item;
    int count = 0;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            num2[i] = num1[i] + items[bucket[i]];

        if (isSequence(num2, bucketSize))
            return 1;
        return 0;
    }
    lastIndex = bucketSize - k - 1;

    smallest = 0;

    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        count += pick(items, n, bucket, bucketSize, k - 1, num1, num2);
    }
    return count;
}


int isSequence(int* a, int size) {

    if (size <= 2)
        return 1;

    int diff = a[1] - a[0];
    for (int i = 0; i < size - 1; i++)
        if (a[i + 1] - a[i] != diff)
            return 0;
    return 1;
}

void printSequence(int* a, int size) {

    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int calOperation(int* a1, int* a2, int size) {

    int count = 0;
    for (int i = 0; i < size; i++)
        if (a1[i] != a2[i])
            count++;
    return count;

}


int main() {

    int items[3] = { -1, 0, 1 };
    int n;
    int* bucket;
    int* num1;
    //num2에 원복
    int* num2;

    printf("개수 입력");
    scanf("%d", &n);

    bucket = (int*)malloc(sizeof(int) * n);
    num1 = (int*)malloc(sizeof(int) * n);
    num2 = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &num1[i]);
    printf("%d\n", pick(items, 3, bucket, n, n, num1, num2));

    free(bucket);
    free(num1);
    free(num2);
    return 0;


}