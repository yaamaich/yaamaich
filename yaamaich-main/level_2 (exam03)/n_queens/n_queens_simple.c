#include <stdio.h>
#include <stdlib.h>

void print_board(int *board, int n)
{
	int i = 0;
	while (i < n - 1)
	{
		printf("%i ", board[i]);
		i++;
	}
	printf("%i\n", board[n - 1]);
}

int is_validate(int *board, int row, int col)
{
	int i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
			return 0;
		i++;
	}
	return 1;
}


void nqueen(int *board, int n, int row)
{
	int col = 0;

	if (row == n)
	{
		print_board(board, n);
		return;
	}
	while (col < n)
	{
		if (is_validate(board, row, col))
		{
			board[row] = col;
			nqueen(board, n, row + 1);
		}
	   col++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 1)
		return (0);

	int n = atoi(av[1]);
	int *board = malloc(sizeof(int) * n);
	int y = 0;
	while (y < n)
	{
		board[y] = -1;
		y++;
	}
	nqueen(board, n, 0);
	free(board);
}
