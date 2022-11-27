#include <stdio.h>

int main(void) {
    int a;
    int b;
    int num1, num2, cnt = 0, carry = 0, sum;

    scanf("%d %d", &a, &b);

    while (a != 0 || b != 0) {
        num1 = a % 10;
        num2 = b % 10;

        a /= 10;
        b /= 10;

        sum = num1 + num2 + carry;
        carry = sum / 10;

        if (carry == 1)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}