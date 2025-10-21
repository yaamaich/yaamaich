#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int i = start - end;
    if (i < 0)
        i = -i;
    int *ray = malloc (sizeof(int) * i);
    int j = 0;
    while (i >= 0)
    {
        if (start > end)
        {
            ray[j] = end;
            end++;
        }else{
            ray[j] = end;
            end--;
        }
        j++;
        i--;
    }
    return ray;
}
int main()
{
    int *s;
    int i = 12;
    int j = 0;
    s = ft_rrange(0 , 12);
    while (i >= 0)
    {
        printf("%d", s[j]);
        j++;
        i--;
    }
}