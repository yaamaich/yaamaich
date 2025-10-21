/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaiche <yamaiche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:47:38 by yamaiche          #+#    #+#             */
/*   Updated: 2024/06/29 23:48:28 by yamaiche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
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
    int i = 2;
    int d = 4;
	int a;
	int b;
    ft_div_mod(i, d, &a, &b);
    putnbr(a);
    putnbr(b);
}
*/