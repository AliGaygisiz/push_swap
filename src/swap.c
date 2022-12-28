#include "../push_swap.h"

void refactor(t_root *root)
{
    root->a = stack_first(root->a);
    root->b = stack_first(root->b);
    root->a_len = stack_len(root->a);
    root->b_len = stack_len(root->b);
    reindex(root->a);
    reindex(root->b);
    print_stack(root);
}

void sa(t_root *root)
{
    t_stack *a;
    t_stack *new_a;

    a = root->a;
    if (stack_len(a) < 2)
        return;
    new_a = a->next;
    a->next = new_a->next;
    if (stack_len(root->a) > 2)
        new_a->next->previous = a;
    a->previous = new_a;
    new_a->next = a;
    new_a->previous = 0;
    ft_printf("sa\n");
    refactor(root);
}	

void sb(t_root *root)
{
    t_stack *b;
    t_stack *new_b;

    b = root->b;
    if (stack_len(b) < 2)
        return;
    new_b = b->next;
    b->next = new_b->next;
    if (stack_len(root->b) > 2)
        new_b->next->previous = b;
    b->previous = new_b;
    new_b->next = b;
    new_b->previous = 0;
    ft_printf("sb\n");
    refactor(root);
}	

static void ss_a(t_root *root)
{
    t_stack *a;
    t_stack *new_a;

    a = root->a;
    if (stack_len(a) < 2)
        return;
    new_a = a->next;
    a->next = new_a->next;
    a->previous = new_a;
    new_a->next = a;
    new_a->previous = 0;
    refactor(root);
}	

static void ss_b(t_root *root)
{
    t_stack *b;
    t_stack *new_b;

    b = root->b;
    if (stack_len(b) < 2)
        return;
    new_b = b->next;
    b->next = new_b->next;
    b->previous = new_b;
    new_b->next = b;
    new_b->previous = 0;
    refactor(root);
}	

void ss(t_root *root)
{
    ss_a(root);
    ss_b(root);
    ft_printf("ss\n");
    print_stack(root);
}
