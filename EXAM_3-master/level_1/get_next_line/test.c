#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
    static char buffer[BUFFER_SIZE];
    char line [70000];
    static int be_read = 0;
    static int pos = 0;
    int i = 0;
    if (fd < 0|| BUFFER_SIZE < 1)
        return NULL;
    while (1)
    {
        if (pos >= be_read)
        {
            be_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if(be_read <= 0)
                break;
        }
        line[i++] = buffer[pos++];
        if (buffer[pos - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return NULL;
    return ft_strdup(line);
}
int main()
{
    int i = open("myfile.txt", O_RDWR | O_CREAT, 777);
    printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));
        printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));    printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));

}