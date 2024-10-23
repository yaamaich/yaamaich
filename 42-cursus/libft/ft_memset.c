/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:46:51 by yaamaich          #+#    #+#             */
/*   Updated: 2024/10/23 18:48:08 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	char *p = str;

	while (--len > 0)
	{
		*p = c;
		p++;
	}
	return str;
}

/*
int main ()
{
	char c[10];
	int i = 'v';
	ft_memset(c, i, sizeof(c));
	printf("%s", c);
}
*/
