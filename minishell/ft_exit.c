/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:32:07 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:13:01 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	ft_atol(const char *str)
{
	long long			i;
	long long			sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result > LONG_MAX && sign == 1)
			return (-1);
		if (result > (unsigned long long)LONG_MAX + 1 && sign == -1)
			return (0);
	}
	return (result * sign);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_exit(t_command *cmd, t_env *env, int gtfo)
{
	free_env(env);
	free_command(cmd);
	exit(gtfo);
}

void	ft_exit(t_command *cmd, t_env *env)
{
	if (!cmd->args[1])
		exit(0);
	if (!is_numeric(cmd->args[1]))
	{
		ft_putstr_fd("exit\nminshell: exit: numeric argument required\n", 2);
		free_exit(cmd, env, 255);
	}
	if (cmd->args[2])
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		free_exit(cmd, env, 1);
	}
	if (ft_atol(cmd->args[1]) == -1 && ft_strlen(cmd->args[1]) >= 19)
	{
		ft_putstr_fd("exit\nminishell: exit: numeric argument required\n", 2);
		free_exit(cmd, env, 255);
	}
	if (ft_atol(cmd->args[1]) == 0 && ft_strlen(cmd->args[1]) >= 20)
	{
		ft_putstr_fd("exit\nminishell: exit: numeric argument required\n", 2);
		free_exit(cmd, env, 255);
	}
	free_exit(cmd, env, ft_atol(cmd->args[1]));
}
