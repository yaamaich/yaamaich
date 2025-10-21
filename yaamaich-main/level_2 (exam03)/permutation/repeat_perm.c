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

void	ft_swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_sort(char *s)
{
	int i = 0, j;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				ft_swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
}

void	solve(char *copy, int start, int end)
{
	if (start == end)
	{
		puts(copy);
		return ;
	}
	int i = start;
	while (copy[i])
	{
		ft_sort(&copy[start]);
		ft_swap(&copy[start], &copy[i]);
		solve(copy, start + 1, end);
		ft_swap(&copy[start], &copy[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int len = ft_strlen(av[1]);
	char *copy = ft_strdup(av[1]);
	solve(copy, 0, len - 1);
}