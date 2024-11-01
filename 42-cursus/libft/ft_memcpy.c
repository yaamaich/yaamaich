/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:44:56 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/01 00:13:10 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void	 *ft_memcpy(void *to,const void	*from,size_t c)
{
	unsigned char *dest = (unsigned char *)to;
	unsigned char *src = (unsigned char *)from;
	
	if (!(src && dest))
		return (NULL);
	while (c-- > 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return to;
}

