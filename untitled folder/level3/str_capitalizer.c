#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        int i = 1;
        int j = 0;
        while (i < argc)
        {
            j = 0;
            if (i > 1)
                write(1, "\n", 1);
            if (argv[i][0] >= 'a' && argv[i][0] <= 'z')
            {
                argv[i][j] -= 32;
                 write(1, &argv[i][j], 1);
                j++;
            }
            if (argv[i][0] >= 'A' && argv[i][0] <= 'Z')
            {
                write(1, &argv[i][j], 1);
                j++;
            }    
            while (argv[i][j])
            {
                if (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
                {
                    if (argv[i][j + 1] > 32)
                    {
                        if (argv[i][j + 1] >= 'a' && argv[i][j + 1] <= 'z')
                            argv[i][j + 1] -= 32;
                    }

                }else if (argv[i][j] > 32 && !(argv[i][j - 1] == 32 || (argv[i][j - 1] >= 9 && argv[i][j - 1] <= 13)))
                {
                    if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                        argv[i][j] += 32;
                    
                }
                write(1, &argv[i][j], 1);
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}