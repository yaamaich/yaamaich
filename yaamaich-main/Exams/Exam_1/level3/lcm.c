#include <unistd.h>
#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b)
{
    int i = 0;
    while (b)
    {
        i = b;
        b = a % b;
        a = i;
    }
    return a;
}
unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int i = (a * b) / gcd(a, b);
    return i;
}
int main()
{
    printf("%d", gcd(48, 18));
}