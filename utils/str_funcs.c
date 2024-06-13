/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:52:40 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 15:30:38 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_to_nums(char *str)
{
	char	**args;

	if (ft_strlen(str) == 0)
	{
		err_message("Error");
		exit(1);
	}
	args = ft_split(str, ' ');
	return (args);
}

int	get_len(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
		len++;
	return (len);
}
