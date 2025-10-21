#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int max = 0;
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}
int main()
{
    int i[10] = {1, 2, 3, 4, 67};
    int k = 0;
    while (i[k])
        k++;
    printf("%d", max(i, k));
}