#include <unistd.h>
int ft_size (char *str)
{
    int i = 0; 
    while (str[i])
        i++;
    return i;
}
int main (int argc , char **argv)
{
    if (argc == 4)
    {
        if (ft_size(argv[2]) > 1 || ft_size(argv[3]) > 1)
        {
            write(1, "\n", 1);
            return 0;
        }
        int i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
                argv[1][i] = argv[3][0];
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}