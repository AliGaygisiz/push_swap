#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void init_stack(t_root *root, int argc, char *inputs[])
{
    int i;

    i = 1;
    root->a = new_stack(ft_atoi(inputs[i]));
    while (++i < argc)
        stack_add_back(&root->a, new_stack(ft_atoi(inputs[i])));
    root->b = NULL;
    root->a_len = stack_len(root->a);
    root->b_len = stack_len(root->b);
}

void print_list(t_stack *start)
{
    while (start)
    {
        ft_printf("%d\n", start->nbr);
        start = start->next;
    }
}

void print_stack(t_root *root)
{
    int max_len;
    t_stack *a;
    t_stack *b;

    a = root->a;
    b = root->b;
    if (root->a_len > root->b_len)
        max_len = root->a_len;
    else
        max_len = root->b_len;
    while (max_len >= 1)
    {
        if (max_len <= root->a_len && max_len > root->b_len)
        {
            ft_printf("% -4d\n", a->nbr);
            a = a->next;
            max_len--;
        }
        else if (max_len > root->a_len && max_len <= root->b_len)
        {
            ft_printf("        % 4d\n", b->nbr);
            b = b->next;
            max_len--;
        }
        else
        {
            ft_printf("% -4d    % 4d\n", a->nbr, b->nbr);
            a = a->next;
            b = b->next;
            max_len--;
        }
    }
    ft_printf("-----    -----\n");
    ft_printf("  a        b\n");
    ft_printf("\n");
}

int find_lowest(t_stack *list)
{
    int lowest;

    lowest = list->nbr;
    while (list)
    {
        if (list->nbr < lowest)
            lowest = list->nbr;
        list = list->next;
    }
    return (lowest);
}

int main (int argc, char *argv[])
{
    t_root root;

    if (argc == 1)
        return (0);
    if (!check_errors(argc, argv))
    {
        ft_printf("Error\n");
        return (0);
    }
    // a = root.a;
    init_stack(&root, argc, argv);
    print_stack(&root);
    pb(&root);
    pb(&root);
    print_stack(&root);
    rr(&root);
    print_stack(&root);

    return 0;
}
