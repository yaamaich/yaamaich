#include <unistd.h> 

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void putnbr(int n)
{
    if (n  ==  -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        n = 147483648;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }else if (n >= 10)
    {
        putnbr(n / 10);
        ft_putchar((n % 10) + '0');
    }else 
        ft_putchar(n + '0');

}
int ft_atoi(char *str)
{
     int i = 0;
     int sin = 1;
     int result = 0;
     while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        ft_putchar('-');
        sin *= -1;
        i++;
    }else if (str[i] == '+')
        i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
        result *= 10;
        result += str[i] - '0';
        i++;
    }
    return (result * sin);
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 1;
        int n = ft_atoi(argv[1]);
        while (i <= 9)
        {
            ft_putchar(i + 48);
            write(1, " * ", 3);
            putnbr(n);
            write(1, " = ", 3);
            putnbr(i * n);
            write(1, "\n", 1);
            i++;
        }
    }else 
        write(1, "\n", 1);
}