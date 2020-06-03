#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 8
#define COLUMNS 8
#define MOVEMENTS 8
#define POS_MAX 64

int positions_correct(int x, int y);
int is_posible_put(int x, int y, int map[ROWS][COLUMNS]);
void print_2d(int map[ROWS][COLUMNS]);
void print_heuristic(int map[ROWS][COLUMNS]);
int is_fill(int map[ROWS][COLUMNS]);

/**
 * main - (Eight Queens: Brute-Force Approaches)
 *        Put eight queens in the board
 *        without these crash
 *
 * Return: 0 if is success
 */
int main(void)
{
	int board[ROWS][COLUMNS] = {0};
	int vertical[MOVEMENTS] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int horizontal[MOVEMENTS] = {0, 1, 1, 1, 0, -1, -1, -1};
	int currow = 4, currcol = 4, x = 0, y = 0;
	int dir = 8, numqueen = 1;

	srand(time(0));

	/* 1 Tour of 8 Queens */
	while (numqueen <= 8) {
		if (is_fill(board)) {
			currow = 1 + rand() % 7;
			currcol = 1 + rand() % 7;

			if (is_posible_put(currow, currcol, board))
				board[currow][currcol] = 65;
			else
				continue;

			dir = 0;
		} else {
			numqueen = 8;
		}

		x = currcol + horizontal[dir];
		y = currow + vertical[dir];
		while (dir < 8) {
			while (positions_correct(x, y)) {
				board[y][x] = 70;
				x += horizontal[dir];
				y += vertical[dir];
			}
			++dir;
			x = currcol + horizontal[dir];
			y = currow + vertical[dir];
		}
		++numqueen;
		print_2d(board);
		puts("");
	}

	return (0);
}

/**
 * positions_correct - Verify if the positions are corrects
 * @x: (int) Position in X
 * @y: (int) Position in Y
 *
 * Return: 1 If the positions are correct otherwise 0
 */
int positions_correct(int x, int y)
{
	return((x >= 0 && x <= 7) && (y >= 0 && y <= 7) ? 1 : 0);
}


/**
 * is_posible_put - Look if is posible put a new queen in the positions given
 * @x: (int) Position in X
 * @y: (int) Position in Y
 * @map: (int) Contiguos memory that contain the map
 *
 * Return: 1 if is posible put the queen otherwise 0
 */
int is_posible_put(int x, int y, int map[ROWS][COLUMNS])
{
	if (positions_correct(x, y)) {
		if (map[x][y] != 65 && map[x][y] != 70) {
			return (1);
		}
	}
	return (0);
}


/**
 * print_2d - Print the chessboard
 * @map: (int) Matrix to print
 */
void print_2d(int map[ROWS][COLUMNS])
{
	printf("    0  1  2  3  4  5  6  7\n");
	for (size_t i = 0; i < ROWS; ++i) {
		printf("%ld ", i);
		for (size_t j = 0; j < COLUMNS; ++j) {
			if (map[i][j] == 0) {
				printf("%3s", "-");
			}
			if (map[i][j] == 65) {
				printf("%3s", "Q");
			}
			if (map[i][j] == 70)
				printf("%3s", "*");
		}
		putchar(10);
	}
}


/**
 * print_heuristic - Print the heuristic chessboard
 * @map: (int) Matrix to print
 */
void print_heuristic(int map[ROWS][COLUMNS])
{
	printf("    0  1  2  3  4  5  6  7\n");
	for (size_t i = 0; i < ROWS; ++i) {
		printf("%ld  ", i);
		for (size_t j = 0; j < COLUMNS; ++j) {
			printf("%d ", map[i][j]);
		}
		putchar(10);
	}
}


/**
 * is_fill - Look if it fill
 * @map: (int) Contiguos memory with the chessboard
 *
 * Return: 1 if it's clean and otherwise 0
*/
int is_fill(int map[ROWS][COLUMNS])
{
	int clean = 0;

	for (size_t i = 0; i < ROWS; ++i) {
		for (size_t j = 0; j < COLUMNS; ++j) {
			if (map[i][j] == 0) {
				++clean;
			}
		}
	}

	return ((clean >= 1) ? 1 : 0);
}
