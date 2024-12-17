/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:18:05 by yaamaich          #+#    #+#             */
/*   Updated: 2024/12/17 02:50:31 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    if (!str || str[0] == '\0')
        return (NULL);
    k = ft_count(str);
    p = malloc(k + 1);
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

static char *ft_read(int fd, char *str)
{
    char *buf;
    char *tmp;
    int len;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (free(str), NULL);
    len = 1;
    while (len)
    {
        len = read(fd, buf, BUFFER_SIZE);
        if (len == -1)
            return (free(buf), free(str), NULL);
        buf[len] = '\0';
        tmp = ft_strjoin(str, buf);
        free(str);
		 if (!tmp)
            return (free(buf), NULL);
        str = tmp;
        if (!str || ft_strchr(str, '\n'))
            break;
    }
    free(buf);
    buf = NULL;
    return (str);
}

char *get_next_line(int fd)
{
    static char *str;
    char *line;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (free(str), str = NULL, NULL);
    str = ft_read(fd, str);
    if (!str || str[0] == '\0')
        return (free(str), str = NULL, NULL);
    line = ft_get_line(str);
    if (!line)
        return (free(str), str = NULL, NULL);
    tmp = ft_substr(str, ft_count(str), ft_strlen(str) - ft_count(str));
    free(str);
    str = tmp;
    return (line);
}