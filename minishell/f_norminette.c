/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_norminette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:29:17 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:14:47 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	f_norminette(t_ms *head, t_command *command, t_env *env)
{
	command->fd_in = dup(STDIN_FILENO);
	command->fd_out = dup(STDOUT_FILENO);
	command->her_pipe[0] = -1;
	command->her_pipe[1] = -1;
	command->pipe[0] = -1;
	command->pipe[1] = -1;
	if (head && (head->type >= TOKEN_REDIR_IN && head->type <= TOKEN_HEREDOC))
	{
		command->redirections = mk_redirection(head);
		head = re_pipe(head);
	}
	ft_herdoc(command->redirections, command, env);
	command->next = NULL;
	if (env->exit_s)
		return ;
	if (head && head->type == TOKEN_PIPE)
	{
		if (head->next || head->type != TOKEN_EOF)
			command->next = mk_command(head->next, command, env);
	}
}

void	free_redirections(t_redirection *redir)
{
	t_redirection	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next_re;
		free(tmp->file);
		free(tmp);
	}
}

void	free_command(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	free(cmd->name);
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	close_fds(cmd);
	free_redirections(cmd->redirections);
	free_command(cmd->next);
	free(cmd);
}

void	free_env(t_env *envs)
{
	int	i;

	i = 0;
	while (envs->vars[i])
	{
		free(envs->vars[i]);
		i++;
	}
	free(envs->vars);
	free(envs);
}

void	ft_free_token(t_ms *token)
{
	free(token->value);
	free(token);
}
