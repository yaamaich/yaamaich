#include <unistd.h>

void ft_putchar(char c)
{
 write (1, &c, 1);
}
void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        n = 147483648;
    }
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= 0 && n <= 9)
        ft_putchar(n + '0');
    else if (n > 9)
    {
        ft_putchar((n % 10) + '0');
        ft_putnbr(n / 10);
    }
}
int main(int argc, char **argv)
{
    ft_putnbr(argc - 1);
    write(1, "\n", 1);
}