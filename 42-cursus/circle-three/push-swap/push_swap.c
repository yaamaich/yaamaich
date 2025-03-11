#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        // تخصيص الذاكرة والتحقق من نجاح malloc
        t_swap *head = malloc(sizeof(t_swap));
        if (!head)
        {
            printf("Memory allocation failed.\n");
            return (1);
        }
        head->stack_a = NULL;
        head->stack_b = NULL;

        // إنشاء أول عنصر في stack_a
        head->stack_a = ft_lstnew(ft_atoi(argv[1]));
        if (!head->stack_a)  // التحقق من نجاح إنشاء العقدة الأولى
        {
            free(head);
            printf("Failed to create first node.\n");
            return (1);
        }

        // إضافة بقية العناصر إلى stack_a
        t_list *current = head->stack_a;
        int i = 2;
        while (i < argc)
        {
            current->next = ft_lstnew(ft_atoi(argv[i]));
            if (!current->next)  // التحقق من نجاح malloc في ft_lstnew
            {
                ft_freelst(head->stack_a);
                free(head);
                printf("Memory allocation failed.\n");
                return (1);
            }
            current = current->next;
            i++;
        }
        current->next = NULL;
        t_list *temp3 = head->stack_a;
        while (temp3)
        {
            printf("%ld\n", temp3->content);
            temp3 = temp3->next;
        }
        printf("check_a\n");
        ft_pb(&head->stack_b, &head->stack_a);
		ft_pb(&head->stack_b, &head->stack_a);
		t_list *temp1 = head->stack_b;
		while (temp1)
        {
            printf("%ld--\n", temp1->content);
            temp1 = temp1->next;
        }
        printf("push_b\n");
        ft_rr(&head->stack_a, &head->stack_b);
        t_list *temp4 = head->stack_a;
        t_list *temp5 = head->stack_b;
        while (temp4)
        {
            printf("%ld+\n", temp4->content);
            temp4 = temp4->next;
        }
        printf("rotate_a\n");
        while (temp5)
        {
            printf("%ld_\n", temp5->content);
            temp5 = temp5->next;
        }
        printf("rotate_b\n");

		ft_rrr(&head->stack_a, &head->stack_b);
        t_list *temp = head->stack_a;
		
		t_list *temp2 = head->stack_b;
		while (temp)
        {
            printf("%ld+\n", temp->content);
            temp = temp->next;
        }
        printf("rrotate_a\n");
		while (temp2)
        {
            printf("%ld_\n", temp2->content);
            temp2 = temp2->next;
        }
        printf("rrotate_b\n");
        // تحرير الذاكرة
        free(head);
    }
    return (0);
}
