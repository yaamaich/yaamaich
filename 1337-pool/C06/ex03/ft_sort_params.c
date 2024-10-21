/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:10:11 by yaamaich          #+#    #+#             */
/*   Updated: 2024/07/16 23:32:39 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		j;
	int		k;
	char	*tmp;

	k = 0;
	if (argc >= 1)
	{
		while (++k < argc) 
		{
			j = 0;
			while (++j < argc)
			{
				if (ft_strcmp(argv[k], argv[j]) < 0)
				{
					tmp = argv[k];
					argv[k] = argv[j];
					argv[j] = tmp;
				}
			}
		}
		k = 0;
		while (++k < argc)
			ft_putstr(argv[k]);
	}
}
