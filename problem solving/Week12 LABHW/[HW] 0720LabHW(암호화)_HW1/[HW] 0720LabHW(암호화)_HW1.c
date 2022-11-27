#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
void makeCode(char code[], int dist) { 
	char alpha[27] = ""; 
	int i;
	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	for (i = 0; i < 26; i++) {
		code[i] = alpha[i] + dist;
		if (code[i] > 'Z')
			code[i] = code[i] - 26;
	}
	code[i] = '\0'; 
	printf("%s\n", alpha);
}
void printCode(char code[]) { 
	//for (int i = 0; code[i] != '\0'; i++) 
		//printf("%c", code[i]);
	printf("%s\n", code);
}
void encode(char code[], char s[], char e[]) { 
	int str_len = strlen(s);
	int i;

	for (i = 0; i < str_len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			int idx = s[i] - 'A';
			e[i] = code[idx]; 
		}
		else
			e[i] = s[i];
	}
	e[i] = '\0';
}
void decode(char code[], char e[], char d[]) { 
	int str_len = strlen(e);
	int idx, i;

	char alpha[27] = "";
	for (int i = 0; i < 26; i++)
		alpha[i] = 'A' + i;

	for (i = 0; i < str_len; i++) {
		if (e[i] >= 'A' && e[i] <= 'Z') {
			for (int j = 0; j < 26; j++)
				if (e[i] == code[j])
					idx = j; 
			d[i] = alpha[idx];   
		}
		else
			d[i] = e[i];
	}
	d[i] = '\0';

}
int main(void)
{
	char code[27]; // code[0]부터 'A'의 암호화문자를 넣음
	int distance;
	char sentence[80];
	char encodedSentence[80];
	char decodedSentence[80];
	printf("Enter a distance for encoding:");
	scanf("%d", &distance);
	makeCode(code, distance);
	printCode(code);
	fflush(stdin);
	printf("Enter a sentence to encode:");
	fgets(sentence, sizeof(sentence), stdin);
	fgets(sentence, sizeof(sentence), stdin); 
	encode(code, sentence, encodedSentence);
	printf("original sentence:\t");
	puts(sentence);
	printf("encoded sentence:\t");
	puts(encodedSentence);
	decode(code, encodedSentence, decodedSentence);
	printf("decoded sentence:\t");
	puts(decodedSentence);
}