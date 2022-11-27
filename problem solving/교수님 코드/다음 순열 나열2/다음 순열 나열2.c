# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pick(int n, int* picked, int m, int toPick, int* numbers, int* global_flag) {
    int i, j, lastIndex, smallest;

    if (toPick == 0) {
        if (*global_flag == 1) {
            //참조연산을 하기위함이므로 *global_Flag
            for (i = 0; i < m; i++) {
                printf("%d ", picked[i] + 1);
            }
            printf("\n");
            *global_flag = 0;
            return;
        }
        for (i = 0; i < m; i++) {
            if (picked[i] + 1 != numbers[i])
                return;
        }
        *global_flag = 1;
        return;
    }
    lastIndex = m - toPick - 1;
    for (i = 0; i < n; i++) {
        int flag = 0;

        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i)
                flag = 1;

        if (flag == 1)
            continue;

        picked[lastIndex + 1] = i;
        pick(n, picked, m, toPick - 1, numbers, global_flag);
    }
}


int main() {
    int n, * picked, * numbers, i;
    int global_flag = 0;

    scanf("%d", &n);

    numbers = (int*)malloc(sizeof(int) * n);
    picked = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    pick(n, picked, n, n, numbers, &global_flag);

    return 0;



}