/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:11:25 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/28 06:45:00 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// else
	//     sort_algo(llst);
	head = (*llst)->stack_a;
	while (head)
	{
		printf("%d", head->content);
		head = head->next;
	}
}
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		initstack(argc, argv);
	}
	else
		ft_exit_error();
}