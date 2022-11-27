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
int quickSort(struct Student* p, int n, int r, int num);  
void swap(int i, struct Student* p);
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
		printf("학생 %2d의 학번 : %2d	", i + 1, p[i].id);
		printf("국어 %3d		 수학 %3d	 영어 %3d\n", p[i].korean, p[i].math, p[i].english);
	} printf("\n");

	int num;
	do {
		printf("정렬 기준 선택 <1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기> ");
		scanf("%d", &num);

		quickSort(p, 0, n - 1, num); 

		printf("정렬된 후:\n");
		for (int i = 0; i < n; i++) {
			printf("학생 %2d의 학번 : %2d	", i + 1, p[i].id);
			printf("국어 %d		 수학 %d	 영어 %d\n", p[i].korean, p[i].math, p[i].english);
		}

	} while (num != 0);
}
int partition(struct Student* A, int p, int r, int num) { 
	int i, j, t;
	i = p - 1;
	if (num == 1) {
		for (j = p; j < r; j++) {
			if (A[j].korean < A[r].korean) {
				i++;
				swap(i, j, A);
			}
		}
		i++;
		swap(i, r, A);
	}
	if (num == 2) {
		for (j = p; j < r; j++) {
			if (A[j].math < A[r].math) {
				i++;
				swap(i, j, A);
			}
		}
		i++;
		swap(i, r, A);
	}
	if (num == 3) {
		for (j = p; j < r; j++) {
			if (A[j].english < A[r].english) {
				i++;
				swap(i, j, A);
			}
		}
		i++;
		swap(i, r, A);
	}
	if (num == 4) {
		for (j = p; j < r; j++) {
			if (A[j].id < A[r].id) { 
				i++;
				swap(i, j, A);
			}
		}
		i++;
		swap(i, r, A);
	}

	return i;
}
int quickSort(struct Student* p, int n, int r, int num) 
{
	int q;
	if (n < r) {
		q = partition(p, n, r, num);
		quickSort(p, n, q - 1, num);
		quickSort(p, q + 1, r, num); 
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