/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:28:38 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/30 06:09:41 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
	while (*s)
		s++;
	while (*s >= 0)
	{
		if(*s == (char )c)
			return (char *)s;
		s--;
	}
	return NULL;
}