#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int main() {
    //C6386 ���� �ʱ�ȭ�� ���� ������ ��� ���Ҵ�.
    int n = 0, i, j, temp = 0, min; 
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

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }


    printf("���ĵ� ��:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);
    return 0;
}