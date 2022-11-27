# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int minusCarryConut(int n1, int n2) {

    int carry = 0, totalCarry = 0;
    int calNum1, calNum2;
    int digit;

    while (n1 > 0) {
        calNum1 = n1 % 10;
        calNum2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;


        if ((digit = calNum1 - calNum2 - carry) < 0) {
            totalCarry++;
            carry = 1;
        }
        else
            carry = 0;
    }

    return totalCarry;

}

int main(void) {

    int num1, num2;
    int carry = 0;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", minusCarryConut(num1, num2));
    return 0;

}