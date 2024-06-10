#include "../push_swap.h"

static void reverse_rotate(t_stack **s)
{
    if (!s || !(*s) || !(*s)->next)
        return; // If the stack is empty or has only one element, do nothing

    t_stack *current = *s;

    while (current->next->next)
        current = current->next;
    t_stack *last = current->next;
    current->next = NULL; 
    last->next = *s;
    last->before = NULL;
    (*s)->before = last;
    *s = last;
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