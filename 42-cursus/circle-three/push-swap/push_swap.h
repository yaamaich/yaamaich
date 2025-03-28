#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_swap;

void 	ft_sa(t_list **list);
void 	ft_sb(t_list **list);
void	ft_ra(t_list **lst);
void	ft_rb(t_list **lst);
void	ft_rr(t_list **stack_A, t_list **stack_B);
void	ft_rra(t_list **lst);
void	ft_rrb(t_list **lst);
void	ft_rev(t_list **list);
void	ft_rrr(t_list **stack_A, t_list **stack_B);
void	ft_ss(t_list **stack_A, t_list **satck_B);
void 	ft_pa(t_list **stack1, t_list **stack2);
void 	ft_pb(t_list **stack1, t_list **stack2);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_freelst(t_list *list);
void    sort_5(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	sort_algo(t_swap **swap);
int	is_sorted(t_list *list);
int	ft_check_double(t_list *lst, int k);
void	ft_usesplit(char *str, t_swap **sswap);
void	initstack(int size, char **str);
void	check_sorting(t_swap **llst);


#endif