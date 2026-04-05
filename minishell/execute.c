/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:42:12 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:12:26 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_red(t_redirection *redirs, t_command *cmd)
{
	int	fd;

	while (redirs)
	{
		if (redirs->type == TOKEN_REDIR_IN)
			fd = open(redirs->file, O_RDONLY);
		else if (redirs->type == TOKEN_REDIR_OUT)
			fd = open(redirs->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redirs->type == TOKEN_APPEND)
			fd = open(redirs->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (redirs->type == TOKEN_HEREDOC)
			fd = cmd->her_pipe[0];
		if (fd == -1)
			return (perror("minishell"), 0);
		if (redirs->type == TOKEN_REDIR_IN || redirs->type == TOKEN_HEREDOC)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		redirs = redirs->next_re;
	}
	return (1);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	ft_exec(t_command	*commands, t_env *env)
{
	char	*com_path;
	char	*path;
	char	**paths;
	char	*temp;
	int		i;

	khadem_program(commands, env);
	path = ft_getenv(env, "PATH");
	paths = ft_split(path, ':');
	i = -1;
	while (path && paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		com_path = ft_strjoin(temp, commands->name);
		free(temp);
		if (access(com_path, X_OK) == 0)
		{
			free_paths(paths);
			if (execve(com_path, commands->args, env->vars) == -1)
				return (free(com_path), perror("minishell"), exit(126));
		}
		free(com_path);
	}
	return (ft_putstr_fd("minishell: command not found\n", STDERR_FILENO),
		free_paths(paths), exit(127));
}

int	ft_fork(t_command *cmd, t_env *env, t_command *allcmds)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (ft_wait(&env->exit_s, allcmds),
			perror("fork"), env->exit_s = 1, -1);
	return (0);
}

void	ft_executing(t_command *cmd, t_env *env)
{
	t_command	*current;

	if (!cmd)
		return ;
	if (cmd->is_builtin == 1 && (!cmd->prev && !cmd->next))
		builts_in(cmd, env, 1);
	else
	{
		current = cmd;
		while (current)
		{
			if (current->next)
				pipe(current->pipe);
			if (ft_fork(current, env, cmd))
				return ;
			if (current->pid == 0)
				child(current, env);
			else
			{
				father(current);
				current = current->next;
			}
		}
		ft_wait(&env->exit_s, cmd);
	}
}
