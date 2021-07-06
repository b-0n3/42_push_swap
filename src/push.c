#include "push_swap.h"

void	push_b(t_stacks *this)
{
    void *ptr;

    if (this != NULL)
    {
        if (this->stack_a.index > 0)
        {
            ptr = this->stack_a.pop_i(&this->stack_a, this->stack_a.index - 1);
            if (ptr != NULL)
            {
                ft_putstr("pb\n");
                this->stack_b.push(&this->stack_b, ptr, sizeof (int));            
            }
        }
    }
}

void	push_a(t_stacks *this)
{
    void *ptr;

    if (this != NULL)
    {
        if (this->stack_b.index > 0)
        {
            ptr = this->stack_b.pop_i(&this->stack_b, this->stack_b.index - 1);
            if (ptr != NULL)
            {
                ft_putstr("pa\n");
                this->stack_a.push(&this->stack_a, ptr, sizeof (int));            
            }
        }
    }
}