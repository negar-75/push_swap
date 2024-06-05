#include "../push_swap.h"

static void rotate(t_stack **s)
{
    if (!s || !(*s) || !(*s)->next)
        return;

    t_stack *temp;
    t_stack *current;

    current = *s;
    while (current->next)
    {
        current = current->next;
    }
    temp = *s;
    *s = (*s)->next;
    (*s)->before = NULL;
    current->next = temp;
    temp->next = NULL;
    temp->before = current;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}