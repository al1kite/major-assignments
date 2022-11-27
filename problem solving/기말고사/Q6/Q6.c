#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
int main() {
	char alpha[27] = "";
	char encode[27] = "";
	char plain_text[1000] = "";
	char encoded_text[1000] = "";

	for (int i = 0; i < 26; i++)
		alpha[i] = 'A' + i;
	//scanf("%d", &dist);

	for (int i = 0; i < 26; i++) {
		encode[i] = alpha[25 - i];
	}
	scanf("%s", &plain_text);

	for (int i = 0; plain_text[i] != '\0'; i++) {
		if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
			int idx = plain_text[i] - 'A';
			encoded_text[i] = encode[idx];
		}
		else
			encoded_text[i] = plain_text[i];

	}
	printf("%s", encoded_text);

}