#include "../push_swap.h"

static void	rotate(t_stack **s)
{
    if (!s || !(*s) || !(*s)->next) 
        return;
    t_stack *temp;
    t_stack *current;

    current = *s; 
    temp = *s;
    while(current->next)
    {
        current++;
    }
    current->next = temp;
    temp->next = NULL;
}

long	ra(t_stack **a, t_bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
	return (1);
}

long	rb(t_stack **b, t_bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
	return (1);
}

long	rr(t_stack **a, t_stack **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
	return (1);
}