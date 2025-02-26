/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:45:51 by yaamaich          #+#    #+#             */
/*   Updated: 2025/02/10 22:45:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void	print_server(void)
{
	ft_putstr("\033[1;34m");
	ft_putstr(" ███████ ███████ ██████  ██    ██ ███████ ██████  \n");
	ft_putstr(" ██      ██      ██   ██ ██    ██ ██      ██   ██ \n");
	ft_putstr(" ███████ █████   ██████  ██    ██ █████   ██████  \n");
	ft_putstr("      ██ ██      ██   ██  ██  ██  ██      ██   ██ \n");
	ft_putstr(" ███████ ███████ ██   ██   ████   ███████ ██   ██ \n");
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	signal_handler(int signum)
{
	static int	bit_count;
	static char	our_char;
	static int	bits[8];
	int			i;

	i = 0;
	if (signum == SIGUSR1)
		bits[bit_count] = 0;
	else
		bits[bit_count] = 1;
	bit_count++;
	if (bit_count == 8)
	{
		while (i < 8)
		{
			our_char = (our_char << 1) | bits[i];
			i++;
		}
		ft_putchar(our_char);
		bit_count = 0;
		our_char = 0;
	}
}

int	main(void)
{
	print_server();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr("Hahuwa pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
