/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:47:14 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/16 11:33:17 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack {
	struct s_stack	*next;
	int				data;
	int				index;
}	t_stack;

void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a, int print);
void		sb(t_stack **b, int print);
void		ss(t_stack **a, t_stack **b, int print);
void		ra(t_stack **a, int print);
void		rb(t_stack **b, int print);
void		rr(t_stack **a, t_stack **b, int print);
void		rra(t_stack **a, int print);
void		rrb(t_stack **b, int print);
void		rrr(t_stack **a, t_stack **b, int print);
void		free_list(t_stack **a);
void		sort_five(int ac, char **av, t_stack **a, t_stack **b);
void		sort_three(t_stack **a);
void		sort_two(t_stack **a);
t_stack		*sort_elements(int ac, char **av, t_stack **a, t_stack **b);
int			ft_atoi(const char *str);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *s, unsigned int start, size_t len);
void		assign_index(t_stack **a);
t_stack		*init_stack(int ac, char **av, t_stack *a);
int			count_nodes(int ac, char **av);
int			valid_int(char *str);
int			sorted(t_stack *a);
int			duplicated(t_stack *a);
void		ft_error(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_work_split(char **split);
void		free_stack(t_stack **a);

#endif