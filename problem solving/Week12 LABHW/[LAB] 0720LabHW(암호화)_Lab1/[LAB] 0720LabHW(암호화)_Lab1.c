#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
int main() {
	char alpha[27] = "";
	char encode[27] = "";
	char plain_text[81] = "";
	char encoded_text[81] = "";
	int dist;

	for (int i = 0; i < 26; i++)
		alpha[i] = 'A' + i;
	scanf("%d", &dist);

	for (int i = 0; i < 26; i++) {
		encode[i] = alpha[i] + dist;
		if (encode[i] > 'Z')
			encode[i] = encode[i] - 26;
	}
	printf("%s\n", alpha);
	printf("%s\n", encode);

	fgets(plain_text, 80, stdin);
	fgets(plain_text, 80, stdin);

	//printf("%s", plain_text);
	int str_len = strlen(plain_text);

	for (int i = 0; i < str_len; i++) {
		if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
			int idx = plain_text[i] - 'A';
			encoded_text[i] = encode[idx];
		}
		else
			encoded_text[i] = plain_text[i];

	}
	printf("%s", plain_text);
	printf("%s", encoded_text);

}