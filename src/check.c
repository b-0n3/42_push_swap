/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:11:30 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:11:31 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_stack_is_sorted(t_array_list *list)
{
	int		i;
	t_chunk	*min;
	t_chunk	*current_value;

	if (list == NULL)
		return (FALSE);
	i = (int)(list->index - 1);
	min = (t_chunk *)list->get(list, i);
	while (i > 0)
	{
		i--;
		current_value = (t_chunk *)list->get(list, i);
		if (current_value->value != NULL && min->value != NULL)
			if (*(min->value) > *(current_value->value))
				return (FALSE);
		min = current_value;
	}
	return (TRUE);
}

t_bool	stack_a_is_sorted(t_stacks *this)
{
	if (this == NULL)
		return (FALSE);
	return (check_stack_is_sorted(&this->stack_a));
}

t_bool	stack_b_is_sorted(t_stacks *this)
{
	if (this == NULL)
		return (FALSE);
	return (check_stack_is_sorted(&this->stack_b));
}

t_bool	stack_a_is_empty(t_stacks *this)
{
	if (this == NULL)
		return (FALSE);
	return (this->stack_a.index == 0);
}

t_bool	stack_b_is_empty(t_stacks *this)
{
	if (this == NULL)
		return (FALSE);
	return (this->stack_b.index == 0);
}
