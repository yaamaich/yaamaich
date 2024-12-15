
#include "get_next_line_bonus.h"
#include <limits.h>

static char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

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

	if (!str)
		return (NULL);
	ptr = (char *)malloc(ft_count(str) + 1);
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
	char	*buffer;
	char	*tmp;
	int		num;

	if (!str)
		str = ft_strdup("");
	num = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (num)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		buffer[num] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
		if (!str || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0 || 
		read(fd, 0, 0) < 0)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_read(fd, str[fd]);
	if (str[fd][0] == '\0' || !str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(str[fd]);
	if (!line)
		return (ft_free(str[fd]));
	tmp = ft_substr(str[fd], ft_count(str[fd]),
			ft_strlen(str[fd]) - ft_count(str[fd]));
	free(str[fd]);
	str[fd] = tmp;
	return (line);
}
