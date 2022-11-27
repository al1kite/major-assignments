#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    long long int n, num = 0, k = 0, index = 0, carry = 1, del = 1, t = 0;
    scanf("%lld", &n);

    //long long int* a = (long long int*)malloc(sizeof(long long int) * n);
    int a[1000]; 

    for (int i = 1; i < n + 1; i++) {
        t = i;
        while (t > 0) {
            t = t / 10;
            k++;
        }
        for (int j = 0; j < k - 1; j++)
            del *= 10;
        if (index == n)
            carry = del;
        t = i;
        while (del > 0) {
            if (del > 1) {
                a[index] =  t / (del * 10) - t / del;
            }
            else
                a[index] = t / del; 
            del /= 10;
            index++;
        }
        del = 1;
        k = 0;
    }

    printf("%lld", a[n - 1]);

}