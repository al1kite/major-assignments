#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int main() {
    //C6386 ���� �ʱ�ȭ�� ���� ������ ��� ���Ҵ�.
    int n = 0, i, j, temp = 0;
    srand((unsigned)time(NULL));
 
    printf("Enter a number: ");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    //�޸� �Ҵ� ���� �� ����� ������ ��� ���Ҵ�.
    if (a == NULL) { return 0; }
    
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        printf("%d ", a[i]);
    } printf("\n");

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j <  n - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    }

    printf("���ĵ� ��:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);
    return 0;
}