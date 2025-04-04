/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:03:50 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/04 19:14:38 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_check_double(t_list *lst, int k)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content == k)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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

void	ft_checkerror(t_swap **swap, char **str, int k)
{
	int	i;

	i = k;
	if (valid_int(str[i]) == -1)
	{
		ft_free_split(str);
		ft_exit_error();
	}
	if (ft_check_double((*swap)->stack_a, ft_atoi(str[i])) == 1)
	{
		ft_free_split(str);
		ft_exit_error();
	}
}

void	ft_usesplit(int size, char **str, t_swap **sswap)
{
	int		k;
	int		i;
	char	**c;

	i = 1;
	while (i < size)
	{
		c = ft_split(str[i], ' ');
		if (!c[0])
			ft_exit_error();
		k = 0;
		while (c[k])
		{
			ft_checkerror(sswap, c, k);
			if ((*sswap)->stack_a == NULL)
				(*sswap)->stack_a = ft_lstnew((ft_atoi(c[k])));
			else
				ft_lstadd_back(&(*sswap)->stack_a, ft_lstnew(ft_atoi(c[k])));
			k++;
		}
		ft_free_split(c);
		i++;
	}
}
