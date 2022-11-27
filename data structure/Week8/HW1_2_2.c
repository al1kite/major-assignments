#include <stdio.h>
#include <malloc.h>
// 스택을 위한 타입 정의
typedef struct {
	int num;
	char numString[100];
}element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// 피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
void print_stack(LinkedStackType* s)
{
	if (is_empty(s))
		printf("(empty)\n");
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("[%d, %s]", p->data.num, p->data.numString); 
		if (p == s->top)
			printf("<-top");
		printf("\n");
	}
	printf("-- \n");
}
// 주 함수
void main()
{
	LinkedStackType s;
	element e;
	init(&s); print_stack(&s);
	e.num = 10;
	strcpy(e.numString, "ten");
	push(&s, e); print_stack(&s);
	e.num = 20;
	strcpy(e.numString, "twenty");
	push(&s, e); print_stack(&s);
	e.num = 30;
	strcpy(e.numString, "thirty");
	push(&s, e); print_stack(&s);
	e.num = 40;
	strcpy(e.numString, "fourty");
	push(&s, e); print_stack(&s);
	pop(&s); print_stack(&s);
	e.num = 50;
	strcpy(e.numString, "fifry");
	push(&s, e); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}
