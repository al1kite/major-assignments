#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING 100
typedef struct {
	char data[MAX_STRING]; 
	int top;
} StackType;
// 스택 초기화 함수
void init(StackType* s) 
{
	s->top = -1;
}
// 공백 상태 검출 함수 
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수 
int is_full(StackType* s)
{
	return (s->top == (MAX_STRING - 1));
}
// 삽입함수 
void push(StackType* s, char item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// 삭제함수 
char pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int palindrome(char str[]) 
{
	StackType s;
	init(&s);
	char ch;
	int boolen = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
		ch = str[i];
		if (ch >= 'a' && ch <= 'z') {
			push(&s, ch);
		}
	}
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] != pop(&s)) {
				boolen = 1;
				break;
			}
		}
	}
	return boolen; 
}

int main(void)
{
	char word[MAX_STRING]; 
	printf("Enter a word to check palindrome: "); 
	scanf("%s", word);  

	if (palindrome(word)) 
		printf("palindrome 입니다.\n"); 
	else 
		printf("palindrome 이 아닙니다.\n");
}