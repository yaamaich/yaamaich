#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *ft_strdup(char *line)
{
    char *copy = malloc(strlen(line) + 1);
    int i = 0;
    while(line[i])
    {
        copy[i] = line[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int b_pos = 0;
    static int b_read = 0;
    int i = 0;
    if(fd < 0 || BUFFER_SIZE < 1)
        return NULL;
    while(42)
    {
        if(b_pos >= b_read)
        {
            b_read = read(fd,buffer,BUFFER_SIZE);
            b_pos = 0;
            if(b_read <= 0)
                break;
        }
        line[i++] = buffer[b_pos++];
        if(buffer[b_pos -1] == '\n')
            break;
    }
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return ft_strdup(line);
}
