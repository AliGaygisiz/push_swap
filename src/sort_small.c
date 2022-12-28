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

void smallest_to_top_four(t_root *root)
{
    t_stack *a;

    a = root->a;
    if (lowest_index(a) == 1)
    {
        if (locate(a, 0)->nbr > median(a))
            ra(root);
        else
            sa(root);
    }
    else if (lowest_index(a) == 2)
    {
        if (locate(a, 3)->nbr > median(a))
        {
            ra(root);
            sa(root);
        }
        else
        {
            rra(root);
            rra(root);
        }
    }
    else if (lowest_index(a) == 3)
        rra(root);
}

void smallest_to_top_three(t_root *root)
{
    t_stack *a;

    a = root->a;
    if (lowest_index(a) == 1)
    {
        if (locate(a, 0)->nbr > median(a))
            ra(root);
        else
            sa(root);
    }
    else if (lowest_index(a) == 2)
    {
        if (locate(a, 1)->nbr == median(a))
        {
            ra(root);
            sa(root);
        }
        else
            rra(root);
    }
}

void sort_four(t_root *root)
{
    smallest_to_top_four(root);
    pb(root);
    smallest_to_top_three(root);
    pb(root);
    if (root->a->nbr > root->a->next->nbr)
        sa(root);
    pa(root);
    pa(root);
}
