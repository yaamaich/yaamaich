/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaiche <yamaiche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:41:32 by yamaiche          #+#    #+#             */
/*   Updated: 2024/06/29 23:46:28 by yamaiche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *a / *b;
	*b = c % *b;
}

/*void ft_putchar(char c)
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
    int a = 2;
    int b = 4;
    ft_ultimate_div_mod(&a, &b);
    putnbr(a);
    putnbr(b);
}
*/