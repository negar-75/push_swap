/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:04:39 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 15:30:28 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_max(t_stack *a)
{
	t_stack	*tmp;
	int		max;

	tmp = a;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	tmp = a;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_index(t_stack *a, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp->value != num)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
Find the correct position to insert a number into a stack 'b' while
maintaining descending order.
Parameters:
- b: Pointer to the head of the stack 'b'.
- num_to_push: The number to find the correct position for.
Returns:
The index where 'num_to_push' should be inserted.
*/

int	find_place_in_b(t_stack *b, int num_to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num_to_push > b->value && num_to_push < last_node(b)->value)
		i = 0;
	else if (num_to_push > get_max(b) || num_to_push < get_min(b))
		i = find_index(b, get_max(b));
	else
	{
		tmp = b->next;
		while (b->value < num_to_push || tmp->value > num_to_push)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_in_a(t_stack *a, int num_to_push_back)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num_to_push_back < a->value && num_to_push_back > last_node(a)->value)
		i = 0;
	else if (num_to_push_back > get_max(a) || num_to_push_back < get_min(a))
		i = find_index(a, get_min(a));
	else
	{
		tmp = a->next;
		while (a->value > num_to_push_back || tmp->value < num_to_push_back)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
