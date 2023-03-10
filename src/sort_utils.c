#include "../push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *tmp;
    int     nbr;

    tmp = stack->next;
    nbr = stack->nbr;
    while (tmp != 0)
    {
        if (nbr > tmp->nbr)
            return (0);
        nbr = tmp->nbr;
        tmp = tmp->next;
    }
    return (1);
}

void send_sort(t_root *root)
{
    if (stack_len(root->a) == 2)
        sort_two(root);
    else if (stack_len(root->a) == 3)
        sort_three(root);
    else if (stack_len(root->a) == 4)
        sort_four(root);
}
