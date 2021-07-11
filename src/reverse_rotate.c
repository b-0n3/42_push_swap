/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:12:31 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:12:35 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *this, t_bool print)
{
	size_t i;
	int *tmp;

	if (this != NULL)
	{
		i = 0;
		tmp = this->stack_a.get(&this->stack_a, i);
		if (print)
			ft_putstr("rra\n");
		while (i < this->stack_a.index - 1 )
		{
			this->stack_a.update_at(&this->stack_a,
					this->stack_a.get(&this->stack_a, i + 1),
					i);
			i++;
		}
		this->stack_a.update_at(&this->stack_a, tmp, this->stack_a.index -1 );
	}
}

void	reverse_rotate_b(t_stacks *this, t_bool print)
{
	size_t i;
	int *tmp;

	if (this != NULL)
	{
		i = 0;
		tmp = this->stack_b.get(&this->stack_b, i);
		if (print)
			ft_putstr("rrb\n");
		while (i < this->stack_b.index - 1)
		{
			this->stack_b.update_at(&this->stack_b,
					this->stack_b.get(&this->stack_b, i + 1),
					i);
			i++;
		}
		this->stack_b.update_at(&this->stack_b, tmp, this->stack_b.index -1 );
	}
}

void	reverse_rotate_a_and_b(t_stacks *this, t_bool print)
{
	if (this != NULL)
	{
		reverse_rotate_a(this, FALSE);
		reverse_rotate_b(this, FALSE);
		if (print)
			ft_putstr("rrr\n");
	}
}
