#include <stdio.h>
#include <stdlib.h>

void	print_table(int *board, int n)
{
	int row = 0;
	while (row < n - 1)
	{
		printf("%i ", board[row]);
		row++;
	}
	printf("%i\n", board[n - 1]);
}

int	is_valid(int *board, int row, int col)
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

void	nqueen(int *board, int row, int n)
{
	int col = 0;
	if (row == n)
	{
		print_table(board, n);
		return ;
	}
	while (col < n)
	{
		if (is_valid(board, row, col))
		{
			board[row] = col;
			nqueen(board, row + 1, n);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	int n = atoi(av[1]);
	int *board = malloc(sizeof(int) * n);
	int y = 0;
	while (y < n)
	{
		board[y] = -1;
		y++;
	}
	nqueen(board, 0, n);
}