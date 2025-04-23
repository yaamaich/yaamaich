#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if (argv[1][k] == argv[2][j])
                    k++;
                j++;
            }
            i++;
        }
        if(k == i)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
}
