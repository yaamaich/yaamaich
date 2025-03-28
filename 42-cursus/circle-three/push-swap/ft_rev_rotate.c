/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:20 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/28 07:32:43 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rev(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*lst = last;
}
void ft_rra(t_list **lst)
{
    ft_rev(lst);
    ft_printf("rra\n");
}
void ft_rrb(t_list **lst)
{
    ft_rev(lst);
	ft_printf("rrb\n");
}
void ft_rrr(t_list **stack_A, t_list **stack_B)
{
    ft_rev(stack_A);
    ft_rev(stack_B);
	ft_printf("rrr\n");
}
