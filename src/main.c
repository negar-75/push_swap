#include "../push_swap.h"

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
  validate_input(args,get_len(args));
  a = init_stack_a(args,get_len(args));
  if(!a)
	return (-1);
  
  return 0; 
}
