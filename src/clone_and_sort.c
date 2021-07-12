#include "push_swap.h"

int	filter_smaller_number_and_push_to_b(t_chunk *current,
	 t_stacks *stacks, t_chunk *pivot, int current_chunk)
{
	int	nb_ra;

	nb_ra = 0;
	while (current != NULL
		&& is_there_other_smaller_elements(&stacks->stack_a, pivot))
	{
		if (current->chunk != pivot->chunk)
			break ;
		if (*(current->value) < *(pivot->value))
			push_to_b(stacks, 1, current_chunk);
		else
		{
			nb_ra++;
			stacks->ra(stacks, TRUE);
		}
		current = stacks->stack_a.get(&stacks->stack_a,
				stacks->stack_a.index - 1);
	}
	return (nb_ra);
}

void	clone_a_first_chunks_and_sort_it(
			t_stacks *stacks,
			t_array_list *clone,
			int current_chunk)
{
	int		nb_ra;
	t_chunk	*pivot;
	t_chunk	*current;
	size_t	ss;

	ss = stacks->stack_a.index;
	pivot = filter_first_chunk_and_get_pivot(stacks->stack_a, clone);
	if (clone->index <= 2)
	{
		if (!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 1)
			stacks->sa(stacks, TRUE);
		return ;
	}
	current = stacks->stack_a.get(&stacks->stack_a, ss - 1);
	nb_ra = filter_smaller_number_and_push_to_b(current,
			stacks, pivot, current_chunk);
	if (clone->index != ss)
	{
		while (nb_ra)
		{
			nb_ra--;
			stacks->rra(stacks, TRUE);
		}
	}
	pivot->free(pivot);
}

int	filter_greater_number_and_push_to_a(t_chunk *current,
	 t_stacks *stacks, t_chunk *pivot, int current_chunk)
{
	int	nb_ra;

	nb_ra = 0;
	while (current != NULL
		&& is_there_other_greater_elements(&stacks->stack_b, pivot))
	{
		if (current->chunk != pivot->chunk)
			break ;
		if (*(current->value) > *(pivot->value))
			push_to_a(stacks, 1, current_chunk);
		else
		{
			nb_ra++;
			stacks->rb(stacks, TRUE);
		}
		current = stacks->stack_b.get(&stacks->stack_b,
				stacks->stack_b.index - 1);
	}
	return (nb_ra);
}

void	clone_b_first_chunks_and_sort_it(
			t_stacks *stacks,
			t_array_list *clone,
			int current_chunk)
{
	int		nb_ra;
	t_chunk	*pivot;
	t_chunk	*current;
	size_t	stack_size;

	stack_size = stacks->stack_b.index;
	pivot = filter_first_chunk_and_get_pivot(stacks->stack_b, clone);
	if (clone->index == 1)
	{
		push_to_a(stacks, 1, current_chunk);
		return ;
	}
	current = stacks->stack_b.get(&stacks->stack_b,
			stacks->stack_b.index - 1);
	nb_ra = filter_greater_number_and_push_to_a(current, stacks,
			pivot, current_chunk);
	if (clone->index != stack_size)
	{
		while (nb_ra)
		{
			nb_ra--;
			stacks->rrb(stacks, TRUE);
		}
	}
	pivot->free(pivot);
}
