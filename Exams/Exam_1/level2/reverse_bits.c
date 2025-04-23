#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char result = 0;
    while (i--)
    {
        result = (result << 1) | (octet & 1);
        octet >> 1;
    }
    return result;
}