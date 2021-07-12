#include "push_swap.h"

t_chunk	*filter_first_chunk_and_get_pivot(
		t_array_list stack, t_array_list *clone)
{
	t_chunk	*chunk;
	int		i;
	int		chunk_nb;

	chunk = stack.get(&stack, stack.index - 1);
	i = stack.index - 1;
	if (chunk != NULL)
	{
		chunk_nb = chunk->chunk;
		while (i >= 0)
		{
			chunk = stack.get(&stack, i);
			if (chunk != NULL && chunk->chunk == chunk_nb)
				clone->push(clone, clone_chunk(chunk), sizeof(t_chunk *));
			i--;
		}
		clone->sort(clone, chunk_compare, 0, clone->index - 1);
		chunk = (t_chunk *)clone_chunk(clone->get(clone, clone->index / 2));
	}
	return (chunk);
}
