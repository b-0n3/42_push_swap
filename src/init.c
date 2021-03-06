/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:12:06 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/12 16:55:49 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *this)
{
	if (this != NULL)
	{
		this->stack_b.free(&this->stack_b, &free_chunk);
		this->stack_a.free(&this->stack_a, &free_chunk);
	}
}

void	new_stacks(t_stacks *this)
{
	if (this != NULL)
	{
		new_array_list(&this->stack_a, 10, sizeof(t_chunk *));
		new_array_list(&this->stack_b, 10, sizeof(t_chunk *));
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
		this->a_is_sorted = &stack_a_is_sorted;
		this->b_is_sorted = &stack_b_is_sorted;
		this->a_is_empty = &stack_a_is_empty;
		this->b_is_empty = &stack_b_is_empty;
	}
}
