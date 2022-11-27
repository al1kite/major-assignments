#include <stdio.h> 
#define MAX_STACK_SIZE 3  // 배열을 이용한 스택은 사이즈의 제한이 있다 
// 스택을 위한 타입 정의 
typedef int element;
typedef char value;
typedef struct {
	element data[MAX_STACK_SIZE];
	value* word[MAX_STACK_SIZE];
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
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수 
void push(StackType* s, element item, value* pharse)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
		s->word[(s->top)] = pharse;
	}
}
// 삭제함수 
void pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
	}
	else
		s->top--;

}
// 피크함수 
void peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
	}
	else {
		s->data[s->top];
		s->word[s->top];
	}
}
//출력함수
void stack_print(StackType* s)
{
	if (is_empty(s))
		printf("<empty>\n");

	for (int i = s->top; i >= 0; i--) {
		printf("[ %d,", s->data[i]);
		printf("%s ]", s->word[i]);
		if (i == s->top)
			printf(" <- top");
		printf("\n");
	} printf("--\n");
}
// 주함수 
void main()
{
	StackType s;
	init(&s);
	stack_print(&s);

	push(&s, 10, "ten");
	stack_print(&s);

	push(&s, 20, "twenty");
	stack_print(&s);

	push(&s, 30, "thirty");
	stack_print(&s);

	push(&s, 40, "fourty");
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	push(&s, 50, "fifty");
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}