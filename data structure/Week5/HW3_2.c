#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;
// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (head == NULL) head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_next(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;
	ListNode* removed;
	if (head == NULL) return NULL;
	if (temp->link == NULL) {
		removed = temp;
		free(removed);
		head = NULL;
	}
	else { // 둘 이상의 노드
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
		free(removed);
	}
	return head;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
ListNode* search(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}
ListNode* concat(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
ListNode* reverse(ListNode* head)
{
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트.
		// r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; // q의 링크 방향을 바꾼다.
	}
	return q;
}
int is_in_list(ListNode* head, element item)
{
	ListNode* temp = head;
	while (temp != NULL) {
		if (temp->data == item) return 1;
		temp = temp->link;
	}
	return 0;
}
int get_length(ListNode* head)
{
	ListNode* temp = head;
	int len = 0;
	while (temp != NULL) {
		len++;
		temp = temp->link;
	}
	return len;
}
int get_total(ListNode* head)
{
	ListNode* temp = head;
	int total = 0;
	while (temp != NULL) {
		total += temp->data;
		temp = temp->link;
	}
	return total;
}
element get_entry(ListNode* head, int pos)
{
	ListNode* temp = head;
	int i;
	if (temp == NULL)
		error("해당 pos의 노드가 비어있습니다.\n");
	for (i = 0; i < pos; i++) {
		temp = temp->link;
		if (temp == NULL)
			error("해당 pos의 노드가 비어있습니다.\n");
	}
	return temp->data;
}
ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;

	if (head->data == key)
		head = delete_first(head);
	else {
		while (temp != NULL) {
			if (temp->data == key) {
				prevTemp->link = temp->link;
				temp->link = NULL;
				free(temp);
				return head;
			}
			prevTemp = temp;
			temp = temp->link;
		}
		printf("해당 key를 가진 노드가 없어 삭제가 불가능합니다.\n");
	}
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	ListNode* temp = head;
	ListNode* prevTemp = head;
	int i;

	if (pos == 0)
		head = insert_first(head, value);
	else {
		for (i = 0; i < pos; i++) {
			prevTemp = temp;
			temp = temp->link;
		}
		p->link = temp;
		prevTemp->link = p;
	}
	return head;
}
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;
	int i;
	if (pos == 0)
		head = delete_first(head);
	else {
		for (i = 0; i < pos; i++) {
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = temp->link;
		free(temp);
	}
	return head;
}
int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3;
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);
	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->30->
	list1 = delete_first(list1);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);
	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	// list2를 출력
	printf("list2 = ");
	print_list(list2);
	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	list2 = delete_last(list2);
	// list2를 출력
	printf("list2 = ");
	print_list(list2);
	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);
	//list3를 출력한다.
	printf("list3 = ");
	print_list(list3);
	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
	list1 = concat(list1, list3);
	//list1을 출력한다.
	printf("list1 = ");
	print_list(list1);
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자
}