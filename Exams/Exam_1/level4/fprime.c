#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int isprime(int i)
{
    int j;
    j = 2;
    if (i <= 1)
        return 0;
    if (i == 2 || i == 3)
        return 1;
    if (i % 2 == 0 || i % 3 == 0)
        return 0;
    while (j * j <= i)
    {
        if (j % i == 0)
            return 0;
        i += 2;
    } 
    return 1;
}

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        int i = 2;
        int n = atoi(argv[1]);
        while (i <= n)
        {
            if (n % i == 0)
            {
                n = n / i;
                if (i <= n)
                    printf("%d*", i);
                else
                    printf("%d", i);
            }else 
                i++;
        }
    }
    printf("\n");
}