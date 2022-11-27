# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//사실은 1,2,3,4였다. 
int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int target, int* count) {

    int i, lastIndex, smallest;
    int total = 0;
    int cnt = 0;

    lastIndex = bucketSize - k - 1;
    for (i = 0; i < lastIndex; i++) {
        total += items[bucket[i]];
    }

    if (total == target) {
        *count = *count + 1;
        return 1;
    }

    if (total > target)
        return 0;

    if (k == 0)
        return 0;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1;

    for (i = smallest; i < itemSize; i++) {
        bucket[lastIndex + 1] = i;
        cnt = cnt + pick(items, itemSize, bucket, bucketSize, k - 1, target, count);
    }


}

int main(void) {

    int items[] = { 1, 2 };
    int* bucket;
    int n;
    int count = 0;

    printf("수를 입력 ");
    scanf("%d", &n);

    bucket = (int*)malloc(sizeof(int) * n);

    printf("%d\n", pick(items, n / 2, bucket, n, n, n, &count));
    free(bucket);
    return 0;

}