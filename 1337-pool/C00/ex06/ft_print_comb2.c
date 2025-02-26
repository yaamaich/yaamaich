/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:09 by yaamaich          #+#    #+#             */
/*   Updated: 2024/06/29 11:41:27 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	if (a != '9' || b != '8' || c != '9' || d != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0' - 1;
	while (++a <= '9')
	{
		b = '0' - 1;
		while (++b <= '9')
		{
			c = a;
			d = b + 1;
			while (c <= '9')
			{
				while (d <= '9')
				{
					ft_print(a, b, c, d);
					d++;
				}
				d = '0';
				c++;
			}
		}
	}
}
