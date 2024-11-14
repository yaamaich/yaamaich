/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:10:00 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/13 21:11:55 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// int main ()
// {
// 	t_list *list = NULL;

// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *node3 = ft_lstnew("Node 3");

// 	ft_lstadd_front(&list, node3);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node1);

// 	t_list *current = list;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	int i = ft_lstsize(list);
// 	printf("%d", i);
// 	current = list;
// 	while (current)
// 	{
// 		t_list *tmp = current;
// 		current = current->next;
// 		free(tmp);
// 	}

// }