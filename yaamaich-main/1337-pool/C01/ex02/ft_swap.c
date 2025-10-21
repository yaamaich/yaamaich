/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaiche <yamaiche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:11:07 by yamaiche          #+#    #+#             */
/*   Updated: 2024/06/29 23:13:23 by yamaiche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void    putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2", 2);
        nb = 147483648;
    }
    else if(nb < 0) 
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
    {
        putnbr(nb / 10);
        ft_putchar((nb % 10 ) + 48);    
    }
    else
    {
        ft_putchar(nb + 48);
    }
}

int main ()
{
    int i = 1;
    int d = 2;
    ft_swap(&i, &d);
    putnbr(i);
    putnbr(d);
}
*/