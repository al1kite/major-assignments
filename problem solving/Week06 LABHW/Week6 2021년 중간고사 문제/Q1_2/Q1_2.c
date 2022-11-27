#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int* num1;
int* num2; 
void calculateReverse(char n[], int num[]);
int main(void) {
    char a[1000] = {'\0',}, b[1000] = { '\0', }; 
    int cnt = 0, carry = 0, sum = 0, s; 
    int num1[1000] = {0}, num2[1000]={0};

    scanf("%s %s", &a, &b); 
    int size1 = (unsigned int)strlen(a);
    int size2 = (unsigned int)strlen(b);
    if (size1 > size2)
        s = size1; 
    else
        s = size2; 

    calculateReverse(a, num1);  
    calculateReverse(b, num2);

    for (int i = 0; i <= s; i++) {
        sum = num1[i] + num2[i] + carry; 
        carry = sum / 10;

        if (carry == 1)
            cnt++;
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