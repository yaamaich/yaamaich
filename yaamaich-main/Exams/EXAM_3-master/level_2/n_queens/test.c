#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_sol(int *board, int len)
{
    int i = 0;
    while (i < len)
    {
        fprintf(stdout, "%d", board[i]);
        if (i < len - 1)
            fprintf(stdout, " ");
        else
            fprintf(stdout, "\n");
        i++;
    }
}
int is_safe(int *board, int col, int row)
{
    int i = 0;
    while (i < col)
    {
        if (board[i] == row || board[i] - row == col - i || row - board[i] == col - i)
            return 0;
        i++;
    }
    return 1;
}

void slove_nq(int *board, int col, int n)
{
    if (col == n)
    {
        print_sol(board, n);
        return ;
    }
    int row = 0;
    while (row < n)
    {
        if (is_safe(board, col,row))
        {
            board[col] = row;
            slove_nq(board, col + 1, n);
        }
        row++;
    }
    return ;
}
int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int n = atoi(argv[1]);
    if (n <= 0)
        return 0;
    int *board = malloc(sizeof(int) * n);
    if (!board)
        return 0;
    slove_nq(board, 0, n);
    free(board);
    return 0;
}