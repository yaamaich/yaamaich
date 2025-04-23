#include <unistd.h>

int  ft_atoi(const char *str)
{
    int i = 0;
    int signe = 1;
    int result = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        signe *= -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        result *= 10;
        result += (str[i] - '0');
        i++;
    }
    return (result * signe);
}
#include <stdio.h>

int main()
{
   printf("%d" ,ft_atoi("22"));
}
