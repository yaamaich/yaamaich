#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int j = ft_strlen(argv[1]);
        j--;
        while (argv[1][i] && (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)))
            i++;
        while (j >= 0 && (argv[1][j] == 32 || (argv[1][j] >= 9 && argv[1][j] <= 13)))
            j--;
        while (i < j)
        {
            while((argv[1][i] >= 33 && argv[1][i] <= 126))
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            if (i + 1 < j) 
                write(1, " ", 1);
            while ((argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)))
                i++;
            i = i;
        }
    }
    write(1, "\n", 1);
}