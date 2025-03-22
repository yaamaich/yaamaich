#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
char **ft_split(char *str)
{
    char **st;
    int i = 0, n = 0, k = 0, word_len = 0;

    st = malloc(sizeof(char *) * (100));
    if (!st) return NULL;

    while (str[i])
    {
        while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
            i++;
        if (str[i])
        {
            word_len = 0;
            int j = i;
            st[n] = malloc(sizeof(char) * (100));
            k = 0;
            while (str[i] && (str[i] > 32 && str[i] <= 126))
                st[n][k++] = str[i++];
            st[n][k] = '\0';
            n++;
        }
    }
    st[n] = NULL;
    return st;
}
#include <stdio.h>
int		main(int ac, char **av)
{
	int i;
	char **words;

	i = 0;
	if (ac == 2)
	{
		words = ft_split(av[1]);
		while (words[i] != 0)
			i++;
		i--;
		while (i >= 0)
		{
			ft_putstr(words[i]);
			if (i > 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}