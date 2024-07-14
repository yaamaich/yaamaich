/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:10:11 by yaamaich          #+#    #+#             */
/*   Updated: 2024/07/14 02:39:01 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	ft_strcmp(char *s1,char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int	j;
	int 
	j = 1;
	if (argc >= 1)
	{	
		if (ft_strcmp(argv[1] ,argv[2]) < 0)
		{
			c[y] = argv[1];
			argv[1] = argv[2];
			argv[2] = c[y];
		}
		while (j < argc)
		{
			i = 0;
			while (argv[j][i])
			{
				write(1, &argv[j][i], 1);
				i++;
			}
			j++;
		}
	}
}