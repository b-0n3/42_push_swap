#include "push_swap.h"
extern int current_chunk;

void	push_b(t_stacks *this)
{
    void *ptr;

    if (this != NULL)
    {
        if (!this->a_is_empty(this))
        {
            ptr = this->stack_a.pop_i(&this->stack_a, this->stack_a.index - 1);
            if (ptr != NULL)
            {
                ft_putstr("pb\n");
                   ((t_chunk*)ptr)->chunk =current_chunk;
                this->stack_b.push(&this->stack_b, ptr, sizeof (t_chunk *));            
            }
        }
    }
}

void	push_a(t_stacks *this)
{
    void *ptr;

    if (this != NULL)
    {
        if (!this->b_is_empty(this))
        {
            ptr = this->stack_b.pop_i(&this->stack_b, this->stack_b.index - 1);
            if (ptr != NULL)
            {
                ft_putstr("pa\n");
                ((t_chunk*)ptr)->chunk = current_chunk;
                this->stack_a.push(&this->stack_a, ptr, sizeof (t_chunk *));            
            }
        }
    }
}