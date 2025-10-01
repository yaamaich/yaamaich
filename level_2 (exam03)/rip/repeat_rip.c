#include <stdio.h>
#include <string.h>
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int	is_valid(char *s)
{
	int i = 0, bal = 0;

	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			bal--;
			if (bal < 0)
				return 0;
		}
		i++;
	}
	return (bal == 0);
}

void	rip(char *s, int i, int left, int right)
{
	if (left == 0 && right == 0)
	{
		if (is_valid(s))
			puts(s);
		return;
	}
	int j = i;
	while (s[j])
	{
		if (s[j] == '(' && left > 0)
		{
			s[j] = ' ';
			rip(s, i + 1, left - 1, right);
			s[j] = '(';
		}
		else if (s[j] == ')' && right > 0)
		{
			s[j] = ' ';
			rip(s, i + 1, left, right - 1);
			s[j] = ')';
		}
		j++;
	}
}

int main(int ac, char **av)
{
	int len = ft_strlen(av[1]);
	int left = 0, right = 0;
	char s[len + 1];
	int i = 0;
	while (i < len)
	{
		s[i] = av[1][i];
		i++;
	}
	s[i] = '\0';
	i = 0;
	while (i < len)
	{
		if (s[i] == '(')
			left++;
		else if (s[i] == ')')
		{
			if (left > 0)
				left--;
			else
				right++;
		}
		i++;
	}
	rip(s, 0, left, right);
}