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

	FILE* fp1, * fp2; 

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

	if ((fp1 = fopen("original.txt", "rt")) == NULL) {
		printf("파일 오픈 에러1");
		exit(1);
	}
	if ((fp2 = fopen("encoded.txt", "wt")) == NULL) {
		printf("파일 오픈 에러2");
		exit(1);
	}

	int str_len = strlen(plain_text); 

	while (fgets(plain_text, sizeof(plain_text), fp1) != NULL) {
		for (int i = 0; i < str_len; i++) {
			if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
				int idx = plain_text[i] - 'A';
				encoded_text[i] = encode[idx];
			}
			else
				encoded_text[i] = plain_text[i];

		}
		fputs(encoded_text, fp2);  
	}
	fclose(fp1);
	fclose(fp2);


}