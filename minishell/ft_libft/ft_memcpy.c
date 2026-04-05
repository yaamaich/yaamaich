/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:48:06 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/23 15:29:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	unsigned char	*str_to;
	unsigned char	*str_from;

	str_to = (unsigned char *)to;
	str_from = (unsigned char *)from;
	if (to == from)
		return (to);
	while (n--)
		*str_to++ = *str_from++;
	return (to);
}
