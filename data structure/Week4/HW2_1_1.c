#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
typedef struct {
	char name[1000];
}element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
//�ʱ�ȭ�Լ�
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
//������°����Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
//��ȭ���°����Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//�����Լ�
int enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		printf("���� ����ڰ� �����ϴ�. ����ڰ� �� á���� ���� ��ȸ�� �̿�.\n");
		return 0;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
	return 1; 

}
//�����Լ�
element dequeue(QueueType* q)  
{
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
int get_count(QueueType* q) {
	int cnt = 0;
	cnt = q->front - q->rear; 
	if (cnt < 0)
		cnt *= -1; 
	return cnt;
}
void print_queue(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i > q->front && i <= q->rear)
			printf("%s ", q->queue[i]);
	} printf("\n");
}
void match(QueueType* q, QueueType* p) {

	if(is_empty(p))  
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
	else {
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s \n", q->queue[q->front+1], p->queue[p->front+1]); 
		dequeue(q);
		dequeue(p);
	}
}
// �� �Լ� 
int main(void) {
	printf("���� �ּ� ���α׷��Դϴ�.\n");

	QueueType manQ, womanQ;
	element newMan, newWoman;
	char num = 0, sex = 0; 
	char put_name[1000];
	init(&manQ);
	init(&womanQ);

	while(1) {
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
				if(enqueue(&manQ, newMan))
					match(&manQ, &womanQ);
			}
			else if (sex == 'f') {
				strcpy(newWoman.name, put_name);  
				if(enqueue(&womanQ, newWoman))
					match(&womanQ, &manQ); 
			}
			else
				printf("������ m or f �߿��� �Է����ּ���."); 
		}
		else if (num == 'c') {
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);

			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		getchar();

	} 
}