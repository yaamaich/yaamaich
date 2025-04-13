/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:33:09 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar(char c, t_flags flags)
{
	int	written;

	written = 1;
	while (flags.width-- > 1 && !flags.minus)
		written += write(1, " ", 1);
	write(1, &c, 1);
	while (flags.width-- > 0 && flags.minus)
		written += write(1, " ", 1);
	return (written);
}

int	ft_putstr(char *str, t_flags flags)
{
	int	written;
	int	len;

	written = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision && flags.precision_value < len)
		len = flags.precision_value;
	while (flags.width-- > len && !flags.minus)
		written += write(1, " ", 1);
	written += write(1, str, len);
	while (flags.width-- >= len && flags.minus)
		written += write(1, " ", 1);
	return (written);
}
