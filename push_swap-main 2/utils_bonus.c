/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:33:16 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/16 11:23:29 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	duplicated(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->data == tmp->data)
				return (-1);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int	sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	valid_int(char *str)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			&& (str[i + 1] == '+' || str[i + 1] == '-'))
			return (-1);
		else if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '\0'))
			return (-1);
		if (ft_strncmp(str, "-2147483648", 11) == 0)
			return (1);
		if (str[i] == '+' || str[i] == '-')
			i++;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		nb = nb * 10 + str[i] - '0';
		if (nb > INT_MAX)
			return (-1);
		i++;
	}
	return (1);
}

int	count_nodes(int ac, char **av)
{
	char	**numbers;
	int		count;
	int		nb;
	int		i;

	nb = 0;
	i = 1;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		count = 0;
		while (numbers[count])
			count++;
		nb += count;
		i++;
	}
	return (nb);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
