#include "../push_swap.h"


static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		algorithm_sort(stack_a, stack_b);
}


int main(int argc, char**argv)
{
  t_stack *a;
  t_stack *b;
  char **args;
  
  if (argc <= 1)
		err_message("No argument");
  if(argc == 2)
		args = split_to_nums(argv[1]);
  else
  		args = argv + 1;
  validate_input(args,get_len(args), argc);
  a = init_stack_a(args,get_len(args));
  if(!a)
    return (-1);
  b = NULL;
  if(!is_sorted(a))
  	sort_stack(&a,&b);
  
  
}
