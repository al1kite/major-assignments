#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int main() {
    //C6386 ���� �ʱ�ȭ�� ���� ������ ��� ���Ҵ�.
    int n = 0;
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

    free(a); 
    return 0; 
}