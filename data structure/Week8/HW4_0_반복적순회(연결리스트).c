#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//������ ���� Ÿ�� ���� 
typedef TreeNode* element;

typedef struct StackNode { //Node
	element data;
	struct StackNode* link;
} StackNode;

typedef struct { // Stack
	StackNode* top;
} LinkedStackType;

//���⿡ ����� ���� ���α׷� �Լ��� �߰� 
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
	//���⿡ ����� ������ �̿��� �ݺ��� ��ȸ ���� �ڵ� �߰� 
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
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");

	return 0;
}