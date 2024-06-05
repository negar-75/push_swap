#include "../../push_swap.h"
int find_min_index(t_stack **a)
{
    int min_index;
    int i;
    int min_num;
    t_stack *current;

    current = (*a);
    min_index = 0;
    min_num = current->value;
    i = 0;

    while(current)
    {
        if(current->value < min_num)
        {
            min_num = current->value;
            min_index = i;
        }
        i++;
        current = current->next;
    }
    return min_index;
    
}

void move_to_top(t_stack **a, int min_index, int size)
{
    if(min_index < size / 2)
    {
        while(min_index -- > 0)
            ra(a);
    }
    else
    {
        while(min_index ++ < size)
            rra(a);
    }
}

void sort_5(t_stack	**a,t_stack	**b)
{
    int min_index;

    min_index = find_min_index(a);
    move_to_top(a,min_index,5);
    pb(a,b);
    min_index = find_min_index(a);
    move_to_top(a,min_index,4);
    pb(a,b);
    sort_3(a);
    pa(a,b);
    pa(a,b);
}