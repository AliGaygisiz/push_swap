#include "../push_swap.h"

t_stack	*new_stack(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = 0;
	new->previous = 0;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != 0)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*stack_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->previous != 0)
	{
		stack = stack->previous;
	}
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *newarg)
{
	if (!stack || !newarg)
		return ;
	if (*stack == 0)
		*stack = newarg;
	else
	{
		newarg->previous = stack_last(*stack);
		(stack_last(*stack))->next = newarg;
	}
}

void	stack_add_front(t_stack **stack, t_stack *newarg)
{
	if (!!stack && !!newarg)
	{
		newarg->next = *stack;
		*stack = newarg;
	}
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != 0)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
	return (i);
}
