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
	struct s_stack *befor;
}t_stack;



int		sa(t_list **stack_a);
void	validate_input(char	**argv, int argc);
void err_message(char *s);
char**   split_to_nums(char* str);
void set_index(t_stack *node, long i);
t_stack *init_stack_a (char **argv, int argc);
#endif