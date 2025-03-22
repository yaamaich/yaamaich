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
        int s;
        int j = ft_strlen(argv[1]);
        j--;
        while ((!(argv[1][j] >= 33 && argv[1][j] <= 126)) && j >= 0)
            j--;
        s = j;
        while ((argv[1][j] >= 33 && argv[1][j] <= 126) && j >= 0)
            j--;
        i = j + 1;
        while (i <= s && argv[1][j])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}