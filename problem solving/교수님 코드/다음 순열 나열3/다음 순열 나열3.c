# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n, m;
    int i;
    int* A;

    //ũ�� 1~n, m��
    scanf("%d %d", &n, &m);

    A = (int*)malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
        scanf("%d", &A[i]);

    //7, 6, 5, 4 ���� ���� ���� Ƣ����� ��������
    for (i = 0; i < m; i++)
        if (A[m - i - 1] < n - i)
            break;

    i = m - i - 1;
    if (i == -1) {
        printf("-1\n");
        return 0;
    }

    //�켱 �ϳ� ����������
    A[i]++;
    i++;

    //������ �ִ� �� + 1
    for (; i < m; i++)
        A[i] = A[i - 1] + 1;

    for (i = 0; i < m; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;

}