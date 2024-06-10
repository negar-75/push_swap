#include "../push_swap.h"


static void swap(t_stack **s)
{
    if (!s || !(*s) || !(*s)->next)
        return;
    t_stack *first = *s;
    t_stack *second = (*s)->next;

    first->next = second->next;
    second->next = first;
    second->before = first->before;
    first->before = second;
    
    if (first->next)
        first->next->before = first;

    *s = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}