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
// ���� �ʱ�ȭ �Լ�
void init(StackType* s) 
{
	s->top = -1;
}
// ���� ���� ���� �Լ� 
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ� 
int is_full(StackType* s)
{
	return (s->top == (MAX_STRING - 1));
}
// �����Լ� 
void push(StackType* s, char item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// �����Լ� 
char pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
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
		printf("palindrome �Դϴ�.\n"); 
	else 
		printf("palindrome �� �ƴմϴ�.\n");
}