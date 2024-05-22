#include "../push_swap.h"
char**   split_to_nums(char* str)
{
    char** args;

    args = ft_split(str, ' ');
    return (args); 
}
int get_len(char ** str)
{
    int len = 0;
    while(str[len] != NULL)
        len++;
    return len;
}