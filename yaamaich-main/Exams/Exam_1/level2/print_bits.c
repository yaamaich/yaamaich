#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char c;
    while (i--)
    {
        c = (octet >> i & 1) + '0';
        write(1, &c, 1);
    }
}
int main()
{
    print_bits(1);
}