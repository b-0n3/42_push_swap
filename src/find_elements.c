#include "push_swap.h"

t_bool	is_there_other_greater_elements(
		t_array_list *stack, t_chunk *pivot)
{
	int		i;
	t_chunk	*chunk;

	if (stack != NULL && pivot != NULL)
	{
		i = stack->index - 1;
		while (i >= 0)
		{
			chunk = stack->get(stack, i);
			if (chunk->chunk != pivot->chunk)
				return (TRUE);
			if (*(chunk->value) > *(pivot->value))
				return (TRUE);
			i--;
		}
	}
	return (FALSE);
}

t_bool	is_there_other_smaller_elements(
		t_array_list *stack, t_chunk *pivot)
{
	int		i;
	t_chunk	*chunk;

	if (stack != NULL && pivot != NULL)
	{
		i = stack->index - 1;
		while (i >= 0)
		{
			chunk = stack->get(stack, i);
			if (chunk->chunk != pivot->chunk)
				return (TRUE);
			if (*(chunk->value) < *(pivot->value))
				return (TRUE);
			i--;
		}
	}
	return (FALSE);
}
