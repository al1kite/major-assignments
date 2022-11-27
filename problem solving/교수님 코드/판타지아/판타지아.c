# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {

    int n, m;
    int rootN = 1;
    int rootM = 1;
    int pLN = 0;
    int pLM = 1;
    int pRN = 1;
    int pRM = 0;

    //N은 분자 M은 분모

    scanf("%d %d", &n, &m);

    while (n * rootM != m * rootN) {
        if (n * rootM < m * rootN) {
            pRN = rootN;
            pRM = rootM;
            printf("L");
        }
        else {
            pLN = rootN;
            pLM = rootM;
            printf("R");
        }
        rootN = pRN + pLN;
        rootM = pRM + pLM;
    }
    printf("\n");

}