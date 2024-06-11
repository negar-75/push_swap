/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:04:51 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:11:19 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	do_ra_rb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->value != num && find_place_in_b(*b, num) > 0)
			rr(a, b);
		while ((*a)->value != num)
			ra(a);
		while (find_place_in_b(*b, num) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->value != num && find_place_in_a(*a, num) > 0)
			rr(a, b);
		while ((*b)->value != num)
			rb(b);
		while (find_place_in_a(*a, num) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	do_rra_rrb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->value != num && find_place_in_b(*b, num))
			rrr(a, b);
		while ((*a)->value != num)
			rra(a);
		while (find_place_in_b(*b, num) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->value != num && find_place_in_a(*a, num) > 0)
			rrr(a, b);
		while ((*b)->value != num)
			rrb(b);
		while (find_place_in_a(*a, num) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	do_ra_rrb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->value != num)
			ra(a);
		while (find_place_in_b(*b, num) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (find_place_in_a(*a, num) > 0)
			ra(a);
		while ((*b)->value != num)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}

int	do_rra_rb(t_stack **a, t_stack **b, int num, char c)
{
	if (c == 'a')
	{
		while ((*a)->value != num)
			rra(a);
		while (find_place_in_b(*b, num) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (find_place_in_a(*a, num) > 0)
			rra(a);
		while ((*b)->value != num)
			rb(b);
		pa(a, b);
	}
	return (-1);
}
