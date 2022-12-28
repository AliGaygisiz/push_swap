#include "../push_swap.h"
#include <stdio.h>

int *sort_median(int *nbrs, int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    while (i < (len - 1))
    {
        while (j < (len - 1))
        {
            if (nbrs[j] > nbrs[j + 1])
            {
                tmp = nbrs[j];
                nbrs[j] = nbrs[j + 1];
                nbrs[j + 1] = tmp;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (nbrs);
}

float median(t_stack *stack)
{
    int *nbrs;
    int len;
    int i;

    i = 0;
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
    sort_median(nbrs, len);
    if (len % 2 == 1)
        return (nbrs[(len - 1) / 2]);
    else if (len % 2 == 0)
        return (((nbrs[(len / 2) - 1] + nbrs[(len / 2)]) / (float)2));
    return (0);
}
