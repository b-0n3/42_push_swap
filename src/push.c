/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:12:14 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:12:20 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks *this, t_bool print)
{
	void	*ptr;

	if (this != NULL)
	{
		if (!this->a_is_empty(this))
		{
			ptr = this->stack_a.pop_i(&this->stack_a, this->stack_a.index - 1);
			if (ptr != NULL)
			{
				if (print)
					ft_putstr("pb\n");
				this->stack_b.push(&this->stack_b, ptr, sizeof(t_chunk *));
			}
		}
	}
}

void	push_a(t_stacks *this, t_bool print)
{
	void	*ptr;

	if (this != NULL)
	{
		if (!this->b_is_empty(this))
		{
			ptr = this->stack_b.pop_i(&this->stack_b, this->stack_b.index - 1);
			if (ptr != NULL)
			{
				if (print)
					ft_putstr("pa\n");
				this->stack_a.push(&this->stack_a, ptr, sizeof (t_chunk *));
			}
		}
	}
}
