/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:52:03 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
//segfaults in case of passing null pointer as haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t max_search)
{
	size_t	haystack_index;
	size_t	match_count;

	if (!haystack && !max_search)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	haystack_index = 0;
	while (haystack[haystack_index] && haystack_index < max_search)
	{
		match_count = 0;
		while (haystack_index + match_count < max_search && needle[match_count]
			&& haystack[haystack_index + match_count] == needle[match_count])
			match_count++;
		if (!needle[match_count])
			return ((char *)&haystack[haystack_index]);
		haystack_index++;
	}
	return (NULL);
}
