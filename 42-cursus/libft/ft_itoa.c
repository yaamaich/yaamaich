/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:14:05 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/09 00:43:11 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	char		*dst;
	int			count;
	int			i;
	long int	n;

	i = 0;
	n = num;
	count = count_size(n);
	if (n < 0 || count == 0)
		count++;
	dst = ft_calloc(count + 1, sizeof(char));
	if (!dst)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
		i++;
	}
	while (--count > i)
	{
		dst[count] = (n % 10) + '0';
		n /= 10;
	}
	return (dst);
}
