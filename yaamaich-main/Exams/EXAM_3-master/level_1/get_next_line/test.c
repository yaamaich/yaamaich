#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

#endif

char *ft_strdup(char *line)
{
	int i = 0;
	char *dst = malloc(strlen(line) + 1);
	while (line[i])
	{
		dst[i] = line[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}
char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	char line[70000];
	static int b_read = 0;
	static int pos = 0;
	int i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while (42)
	{
		if (pos >= b_read)
		{
			b_read = read(fd, buff, BUFFER_SIZE);
			pos = 0;
			if (b_read == 0)
				break;
		}
		line[i++] = buff[pos++];
		if (buff[pos - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(line));
}
int main()
{
	int i = open("myfile.txt", O_RDWR | O_CREAT, 777);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
 
}