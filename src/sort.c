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


void push_to_a(t_stacks *stacks, int nb, int chunk_n)
{
	void *ptr;

	while (nb > 0)
	{
		ptr = stacks->stack_b.get(&stacks->stack_b, stacks->stack_b.index - 1);
		((t_chunk*)ptr)->chunk = chunk_n;
		stacks->pa(stacks, TRUE);
		nb--;
	}
}

void push_to_b(t_stacks *stacks, int nb, int chunk_n)
{
	void *ptr;

	while (nb > 0)
	{
		ptr = stacks->stack_a.get(&stacks->stack_a, stacks->stack_a.index - 1);
		((t_chunk*)ptr)->chunk = chunk_n;
		stacks->pb(stacks, TRUE);
		nb--;
	}
}

void *clone_chunk(void *item)
{
	t_chunk *chunk;
	int *ptr;

	if (item == NULL)
		return NULL;
	if ((ptr = malloc(sizeof(int))) == NULL)
		return NULL;
	memcpy(ptr, ((t_chunk *)item)->value, sizeof(int));
	chunk =  new_chunk(ptr, ((t_chunk *)item)->index);
	if (chunk == NULL)
	{
		free(ptr);
		return NULL;
	}
	chunk->chunk = ((t_chunk *)item)->chunk;
	return chunk;
}

t_chunk *filter_first_chunk_and_get_pivot(t_array_list stack, t_array_list *clone)
{
	t_chunk *chunk;
	int i;
	int chunk_nb;

	chunk = stack.get(&stack, stack.index - 1);
	i = stack.index - 1;

	if (chunk != NULL)
	{
		chunk_nb = chunk->chunk;
		while (i >= 0)
		{
			chunk = stack.get(&stack , i);
			if (chunk != NULL && chunk->chunk == chunk_nb)
				// break;
				clone->push(clone, clone_chunk(chunk), sizeof(t_chunk *));
			i--;
		}
		clone->sort(clone, chunk_compare, 0 ,clone->index - 1);
		chunk =(t_chunk *) clone_chunk(clone->get(clone, clone->index /2));
	}
	return chunk;
}
t_bool is_there_other_greater_elements(t_array_list *stack, t_chunk *pivot)
{
	int i;
	t_chunk *chunk;

	if(stack != NULL && pivot != NULL)
	{
		i = stack->index -1;
		while (i >= 0)
		{
			chunk = stack->get(stack, i);
			if (chunk->chunk != pivot->chunk)
				return TRUE;
			if (*(chunk->value) > *(pivot->value))
				return TRUE;
			i--;
		}        
	}
	return FALSE;
}

t_bool is_there_other_smaller_elements(t_array_list *stack, t_chunk *pivot)
{
	int i;
	t_chunk *chunk;

	if(stack != NULL && pivot != NULL)
	{
		i = stack->index -1;
		while (i >= 0)
		{
			chunk = stack->get(stack, i);
			if (chunk->chunk != pivot->chunk)
				return TRUE;
			if (*(chunk->value) < *(pivot->value))
				return TRUE;
			i--;
		}        
	}
	return FALSE;
}

void clone_a_first_chunks_and_sort_it(
		t_stacks *stacks,
		t_array_list *clone,
		int current_chunk
		)
{
	int nb_ra = 0;
	t_chunk *pivot;
	t_chunk *current;
	size_t stack_size = stacks->stack_a.index;

	pivot = filter_first_chunk_and_get_pivot(stacks->stack_a, clone);
	if (clone->index <= 2)
	{
		if(!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 1 )
			stacks->sa(stacks , TRUE);
		return;
	}
	while (
			(current = stacks->stack_a.get(&stacks->stack_a, stacks->stack_a.index -1)) != NULL
			&& is_there_other_smaller_elements(&stacks->stack_a, pivot))
	{
		if(current->chunk != pivot->chunk)
			break;
		if (*(current->value) < *(pivot->value))
		{

			push_to_b(stacks, 1, current_chunk);
		}
		else
		{
			nb_ra++;
			stacks->ra(stacks, TRUE);
		} 
	}
	if (clone->index != stack_size)
		while (nb_ra)
		{
			nb_ra--;
			stacks->rra(stacks, TRUE);
		}
	pivot->free(pivot);
}



void clone_b_first_chunks_and_sort_it(
		t_stacks *stacks,
		t_array_list *clone,
		int current_chunk
		)
{
	int nb_ra = 0;
	t_chunk *pivot;
	t_chunk *current;

	size_t stack_size = stacks->stack_b.index;
	pivot = filter_first_chunk_and_get_pivot(stacks->stack_b, clone);

	if (clone->index == 1)
	{

		//stacks->pa(stacks);
		push_to_a(stacks, 1, current_chunk);
		return;
	}
	while (
			(current = stacks->stack_b.get(&stacks->stack_b, stacks->stack_b.index -1))!= NULL
			&& is_there_other_greater_elements(&stacks->stack_b, pivot))
	{
		if(current->chunk != pivot->chunk)
			break;
		if (*(current->value) > *(pivot->value))
		{

			// stacks->pa(stacks);
			push_to_a(stacks, 1, current_chunk);
		}
		else
		{
			nb_ra++;
			stacks->rb(stacks, TRUE);
		}

	}
	if (clone->index != stack_size)
		while (nb_ra )
		{
			nb_ra--;
			stacks->rrb(stacks, TRUE);
		}
	pivot->free(pivot);
}



void sort_stacks(t_stacks *stacks)
{
	t_array_list clone;

	static int  current_chunk;

	current_chunk++;


	if (stacks->stack_a.index == 3)
		sort_tree(stacks, TRUE);
	if (stacks->stack_b.index == 3)
	{
		sort_tree(stacks, FALSE);
		if (stacks->a_is_sorted(stacks))
			push_to_a(stacks , 3 , current_chunk);
	}
	new_array_list(&clone ,  10 , sizeof(t_chunk *));
	if (!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 2)
	{
		clone_a_first_chunks_and_sort_it(stacks ,&clone, current_chunk);

		clone.free(&clone , &free_chunk);
		sort_stacks(stacks);
	}
	if (stacks->stack_a.index == 2)
	{
		if(!stacks->a_is_sorted(stacks) && stacks->stack_a.index > 1)
			stacks->sa(stacks , TRUE);
	}
	if (stacks->stack_b.index == 2)
	{
		if(stacks->b_is_sorted(stacks))
			stacks->sb(stacks , TRUE);
		if (stacks->stack_b.index ==2)
			push_to_a(stacks , 2 , current_chunk);
	}
	if (!stacks->b_is_empty(stacks))
	{
		clone_b_first_chunks_and_sort_it(stacks ,&clone,current_chunk);
		clone.free(&clone , &free_chunk);
		sort_stacks(stacks);
	}
	if (clone.arr != NULL)
		clone.free(&clone , &free_chunk);
}


int get_min_pos(t_array_list list)
{
	int min;
	int i;
	int index;

	i = 2;
	min = *(((t_chunk *) list.get(&list, i))->value);
	index = i;
	while (i >=0)
	{
		if (min > *(((t_chunk *) list.get(&list, i))->value))
		{
			min = *(((t_chunk *) list.get(&list, i))->value);
			index = i;
		}
		i--;
	}
	return index;

}

int get_max_pos(t_array_list list)
{
	int max;
	int i;
	int index;

	i = 2;
	max = *(((t_chunk *) list.get(&list, i))->value);
	index = i;
	while (i >= 0)
	{
		if (max < *(((t_chunk *) list.get(&list, i))->value))
		{
			max = *(((t_chunk *) list.get(&list, i))->value);
			index = i;
		}
		i--;
	}
	return index;
}

void sort_tree(t_stacks *stacks, t_bool is_a)
{

	int minpos;
	int maxpos;

	if (is_a)
	{
		minpos = get_min_pos(stacks->stack_a);
		maxpos = get_max_pos(stacks->stack_a);
		if (minpos == 1 && maxpos == 0)
			stacks->sa(stacks, TRUE);
		if (maxpos == 2 && minpos == 0)
		{
			stacks->sa(stacks, TRUE);
			stacks->rra(stacks, TRUE);
		}
		if (minpos == 1 && maxpos == 2)
			stacks->ra(stacks, TRUE);
		if (minpos == 0 && maxpos == 1)
			stacks->rra(stacks, TRUE);
		if (maxpos == 1 && minpos == 2)
		{
			stacks->sa(stacks, TRUE);
			stacks->ra(stacks, TRUE);
		}

	}
	else
	{
		minpos = get_min_pos(stacks->stack_b);
		maxpos = get_max_pos(stacks->stack_b);
		if (minpos == 1 && maxpos == 0)
			stacks->rrb(stacks, TRUE);

		if (minpos == 1 && maxpos == 2)
		{
			stacks->rb(stacks, TRUE);
			stacks->sb(stacks, TRUE);
			stacks->rrb(stacks, TRUE);
		}
		if (minpos == 0 && maxpos == 1)
			stacks->sb(stacks, TRUE);
		if (maxpos == 1 && minpos == 2)
			stacks->rb(stacks, TRUE);
	}
}

