/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:53:16 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 14:59:01 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *node, long i)
{
	if (i == -1)
	{
		node->i = 0;
		node->index_set = false;
	}
	else
	{
		node->i = (unsigned int)i;
		node->index_set = true;
	}
}

t_bool	is_sorted(t_stack *a)
{
	int	i;

	i = a->value;
	while (a)
	{
		if (i > a->value)
			return (0);
		i = a->value;
		a = a->next;
	}
	return (1);
}

int	stack_size(t_stack *s)
{
	int	count;

	count = 0;
	while (s != NULL)
	{
		count++;
		s = s->next;
	}
	return (count);
}

t_stack	*last_node(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
