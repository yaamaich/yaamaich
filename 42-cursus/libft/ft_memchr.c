/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:23:37 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/03 02:54:52 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*p;

	p = (char *)str;
	while (n > 0)
	{
		if (*p == (char)c)
			return (p);
		n--;
		p++;
	}
	return (NULL);
}
