#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int main() {
    int n = 0, i, j, temp, max = 0;
    int check = 0;

    srand((unsigned)time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    //�޸� �Ҵ� ���� �� ����� ������ ��� ���Ҵ�.
    if (a == NULL) { return 0; }

    printf("�ʱ� :  ");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%2d  ", a[i]);
    } printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        printf("i = %2d: ", i);
        for (int k = 0; k < n; k++)
            printf("%2d  ", a[k]);
        printf("\n");

        for (int k = 0; k < n - 1; k++)
            if (a[k + 1] < a[k])
                break;
            else
                check++;
        if (check == n - 1)
            break;
        check = 0;
    }
    printf("���� ��: ");
    for (int k = 0; k < n; k++)
        printf("%2d ", a[k]);
    return 0;
}