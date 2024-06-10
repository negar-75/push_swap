#include "../../push_swap.h"

void	sort_4(t_stack **a, t_stack **b)
{
	int		s[4];
    
    init_arr(s,a);
    if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3])
		pb(a, b);
	else if (s[1] < s[0] && s[1] < s[2] && s[1] < s[3])
	{
        sa(a);
		pb(a, b);
	}
	else if (s[2] < s[0] && s[2] < s[1] && s[2] < s[3])
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (s[3] < s[0] && s[3] < s[1] && s[3] < s[2])
	{
		rra(a);
		pb(a, b);
	}
	if (stack_size(*a) == 3)
		sort_3(a);
	pa(a, b);
}