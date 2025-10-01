#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int    ft_strlen(char *s)
{
	int    i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strdup(char *s)
{
	char    *res;
	int        i;

	if (!s)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void    ft_swap(char *c1, char *c2)
{
	char    tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void ft_sort(char *str)
{
	int i, j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
			   ft_swap(&str[i], &str[j]);
			}
			j++;
		}
		i++;
	}
}

void    solve(char *copy, int start, int end)
{
	int    i;

	if (start == end)
	{
		puts(copy);
		return ;
	}
	i = start;
	while (copy[i])
	{
		ft_sort(&copy[start]);
		ft_swap(&copy[start], &copy[i]);
		solve(copy, start + 1, end);
		ft_swap(&copy[start], &copy[i]);
		i++;
	}
}

int    main(int ac, char **av)
{
	int		len;
	char	*copy;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	copy = ft_strdup(av[1]);
	if (!copy)
		return (1);
	solve(copy, 0, len - 1);
	free(copy);
	return (0);
}