/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:51:07 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 16:14:56 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_work_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

static int	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	*free_split(char **split, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free(split[k]);
		k++;
	}
	free(split);
	return (NULL);
}

static char	**my_split(char const *s, char c, char **split, int end)
{
	int	j;
	int	start;

	j = 0;
	start = 0;
	split = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (s[end])
	{
		while (s[end] == c)
			end++;
		if (s[end] != '\0')
		{
			start = end;
			while (s[end] && s[end] != c)
				end++;
			split[j] = ft_substr(s, start, end - start);
			if (!split[j])
				return (free_split(split, j));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	return (my_split(s, c, split, i));
}
