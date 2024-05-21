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

