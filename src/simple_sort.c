#include "../push_swap.h"

void	init_arr(int *nums, t_stack *a)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = a;
	while (current)
	{
		nums[i] = current->value;
		current = current->next;
        i++;
	}
}

void	sort_3(t_stack **a)
{
	int		s[3];

    init_arr(s,*a);
    if (s[0] > s[1] && s[1] < s[2] && s[2] > s[0])
		sa(a, true);
	else if (s[0] > s[1] && s[1] < s[2] && s[2] < s[0])
		ra(a, true);
	else if (s[0] < s[1] && s[1] > s[2] && s[2] < s[0])
		rra(a, true);
	else if (s[0] > s[1] && s[1] > s[2] && s[2] < s[0])
	{
        sa(a, true);
        rra(a, true);
	}
	else if (s[0] < s[1] && s[1] > s[2] && s[2] > s[0])
	{
        sa(a, true);
        ra(a, true);
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	int		s[4];
    
    init_arr(s,*a);
    if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3])
        pb(a, b, true);
	else if (s[1] < s[0] && s[1] < s[2] && s[1] < s[3])
	{
        sa(a, true);
		pb(a, b, true);
	}
	else if (s[2] < s[0] && s[2] < s[1] && s[2] < s[3])
	{
		ra(a, true);
		ra(a, true);
		pb(a, b, true);
	}
	else if (s[3] < s[0] && s[3] < s[1] && s[3] < s[2])
	{
		rra(a, true);
		pb(a, b, true);
	}
	if (ft_stack_size(*a) == 3)
		sort_3(a);
	pa(a, b, true);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int size;

	size = ft_stack_size(*a);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(a, true);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	// else if(size == 5)
	//     sort_5(a);
	else
		return ;
}