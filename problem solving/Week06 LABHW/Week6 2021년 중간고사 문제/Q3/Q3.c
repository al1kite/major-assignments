/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int main(void) {
	int r = 0, c = 0, n;
	scanf("%d %d", &r, & c); 
	scanf("%d", &n); 
	char** arr;
	arr = (char**)malloc(sizeof(char*) * r);
	for (int i = 0; i < r; i++) 
		arr[i] = (char*)malloc(sizeof(char) * c); 
	if (arr == NULL) { return 0; } 
	
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++)
			scanf("%s", &arr[i][j]);
	
	int key = n;  
	for (int i = 0; i < r; i++) {
		for(int j=key; j < c; j++)
			if (arr[i][j] == 1) {
				key = j;  
				break; 
			}

	}
	printf("%d", key);
}*/
#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>

int main() {
	int w, h;
	int s, i;
	char ladder[100][100] = { 0, };

	scanf("%d %d", &w, &h);
	scanf("%d", &s);

	for (i = 0; i < h; i++)
		scanf("%s", ladder[i]);

	for (i = 0; i < h; i++) {
		if (s == 0) {
			if (ladder[i][s] == '1')
				s++;
		}
		else if (s == w - 1) {
			if (ladder[i][s - 1] == '1')
				s--;
		}
		else {
			if (ladder[i][s] == '1')
				s++;
			else if (ladder[i][s - 1] == '1')
				s--;
		}
	}
	printf("%d\n", s);
	return 0;

}