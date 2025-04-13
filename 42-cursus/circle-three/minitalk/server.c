/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:45:51 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/05 19:32:14 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_stat	g_stat = {0, 0, {0}, 0};

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

void	reset_if_needed(int sender_pid)
{
	int	i;

	i = 0;
	if (g_stat.pid != 0 && g_stat.pid != sender_pid)
	{
		g_stat.bit_count = 0;
		g_stat.our_char = 0;
		while (i < 8)
			g_stat.bits[i++] = 0;
		g_stat.pid = sender_pid;
	}
	if (g_stat.pid == 0)
		g_stat.pid = sender_pid;
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	int	i;

	i = -1;
	(void)context;
	reset_if_needed(info->si_pid);
	if (g_stat.pid == 0)
		g_stat.pid = info->si_pid;
	if (g_stat.bit_count < 8)
	{
		if (signum == SIGUSR1)
			g_stat.bits[g_stat.bit_count] = 0;
		else
			g_stat.bits[g_stat.bit_count] = 1;
		g_stat.bit_count++;
	}
	if (g_stat.bit_count == 8)
	{
		while (++i < 8)
			g_stat.our_char = (g_stat.our_char << 1) | g_stat.bits[i];
		ft_putchar(g_stat.our_char);
		g_stat.bit_count = 0;
		g_stat.our_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	print_server();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Hahuwa g_stat.pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
