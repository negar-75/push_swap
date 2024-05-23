#include "../push_swap.h"

void set_index(t_stack *node, long i)
{
    if (i == -1)
	{
		node->i = 0;
		node->index_set = false;
	}
	else
	{
		node->i = (unsigned int)i;
		node->index_set = true;
	}
}

t_bool is_sorted (t_stack *a)
{
	t_stack *current = a;
	while(current)
	{

	}
	return 1;
}
