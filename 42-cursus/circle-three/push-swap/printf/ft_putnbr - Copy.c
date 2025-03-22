/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:27:50 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/26 16:20:39 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base, char type)
{
	int		count;
	char	*symbols1;
	char	*symbols2;

	count = 0;
	symbols1 = "0123456789abcdef";
	symbols2 = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base, type) + 1);
	}
	if (n < base)
	{
		if (type == 'X')
			return (ft_putchar(symbols2[n]));
		else
			return (ft_putchar(symbols1[n]));
	}
	else
	{
		count = ft_putnbr(n / base, base, type);
		return (count + ft_putnbr(n % base, base, type));
	}
}
