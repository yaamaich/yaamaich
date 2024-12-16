/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yup <yup@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:17:13 by yaamaich          #+#    #+#             */
/*   Updated: 2024/12/16 19:41:09 by yup              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char *ptr;
	int i;
	int k;
	
	i = 0;
	if (!str)
		return (NULL);
	k = ft_count(str);
	ptr = malloc (k + 1);
	if (!ptr)
		return (NULL);
	while (i < k)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}
static char *ft_read(int fd, char *str)
{
	char *tmp;
	char *buf;
	int len;

	if (!str)
		str = ft_strdup("");
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = ft_strjoin(str , buf); 
		free (str);
		str = tmp;
		if (!str || ft_strchr(str, '\n'))
			break;
	}
	free (buf);
	return (str);
}

char *get_next_line(int fd)
{
	static char *str[10240];
	char *line;
	char *tmp;
	
	if (fd > 10240)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0);
		return (NULL);
	str[fd] = ft_read(fd , str[fd]);
	if (!str || str[fd][0] == '\0')
		return (ft_free(str[fd]));
	line = ft_get_line(str[fd]);
	tmp = ft_substr(str[fd], ft_count(str[fd]), ft_strlen(str[fd]) - ft_count(str[fd]));
	free(str[fd]);
	str[fd] = tmp;
	return (line);
}
