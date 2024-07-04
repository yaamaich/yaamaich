#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main ()
{
	char c[] = "yahya";
	printf("%d", ft_strlen(c));

}