#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//스택을 위한 타입 정의 
typedef TreeNode* element;

typedef struct StackNode { //Node
	element data;
	struct StackNode* link;
} StackNode;

typedef struct { // Stack
	StackNode* top;
} LinkedStackType;

//여기에 연결된 스택 프로그램 함수를 추가 
void init(LinkedStackType* stack) {
	stack->top = NULL;
}
int is_empty(LinkedStackType* stack) {
	return stack->top == NULL;
}
void push(TreeNode* p, LinkedStackType* stack) //Stack
{
	if (p != NULL) {
		StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
		temp->data = p;
		temp->link = stack->top;
		stack->top = temp;
	}
}
TreeNode* pop(LinkedStackType * stack)
{
	TreeNode* p = NULL;
	if (!is_empty(stack)) {
		StackNode* temp = stack->top;
		p = temp->data;
		stack->top = stack->top->link;
		free(temp);
	} return p; 
}
void inorder_iter(TreeNode* root)
{
	//여기에 연결된 스택을 이용한 반복적 순회 관련 코드 추가 
	LinkedStackType* stack = (LinkedStackType*)malloc(sizeof(LinkedStackType));
	while (1) {
		for (; root; root = root->left)
			push(root, stack);
		root = pop(stack);  
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}