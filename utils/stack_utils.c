/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:53:16 by nnasiri           #+#    #+#             */
/*   Updated: 2024/05/23 14:17:34 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *node, long i)
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

t_bool	is_sorted(t_stack *a)
{
	t_stack	*current;
	t_stack *ne;

	current = a;
	while(current)
    {
        ne = current->next;
        while(ne)
        {
            if(current->value > ne->value)
            {
                return (0);
            }
            ne = ne->next;
        }
        current = current->next;
    }
	return (1);
}

int	ft_stack_size(t_stack *s)
{
	int	count;

	count = 0;
	while (s != NULL)
	{
		count++;
		s = s->next;
	}
	return (count);
}

void	init_arr(int *nums, t_stack **a)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *a;
	while (current)
	{
		nums[i] = current->value;
		current = current->next;
		i++;
	}
}