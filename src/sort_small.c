#include "../push_swap.h"

void sort_two(t_root *root)
{
    t_stack *a;

    a = root->a;
    if (a->nbr > a->next->nbr)
        sa(root);
}
