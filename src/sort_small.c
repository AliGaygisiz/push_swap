#include "../push_swap.h"

void sort_two(t_root *root)
{
    t_stack *a;

    ft_printf("sort two\n");
    a = root->a;
    if (a->nbr > a->next->nbr)
        sa(root);
}

void sort_three(t_root *root)
{
    t_stack *a;

    a = root->a;
    if (is_sorted(a))
        return;
    if (a->nbr > a->next->nbr && a->nbr < a->next->next->nbr)
        sa(root);
    else if (a->nbr < a->next->nbr && a->nbr > a->next->next->nbr)
        rra(root);
    else if (a->next->next->nbr < a->nbr 
            && a->next->next->nbr > a->next->nbr)
        ra(root);
    a = root->a;
    if (is_sorted(root->a))
        return;
    sa(root);
    a = root->a;
    if (a->nbr < a->next->nbr && a->nbr > a->next->next->nbr)
        rra(root);
    else if (a->nbr > a->next->nbr && a->nbr > a->next->next->nbr)
        ra(root);
}

void smallest_to_top(t_root *root)
{

}
