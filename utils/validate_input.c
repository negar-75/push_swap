/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:21 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 15:26:58 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_fail(char *message, char **args, int argc)
{
	if (argc == 2)
		ft_free_split(args);
	err_message(message);
}

int	ft_atoi2(const char *str, char **args, int argc)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_fail("Error", args, argc);
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_fail("Error", args, argc);
	return (mod * i);
}

void	validate_input(char **args, int size, int argc)
{
	int	i;
	int	j;
	int	num;

	j = 0;
	i = 0;
	while (i < size)
	{
		num = ft_atoi2(args[i], args, argc);
		if ((ft_strncmp(args[i], "0", 1) != 0 && ft_strncmp(args[i], "+0",
					2) != 0 && ft_strncmp(args[i], "-0", 2) != 0) && num == 0)
			ft_fail("Error", args, argc);
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ft_fail("Error", args, argc);
			j++;
		}
		i++;
	}
}
