/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:21:59 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/03 05:22:02 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;
	char *p;
	
	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = malloc(i + j + 1);
	if (!p)
	return (NULL);
	while (s1[k])
	{
		p[k] = s1[k];
		k++;
	}
	i = 0;
	while (s2[i])
	{
		p[k] = s2[i];
		k++;
		i++;
	}
	p[k] = '\0';
	return (p);
	free(p);
}