#include "../../push_swap.h"

void	simple_sort(t_stack **a, t_stack **b)
{
	int size;

	size = ft_stack_size(*a);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if(size == 5)
	    sort_5(a,b);
	else
		return ;
}