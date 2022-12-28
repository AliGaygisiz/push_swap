#include "../push_swap.h"

t_stack *locate(t_stack *stack, int index)
{
    while (stack != 0)
    {
        if (stack->index == index)
            return (stack);
        stack = stack->next;
    }
    return (0);
}

int lowest_index(t_stack *stack)
{
    t_stack *tmp;
    int nbr;
    int index;

    tmp = stack->next;
    nbr = stack->nbr;
    index = stack->index;
    while (tmp != 0)
    {
        if (nbr > tmp->nbr)
        {
            nbr = tmp->nbr;
            index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (index);
}

int highest_index(t_stack *stack)
{
    t_stack *tmp;
    int nbr;
    int index;

    tmp = stack->next;
    nbr = stack->nbr;
    index = stack->index;
    while (tmp != 0)
    {
        if (nbr < tmp->nbr)
        {
            nbr = tmp->nbr;
            index = tmp->index;
        }
        tmp = tmp->next;
    }
    return (index);
}
