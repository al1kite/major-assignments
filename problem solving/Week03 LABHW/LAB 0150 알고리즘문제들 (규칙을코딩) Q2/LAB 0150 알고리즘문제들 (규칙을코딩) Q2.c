/*--- overflow ---*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long long calculateReverse(unsigned long long n);
// �����÷ο�� testcase 2�� �ȵ��ư�. int ������ ���� �� unsigned long long���� �ٲ㼭 �ذ������ ��.
int main(void) {
    int n, num = 0, cnt = 0;
    scanf("%d", &n);
    unsigned long long r, palindrome = n;

    while (cnt < 1000) {

        r = calculateReverse(palindrome);
        palindrome = palindrome + r;
        cnt++;
        if (palindrome == calculateReverse(palindrome)) {
            printf("%d %lld ", cnt, palindrome);
            break;
        }
    }
    if (cnt == 1000)
        printf("NaN");
    return 0;
}
unsigned long long calculateReverse(unsigned long long n)
{
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}