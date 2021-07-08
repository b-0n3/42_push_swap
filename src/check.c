#include "push_swap.h"
t_bool check_stack_is_sorted(t_array_list *list)
{
    int i;
    int *min;
    int *current_value;
    
    if (list == NULL)
        return FALSE;
    i = (int) list->index - 1;
    min = list->get(list, i);
    while(i >= 0)
    {
        current_value = list->get(list , i);
        if (*min > *current_value)
            return FALSE;
    }
    return TRUE;
}

t_bool stack_a_is_sorted(t_stacks *this)
{
    if (this == NULL)
        return FALSE;
    return check_stack_is_sorted(&this->stack_a);
}

t_bool stack_b_is_sorted(t_stacks *this){
  if (this == NULL)
        return FALSE;
    return check_stack_is_sorted(&this->stack_b);
}

t_bool stack_a_is_empty(t_stacks *this)
{
    if (this == NULL)
        return FALSE;
    return this->stack_a.index == 0;
}

t_bool stack_b_is_empty(t_stacks *this)
{
    if (this == NULL)
        return FALSE;
    return this->stack_b.index == 0;
}