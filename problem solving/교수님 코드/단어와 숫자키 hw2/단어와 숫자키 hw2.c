# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void remove_duplicated_char(char* word) {

    int i, j, k;

    for (i = 0; i < strlen(word); i++)
    {
        for (j = i + 1; word[j] != '\0'; j++)
        {
            if (word[j] == word[i])
            {
                for (k = j; word[k] != '\0'; k++)
                {
                    word[k] = word[k + 1];
                }
            }
        }
    }

}
void printCode(char code[]) {

    for (int i = 0; code[i] != '\0'; i++)
        printf("%c", code[i]);
}
void makeCode(char code[], int distance, char key[]) {

    int i;
    for (i = 0; i < 5; i++) {
        code[i] = 'V' + i;

    }
    for (i = 0; i < sizeof(key); i++) {
        code[distance] = key[i];
        distance++;
    }
    strcat(code, "BCDEFHJKLQSTU");



}
int main() {

    char alpha[27] = "";
    char encode[27] = "";
    char key[30] = "";
    int dist;
    int i;
    int str_len;

    char plain_text[81] = "";
    char encoded_text[81] = "";

    for (i = 0; i < 26; i++) {
        alpha[i] = 'A' + i;
    }

    printf("Enter a word to use for encoding(대문자로된 단어입력):");
    scanf("%s", &key);
    remove_duplicated_char(key);
    printf("Enter a distance for encoding:");
    scanf("%d", &dist);

    printf("---------------------------------------------------------\n");
    printf("alphabet:  \t");
    printCode(alpha);
    printf("\nencoded:  \t");
    makeCode(encode, dist, key);
    printCode(encode);
    printf("\n---------------------------------------------------------\n\n");

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

}