#include <unistd.h>

int check(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}
int main (int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        char str[1000];
        while (argv[1][i])
        {
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j] && check(str, argv[1][i]))
                {
                    str[k] = argv[1][i];     
                    k++;
                }
                j++;
            }
            i++;
        }
        str[k] = '\0';
        i = 0;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}