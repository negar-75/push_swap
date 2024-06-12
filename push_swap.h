/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:07:32 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/11 16:07:35 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/ft_printf/ft_printf.h"
# include "libs/libft/libft.h"
# include <limits.h>

typedef enum
{
	false = 0,
	true = 1
}					t_bool;

typedef struct s_stack
{
	int				value;
	unsigned int	i;
	t_bool			index_set;
	struct s_stack	*next;
	struct s_stack	*before;
}					t_stack;

void				validate_input(char **argv, int size, int argc);
void				err_message(char *s);
char				**split_to_nums(char *str);
void				set_index(t_stack *node, long i);
t_stack				*init_stack_a(char **argv, int argc);
int					get_len(char **str);
void				ft_free_split(char **str);

t_bool				is_sorted(t_stack *a);
int					stack_size(t_stack *s);
void				simple_sort(t_stack **a);
void 				free_stack(t_stack **a);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				sa(t_stack **a);
void				sb(t_stack **b);

void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);

void				algorithm_sort(t_stack **a, t_stack **b);
t_stack				*last_node(t_stack *a);
int					get_max(t_stack *a);
int					get_min(t_stack *a);

int					find_place_in_b(t_stack *b, int num_to_push);
int					find_place_in_a(t_stack *a, int num_to_push_back);
int					find_index(t_stack *a, int num);
int					rotate_type_ab(t_stack **a, t_stack **b);
int					rotate_type_ba(t_stack **a, t_stack **b);
int					get_max(t_stack *a);
int					get_min(t_stack *a);
int					cost_rra_rrb(t_stack **a, t_stack **b, int num,
						char source);
int					cost_ra_rb(t_stack **a, t_stack **b, int num, char source);
int					cost_ra_rrb(t_stack **a, t_stack **b, int num, char source);
int					cost_rra_rb(t_stack **a, t_stack **b, int num, char source);

int					do_ra_rb(t_stack **a, t_stack **b, int num, char source);
int					do_rra_rrb(t_stack **a, t_stack **b, int num, char source);
int					do_ra_rrb(t_stack **a, t_stack **b, int num, char source);
int					do_rra_rb(t_stack **a, t_stack **b, int num, char source);

#endif