/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:03:41 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 18:40:33 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!s || !(*s) || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	first->next = second->next;
	second->next = first;
	second->before = first->before;
	first->before = second;
	if (first->next)
		first->next->before = first;
	*s = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putendl("sa", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putendl("sb", 1);
}
