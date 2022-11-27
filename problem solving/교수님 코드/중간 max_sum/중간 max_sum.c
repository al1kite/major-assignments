# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int left_max_sum(int A[], int left, int right) {
    int i, max_sum, sum;
    sum = A[right];
    max_sum = A[right];

    for (i = right - 1; i >= left; i--) {
        sum = sum + A[i];
        if (max_sum < sum)
            max_sum = sum;
    }

    return max_sum;
}

int right_max_sum(int A[], int left, int right) {
    int i, max_sum, sum;
    sum = A[left];
    max_sum = A[left];

    for (i = left + 1; i <= right; i++) {
        sum = sum + A[i];
        if (max_sum < sum)
            max_sum = sum;
    }
    return max_sum;
}

int max_sub_array(int* A, int p, int r) {
    int mid;
    int V1, V2, V3, V3_1, V3_2;
    int ret;

    if (p == r)
        return A[p];

    mid = (p + r) / 2;

    V1 = max_sub_array(A, p, mid);
    V2 = max_sub_array(A, mid + 1, r);

    V3_1 = right_max_sum(A, mid + 1, r);
    V3_2 = left_max_sum(A, p, mid);
    V3 = V3_1 + V3_2;

    ret = V1 > V2 ? V1 : V2;
    ret = ret > V3 ? ret : V3;

    return ret;

}

int main() {

    int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    printf("max_value = %d\n", max_sub_array(A, 0, 8));

}