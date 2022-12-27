#include "../push_swap.h"
#include <stdlib.h>

float median(t_stack *stack)
{
    int *nbrs;
    int len;
    float median;
    int i;
    int j;

    i = 0;
    j = 0;
    len = stack_len(stack);
    nbrs = malloc(len * sizeof(int));
    if (!nbrs)
        return (0);
    while (stack != NULL)
    {
        nbrs[i] = stack->nbr;
        stack = stack->next;
        i++;
    }
    ft_printf("%d\n", nbrs[0]);
    ft_printf("%d\n", nbrs[1]);
    ft_printf("%d\n", nbrs[2]);
    return (0);
}

