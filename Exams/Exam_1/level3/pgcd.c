#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int tmp;
    while (b)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        printf("%d", gcd(atoi(argv[1]), atoi(argv[2])));
    }
    printf("\n");
}