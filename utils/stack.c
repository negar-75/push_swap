#include "../push_swap.h"
static void	set_indices(t_stack *stack, t_stack	*s[5])
{
	unsigned int	cur_i;	

	cur_i = 1;
	s[3] = stack;
	while (s[3]->next)
	{
		s[4] = stack;
		s[0] = s[2];
		while (s[4])
		{
			if (!s[4]->index_set && s[4]->value < s[0]->value)
				s[0] = s[4];
			s[4] = s[4]->next;
		}
		set_index(s[0], cur_i);
		cur_i++;
		s[3] = s[3]->next;
	}
}
static void	ini_indices(t_stack *stack)
{
	t_stack			*s[5];

	s[1] = stack;
	s[2] = stack;
	s[3] = stack;
	while (s[3])
	{
        ft_printf("%d %d\n",s[3] ->value,s[1]->value);
		if (s[3]->value < s[1]->value)
			s[1] = s[3];
         ft_printf("%d %d\n",s[3] ->value,s[2]->value);
		if (s[3]->value > s[2]->value)
			s[2] = s[3];
		s[3] = s[3]->next;
	}
	set_index(s[1], 0);
	set_indices(stack, s);
}
t_stack *init_stack_a (char **argv, int argc)
{
    t_stack *new_stack;
    t_stack *last_node;
    int i;

    new_stack = malloc(sizeof(t_stack));
    if(!new_stack)
        return (NULL);
    new_stack->value = ft_atoi(argv[1]);
	set_index(new_stack, -1);
	last_node = new_stack;
	i = 2;
	while (i < argc)
	{
		last_node->next = malloc(sizeof(t_stack));
		if (!last_node->next)
			return (NULL);
		last_node = last_node->next;
		last_node->value = ft_atoi(argv[i]);
		set_index(last_node, -1);
		i++;
	}
    last_node->next = NULL;
    ini_indices(new_stack);
    t_stack* current_node = new_stack;
    
    while (current_node) {
        ft_printf("this is value %d\n", current_node->value);
        ft_printf("this is index set %s\n", current_node->index_set ? "true" : "false");
        ft_printf("this is i %d\n", current_node->i);
        current_node = current_node->next;
    }

    return new_stack;
}

