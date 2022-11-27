#include <stdio.h>
#include <stdlib.h>

long long H(int n, long long* M) {

    int i;
    long long sum = 0;

    if (M[n] != 0)
        return M[n];

    if (n == 1)
        M[n] = 1;
    else {
        for (i = 1; i < n; i++)
            sum += i * H(n - i, M);
        M[n] = sum;
    }
    return M[n];

}

int main(void) {

    int n;
    long long* M;
    int i;
    scanf("%d", &n);

    M = (long long*)malloc(sizeof(long long) * (n + 1));
    for (i = 0; i <= n; i++)
        M[i] = 0;
    printf("%lld\n", H(n, M));
    free(M);
    return 0;
}