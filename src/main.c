#include "../push_swap.h"

int main(int argc, char**argv)
{
  t_stack *a;
  t_stack *b;
  if (argc == 1)
		err_message("No argument");
  validate_input(argv,argc);
  a = init_stack_a(argv,argc);
  return 0; 
}