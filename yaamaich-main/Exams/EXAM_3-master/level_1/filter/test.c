#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int ft_strcmp(char *s1, char *s2, int len)
{
    int i = 0;
    while(s1[i] == s2[i] && (s1[i] || s2[i]))
        i++;
    if (i == len)
        return 1;
    return 0; 
}
int main (int argc, char **argv)
{
    if (argc != 2)
        return 0;
    char c;
    char *buff = malloc (1000000);
    int b;
    int i = 0;
    b = read(0, &c, 1);
    while (b > 0)
    {
        buff[i++] = c;
        b = read(0, &c, 1);
    }
    int j = 0;
    int len = ft_strlen(argv[1]);
    while (buff[j])
    {
        if (ft_strcmp(argv[1], &buff[j], len))
        {
            int s = 0;
            while (s < len)
            {
                write(1, "*", 1);
                s++;
            }
            j += len;
        }else
        {
            write(1, &buff[j], 1);
            j++;
        }
    }
}