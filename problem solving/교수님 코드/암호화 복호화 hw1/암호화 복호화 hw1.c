# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

    char alpha[27] = "";
    char encode[27] = "";
    char decode[27] = "";
    int dist;
    int i;
    int str_len;

    char plain_text[81] = "";
    char encoded_text[81] = "";
    char decoded_text[81] = "";

    for (i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }

    printf("Enter a distance for encoding:");
    scanf("%d", &dist);

    for (i = 0; i < 26; i++) {
        encode[i] = alpha[i] + dist;
        if (encode[i] > 'Z')
            encode[i] = encode[i] - 26;
    }

    printf("---------------------------------------------------------\n");
    printf("alphabet: \t%s\n", alpha);
    printf("encoded:  \t%s\n", encode);
    printf("---------------------------------------------------------\n\n");

    printf("Enter a senetence to encode:");
    fgets(plain_text, 80, stdin);
    fgets(plain_text, 80, stdin);

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


    for (i = 0; i < str_len; i++) {
        if (encoded_text[i] >= 'A' && encoded_text[i] <= 'Z') {
            int idx = plain_text[i] + 'A';
            decoded_text[i] = alpha[idx];
        }
        else
            decoded_text[i] = plain_text[i];
    }
    printf("decoded sentence:  \t%s", decoded_text);
}