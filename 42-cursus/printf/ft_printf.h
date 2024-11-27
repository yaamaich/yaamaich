/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:20:28 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/26 16:20:33 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(long n, int base, char type);
int	ft_putunsnbr(unsigned int n);
int	ft_putptr(void *s);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

#endif
