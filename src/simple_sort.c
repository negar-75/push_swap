#include "../push_swap.h"

void init_arr(int stack_size,t_stack *a)
{

}

long sort_3(t_stack **a)
{
	int	nums[3];
	long	count_actions;

	count_actions = 0;
	nums[0] = (*a)->value;
	nums[1] = (*a)->next->value;
	nums[2] = (*a)->next->next->value;
	if(nums[0] > nums[1] && nums[1] < nums[2] && nums[2] > nums[0])
		count_actions += sa(a,true);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[2] < nums[0])
		count_actions += ra(a,true);
	else if(nums[0] < nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
		count_actions += rra(a,true);
	else if (nums[0] > nums[1] && nums[1] > nums[2] && nums[2] < nums[0])
	{
		count_actions += sa(a, true);
		count_actions += rra(a, true);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[2] > nums[0])
	{
		count_actions += sa(a, true);
		count_actions += ra(a, true);
	}
	return(count_actions);
}

long sort_4(t_stack **a, t_stack **b)
{
	int s[4];
	long	count_actions;
	t_stack *current;

    current = *a;
    for (int i = 0; i < 4; i++) {
        s[i] = current->value;
        current = current->next;
    }
	if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3]) {
        count_actions +=pb(a, b, true);
    } else if (s[1] < s[0] && s[1] < s[2] && s[1] < s[3]) {
        count_actions +=sa(a, true);
        count_actions +=pb(a, b, true);
    } else if (s[2] < s[0] && s[2] < s[1] && s[2] < s[3]) {
        count_actions +=ra(a, true);
        count_actions +=ra(a, true);
        count_actions +=pb(a, b, true);
    } else if (s[3] < s[0] && s[3] < s[1] && s[3] < s[2])
	{
        count_actions += rra(a, true);
        count_actions += pb(a, b, true);
    }
	if (ft_stack_size(*a) == 3)
		count_actions += sort_3(a);
    pa(a, b, true);
	return count_actions;
}

void simple_sort (t_stack **a, t_stack **b)
{
    int size;

    size = ft_stack_size(*a);
    if (size == 0 || size == 1)
        return;
    if(size == 2)
        sa(a,true);
    else if(size == 3)
        sort_3(a);
    else if(size == 4)
        sort_4(a,b);
    // else if(size == 5)
    //     sort_5(a);
    else
        return;
}