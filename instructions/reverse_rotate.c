#include "../push_swap.h"

static void reverse_rotate(t_stack **a)
{
    if (!a || !(*a) || !(*a)->next)
        return;

    t_stack *current;
    t_stack *last;

    current = *a;
    while (current->next->next)
        current = current->next;
    
    last = current->next;
    current->next = NULL;
    last->next = *a;
    last->before = NULL;
    if (*a)
        (*a)->before = last;
    *a = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}