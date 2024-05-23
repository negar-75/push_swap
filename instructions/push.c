/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:41:57 by nnasiri           #+#    #+#             */
/*   Updated: 2024/05/23 19:06:56 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src,t_stack *dest)
{
	t_stack	*tmp;

	if (!src || !dest)
		return ;
		tmp = src;
		stacks->a = src->n;
		buffer_node->n = stacks->b;
		stacks->b = buffer_node;
}


long	pa(t_stacks *stacks, t_bool print)
{
	push(stacks, ft_false);
	if (print)
		ft_printf("pa\n");
	return (1);
}

long	pb(t_stacks *stacks, t_bool print)
{
	push(stacks, ft_true);
	if (print)
		ft_printf("pb\n");
	return (1);
}