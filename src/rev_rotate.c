#include "../push_swap.h"

void rra(t_root *root)
{
    t_stack *old_start;
    t_stack *new_start;

    if (stack_len(root->a) < 2)
        return;
    old_start = root->a;
    new_start = stack_last(root->a);
    new_start->previous->next = 0;
    old_start->previous = new_start;
    new_start->next = old_start;
    new_start->previous = 0;
    root->a = new_start;
    ft_printf("rra\n");
    refactor(root);
}

void rrb(t_root *root)
{
    t_stack *old_start;
    t_stack *new_start;

    if (stack_len(root->b) < 2)
        return;
    old_start = root->b;
    new_start = stack_last(root->b);
    new_start->previous->next = 0;
    old_start->previous = new_start;
    new_start->next = old_start;
    new_start->previous = 0;
    root->b = new_start;
    ft_printf("rrb\n");
    refactor(root);
}

static void rrr_a(t_root *root)
{
    t_stack *old_start;
    t_stack *new_start;

    if (stack_len(root->a) < 2)
        return;
    old_start = root->a;
    new_start = stack_last(root->a);
    new_start->previous->next = 0;
    old_start->previous = new_start;
    new_start->next = old_start;
    new_start->previous = 0;
    root->a = new_start;
    refactor(root);
}

static void rrr_b(t_root *root)
{
    t_stack *old_start;
    t_stack *new_start;

    if (stack_len(root->b) < 2)
        return;
    old_start = root->b;
    new_start = stack_last(root->b);
    new_start->previous->next = 0;
    old_start->previous = new_start;
    new_start->next = old_start;
    new_start->previous = 0;
    root->b = new_start;
    refactor(root);
}

void rrr(t_root *root)
{
    rrr_a(root);
    rrr_b(root);
    ft_printf("rrr\n");
    print_stack(root);
}
