#include <unistd.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int k = start - end;
    int index = 0;
    if (k < 0)
        k = -k;
    int *l;
    l = malloc (sizeof(int) * k + 1);
    while (index <= k)
    {
        if (start > end)
        {
            l[index] = start;
            start--;
        }
        else if (start < end)
        {
            l[index] = start;
            start++;
        }else 
            l[index] = end;
        index++;
    }
    l[index] = '\0';
    return l;
}
