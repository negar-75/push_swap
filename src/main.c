/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:06:27 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 18:47:09 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) <= 3)
		simple_sort(stack_a);
	else
		algorithm_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (argc <= 1)
		exit(1);
	if (argc == 2)
		args = split_to_nums(argv[1]);
	else
		args = argv + 1;
	validate_input(args, get_len(args), argc);
	a = init_stack_a(args, get_len(args));
	if (!a)
		return (-1);
	b = NULL;
	if (!is_sorted(a))
		sort_stack(&a, &b);
	if (argc == 2)
		ft_free_split(args);
	free_stack(&a);
}
