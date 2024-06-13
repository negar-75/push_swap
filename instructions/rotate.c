/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:03:14 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 18:40:11 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*temp;
	t_stack	*current;

	if (!s || !(*s) || !(*s)->next)
		return ;
	temp = *s;
	current = *s;
	while (current->next)
	{
		current = current->next;
	}
	*s = (*s)->next;
	(*s)->before = NULL;
	current->next = temp;
	temp->next = NULL;
	temp->before = current;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl("ra", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl("rr", 1);
}
