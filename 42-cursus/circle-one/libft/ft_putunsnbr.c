/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:33:57 by yaamaich          #+#    #+#             */
/*   Updated: 2025/02/06 03:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		return (ft_putchar(n + 48));
	}
	else
	{
		count = ft_putunsnbr(n / 10);
		return (count + ft_putunsnbr(n % 10));
	}
}
