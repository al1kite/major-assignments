# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char a[10];
    char b[10];
    int carry = 0;
    int cnt = 0;
    int sum = 0;

    scanf("%s %s", &a, &b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    while (len_a != 0 || len_b != 0) {

        int x = 0; int y = 0;
        if (len_a > 0) {
            x = a[len_a - 1] - '0';
            len_a--;
        }
        if (len_b > 0) {
            y = b[len_b - 1] - '0';
            len_b--;
        }

        int sum = x + y + carry;

        if (sum >= 10) {
            carry = 1;
            cnt++;
        }
        else
            carry = 0;

    }

    printf("%d", cnt);
}