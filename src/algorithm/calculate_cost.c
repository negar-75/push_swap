/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:05:12 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:11:59 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
all functions here responsible for calculate how many moves
we need to push number from a to b or b to a
bacause the destination stack is the place that we should use find_place
functions, because it should be in specific order
*/
int	cost_rra_rrb(t_stack **a, t_stack **b, int num, char source)
{
	int	i;

	i = 0;
	if (source == 'a')
	{
		if (find_place_in_b(*b, num))
			i = stack_size(*b) - find_place_in_b(*b, num);
		if (i < stack_size(*a) - find_index(*a, num) && find_index(*a, num))
			i = stack_size(*a) - find_index(*a, num);
	}
	else
	{
		if (find_place_in_a(*a, num))
			i = stack_size(*a) - find_place_in_a(*a, num);
		if ((i < (stack_size(*b) - find_index(*b, num))) && find_index(*b, num))
			i = stack_size(*b) - find_index(*b, num);
	}
	return (i);
}

int	cost_ra_rb(t_stack **a, t_stack **b, int num, char source)
{
	int	i;

	i = 0;
	if (source == 'a')
	{
		i = find_place_in_b(*b, num);
		if (i < find_index(*a, num))
			i = find_index(*a, num);
	}
	else
	{
		i = find_place_in_a(*a, num);
		if (i < find_index(*b, num))
			i = find_index(*b, num);
	}
	return (i);
}

int	cost_rra_rb(t_stack **a, t_stack **b, int num, char source)
{
	int	i;

	i = 0;
	if (source == 'a')
	{
		if (find_index(*a, num))
			i = stack_size(*a) - find_index(*a, num);
		i = find_place_in_b(*b, num) + i;
	}
	else
	{
		if (find_place_in_a(*a, num))
			i = stack_size(*a) - find_place_in_a(*a, num);
		i = find_index(*b, num) + i;
	}
	return (i);
}

int	cost_ra_rrb(t_stack **a, t_stack **b, int num, char source)
{
	int i;

	i = 0;
	if (source == 'a')
	{
		if (find_place_in_b(*b, num))
			i = stack_size(*b) - find_place_in_b(*b, num);
		i = find_index(*a, num) + i;
	}
	else
	{
		if (find_index(*b, num))
			i = stack_size(*b) - find_index(*b, num);
		i = find_place_in_a(*a, num) + i;
	}
	return (i);
}
