#include <stdio.h>
# define _CRT_SECURE_NO_WARNINGS

void print_k_ary(int n, int k) {

    if (n != 0) {
        print_k_ary(n / k, k);
        printf("%d ", n % k);
    }
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    print_k_ary(n, k);
    printf("\n");
    return 0;

}