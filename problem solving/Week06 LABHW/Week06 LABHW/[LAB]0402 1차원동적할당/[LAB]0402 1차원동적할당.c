#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int main() {
    //C6386 변수 초기화로 버퍼 오버런 경고를 막았다.
    int n = 0;
    srand((unsigned)time(NULL));

    printf("Enter a number: ");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    //메모리 할당 실패 시 종료로 역참조 경고를 막았다.
    if (a == NULL) { return 0; }

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        printf("%d ", a[i]);
    } printf("\n");

    free(a); 
    return 0; 
}