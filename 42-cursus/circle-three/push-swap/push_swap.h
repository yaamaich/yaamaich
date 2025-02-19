#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

void ft_sa(t_list *list);
void ft_pa(t_list **pa, int put);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_atoi(const char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_freelst(t_list *list);



#endif