/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:29:33 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/17 18:13:20 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_env *env)
{
	char	*pwd;

	pwd = ft_getenv(env, "PWD");
	if (pwd)
	{
		printf("%s\n", pwd);
		env->exit_s = 0;
		return (0);
	}
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		env->exit_s = 0;
	}
	else
	{
		env->exit_s = 1;
		perror("pwd");
	}
	free(pwd);
	return (0);
}
