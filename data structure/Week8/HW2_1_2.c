//LinkedQueue.c
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[1000];
}element;// 요소의 타입
typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct { // 큐 ADT 구현
	QueueNode* front, * rear;
	int cnt;
} LinkedQueueType;
// 초기화 함수
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) // 항상 거짓, 포화상태일때가 없다. 연결리스트로 구현하였으므로
{
	return 0;
}
// 삽입 함수
int enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item; // 데이터 저장
		temp->link = NULL; // 링크 필드를 NULL
		if (is_empty(q)) { // 큐가 공백이면
			q->front = temp;
			q->rear = temp;
		}
		else { // 큐가 공백이 아니면
			q->rear->link = temp; // 순서가 중요
			q->rear = temp;
		}
		q->cnt++;
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // 공백상태
		printf("큐가 비어 있읍니다");
	else {
		item = temp->data; // 데이터를 꺼낸다.
		q->front = q->front->link; // front 를 다음노드를 가리키도록 한다.
		if (q->front == NULL) // 공백 상태
			q->rear = NULL;
		free(temp); // 동적메모리 해제
		q->cnt--;
		return item; // 데이터 반환
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
		printf("아직 대상자가 없습니다. 기다려주십시오.\n");
	else {
		printf("커플이 탄생했습니다! %s과 %s \n", q->front, p->rear);
		dequeue(q);
		dequeue(p);
	}
}
int main(void) {
	printf("미팅 주선 프로그램입니다.\n");

	LinkedQueueType manQ, womanQ;
	manQ.cnt = 0, womanQ.cnt = 0;
	element newMan, newWoman;
	char num = 0, sex = 0;
	char put_name[1000];
	init(&manQ);
	init(&womanQ);

	while (1) {
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
				if (enqueue(&manQ, newMan))
					match(&manQ, &womanQ);
			}
			else if (sex == 'f') {
				strcpy(newWoman.name, put_name);
				if (enqueue(&womanQ, newWoman))
					match(&womanQ, &manQ);
			}
			else
				printf("성별은 m or f 중에서 입력해주세요.");
		}
		else if (num == 'c') {
			printf("남성 대기자 %d명: ", manQ.cnt);
			print_queue(&manQ);

			printf("여성 대기자 %d명: ", womanQ.cnt);
			print_queue(&womanQ);
		}
		getchar();

	}
}