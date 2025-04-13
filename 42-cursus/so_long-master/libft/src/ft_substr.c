/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:50:10 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t max_substring_len)
{
	char	*substring;
	size_t	substring_len;

	if (!s)
		return ((char *)s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substring_len = ft_strlen(s) - start;
	if (substring_len > max_substring_len)
		substring_len = max_substring_len;
	substring = malloc(substring_len + 1);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, substring_len + 1);
	return (substring);
}
