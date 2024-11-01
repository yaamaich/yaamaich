/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:18:41 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/30 23:33:16 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp (const void *s1, const void *s2, size_t n)
{
	unsigned char  *i = (unsigned char *)s1;
	unsigned char  *l = (unsigned char *)s2;
	while (*i && *i == *l && n > 0)
	{
		n--;
		i++;
		l++;
	}
	return (*i - *l);
}