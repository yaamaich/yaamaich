#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

void    print_solution(int *board, int n)
{
    int i = 0;

    while (i < n)
    {
        fprintf(stdout, "%d", board[i]);
        if (i < n - 1)
            fprintf(stdout, " ");
        else
            fprintf(stdout, "\n");
        i++;
    }
}

int is_safe(int *board, int col, int row)
{
	int i = 0;
	while(i < col)
	{
		if(board[i] == row || board[i] - row == col - i || row - board[i] == col - i)
		{
			return 0;
		}
		i++;
	}
	return 1;
}


void solve_nq(int *board, int col, int n)
{
	if( col == n)
	{
		printf("ana hna");
		print_solution(board,n);
		return ;
	}
	int row = 0;
	while(row < n)
	{
		if(is_safe(board,col,row))
		{
			board[col] = row;
			solve_nq(board,col + 1,n);
		}
		row++;
	}
	return ;
}

int main(int argc, char **argv)
{
	if(argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if(n <= 0)
		return 1;
	int *board = malloc(sizeof(int) * n);
	if(!board)
		return 1;
	solve_nq(board,0,n);
	free(board);
	return 0;
}