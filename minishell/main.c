/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:38:03 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:13:51 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_command	*commands;
	char		*input;
	t_env		*envs;

	(void)av;
	if (ac != 1)
		return (printf("no need for args lady\n"), 1);
	setup_sig();
	envs = init_env(env);
	input = readline("minishell$ ");
	while (input)
	{
		add_history(input);
		commands = token_input(input, envs);
		ft_executing(commands, envs);
		free_command(commands);
		free(input);
		input = readline("minishell$ ");
	}
	printf("exit");
	free_env(envs);
}
