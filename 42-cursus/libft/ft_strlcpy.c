/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:54:05 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/01 05:48:41 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t    ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t    src_len;
    src_len = ft_strlen((char *)src);
    if (!dest || size == 0)
        return (src_len);
    if (src_len + 1 < size)
        ft_memcpy(dest, src, src_len + 1);
    else 
    {
        ft_memcpy(dest, src, size - 1);   
        dest[size - 1] = '\0';
    }
    return (src_len);
}
