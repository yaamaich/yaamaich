/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:33:21 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/13 02:30:08 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *p, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (p[i])
	{
		if ((p[i] != c && (p[i + 1] == '\0' || p[i + 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **split, int j)
{
    for (int k = 0; k < j; k++)
        free(split[k]);
    free(split);
}
char	**ft_split(char const *s, char c)
{
	char	**split;
	int	i;
	int	j;
	int start;

	i = 0;
	j = 0;
	if (!s || !(split = malloc((count_word((char *)s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(split[j++] = ft_substr(s, start, i - start)))
				return (free_split(split, j - 1), NULL);
		}
	}
	split[j] = NULL;
	return (split);
}

