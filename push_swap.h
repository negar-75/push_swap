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

long	rra(t_stack **a, t_bool print);
long	rrb(t_stack **b, t_bool print);
long	rrr(t_stack **a, t_stack **b, t_bool print);

long	ra(t_stack **a, t_bool print);
long	rb(t_stack **b, t_bool print);
long	rr(t_stack **a, t_stack **b, t_bool print);

long	pa(t_stack **a,t_stack **b, t_bool print);
long	pb(t_stack **a,t_stack **b, t_bool print);

long	sa(t_stack **a, t_bool print);
long	sb(t_stack **b, t_bool print);
#endif