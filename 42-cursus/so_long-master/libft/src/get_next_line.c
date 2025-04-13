/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:18:59 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/06 21:27:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*read_line(int fd, char **line)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*line = ft_strjoin2(*line, buffer);
		if (ft_strchr2(*line, '\n') >= 0)
			return (free(buffer), *line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buffer), free(*line), *line = NULL, NULL);
	return (free(buffer), *line);
}

char	*extract_line(char **line)
{
	char	*extracted;
	int		nl_index;
	char	*temp;

	if (!line || !*line)
		return (free(*line), *line = NULL, NULL);
	nl_index = ft_strchr2(*line, '\n');
	if (nl_index >= 0)
	{
		extracted = ft_substr2(*line, 0, nl_index + 1);
		temp = ft_strdup2(*line + nl_index + 1);
		free(*line);
		*line = temp;
		if (!extracted || (*line && !**line))
			return (free(*line), *line = NULL, extracted);
		return (extracted);
	}
	return (extracted = ft_strdup2(*line), 
		free(*line), *line = NULL, extracted);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(line), line = NULL, NULL);
	line = read_line(fd, &line);
	return (extract_line(&line));
}
