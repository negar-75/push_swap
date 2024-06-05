/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:21 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/05 17:52:25 by nnasiri          ###   ########.fr       */
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
	{
		ft_printf("args is 2");
		ft_free(argv);
	}
	err_message(message);
}

int	ft_atoi2(const char *str, char **argv, int argc)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			fail_fun("Invalid argument", argv, argc);
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		fail_fun("Invalid argument", argv, argc);
	return (mod * i);
}

void	validate_input(char **argv, int size, int argc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size)
	{
		ft_atoi2(argv[i], argv, argc);
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				fail_fun("Duplicate", argv, argc);
			j++;
		}
		i++;
	}
}
