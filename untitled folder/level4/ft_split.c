#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int ft_count(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i])
    {
        while(str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i])
            count++;
        while(str[i] >= 33 && str[i] <= 126)
            i++;
    }
    return count;
}
char    **ft_split(char *str)
{
    int i = 0, n = 0, k = 0, j = 0,count_woed = 0;
    char **st;
    st = malloc (sizeof(char *) * (ft_count(str) + 1));       
    while (str[i])
    {
        while(str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        j = i;
        count_woed = 0;
        while(str[j] && str[j] >= 33 && str[j] <= 126)
        {
            count_woed++;
            j++;
        }
        if(count_woed > 0)
        {
            st[n] = malloc (sizeof(char) * (count_woed + 1));
            k = 0;
            while(str[i] && str[i] >= 33 && str[i] <= 126)
            {
                st[n][k] = str[i];
                i++;
                k++;
            }
            st[n][k] = '\0';
            n++;
        }
    }
    st[n] =  NULL;
    return st;
}
int main()
{


    char **st;
    st = ft_split("yahya   ");
    printf("%s" ,st[0]);
    free(st);
}