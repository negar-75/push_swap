/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:21 by nnasiri           #+#    #+#             */
/*   Updated: 2024/05/23 17:25:38 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	fail_fun(char *message, char **argv, int argc)
{
	if (argc == 2)
		ft_free(argv);
	err_message(message);
}

void	check_args_number(char *str, char **args, int argc)
{
	char	*b;

	b = ft_itoa(ft_atoi(str));
	if (str[0] == '+')
	{
		if (ft_strlen(str + 1) != ft_strlen(b) || ft_strncmp(str + 1, b,
				ft_strlen(b) != 0))
		{
			free(b);
			fail_fun("Invalid argument", args, argc);
		}
	}
	else
	{
		if (ft_strlen(str) != ft_strlen(b) || ft_strncmp(str, b,
				ft_strlen(b) != 0))
		{
			free(b);
			fail_fun("Invalid argument", args, argc);
		}
	}
}

void	validate_input(char **argv, int argc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < argc)
	{
		check_args_number(argv[i], argv, argc);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				fail_fun("Duplicate", argv, argc);
			j++;
		}
		i++;
	}
}
