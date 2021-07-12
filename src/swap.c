/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:13:21 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:13:22 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *this, t_bool print)
{
	if (this != NULL)
	{
		if (this->stack_a.index > 1)
		{
			if (print)
				ft_putstr("sa\n");
			this->stack_a.swap_i(&this->stack_a,
				this->stack_a.index - 2, this->stack_a.index - 1);
		}
	}
}

void	swap_b(t_stacks *this, t_bool print)
{
	if (this != NULL)
	{
		if (this->stack_b.index > 1)
		{
			if (print)
				ft_putstr("sb\n");
			this->stack_b.swap_i(&this->stack_b,
				this->stack_b.index - 2, this->stack_b.index - 1);
		}
	}
}

void	swap_a_and_b(t_stacks *this, t_bool print)
{
	if (this != NULL)
	{
		this->sa(this, FALSE);
		this->sb(this, FALSE);
		if (print)
			ft_putstr("ss\n");
	}
}
