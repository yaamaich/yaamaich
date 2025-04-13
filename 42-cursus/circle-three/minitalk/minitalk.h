/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:46:03 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/05 20:09:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stat 
{
	int		pid;
	int		bit_count;
	int		bits[8];
	char	our_char;
}				t_stat;

extern t_stat	g_stat;

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

#endif