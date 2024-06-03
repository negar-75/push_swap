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

#include "../push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if (!src || !*src) {
        return;
    }
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
}

long	pa(t_stack **a,t_stack **b, t_bool print)
{
	push(b,a);
	if (print)
		ft_printf("pa\n");
	return (1);
}

long	pb(t_stack **a,t_stack **b, t_bool print)
{
	push(a,b);
	if (print)
		ft_printf("pb\n");
	return (1);
}
