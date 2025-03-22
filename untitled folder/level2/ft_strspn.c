#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j = 0;
    while (s[i] && accept[j] && s[i] == accept[j])
        i++, j++;
    return i;
}

int main()
{
    printf("%zu", ft_strspn("banana", "ban"));
}