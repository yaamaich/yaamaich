/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:23:37 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/31 21:57:40 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)str;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		n--;
		p++;
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s",ft_memchr(200,200,5));
// 	printf("%s",ft_memchr(200,200,5));
// }