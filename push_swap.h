# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libs/ft_printf/ft_printf.h"
#include "libs/libft/libft.h"
#include <limits.h>

typedef enum {
    false = 0,
    true = 1
} t_bool;

typedef struct s_stack
{
	int value;
	unsigned int i;
	t_bool			index_set;
	struct s_stack *next;
	struct s_stack *before;
}t_stack;


void	validate_input(char	**argv, int argc);
void	err_message(char *s);
char	**split_to_nums(char* str);
void	set_index(t_stack *node, long i);
t_stack	*init_stack_a (char **argv, int argc);
int	get_len(char ** str);


t_bool	is_sorted(t_stack *a);
int	ft_stack_size(t_stack *s);
void simple_sort (t_stack **a, t_stack **b);
void	init_arr(int *nums, t_stack **a);

void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void pa(t_stack **a,t_stack **b);
void pb(t_stack **a,t_stack **b);

void sa(t_stack **a);
void sb(t_stack **b);

void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack	**a,t_stack	**b);

#endif