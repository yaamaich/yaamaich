#include "push_swap.h"

int is_sorted(t_list *list)
{
    t_list *temp;
    temp = list;
    while (temp->next)
    {
        if (temp->content > temp->next->content)
            return (0);
        temp = temp->next;
    }
    return (1);
}
int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        t_swap *swap;
        swap = malloc(sizeof(t_swap));
        swap->stack_a = NULL;
        swap->stack_b = NULL;
        swap->asize = 0;
        swap->bsize = 0;
        int i = 1;
        while (i < argc)
        {
            if (ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
            {
                ft_putstr_fd("Error\n", 2);
                return (0);
            }
            ft_lstadd_back(&swap->stack_a, ft_lstnew(ft_atoi(argv[i])));
            swap->asize++;
            i++;
        }
        if (is_sorted(swap->stack_a))
            return (0);
        if (swap->asize == 2)
            ft_sa(&swap->stack_a);
        else if (swap->asize == 3)
            sort_3(&swap->stack_a);
        else if (swap->asize <= 5)
            sort_5(&swap->stack_a, &swap->stack_b);
        ft_freelst(swap->stack_a);
        ft_freelst(swap->stack_b);
    }
    return (0);
}
