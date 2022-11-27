#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { //노드타입
	element data;
	struct ListNode* link;
} ListNode;
void print_list(ListNode* head) // 틀림(수정해야)
{
	ListNode* p = head->link;
	//비어있으면 print 안함
	if (head == NULL) return;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) 
		head->link = node; // (2) 
	}
	return head; // 변경된헤드포인터를반환한다.
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) 
		head->link = node; // (2) 
		head = node; // (3) 
	}
	return head; // 변경된헤드포인터를반환한다.
}
ListNode* delete_first(ListNode* head)
{
	ListNode* temp;
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n"); 
			return NULL;
	}
	else if (head == head->link) { //즉하나의노드가남았을때
			temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* pev = head;

	if (head == NULL) {
		printf("list empty");
		return 0;
	}
	while (pev->link != head) {
		temp = pev;
		pev = pev->link;
	}
	free(pev);
	return;
}
ListNode* search(ListNode* head, element data)
{
	ListNode* p;
	if (head == NULL)
		return NULL;
	p = head->link;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != head);
	return NULL;
}
ListNode* get_size(ListNode* head)
{
	ListNode* p;
	int cnt = 0;
	if (head == NULL)
		return 0;
	p = head->link;
	cnt++;

	while (p != head) {
		cnt++;
		p = p->link;
	} 
	return cnt;
}
// 원형연결리스트테스트프로그램
int main(void)
{
	ListNode* head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);
	/**/
	return 0;
}