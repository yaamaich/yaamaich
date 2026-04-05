/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_token_tools_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:38:53 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 15:54:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ms	*link_and_unlink(t_ms *head)
{
	t_ms	*cur;
	t_ms	*tmp;

	if (!head)
		return (NULL);
	while (head && !ft_strlen(head->value) && head->type == TOKEN_WORD)
	{
		tmp = head;
		head = head->next;
		ft_free_token(tmp);
	}
	cur = head;
	while (cur && cur->next)
	{
		if (!ft_strlen(cur->next->value) && cur->next->type == TOKEN_WORD)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			ft_free_token(tmp);
		}
		else
			cur = cur->next;
	}
	return (head);
}

void	herdoc(t_command *com, t_redirection *red, t_env *env)
{
	char	*line;
	char	*old_line;

	reset_signals();
	close(com->her_pipe[0]);
	while (1)
	{
		old_line = readline("heredoc << ");
		if (!old_line || !ft_strncmp(old_line, red->file, 99))
		{
			free(old_line);
			break ;
		}
		if (red->type_of_file != TOKEN_DQUOTE
			&& red->type_of_file != TOKEN_SQUOTE)
			line = shorting_code(old_line, env);
		else
			line = old_line;
		write(com->her_pipe[1], line, ft_strlen(line));
		write(com->her_pipe[1], "\n", 1);
		free(line);
	}
	close(com->her_pipe[1]);
	exit(0);
}

int	make_herdoc(t_command *com, t_redirection *red, int key, t_env *env)
{
	int	status;

	if (key)
		close(com->her_pipe[0]);
	pipe(com->her_pipe);
	if (fork() == 0)
		herdoc(com, red, env);
	else
		wait(&status);
	close(com->her_pipe[1]);
	if (WIFSIGNALED(status))
		return (close(com->her_pipe[1]), 128 + WTERMSIG(status));
	return (0);
}

void	ft_herdoc(t_redirection *red, t_command *com, t_env *env)
{
	int	key;

	if (!red)
		return ;
	key = 0;
	while (red)
	{
		if (red->type == TOKEN_HEREDOC)
		{
			env->exit_s = make_herdoc(com, red, key, env);
			if (env->exit_s)
				break ;
			key = 1;
		}
		red = red->next_re;
	}
}

t_command	*short_token_input(t_ms *head, t_env *env)
{
	t_command	*com;

	girv(head, env);
	glue_tokens(head);
	if (head)
		env->exit_s = 0;
	head = link_and_unlink(head);
	com = mk_command(head, NULL, env);
	ft_free(head);
	if (env->exit_s)
	{
		free_command(com);
		com = NULL;
	}
	return (com);
}
