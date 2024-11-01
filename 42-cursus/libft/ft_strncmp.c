/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 06:48:00 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/01 06:26:09 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <stddef.h>

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
    if (n == 0)
        return 0;

    while (n > 0 && (*str1 || *str2))
    {
        unsigned char c1 = (unsigned char)*str1;
        unsigned char c2 = (unsigned char)*str2;

        if (c1 != c2)
            return c1 - c2;

        str1++;
        str2++;
        n--;
    }
    return 0;
}


