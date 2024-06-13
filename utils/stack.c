/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:57 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:12:49 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// s[0] --> find the lowest number after s[1]
// s[1] -->lowset
// s[2] -->highest
// s[3] --> head
// s[4] --> head

static void	set_indices(t_stack *stack, t_stack *s[5])
{
	unsigned int	cur_i;

	cur_i = 1;
	s[3] = stack;
	while (s[3]->next)
	{
		s[4] = stack;
		s[0] = s[2];
		while (s[4])
		{
			if (!s[4]->index_set && s[4]->value < s[0]->value)
				s[0] = s[4];
			s[4] = s[4]->next;
		}
		set_index(s[0], cur_i);
		cur_i++;
		s[3] = s[3]->next;
	}
}

// s[0] -->
// s[1] -->lowset
// s[2] -->highest
// s[3] -->NULL
// s[4] -->

static void	initialize_indices(t_stack *stack)
{
	t_stack	*s[5];

	s[1] = stack;
	s[2] = stack;
	s[3] = stack;
	while (s[3])
	{
		if (s[3]->value < s[1]->value)
			s[1] = s[3];
		if (s[3]->value > s[2]->value)
			s[2] = s[3];
		s[3] = s[3]->next;
	}
	set_index(s[1], 0);
	set_indices(stack, s);
}

t_stack	*init_stack_a(char **args, int argc)
{
	t_stack	*new_stack;
	t_stack	*last_node;
	int		i;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = ft_atoi(args[0]);
	set_index(new_stack, -1);
	last_node = new_stack;
	i = 1;
	while (i < argc)
	{
		last_node->next = malloc(sizeof(t_stack));
		if (!last_node->next)
			return (NULL);
		last_node = last_node->next;
		last_node->value = ft_atoi(args[i]);
		set_index(last_node, -1);
		i++;
	}
	last_node->next = NULL;
	initialize_indices(new_stack);
	return (new_stack);
}
