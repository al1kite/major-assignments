struct Student{
	int id;
	int english;
	int math;
	int korean; 
};
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h> 
#include<time.h>
int selection_sort(struct Student * p, int n); 
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
		printf("학생 %2d의 학번 : %2d	", i + 1, p[i].id);
		printf("국어 %d		 수학 %d	 영어 %d\n", p[i].korean, p[i].math, p[i].english);
	} printf("\n"); 

	selection_sort(p, n);
}
int selection_sort(struct Student* p, int n)
{
    //C6386 변수 초기화로 버퍼 오버런 경고를 막았다.
    int i, j, temp = 0, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (p[min].korean > p[j].korean) 
                min = j;
		swap(i, min, p);
    }


    printf("정렬된 후:\n");
	for (i = 0; i < n; i++) {
		printf("학생 %2d의 학번 : %2d	", i + 1, p[i].id);
		printf("국어 %d		 수학 %d	 영어 %d\n", p[i].korean, p[i].math, p[i].english);
	}

    return 0;
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