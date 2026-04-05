/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_norminette2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:17:23 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:14:42 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(t_command *cmd)
{
	if (cmd->fd_in != -1)
		close(cmd->fd_in);
	if (cmd->fd_out != -1)
		close(cmd->fd_out);
	if (cmd->her_pipe[0] != -1)
		close(cmd->her_pipe[0]);
	if (cmd->her_pipe[1] != -1)
		close(cmd->her_pipe[1]);
	if (cmd->pipe[1] != -1)
		close(cmd->pipe[1]);
	if (cmd->pipe[0] != -1)
		close(cmd->pipe[0]);
}
