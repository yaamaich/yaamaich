#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int		ft_is_prime(int nb)
{
	int i;
    if (nb <= 1)
        return 0;
    if (nb == 2 || nb == 3)
        return 1;
    if (nb % 2 == 0 || nb % 3 == 0)
        return 0;
	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);

}
int nextprime(int n)
{
    n += 1;
    while (ft_is_prime(n) == 0)
        n++;
    return n;
}

int		ft_add_prime_sum(int nb)
{
	int i;
	int prime_sum;

	i = 2;
	prime_sum = 0;
	if (nb <= 0)
		return (0);
	while (nb - i >= 0)
	{
    	if (ft_is_prime(i))
			prime_sum += i;
		i  = nextprime(i);
	}
	return (prime_sum);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putnbr(ft_add_prime_sum(ft_atoi(av[1])));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}