/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:13:20 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/25 23:53:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int	ft_putptr(void *ptr, int fd)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	ft_putstr("0x", fd);
	len += 2;
	aux = ft_putnbr((unsigned long)ptr, 16, 'x');
	len += aux;
	return (len);
}