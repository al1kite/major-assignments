#include <stdlib.h> 
#include <string.h>
int* num1;
int* num2;
void calculateReverse(char n[], int num[]);
int main(void) {
    char a[1000] = { '\0', }, b[1000] = { '\0', };
    int cnt = 0, carry = 0, sum = 0;
    int num1[1000] = { 0 }, num2[1000] = { 0 };

    scanf("%s %s", &a, &b);
    int size = (unsigned int)strlen(a);

    calculateReverse(a, num1);
    calculateReverse(b, num2);

    for (int i = 0; i < size; i++) {
        sum = num1[i] - num2[i] + carry;
        if (sum < 0) {
            cnt++;
            carry = -1;
        }
    }

    printf("%d", cnt);
    return 0;
}
void calculateReverse(char n[], int num[])
{
    int size = (unsigned int)strlen(n);
    for (int i = 0; i < size; i++) {
        num[i] = ((int)(n[size - i - 1]) - 48);
    }
}