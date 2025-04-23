#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char    *ft_strrev(char *str)
{
    int j = 0;
    int i = ft_strlen(str) - 1;
    char tmp;
    while (i > j)
    {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i--;
        j++;
    }
    return str;
}
#include <stdio.h>

int main()
{
    char str[11111] = "hello";
    ft_strrev(str);
    printf("%s", str);    
}