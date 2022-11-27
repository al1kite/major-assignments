# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char a[1000000000];
    scanf("%s", &a);

    int len = strlen(a);

    if (a[len - 1] % 2 == 0)
        printf("1");
    else
        printf("0");

}