/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:18:05 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 20:44:35 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_get_line(char *str)
{
	char	*ptr;
	int		i;

	if (!str || str[0] == '\0')
		return (NULL);
	ptr = malloc(ft_count(str) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

static char	*ft_read(int fd, char *str)
{
	char	*buf;
	char	*tmp;
	int		len;

	if (!str)
		str = ft_strdup("");
	if (!str)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(str), NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		if (!str || ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;

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
int check_str(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else if (str[i] == 'P')
			i++;
		else if (str[i] == '0')
			i++;
		else if (str[i] == 'E')
			i++;
		else if (str[i] == 'C')
			i++;
		else if (str[i] == '\n' && str[i + 1] == '\0')
			i++;
		else 
			return 0;
	}
	return 1;
}
int main()
{
	int i = open("text.txt",  O_RDONLY | O_CREAT);
	char *ptr;
	while ((ptr = get_next_line(i)) && (check_str(ptr)))
		printf("%s", ptr);
}