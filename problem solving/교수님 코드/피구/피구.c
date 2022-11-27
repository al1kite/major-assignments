# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int ability[], int n, int* bucket, int bucketSize, int k, int total, int* min) {

    int i, lastIndex, smallest, item;
    int sum = 0;
    int diff;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            sum += ability[bucket[i]];
        diff = (abs(total - 2 * sum));
        if (*min > diff)
            *min = diff;
        return;
    }

    lastIndex = bucketSize - k - 1;

    if (bucketSize == k)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (item = smallest; item < n; item++) {
        bucket[lastIndex + 1] = item;
        pick(ability, n, bucket, bucketSize, k - 1, total, min);
    }


}
int main(void) {

    int n, i;
    int* bucket;
    int* ability;
    int total = 0;
    int min;

    scanf("%d", &n);

    ability = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ability[i]);
        total += ability[i];
    }

    bucket = (int*)malloc(sizeof(int) * n);
    min = total;
    bucket[0] = 0;
    pick(ability, n, bucket, n / 2, n / 2 - 1, total, &min);
    printf("%d\n", min);
    free(bucket);
    return 0;

}