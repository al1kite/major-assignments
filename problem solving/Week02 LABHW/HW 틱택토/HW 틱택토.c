#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define BOARD_SIZE 3 
void display(char b[][BOARD_SIZE])
{
	int i, j;
	printf("     ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n    ---------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}
int winCheck(char b[][BOARD_SIZE], int r, int c)
{
	//verticality
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (b[i][j] != b[r][c])
				break;
			if (j == BOARD_SIZE - 1)
				return 1;
		}
	}
	//horizontality
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (b[j][i] != b[r][c])
				break;
			if (j == BOARD_SIZE - 1)
				return 1;
		}
	}
	//diagonal_left
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (b[i][i] != b[r][c])
			break;
		if (i == BOARD_SIZE - 1)
			return 1;
	}
	//diagonal_right
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (b[i][BOARD_SIZE - 1 - i] != b[r][c])
			break;
		if (i == BOARD_SIZE - 1)
			return 1;
	}
	return 0;
}
void main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn1 = 'X';
	char turn2 = 'O';
	int r, c;
	int i, j;
	int count;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';
	count = 1;
	display(board);
	do
	{
		if (count % 2 == 1) {
			do {
				printf("Player %c(행 열):", turn1);
				scanf("%d %d", &r, &c);
			} while (board[r][c] != ' ');
			board[r][c] = turn1;
			display(board);
			if (winCheck(board, r, c) == 1) {
				printf("Player %c wins!", turn1);
				break;
			}
		}
		else if (count % 2 == 0) {
			do {
				printf("Player %c(행 열):", turn2);
				scanf("%d %d", &r, &c);
			} while (board[r][c] != ' ');
			board[r][c] = turn2;
			display(board);
			if (winCheck(board, r, c) == 1) {
				printf("Player %c wins!", turn2);
				break;
			}
		}
		count++;

		if (count > BOARD_SIZE * BOARD_SIZE)
			printf("Nobody wins!");

	} while (count <= BOARD_SIZE * BOARD_SIZE);

}