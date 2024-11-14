/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:56:38 by yaamaich          #+#    #+#             */
/*   Updated: 2024/11/14 00:29:47 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	s;

	s = ft_lstsize(lst);
	i = 0;
	while (i < s - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
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
// 	// int i = ft_lstsize(list);
// 	// printf("%d", i);
// 	t_list *last = ft_lstlast(list);
// 	printf("%s",(char *)last->content );
// 	current = list;
// 	while (current)
// 	{
// 		t_list *tmp = current;
// 		current = current->next;
// 		free(tmp);
// 	}
// }