#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int k;

    k = 0;
    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                k = argv[1][i] - 'a';
                while (k >= 0)
                {
                    write(1, &argv[1][i], 1);
                    k--;
                }
            }
             if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                k = argv[1][i] - 'A';
                while (k >= 0)
                {
                    write(1, &argv[1][i], 1);
                    k--;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
}