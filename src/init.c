#include "push_swap.h"

void	free_stacks(t_stacks *this)
{
    if (this != NULL)
    {
        this->stack_b.free(&this->stack_b , NULL);
        this->stack_a.free(&this->stack_a , NULL);
    }
}

void	new_stacks(t_stacks *this)
{
    if (this != NULL)
    {
        new_array_list(&this->stack_a, 10, sizeof(int));
        new_array_list(&this->stack_b, 10, sizeof(int));
        this->sa = &swap_a;
        this->sb = &swap_b;
        this->ss = &swap_a_and_b;
        this->pa = &push_a;
        this->pb = &push_b;
        this->ra = &rotate_a;
        this->rb = &rotate_b;
        this->rr = &rotate_a_and_b;
        this->rra = &reverse_rotate_a;
        this->rrb = &reverse_rotate_b;
        this->rrr = &reverse_rotate_a_and_b;
        this->free = &free_stacks;
    }
}