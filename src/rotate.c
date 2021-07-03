#include "push_swap.h"

// 1,2,3,4,5,6
void	rotate_a(t_stacks *this, t_bool print)
{
    int i;
    int *tmp;

    if (this != NULL)
    {
        i = this->stack_a.index - 1;
        tmp = this->stack_a.get(&this->stack_a, i);
        if (print)
            ft_putstr("ra\n");
        while (i > 0)
        {
            this->stack_a.update_at(&this->stack_a,
                 this->stack_a.get(&this->stack_a, i -1),
                  i);
            i--;
        }
        this->stack_a.update_at(&this->stack_a, tmp, 0);
    }
}

void	rotate_b(t_stacks *this, t_bool print)
{
    int i;
    int *tmp;

    if (this != NULL)
    {
        i = this->stack_b.index - 1;
        tmp = this->stack_b.get(&this->stack_b, i);
        if (print)
            ft_putstr("ra\n");
        while (i > 0)
        {
            this->stack_b.update_at(&this->stack_b,
                 this->stack_b.get(&this->stack_b, i -1),
                  i);
            i--;
        }
        this->stack_b.update_at(&this->stack_b, tmp, 0);
    }
}

void	rotate_a_and_b(t_stacks *this)
{
    if (this != NULL)
    {
        rotate_a(this, FALSE);
        rotate_b(this, FALSE);
        ft_putstr("rr\n");
    }

}