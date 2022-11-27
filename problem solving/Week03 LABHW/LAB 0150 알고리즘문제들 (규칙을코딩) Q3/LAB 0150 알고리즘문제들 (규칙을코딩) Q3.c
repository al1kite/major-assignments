#include <stdio.h>

int main(void) {
    int n, c = 1, cnt = 1;
    scanf("%d", &n);
    while (1) {
        if (c % n == 0)
            break;
        c = c * 10 + 1;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}