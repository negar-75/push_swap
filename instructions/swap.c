#include "../push_swap.h"


static void	swap(t_stack **s)
{
    if (!s || !(*s) || !(*s)->next) 
        return; // If the stack is empty or has only one element, do nothing
    
    t_stack *first;
    t_stack *second;

    first = *s;
    second = (*s)->next;
    first->next = second->next;
    second->next = first;
    second->before = NULL;
    first->before = second;
    *s = second;
}

long	sa(t_stack **a, t_bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
	return (1);
}

long	sb(t_stack **b, t_bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
	return (1);
}