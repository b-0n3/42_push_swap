/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:13:12 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:13:14 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stacks *stacks,
		t_array_list *clone, int current_chunk)
{
	if (stacks->stack_a.index == 2)
	{
		if (!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 1)
			stacks->sa(stacks, TRUE);
	}
	if (stacks->stack_b.index == 2)
	{
		if (stacks->b_is_sorted(stacks))
			stacks->sb(stacks, TRUE);
		if (stacks->stack_b.index == 2)
			push_to_a(stacks, 2, current_chunk);
	}
	if (!stacks->b_is_empty(stacks))
	{
		clone_b_first_chunks_and_sort_it(stacks, clone, current_chunk);
		clone->free(clone, &free_chunk);
		sort_stacks(stacks);
	}
}

void	sort_stacks(t_stacks *stacks)
{
	t_array_list	clone;
	static int		current_chunk;

	current_chunk++;
	if (stacks->stack_a.index == 3)
		sort_tree(stacks, TRUE);
	if (stacks->stack_b.index == 3)
	{
		sort_tree(stacks, FALSE);
		if (stacks->a_is_sorted(stacks))
			push_to_a(stacks, 3, current_chunk);
	}
	new_array_list(&clone, 10, sizeof(t_chunk *));
	if (!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 2)
	{
		clone_a_first_chunks_and_sort_it(stacks, &clone, current_chunk);
		clone.free(&clone, &free_chunk);
		sort_stacks(stacks);
	}
	sort_b(stacks, &clone, current_chunk);
	if (clone.arr != NULL)
		clone.free(&clone, &free_chunk);
}
