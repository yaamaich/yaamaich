/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:11:25 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/21 09:05:00 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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
void	check_sorting(t_swap **llst)
{
	t_list	*head;

	if (is_sorted((*llst)->stack_a))
		ft_exit_error();
	if ((*llst)->asize == 2)
		ft_sa(&(*llst)->stack_a);
	else if ((*llst)->asize == 3)
		sort_3(&(*llst)->stack_a);
	else if ((*llst)->asize <= 5)
		sort_5(&(*llst)->stack_a, &(*llst)->stack_b);
    else
        sort_algo(llst);
	head = (*llst)->stack_a;
	while (head)
	{
		printf("%d", head->content);
		head = head->next;
	}
}
void	ft_usesplit(char *str, t_swap **sswap)
{
	int		k;
	char	**c;

	k = 0;
	c = ft_split(str, ' ');
	while (c[k])
	{
		if ((c[k][0] == '0' && c[k][1] != '\0'))
		{
			ft_exit_error();
		}
		if (ft_check_double((*sswap)->stack_a, ft_atoi(c[k])) == 1)
		{
			ft_exit_error();
		}
		ft_lstadd_back(&(*sswap)->stack_a, ft_lstnew(ft_atoi(c[k])));
		(*sswap)->asize++;
        (*sswap)->stack_a->index++;
		k++;
	}
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
		if (ft_check_double(swap->stack_a, ft_atoi(str[i])) == 1)
			ft_exit_error();
		else if ((str[i][0] == '0' && str[i][1] != '\0'))
			ft_exit_error();
		ft_usesplit(str[i], &swap);
		i++;
	}
	check_sorting(&swap);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		initstack(argc, argv);
	}
	ft_exit_error();
}