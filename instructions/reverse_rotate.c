#include "../push_swap.h"

static void	reverse_rotate(t_stack **a)
{
    if (!a || !(*a) || !(*a)->next) {
        return;
    }
    t_stack *current;
    
    current = *a;
    while(current->next)
        current = current->next;
    if (current->before)
        current->before->next = NULL;
    (*a)->before = current;
    current->before = NULL;
    current->next = *a;
    *a = current;
}
long	rra(t_stack **a, t_bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
	return (1);
}

long	rrb(t_stack **b, t_bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
	return (1);
}

long	rrr(t_stack **a, t_stack **b, t_bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
	return (1);
}