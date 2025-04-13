/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:29:32 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*location;
	size_t	total_size;

	total_size = count * size;
	if (!total_size)
		return (malloc(0));
	if (total_size / count != size)
		return (NULL);
	location = malloc(total_size);
	if (!location)
		return (NULL);
	ft_bzero(location, total_size);
	return (location);
}
