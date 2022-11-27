#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int cnt = 0;
int items[] = { 10, 50, 100, 500 };
void pick(int n, int* bucket, int bucketSize, int k, int money) {
    int i, lastIndex, smallest;
    int sum = 0;

    lastIndex = bucketSize - k - 1;
    for (i = 0; i < lastIndex + 1; i++)
        sum += items[bucket[i]];

    if (sum == money) {
        cnt++;
        return;
    }

    if (sum > money) 
        return;

    if (k == bucketSize)
        smallest = 0;
    else
        smallest = bucket[lastIndex];

    for (i = smallest; i < n; i++) {
        bucket[lastIndex + 1] = i;
        pick(n, bucket, bucketSize, k - 1, money); 
    }
    return;

}

int main(void)
{
    int* bucket;
    int money, n;

    scanf("%d", &money);
    n = money / 10;
    bucket = (int*)malloc(sizeof(int) * n);
    if (money % 10 == 0 && money != 0)
        pick(4, bucket, n, n, money); 

    printf("%d", cnt);
}