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
int bubble_sort(struct Student* p, int n, int num);
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
		printf("�л� %2d�� �й� : %2d	", i + 1, p[i].id);
		printf("���� %3d		 ���� %3d	 ���� %3d\n", p[i].korean, p[i].math, p[i].english);
	} printf("\n");
	
	int num;
	do {
		printf("���� ���� ���� <1:����, 2:����, 3:����, 4:id(��������), 0:������> ");
		scanf("%d", &num);

		if(num == 1)
			bubble_sort(p, n, num);
		else if (num == 2)
			bubble_sort(p, n, num);
		else if (num == 3)
			bubble_sort(p, n, num);
		else if (num == 4)
			bubble_sort(p, n, num);
	
	} while (num != 0);
}
int bubble_sort(struct Student* p, int n, int num)
{
	//C6386 ���� �ʱ�ȭ�� ���� ������ ��� ���Ҵ�.
	int i, j, temp = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++){
			if (num == 1)
				if (p[j].korean > p[j + 1].korean)
					swap(j, p);
			if (num == 2)
				if (p[j].math> p[j + 1].math)
					swap(j, p);
			if (num == 3)
				if (p[j].english > p[j + 1].english)
					swap(j, p);
			if (num == 4)
				if (p[j].id > p[j + 1].id)
					swap(j, p);
		}
	}
;
	for (i = 0; i < n; i++) {
		printf("�л� %2d�� �й� : %2d	", i + 1, p[i].id);
		printf("���� %3d		 ���� %3d	 ���� %3d\n", p[i].korean, p[i].math, p[i].english);
	}

	return 0;
}
void swap(int i, struct Student* p)
{
	int temp; 
	temp = p[i].korean;
	p[i].korean = p[i + 1].korean;
	p[i + 1].korean = temp;

	temp = p[i].english;
	p[i].english = p[i + 1].english;
	p[i + 1].english = temp;

	temp = p[i].math;
	p[i].math = p[i + 1].math;
	p[i + 1].math = temp;

	temp = p[i].id;
	p[i].id = p[i + 1].id;
	p[i + 1].id = temp;

}