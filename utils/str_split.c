#include "../push_swap.h"
char**   split_to_nums(char* str)
{
    char** args;

    args = ft_split(str, ' ');
    return (args); 
}