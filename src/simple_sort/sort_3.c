#include "../../push_swap.h"

void	sort_3(t_stack **a)
{
	int		s[3];

    init_arr(s,a);
    if (s[0] > s[1] && s[1] < s[2] && s[2] > s[0])
		sa(a);
	else if (s[0] > s[1] && s[1] < s[2] && s[2] < s[0])
		ra(a);
	else if (s[0] < s[1] && s[1] > s[2] && s[2] < s[0])
		rra(a);
	else if (s[0] > s[1] && s[1] > s[2] && s[2] < s[0])
	{
		sa(a);
		rra(a);
	}
	else if (s[0] < s[1] && s[1] > s[2] && s[2] > s[0])
	{
		sa(a);
		ra(a);
	}
}