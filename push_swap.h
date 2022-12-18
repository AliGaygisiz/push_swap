#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int             nbr;
    int             index;
    struct s_stack  *next;
    struct s_stack  *previous;
} t_stack;

typedef struct s_root
{
    struct s_stack  *a;
    struct s_stack  *b;
    int             a_len;
    int             b_len;
} t_root;

int     is_int(char *str);
int	    is_number(char *str);
char    *no_p(char *str);
int     check_dup(int argc, char *argv[]);
int     check_errors(int argc, char *argv[]);
t_stack	*new_stack(int nbr);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_first(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *newarg);
void	stack_add_front(t_stack **stack, t_stack *newarg);
int	    stack_len(t_stack *stack);
void    refactor(t_root *root);
void    sa(t_root *root);
void    sb(t_root *root);
void    ss(t_root *root);
void    pa(t_root *root);
void    pb(t_root *root);
void    ra(t_root *root);
void    rb(t_root *root);
void    rr(t_root *root);
void    rra(t_root *root);
void    rrb(t_root *root);
void    rrr(t_root *root);
int     is_sorted(t_stack *stack);
void    sort_two(t_root *root);
void    sort_three(t_root *root);
void    send_sort(t_root *root);
void    print_op(int op);
void    print_nodes(t_stack *stack);
void    reindex(t_stack *stack);
int lowest_index(t_stack *stack);

#endif
