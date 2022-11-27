/*--- my code with itoa ---*/
/*#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEVEL 5
#define MAX_WIDTH 70
char screen[MAX_LEVEL][MAX_WIDTH];
int count = 0;
#include <stdio.h>
#include <stdlib.h>
void draw_tree(int row, int left, int right)
{
	int mid;
	char buffer[300];
	if (right - left < 2) return;
	mid = (right + left) / 2;
	_itoa(count, buffer, 100);
	int i = strlen(buffer);
	screen[row][mid] = buffer[i - 1];
	count++;
	draw_tree(row + 1, left, mid);
	draw_tree(row + 1, mid + 1, right);
}
void init(char s[][MAX_WIDTH])
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}
void display(char s[][MAX_WIDTH], int width)
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			printf(" %c", s[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int width;
	init(screen);
	printf("Enter a width(<= 70) of a screen:");
	scanf("%d", &width);
	draw_tree(0, 0, width - 1);
	display(screen, width);
}*/
/*--- code 1 ---*/
/*
# define _CRT_SECURE_NO_WARNINGS
#define MAX_LEVEL 5
#define MAX_WIDTH 70
int screen[MAX_LEVEL][MAX_WIDTH];
int count = 0;
#include <stdio.h>
#include <stdlib.h>
void draw_tree(int row, int left, int right)
{
	int mid;

	if (right - left < 2) return;

	mid = (right + left) / 2;

	screen[row][mid] = count++;
	draw_tree(row + 1, left, mid);
	draw_tree(row + 1, mid + 1, right);
}

void init(int s[][MAX_WIDTH])
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}
void display(int s[][MAX_WIDTH], int width)
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			if (s[i][j] == '-')
				printf(" %c", s[i][j]);
			else 
				printf(" %d", s[i][j]); 
		printf("\n");
	}
}
int main(void)
{
	int width;
	init(screen);
	printf("Enter a width(<= 70) of a screen:");
	scanf("%d", &width);
	draw_tree(0, 0, width - 1);
	display(screen, width);
}
*/
/*--- code2 ---*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LEVEL 5
#define MAX_WIDTH 70

char screen[MAX_LEVEL][MAX_WIDTH];
int count = 0;
/* int sum(int arr[], int start, int end){
*      int ret = 0;
*      for(i=start; i<end; i++)
*         ret += arr[i];
*      return ret;
* }
*/
void draw_tree(int row, int left, int right) {

	int mid;
	//trivial case
	if (right - left < 2)
		return;
	//recursive case
	mid = (right + left) / 2;

	screen[row][mid] = ++count;
	draw_tree(row + 1, left, mid);
	draw_tree(row + 1, mid + 1, right);
}

void init(char s[][MAX_WIDTH]) {
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void display(char s[][MAX_WIDTH], int width)
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
			if (s[i][j] == '-')
				printf(" %c", s[i][j]);
			else
				printf(" %d", s[i][j]);
		printf("\n");
	}

}

int main(void) {

	int width;
	init(screen);
	printf("Enter a width(<=70) of a screen: ");
	scanf("%d", &width);

	draw_tree(0, 0, width - 1);
	display(screen, width);
}