#include <unistd.h>

void ft_putchar (char c)
{
    write(1, &c, 1);
}
void print_hex(int num)
{
    char str[17] = "0123456789abcdef";
    if (num <= 16)
        ft_putchar(str[num]);
    else
    {
        print_hex(num / 16);
        ft_putchar(str[num % 16]);
    }
}
int ft_atoi(char *str)
{
    int i = 0;
    int singe = 1;
    int result = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        singe *= -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result * singe);
}
int main(int argc , char **argv)
{
    if (argc == 2)
    {
        print_hex(ft_atoi(argv[1]));
    }
    write(1, "\n", 1);
}