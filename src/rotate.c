/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:12:41 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:12:57 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *this, t_bool print)
{
	int i;
	t_chunk *tmp;

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
	t_chunk *tmp;


	if (this != NULL)
	{
		i = this->stack_b.index - 1;
		tmp = this->stack_b.get(&this->stack_b, i);
		if (print)
			ft_putstr("rb\n");
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

void	rotate_a_and_b(t_stacks *this, t_bool print)
{
	if (this != NULL)
	{
		rotate_a(this, FALSE);
		rotate_b(this, FALSE);
		if (print)
			ft_putstr("rr\n");
	}

}
