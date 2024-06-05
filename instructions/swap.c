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