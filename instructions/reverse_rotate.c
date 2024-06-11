/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:02:37 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:09:13 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **s)
{
	t_stack	*current;
	t_stack	*last;

	if (!s || !(*s) || !(*s)->next)
		return ;
	current = *s;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *s;
	last->before = NULL;
	(*s)->before = last;
	*s = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
