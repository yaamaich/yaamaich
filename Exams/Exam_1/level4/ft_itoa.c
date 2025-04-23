#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_count(int n)
{
    int  i = 1;
    if (n < 0)
    {
        i++;
        n = -n;
    }
    if (n >= 0 && n <= 9)
        return i;
    while (n > 9)
    {
        n = n / 10;
        i++;
    }
    return i;
}
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
char *ft_strdup(char *str)
{
    int i = 0;
    char *st;
    st = malloc (sizeof(char) * ft_strlen(str));
    while (str[i])
    {
        st[i] = str[i];
        i++;
    }
    return st;
}
char	*ft_itoa(int nbr)
{
    int j = ft_count(nbr);
    char *str;
    str = malloc (sizeof(char) * j + 1);
    if (nbr == 0)
        return ft_strdup("0");
    else if (nbr == -2147483648)
        return ft_strdup("-2147483648");
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    str[j] = '\0';
    j--;
    while (nbr)
    {
        str[j] = nbr % 10 + '0';
        nbr /= 10;
        j--;
    }
    return str;
}

int main()
{
    char *str = ft_itoa(-23456789);
    printf("%s", str);
}