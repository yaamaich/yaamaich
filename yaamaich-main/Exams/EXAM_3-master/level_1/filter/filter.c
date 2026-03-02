#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int ft_strcmp(char *s1, char *s2, int len)
{
    int i = 0;
    while (s1[i] == s2[i] && (s1[i] || s2[i]))
        i++;
    if (i == len)
        return 1;
    return 0;
}
int main (int argc, char **argv)
{
    char c;
    char *buff = malloc(1000000);
    int i = 0;
    int b;
    b = read(0, &c, 1);
    while (b > 0)
    {
        buff[i++] = c;
        b = read(0, &c, 1);
    }
    int j = 0;
    int len = strlen(argv[1]);
    while (buff[j])
    {
        if (ft_strcmp(argv[1], &buff[j], len))
        {
            int s = 0;
            while (s < len)
            {
                write (1, "*", 1);
                s++;
            }
            j += len;
        }else
        {
            write(1, &buff[j], 1);
            j++;
        }
    }
    return 0;
}