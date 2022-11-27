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
//초기화함수
void init(QueueType* q)
{
	q->front = q->rear = 0;
}
//공백상태검출함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
//포화상태검출함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//삽입함수
int enqueue(QueueType* q, element item)
{
	if (is_full(q)) {
		printf("아직 대상자가 없습니다. 대기자가 꽉 찼으니 다음 기회에 이용.\n");
		return 0;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
	return 1; 

}
//삭제함수
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
		printf("아직 대상자가 없습니다. 기다려주십시오.\n");
	else {
		printf("커플이 탄생했습니다! %s과 %s \n", q->queue[q->front+1], p->queue[p->front+1]); 
		dequeue(q);
		dequeue(p);
	}
}
// 주 함수 
int main(void) {
	printf("미팅 주선 프로그램입니다.\n");

	QueueType manQ, womanQ;
	element newMan, newWoman;
	char num = 0, sex = 0; 
	char put_name[1000];
	init(&manQ);
	init(&womanQ);

	while(1) {
		printf("i<nsert, 고객 입력>, c<heck, 대기자 체크>, q<uit>:"); 
		scanf("%c", &num);

		if (num == 'q') 
			break;
		else if (num == 'i') {

			printf("이름을 입력: ");
			scanf("%s", &put_name);
			getchar(); 

			printf("성별을 입력:<m or f>: ");
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
				printf("성별은 m or f 중에서 입력해주세요."); 
		}
		else if (num == 'c') {
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);

			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
		}
		getchar();

	} 
}