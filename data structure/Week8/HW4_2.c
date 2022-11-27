#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode* get_maximum(TreeNode* node);
TreeNode* get_miminum(TreeNode* node);
TreeNode* insert(TreeNode* node, int data)
{
	if (node == NULL) {
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->data = data;
		newNode->left = NULL; 
		newNode->right = NULL;
		 
		return newNode;
	}
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	return node;
}
TreeNode* delete(TreeNode* node, int data)
{
	if (node == NULL) 
		return node;
	if (data < node->data) node->left = delete(node->left, data);
	else if (data > node->data)
		node->right = delete(node->right, data);
	else { 
		if (node->left == NULL) {
			TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		TreeNode* temp = get_maximum(node->left);
		node->data = temp->data;
		node->left = delete(node->left, temp->data);
	}
	return node;
}
TreeNode* search(TreeNode* node, int data)
{
	if (node == NULL)
		return NULL;
	if (node->data == data)
		return node;
	else {
		if (node->data > data)
			return search(node->left, data);
		else
			return search(node->right, data);
	}
}
void print(TreeNode* root) // p274 �ڵ� ����
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	print(root->left);
	print(root->right);
}
int height(TreeNode* node) {
	int high = 0;
	if (node != NULL)
		high = 1 + max(height(node->left), height(node->right)); 
	return high; 
}
int count(TreeNode* node) {
	int cnt = 0;
	if (node != NULL)
		cnt = 1 + count(node->left) + count(node->right); 
	return cnt;
}
TreeNode* get_maximum(TreeNode* node) {
	TreeNode* current = node;

	while (current->right != NULL) {
		current = current->right;
	}

	return current;
}
TreeNode* get_miminum(TreeNode* node) {
	TreeNode* current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}
int main() {
	TreeNode* root = NULL;
	char check = 0;
	int key;
	do {
		printf("Enter i<nset>, d<elete>, s<earch>, p<rint>, h<eight>, c<ount>, m<ax>, n<min>, q<uit>: ");
		scanf(" %c", &check);

		if (check == 'i') {
			printf("������ key�� �Է�: ");
			scanf("%d", &key);
			root = insert(root, key); 
		}
		else if (check == 'd') {
			printf("������ key�� �Է�: ");
			scanf("%d", &key);
			root = delete(root, key);
		}
		else if (check == 's') {
			printf("Ž���� key�� �Է�: ");
			scanf("%d", &key);
			printf("%s\n", search(root, key) ? "����" : "����");
		}
		else if (check == 'p')
			print(root);
		else if (check == 'h')
			printf("Ʈ���� ���̴� %d\n", height(root));
		else if (check == 'c')
			printf("����� ������ %d\n", count(root));
		else if (check == 'm') {
			TreeNode* temp = get_maximum(root);
			printf("���� ū ���� %d\n", temp->data);
		}
		else if (check == 'n') {
			TreeNode* temp = get_miminum(root);
			printf("���� ���� ���� %d\n", temp->data);
		}

	} while (check != 'q');
}
