#include "../../push_swap.h"
/*
this function will calculate for each node in stack a 
how many rotations we need to push number in stack b in descending order
it will go through all nodes and get return the lowest 
amount of movements we can make
*/
int	rotate_type_ab(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = cost_rra_rrb(a, b, (*a)->value,'a');
	while (tmp)
	{
		if (i > cost_ra_rb(a, b, tmp->value,'a'))
			i = cost_ra_rb(a, b, tmp->value,'a');
		if (i > cost_rra_rrb(a, b, tmp->value,'a'))
			i = cost_rra_rrb(a, b, tmp->value,'a');
		if (i > cost_ra_rrb(a, b, tmp->value,'a'))
			i = cost_ra_rrb(a, b, tmp->value,'a');
		if (i > cost_rra_rb(a, b, tmp->value,'a'))
			i = cost_rra_rb(a, b, tmp->value,'a');
		tmp = tmp->next;
	}
	return (i);
}

/*
this function will calculate for each node in stack b 
how many rotations we need to push back number in stack a in ascending order
it will go through all nodes
*/
int rotate_type_ba(t_stack **a, t_stack **b)
{
    int i;
    t_stack *tmp;

    tmp = *b;
    i = cost_rra_rrb(a, b, (*b)->value,'b');
    
    while(tmp)
    {
        if (i > cost_ra_rb(a, b, tmp->value,'b'))
			i = cost_ra_rb(a, b, tmp->value,'b');
		if (i > cost_rra_rrb(a, b, tmp->value,'b'))
			i = cost_rra_rrb(a, b, tmp->value,'b');
		if (i > cost_ra_rrb(a, b, tmp->value,'b'))
			i = cost_ra_rrb(a, b, tmp->value,'b');
		if (i > cost_rra_rb(a, b, tmp->value,'b'))
			i = cost_rra_rb(a, b, tmp->value,'b');
		tmp = tmp->next;
    }
    return(i);
}
