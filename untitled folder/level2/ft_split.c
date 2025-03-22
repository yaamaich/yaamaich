#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_wordcount(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i]) // التأكد من وجود كلمة جديدة
            count++;
        while (str[i] && (str[i] > 32 && str[i] <= 126))
            i++;
    }
    return count;
}



char **ft_split(char *str)
{
    char **st;
    int i = 0, n = 0, k = 0, word_len = 0;

    st = malloc(sizeof(char *) * (ft_wordcount(str) + 1)); // +1 للحرف NULL النهائي
    if (!st) return NULL;

    while (str[i])
    {
        while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i])
        {
            word_len = 0;
            int j = i;
            while (str[j] && (str[j] > 32 && str[j] <= 126))
            {
                word_len++;
                j++;
            }
            st[n] = malloc(sizeof(char) * (word_len + 1));
            k = 0;
            while (str[i] && (str[i] > 32 && str[i] <= 126))
                st[n][k++] = str[i++];
            st[n][k] = '\0';
            n++;
        }
    }
    st[n] = NULL;
    return st;
}
