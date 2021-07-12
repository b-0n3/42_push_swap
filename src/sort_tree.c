#include "push_swap.h"

int	get_min_pos(t_array_list list)
{
	int	min;
	int	i;
	int	index;

	i = 2;
	min = *(((t_chunk *)list.get(&list, i))->value);
	index = i;
	while (i >= 0)
	{
		if (min > *(((t_chunk *)list.get(&list, i))->value))
		{
			min = *(((t_chunk *)list.get(&list, i))->value);
			index = i;
		}
		i--;
	}
	return (index);
}

int	get_max_pos(t_array_list list)
{
	int	max;
	int	i;
	int	index;

	i = 2;
	max = *(((t_chunk *)list.get(&list, i))->value);
	index = i;
	while (i >= 0)
	{
		if (max < *(((t_chunk *)list.get(&list, i))->value))
		{
			max = *(((t_chunk *)list.get(&list, i))->value);
			index = i;
		}
		i--;
	}
	return (index);
}

void	sort_tree_a(t_stacks *stacks, int minpos, int maxpos)
{
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

void	sort_tree_b(t_stacks *stacks, int minpos, int maxpos)
{
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

void	sort_tree(t_stacks *stacks, t_bool is_a)
{
	int	minpos;
	int	maxpos;

	if (is_a)
	{
		minpos = get_min_pos(stacks->stack_a);
		maxpos = get_max_pos(stacks->stack_a);
		sort_tree_a(stacks, minpos, maxpos);
	}
	else
	{
		minpos = get_min_pos(stacks->stack_b);
		maxpos = get_max_pos(stacks->stack_b);
		sort_tree_b(stacks, minpos, maxpos);
	}
}
