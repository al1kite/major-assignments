#include <stdio.h>
#include <malloc.h>
// ������ ���� Ÿ�� ����
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
// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) // Stack �������� �ϳ��� ���ܵξ����� �׻� ������ ��ȯ. �� �� ������ ���� ����
{
	return 0;
}
// ���� �Լ�
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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
// ��ũ �Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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
// �� �Լ�
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
