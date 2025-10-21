#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i;
    i = 0;
    while (src[i])
        i++;
    int j = 0;
    char *str = malloc(sizeof(char) * i + 1);
    while(src[j])
    {
        str[j] = src[j];
        j++;
    }
    str[j] = '\0';
    return str;
}
