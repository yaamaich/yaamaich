/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:36:06 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/05 00:11:36 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	*ptr;
	int				p;

	ptr = (unsigned char *)str;
	p = ft_strlen(str);
	while (p >= 0)
	{
		if (*ptr == (char)ch)
			return ((char *)ptr);
		p--;
		ptr++;
	}
	return (NULL);
}