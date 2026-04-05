/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_token_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:40:11 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 15:54:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", 99) == 0)
		return (2);
	if (ft_strncmp(cmd, "cd", 99) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 99) == 0)
		return (2);
	if (ft_strncmp(cmd, "export", 99) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 99) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 99) == 0)
		return (2);
	if (ft_strncmp(cmd, "exit", 99) == 0)
		return (1);
	return (0);
}

void	parc_args(t_ms *head, t_command *com)
{
	int	i;

	i = 0;
	com->args = malloc(999 * sizeof(char *));
	com->name = NULL;
	while (head)
	{
		head = skip_red(head);
		if (head && (head->type >= TOKEN_PIPE && head->type <= TOKEN_EOF))
			break ;
		if (head)
		{
			if (!i)
				com->name = ft_strdup(head->value);
			com->args[i++] = ft_strdup(head->value);
			head = head->next;
		}
	}
	com->args[i] = NULL;
}
