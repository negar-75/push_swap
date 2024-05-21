/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:43:46 by nnasiri           #+#    #+#             */
/*   Updated: 2024/04/17 14:03:18 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main() {

//    t_list * l =  NULL;
//    printf("%s",ft_lstsize(l) == 0 ? "true" : "false");
//    ft_lstadd_front(&l, ft_lstnew((void*)1));
//    printf("%s",ft_lstsize(l) == 1 ? "true" : "false");
//    ft_lstadd_front(&l, ft_lstnew((void*)2));
//    printf("%s",ft_lstsize(l) == 2 ? "true" : "false");
//    return (0);
// }