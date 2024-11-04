/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:44:56 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/02 01:17:37 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memcpy(void *to, const void *from, size_t c)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)to;
	src = (unsigned char *)from;
	if ((src == NULL && dest == NULL))
		return (NULL);
	while (c-- > 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (to);
}
