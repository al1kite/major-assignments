struct Student {
	int id;
	int english;
	int math;
	int korean;
};
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int quickSort(struct Student* p, int n, int r);
void swap(int i, int min, struct Student* p);
int main(void)
{
	int n = 0;
	srand((unsigned)time(NULL));

	printf("Enter student number: ");
	scanf("%d", &n);

	struct Student* p = (struct Student*)malloc(sizeof(struct Student) * n);
	if (p == NULL) { return 0; }

	for (int i = 0; i < n; i++) {
		p[i].id = i + 1;
		p[i].korean = rand() % 101;
		p[i].english = rand() % 101;
		p[i].math = rand() % 101;
	}
	for (int i = 0; i < n; i++) {
		printf("�л� %2d�� �й� : %2d	", i + 1, p[i].id);
		printf("���� %d		 ���� %d	 ���� %d\n", p[i].korean, p[i].math, p[i].english);
	} printf("\n");

	quickSort(p, 0, n-1);

	printf("���ĵ� ��:\n");
	for (int i = 0; i < n; i++) {
		printf("�л� %2d�� �й� : %2d	", i + 1, p[i].id);
		printf("���� %d		 ���� %d	 ���� %d\n", p[i].korean, p[i].math, p[i].english);
	}
}
int partition(struct Student* A, int p, int r) {
	int i, j, t;
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j].korean < A[r].korean) {
			i++;
			swap(i, j, A); 
		}
	}
	i++;
	swap(i, r, A);  

	return i;
}
int quickSort(struct Student* p, int n, int r) 
{
	int q;
	if (n < r) {
		q = partition(p, n, r); 
		quickSort(p, n, q - 1);
		quickSort(p, q + 1, r);
	}
}
void swap(int i, int min, struct Student* p)
{
	int temp;
	temp = p[i].korean;
	p[i].korean = p[min].korean;
	p[min].korean = temp;

	temp = p[i].english;
	p[i].english = p[min].english;
	p[min].english = temp;

	temp = p[i].math;
	p[i].math = p[min].math;
	p[min].math = temp;

	temp = p[i].id;
	p[i].id = p[min].id;
	p[min].id = temp;

}