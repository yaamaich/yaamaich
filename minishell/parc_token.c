/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:23:20 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 15:54:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	commands(t_ms *head)
{
	int	i;

	i = 0;
	while (head->type == TOKEN_WORD
		|| head->type == TOKEN_SQUOTE || head->type == TOKEN_DQUOTE)
	{
		i++;
		head = head->next;
		if (!head || head->type == TOKEN_EOF)
			break ;
	}
	return (i);
}

t_ms	*re_pipe(t_ms *head)
{
	while (head && !(head->type == TOKEN_PIPE))
		head = head->next;
	return (head);
}

t_redirection	*mk_redirection(t_ms *head)
{
	t_redirection	*redirection;

	if (!head || (head->type == TOKEN_PIPE || head->type == TOKEN_EOF))
		return (NULL);
	if (!(head->type >= TOKEN_REDIR_IN && head->type <= TOKEN_HEREDOC))
		return (mk_redirection(head->next));
	redirection = malloc(sizeof(t_redirection));
	redirection->type = head->type;
	redirection->next_re = NULL;
	head = head->next;
	if (!head || head->type == TOKEN_EOF)
		return (free(redirection), NULL);
	redirection->file = ft_strdup(head->value);
	redirection->type_of_file = head->type;
	redirection->next_re = mk_redirection(head->next);
	return (redirection);
}

t_ms	*skip_red(t_ms *head)
{
	while (head && (head->type >= TOKEN_REDIR_IN
			&& head->type <= TOKEN_HEREDOC))
	{
		head = head->next;
		if (head != NULL)
			head = head->next;
	}
	return (head);
}

t_command	*mk_command(t_ms *head, t_command *prev, t_env *env)
{
	t_command	*command;

	if (!head || head->type == TOKEN_EOF)
		return (NULL);
	command = malloc(sizeof(t_command));
	parc_args(head, command);
	command->redirections = NULL;
	command->prev = prev;
	command->is_builtin = is_builtin(command->name);
	while (head->type >= TOKEN_WORD && head->type <= TOKEN_DQUOTE)
	{
		head = head->next;
		if (!head || head->type == TOKEN_EOF)
			break ;
	}
	f_norminette(head, command, env);
	if (env->exit_s)
		return (command);
	return (command);
}
