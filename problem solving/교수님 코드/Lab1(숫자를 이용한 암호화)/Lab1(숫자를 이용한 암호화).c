# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char alpha[27] = "";
    char encode[27] = "";
    int dist;
    int i;
    int str_len;

    char plain_text[81] = "";
    char encoded_text[81] = "";

    for (i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }

    printf("Enter a distance for encoding:");
    scanf("%d", &dist);

    for (i = 0; i < 26; i++) {
        encode[i] = alpha[i] + dist;
        if (encode[i] > 'Z')
            //소문자일 경우 
            encode[i] = encode[i] - 26;
    }

    printf("---------------------------------------------------------\n");
    printf("alphabet: \t%s\n", alpha);
    printf("encoded:  \t%s\n", encode);
    printf("---------------------------------------------------------\n\n");

    printf("Enter a senetence to encode:");

    //newline char 처리
    fgets(plain_text, 80, stdin);
    //진짜 의미 
    fgets(plain_text, 80, stdin);

    //맨 마지막에 \n이 포함되어 있다 
    printf("%s", plain_text);


    str_len = strlen(plain_text);

    for (i = 0; i < str_len; i++) {
        if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            int idx = plain_text[i] - 'A';
            encoded_text[i] = encode[idx];
        }
        else
            encoded_text[i] = plain_text[i];
    }
    printf("original sentence: \t%s", plain_text);
    printf("encoded sentence:  \t%s", encoded_text);

}