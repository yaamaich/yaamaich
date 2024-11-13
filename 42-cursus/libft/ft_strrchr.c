/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:28:38 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:30 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int				p;

	ptr = (unsigned char *)s;
	p = ft_strlen(s);
	while (p >= 0)
	{
		if (ptr[p] == (unsigned char)c)
			return ((char *)&s[p]);
		p--;
	}
	return (NULL);
}
