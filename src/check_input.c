/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:11:45 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:11:47 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool check_deplicate(t_stacks stacks)
{
	int i;
	int j;
	t_chunk *chunk;
	t_chunk *current;
	i =0;
	while (i < (int)stacks.stack_a.index)
	{
		j = i +1;
		chunk = stacks.stack_a.get(&stacks.stack_a, i);
		if (chunk != NULL)
			while(j < (int)stacks.stack_a.index)
			{
				current = stacks.stack_a.get(&stacks.stack_a, j);
				if (current != NULL && *(current->value) == *(chunk->value))
					return (TRUE);
				j++;
			}
		i++;
	}
	return (FALSE);
}

t_bool check_digits(char *item)
{
	int i;
	int signe;

	signe = 0;
	i = 0;
	while (item[i] != '\0')
	{
		if (signe == 0 && (item[i] == '-' ||  item[i] == '+'))
		{
			signe = 1;
			i++;
			continue;
		}
		if ((item[i] < '0' || item[i] > '9'))
			return FALSE;
		else
			signe = 1;
		i++;
	}
	return (i > 0);
}

int *ft_newnb(char *number)
{
	int *ptr;
	int nb;

	ptr = NULL;
	if (number == NULL || !check_digits(number))
		return NULL;
	nb = ft_atoi(number);
	if (nb >= INT32_MAX || nb <= INT32_MIN)
		return NULL;
	if ((ptr = (int *) malloc(sizeof(int))) == NULL)
		return NULL;
	ft_memcpy(ptr, &nb, sizeof(int));

	return ptr;
}
