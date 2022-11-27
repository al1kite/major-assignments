#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>
typedef struct {
	int midterm; 
	int final; 
}Score;
void printScore(Score* p) //2) 
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) //3) 
{
	Score* p = (Score*)malloc(sizeof(Score));

	if (p1->midterm + p1->final > p2->midterm + p2->final)
		p = p1;
	else
		p = p2;

	return p;

}
Score* totalScore(Score* p1, Score* p2) //4) 
{
	Score* s = (Score*)malloc(sizeof(Score));

	int totalMidterm = (p1->midterm + p1->final);
	int totalFinal = (p2->midterm + p2->final);

	s->midterm = totalMidterm;
	s->final = totalFinal;

	return s;
}
Score* createScore(int m, int f)
{
	Score* p;
	p = (Score*)malloc(sizeof(Score));
	p->midterm = m;
	p->final = f;
	return p;
}
// R
int main(void) {

	Score* p1, * p2, * p3;
	//1)p1, p2에 Score를 저장하기위한 메모리를 할당하고값을 대입한다.각각(50, 100), (70, 70)
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));
	p3 = (Score*)malloc(sizeof(Score));
	
	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);
	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));
	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}
