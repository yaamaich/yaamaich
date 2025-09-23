#include <unistd.h>
#include <string.h>
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
int main(int argc, char **argv)
{
    char c;
    char *buf = malloc (1000000);
    int b;
    int i = 0;
    int j = 0;
    b = read(0, &c, 1);
    while (b > 0)
    {
        buf[i++] = c;
        b = read(0, &c, 1);
    }
    int len = strlen(argv[1]);
    while (buf[j])
    {
        if (ft_strcmp(argv[1], &buf[j], len))
        {
            for (int s = 0; s < len ; s++)
                write(1, "*", 1);
            j += len;
        }else
        {
            write(1, &buf[j], 1);
            j++;
        }
    }
}