/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:10:02 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/04 20:21:25 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *list;
	if (!tmp || !tmp->next)
		return ;
	current = ft_lstlast(tmp);
	while (tmp->next->next)
		tmp = tmp->next;
	current->next = *list;
	tmp->next = NULL;
	*list = current;
}

void	ft_rra(t_list **lst)
{
	ft_rev(lst);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **lst)
{
	ft_rev(lst);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **stack_A, t_list **stack_B)
{
	ft_rev(stack_A);
	ft_rev(stack_B);
	ft_putstr_fd("rrr\n", 1);
}
