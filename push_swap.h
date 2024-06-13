/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnasiri <nnasiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:07:32 by nnasiri           #+#    #+#             */
/*   Updated: 2024/06/13 18:38:12 by nnasiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum s_bool
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
void				free_stack(t_stack **a);
void				sort_3(t_stack **a);

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
// calculte the cost
int					cost_rra_rrb(t_stack **a, t_stack **b, int num,
						char source);
int					cost_ra_rb(t_stack **a, t_stack **b, int num, char source);
int					cost_ra_rrb(t_stack **a, t_stack **b, int num, char source);
int					cost_rra_rb(t_stack **a, t_stack **b, int num, char source);
// do operation
int					do_ra_rb(t_stack **a, t_stack **b, int num, char source);
int					do_rra_rrb(t_stack **a, t_stack **b, int num, char source);
int					do_ra_rrb(t_stack **a, t_stack **b, int num, char source);
int					do_rra_rb(t_stack **a, t_stack **b, int num, char source);

// libs function
int					ft_isdigit(int c);
void				ft_putchar(char c, int fd);
long int			ft_atoi(const char *str);
void				ft_putstr(char *s, int fd);
void				ft_putendl(char *s, int fd);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
#endif