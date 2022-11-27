#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int cnt = 0;
void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money);
void pick(int* items, int itemsize, int* bucket, int bucketSize, int k, int money)
{
    int i, lastIndex, smallest;
    int sum = 0;

    if (k == 0) {
        for (i = 0; i < bucketSize; i++)
            sum += items[bucket[i]];

        if (sum == money) {
            for (i = 0; i < bucketSize; i++) {
                if (bucket[i] > 0);
                //printf("%d ", items[bucket[i]]);

            }
            //printf("\n");
            cnt ++;
        }
        return;
    }
}
int main(void)
{
        int items[] = { 0, 50, 10, 500, 100 };
        int* bucket;
        int money, n;

        scanf("%d", &money);
        n = money / 10;
        bucket = (int*)malloc(sizeof(int) * n);

        pick(items, 5, bucket, n, n, money);

        printf("%d", cnt);
}
