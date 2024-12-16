/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:17:13 by yaamaich          #+#    #+#             */
/*   Updated: 2024/12/16 17:44:59 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *ft_get_line(char *str)
{
	
}
static char *ft_read(int fd, char str)
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
	static char *str;
	char *line;
	char *tmp;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0);
		return NULL;
	str = ft_read(fd , str);
	if (!str || str[0] == '\0')
		return (ft_free(str));
	line = ft_get_line(str);
	
	
	
}