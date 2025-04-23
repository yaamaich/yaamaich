#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = start - end;
    int j = 0;
    if (i < 0)
        i = -i;
    int *arry = malloc (sizeof(int) * i);
    while (i >= 0)
    {
        if (start > end)
        {
            arry[j] = start;
            start--;
        }else 
        {
            arry[j] = start;
            start++;
        }
        j++;
        i--;
    }
    return arry;
}
int main()
{
    int *s;
    int i = 1;
    int j = 0;
    s = ft_range(1 , 0);
    while (i >= 0)
    {
        printf("%d", s[j]);
        j++;
        i--;
    }
}