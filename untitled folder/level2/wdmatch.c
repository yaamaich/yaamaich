#include <unistd.h>

int ft_strcmp(char *str, char *str1)
{
    int i = 0 ;
    while (str[i] && str[i] == str1[i])
        i++;
    return (str[i] - str1[i]);
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        char str[1000];
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    str[k] = argv[1][i];
                    k++;
                    i++;
                }
                j++;
            }
            i++;
        }
        str[k] = '\0';
        if (ft_strcmp(str, argv[1]) != 0)
        {
            write(1, "\n", 1);
            return 0;
        }
        k = 0;
        while (str[k])
        {
             write(1, &str[k], 1);
             k++;
        }
    }
    write(1, "\n", 1);
}