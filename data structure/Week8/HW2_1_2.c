//LinkedQueue.c
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[1000];
}element;// ����� Ÿ��
typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct { // ť ADT ����
	QueueNode* front, * rear;
	int cnt;
} LinkedQueueType;
// �ʱ�ȭ �Լ�
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) // �׻� ����, ��ȭ�����϶��� ����. ���Ḯ��Ʈ�� �����Ͽ����Ƿ�
{
	return 0;
}
// ���� �Լ�
int enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp->data = item; // ������ ����
		temp->link = NULL; // ��ũ �ʵ带 NULL
		if (is_empty(q)) { // ť�� �����̸�
			q->front = temp;
			q->rear = temp;
		}
		else { // ť�� ������ �ƴϸ�
			q->rear->link = temp; // ������ �߿�
			q->rear = temp;
		}
		q->cnt++;
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // �������
		printf("ť�� ��� �����ϴ�");
	else {
		item = temp->data; // �����͸� ������.
		q->front = q->front->link; // front �� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) // ���� ����
			q->rear = NULL;
		free(temp); // �����޸� ����
		q->cnt--;
		return item; // ������ ��ȯ
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data);
	printf("\n");
}
void match(LinkedQueueType* q, LinkedQueueType* p) {

	if (is_empty(p))
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
	else {
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s \n", q->front, p->rear);
		dequeue(q);
		dequeue(p);
	}
}
int main(void) {
	printf("���� �ּ� ���α׷��Դϴ�.\n");

	LinkedQueueType manQ, womanQ;
	manQ.cnt = 0, womanQ.cnt = 0;
	element newMan, newWoman;
	char num = 0, sex = 0;
	char put_name[1000];
	init(&manQ);
	init(&womanQ);

	while (1) {
		printf("i<nsert, �� �Է�>, c<heck, ����� üũ>, q<uit>:");
		scanf("%c", &num);

		if (num == 'q')
			break;
		else if (num == 'i') {

			printf("�̸��� �Է�: ");
			scanf("%s", &put_name);
			getchar();

			printf("������ �Է�:<m or f>: ");
			scanf("%c", &sex);

			if (sex == 'm') {
				strcpy(newMan.name, put_name);
				if (enqueue(&manQ, newMan))
					match(&manQ, &womanQ);
			}
			else if (sex == 'f') {
				strcpy(newWoman.name, put_name);
				if (enqueue(&womanQ, newWoman))
					match(&womanQ, &manQ);
			}
			else
				printf("������ m or f �߿��� �Է����ּ���.");
		}
		else if (num == 'c') {
			printf("���� ����� %d��: ", manQ.cnt);
			print_queue(&manQ);

			printf("���� ����� %d��: ", womanQ.cnt);
			print_queue(&womanQ);
		}
		getchar();

	}
}