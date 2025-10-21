/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamaiche <yamaiche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:42:02 by yamaiche          #+#    #+#             */
/*   Updated: 2024/06/29 22:41:20 by yamaiche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*
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
    int nb;
    int *nb1;
    int **nb2;
    int ***nb3;
    int ****nb4;
    int *****nb5;
    int ******nb6;
    int *******nb7;
    int ********nb8;
    int *********nb9;
    nb = 1;
    nb1 = &nb;
    nb2 = &nb1;
    nb3 = &nb2;
    nb4 = &nb3;
    nb5 = &nb4;
    nb6 = &nb5;
    nb7 = &nb6;
    nb8 = &nb7;
    nb9 = &nb8;
    ft_ultimate_ft(nb9);
    putnbr(nb);
                  
}
*/