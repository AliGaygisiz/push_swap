#include "../push_swap.h"

void pa(t_root *root)
{
    t_stack *new_b;

    if (stack_len(root->b) == 0)
        return;
    if (root->a != 0)
    {
        new_b = root->b->next;
        root->a->previous = root->b;
        root->a->previous->next = root->a;
        root->a = root->a->previous;
        root->b = new_b;
        if (root->b != 0)
            root->b->previous = 0;
        root->a->previous = 0;
    }
    else
    {
        root->a = root->b;
        root->b = root->b->next;
        root->a->next = 0;
        root->b->previous = 0;
    }
    refactor(root);
}

void pb(t_root *root)
{
    t_stack *new_a;

    if (stack_len(root->a) == 0)
        return;
    if (root->b != 0)
    {
        new_a = root->a->next;
        root->b->previous = root->a;
        root->b->previous->next = root->b;
        root->b = root->b->previous;
        root->a = new_a;
        if (root->a != 0)
            root->a->previous = 0;
        root->b->previous = 0;
    }
    else
    {
        root->b = root->a;
        root->a = root->a->next;
        root->b->next = 0;
        root->a->previous = 0;
    }
    refactor(root);
}
