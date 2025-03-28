/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:03:50 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/28 08:01:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void ft_digit(char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i])== 0)
			ft_exit_error();
		i++;
	}
}
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
void	ft_usesplit(char *str, t_swap **sswap)
{
	int		k;
	char	**c;

	k = 0;
	c = ft_split(str, ' ');
	while (c[k])
	{	
		ft_digit(c[k]);
		if (ft_check_double((*sswap)->stack_a, ft_atoi(c[k])) == 1)
			ft_exit_error();
		if ((*sswap)->stack_a == NULL)
			(*sswap)->stack_a = ft_lstnew((ft_atoi(c[k])));
		else
			ft_lstadd_back(&(*sswap)->stack_a, ft_lstnew(ft_atoi(c[k])));
		(*sswap)->asize++;
		(*sswap)->stack_a->index++;
		k++;
	}
	ft_free_split(c);
}
void	initstack(int size, char **str)
{
	t_swap	*swap;
	int		i;

	swap = malloc(sizeof(t_swap));
	swap->stack_a = NULL;
	swap->stack_b = NULL;
	swap->asize = 0;
	swap->bsize = 0;
	i = 1;
	while (i < size)
	{

		ft_usesplit(str[i], &swap);
		i++;
	}
	check_sorting(&swap);
}