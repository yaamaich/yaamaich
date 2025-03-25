#include <stdlib.h>
#include <unistd.h>

int count_word(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] == 32 ||(str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i])
    {
        while (str[i] && (str[i] == 32 ||(str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i])
            count++;
        while (str[i] >= 33 && str[i] <= 126)
            i++;
    }
    return count;
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
       int i = 0;
       int k = 0;
       int n = 0;
       char **str;
       str = malloc (sizeof(char *) * (count_word(argv[1]) + 1));
       while (argv[1][i])
       {
            while (argv[1][i] && (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)))
                i++;
            int j = i;
            int count = 0;
            while ((argv[1][j] >= 33 && argv[1][j] <= 126))
            {
                j++;
                count++;
            }
            if (count > 0)
            {
                str[n] = malloc (sizeof(char) * (count + 1));
                k = 0;
                while ((argv[1][i] >= 33 && argv[1][i] <= 126))
                {
                    str[n][k] = argv[1][i];
                    i++;
                    k++;
                }
                str[n][k] = '\0';
                n++;
            }
       }
       str[n] = NULL;
        if (count_word(argv[1]) > 1)
        {
            n = 1;
            while (str[n])
            {
                k = 0;
                while (str[n][k])
                {
                    write(1, &str[n][k], 1);
                    k++;
                }
                write(1, " ", 1);
                n++;
            }
            k = 0;
            while (str[0][k])
            {
                write(1, &str[0][k], 1);
                k++;
            }
        }else
        {
            n = 0;
            while (str[n])
                {
                    k = 0;
                    while (str[n][k])
                    {
                        write(1, &str[n][k], 1);
                        k++;
                    } 
                    n++;
                }
        }
    }
    write(1, "\n", 1);
}