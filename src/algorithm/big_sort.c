/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:05:01 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:11:44 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sub_init_b(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (stack_size(*a) > 3 && !is_sorted(*a))
	{
		tmp = *a;
		i = rotate_type_ab(a, b);
		while (i >= 0)
		{
			if (i == cost_ra_rb(a, b, tmp->value, 'a'))
				i = do_ra_rb(a, b, tmp->value, 'a');
			else if (i == cost_rra_rrb(a, b, tmp->value, 'a'))
				i = do_rra_rrb(a, b, tmp->value, 'a');
			else if (i == cost_ra_rrb(a, b, tmp->value, 'a'))
				i = do_ra_rrb(a, b, tmp->value, 'a');
			else if (i == cost_rra_rb(a, b, tmp->value, 'a'))
				i = do_rra_rb(a, b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	init_b(t_stack **a, t_stack **b)
{
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		pb(a, b);
	if (stack_size(*a) > 3 && !is_sorted(*a))
		sub_init_b(a, b);
	if (!is_sorted(*a))
		sort_3(a);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = rotate_type_ba(a, b);
		while (i >= 0)
		{
			if (i == cost_ra_rb(a, b, tmp->value, 'b'))
				i = do_ra_rb(a, b, tmp->value, 'b');
			else if (i == cost_ra_rrb(a, b, tmp->value, 'b'))
				i = do_ra_rrb(a, b, tmp->value, 'b');
			else if (i == cost_rra_rrb(a, b, tmp->value, 'b'))
				i = do_rra_rrb(a, b, tmp->value, 'b');
			else if (i == cost_rra_rb(a, b, tmp->value, 'b'))
				i = do_rra_rb(a, b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
}

void	algorithm_sort(t_stack **a, t_stack **b)
{
	int	i;

	init_b(a, b);
	push_back_to_a(a, b);
	i = find_index(*a, get_min(*a));
	if (i < stack_size(*a) / 2)
	{
		while ((*a)->value != get_min(*a))
			ra(a);
	}
	else
	{
		while ((*a)->value != get_min(*a))
			rra(a);
	}
}
