#include <stdio.h>

char	*ft_bzero(void *s, size_t n)
{
	unsigned char *p = s;

	while (--n > 0)
	{
		*p = 0;
		p++;
	}
	return s;
}

int main ()
{
	char c[10] ;

	ft_bzero(c, sizeof(c));
	printf("%s", c);
}