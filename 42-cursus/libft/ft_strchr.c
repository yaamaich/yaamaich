/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:36:06 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/31 23:01:37 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
	
char	*ft_strchr(const char *str, int ch)
{
	if (str == NULL) {
    	return NULL;  
	}
	while (*str)
	{
		if(*str == (char)ch)
			return (char *)str;
		str++;
	}
	return NULL;
}