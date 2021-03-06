/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:56:00 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/12 16:56:02 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stacks *stacks, int nb, int chunk_n)
{
	void	*ptr;

	while (nb > 0)
	{
		ptr = stacks->stack_b.get(&stacks->stack_b, stacks->stack_b.index - 1);
		((t_chunk *)ptr)->chunk = chunk_n;
		stacks->pa(stacks, TRUE);
		nb--;
	}
}

void	push_to_b(t_stacks *stacks, int nb, int chunk_n)
{
	void	*ptr;

	while (nb > 0)
	{
		ptr = stacks->stack_a.get(&stacks->stack_a, stacks->stack_a.index - 1);
		((t_chunk *)ptr)->chunk = chunk_n;
		stacks->pb(stacks, TRUE);
		nb--;
	}
}
