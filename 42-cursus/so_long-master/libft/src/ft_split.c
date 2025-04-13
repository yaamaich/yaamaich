/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:07:48 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*free_table(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

int	count_substring(char *string, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*string)
	{
		if (*string != delimiter && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*string == delimiter)
			in_word = 0; 
		string++;
	}
	return (count);
}

void	*fill_table(char *string, char delimiter, char **table)
{
	int	i;
	int	start;
	int	end;

	end = 0;
	i = 0;
	while (string[end])
	{
		if (string[end] != delimiter)
		{
			start = end;
			while (string[end] != delimiter && string[end])
				end++;
			table[i] = ft_substr(string, start, end - start);
			if (!table[i])
				return (free_table(table, i));
			i++;
		}
		else
			end++;
	}
	table[i] = NULL;
	return (table);
}

char	**ft_split(char const *string, char c)
{
	char	**table;

	if (!string)
		return (NULL);
	table = malloc((count_substring((char *)string, c) + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	return (fill_table((char *)string, c, table));
}
