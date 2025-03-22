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
int main(int argc , char **argv)
{
    if (argc == 3)
    {
        int j = 0;
        int k = 0;
        char str[1000];
        while (argv[1][j])
        {
            if (check(str, argv[1][j]))
            {
                str[k] = argv[1][j];
                k++;
            }
            j++;
        }
        j = 0;
        while (argv[2][j])
        {
            if (check(str, argv[2][j]))
            {
                str[k] = argv[2][j];
                k++;
            }
            j++;
        }

        str[k] = '\0';
        k = 0;
        while (str[k])
        {
            write(1, &str[k], 1);
            k++;
        }
        }
    write(1, "\n", 1);
}