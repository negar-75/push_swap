/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:41:57 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 18:40:17 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
	{
		return ;
	}
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl("pa", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl("pb", 1);
}
