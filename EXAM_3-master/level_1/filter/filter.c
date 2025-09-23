#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strncmp(char *s1, char *s2, int len)
{
    int i = 0;
    while (s1[i] == s2[i] && i < len)
        i++;
    if (i == len)
        return 1;
    return 0;
}
int main(int argc, char **argv)
{
    char c;

    char *buf = malloc(10000000);
    int i = 0;
    int byte = read(0, &c, 1);
    while (byte > 0)
    {
        buf[i++] = c;
        byte = read(0, &c, 1);
    }
    int len = strlen(argv[1]);
    int j = 0;
    while (buf[j] != '\0')
    {
        if (ft_strncmp(argv[1], &buf[j], len))
        {
            for (int s = 0; s < len; s++)
                write(1, "*", 1);
            j += len;
        }
        else
        {
            write(1, &buf[j], 1);
            j++;
        }
    }
}