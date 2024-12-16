/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:18:05 by yaamaich          #+#    #+#             */
/*   Updated: 2024/12/16 17:37:05 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}
static int ft_count(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
static char *ft_get_line(char *str)
{
	char *p;
	int i;
	int k;

	i = 0;
	if (!str)
		return (NULL);
	k = ft_count(str);
	p = malloc (k + 1);
	if (!p)
		return (NULL);
	while (i < k)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
static char *ft_read(int fd,char *str)
{
	char *buf;
	char *tmp;
	int len;
	
	if (!str)
		str = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		if (!str || ft_strchr(str, '\n'))
			break;
	}
	free(buf);
	return (str);
}
char *get_next_line(int fd)
{
	static char *str;
	char *line;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(str));
	str = ft_read(fd, str);
	if (str[0] == '\0' || !str)
		return (ft_free(str));
	line = ft_get_line(str);
	tmp = ft_substr(str, ft_count(str), ft_strlen(str) - ft_count(str));
	free(str);
	str = tmp;
	return (line);
}