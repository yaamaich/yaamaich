/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:33:21 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/08 01:45:54 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char **ft_pplit(char conpt *p, char c)
// {
	
// }
// #include <stdio.h>
// #include "libft.h"
// int count_word(char *p, char c)
// {
// 	int i;
// 	int count;

// 	count = 0;
// 	i = 0;
// 	while (p[i])
// 	{
// 		if((p[i] != c && p[i + 1] == '\0') || (p[i] != c && p[i + 1] == c))
// 			count++;
// 		i++;
// 	}
	
// 	return count;
// }
// char **ft_split(char const *s, char c)
// {
// 	int i;
// 	int start;
// 	char **split;
	
// 	split = malloc(count_word(s, c) * sizeof(char *));

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c &&s[i + 1] != '\0')
// 			start = i;
// 		else if (s[1] == c)
// 		{
// 			*split = ft_substr(s,start,i - start);
			
// 		}
// 		i++;
// 	}
// }
// int main ()
// {
// 	char c[] = "yahya amaiche yea      ddd";
// 	printf("%d", fill_word(c, ' ')); 
// }
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int count_word(char *p, char c)
{
	int i;
	int count = 0;
	i = 0;
	while (p[i])
	{
		if ((p[i] != c && (p[i + 1] == '\0' || p[i + 1] == c)))
			count++;
		i++;
	}
	return count;
}

char **ft_split(char const *s, char c)
{
	int i = 0;
	int j = 0;
	int start;
	char **split;

	split = malloc((count_word((char *)s, c) + 1)* sizeof(char *));
	if (!split)
		return NULL;

	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split[j++] = ft_substr(s, start, i - start);
		}
	}
	split[j] = NULL;
	return split;
}

int main()
{
	char str[] = "yahya amaiche yea ddd";
	char **result = ft_split(str, ' ');
	int i = 0;

	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return 0;
}
