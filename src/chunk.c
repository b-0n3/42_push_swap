/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:11:57 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:11:58 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*new_chunk(int *value, int index)
{
	t_chunk	*chunk;

	if (value == NULL)
		return (NULL);
	chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (chunk != NULL)
	{
		chunk->value = value;
		chunk->index = index;
		chunk->chunk = 0;
		chunk->print = &print_chunk;
		chunk->free = &free_chunk;
	}
	return (chunk);
}

int	chunk_compare(void *v1, void *v2)
{
	t_chunk	*ch1;
	t_chunk	*ch2;

	if (v1 == NULL || v2 == NULL)
		return (-1);
	ch1 = (t_chunk *) v1;
	ch2 = (t_chunk *) v2;
	if (*(ch1->value) > *(ch2->value))
		return (1);
	if (*(ch1->value) < *(ch2->value))
		return (-1);
	return (0);
}

void	print_chunk(t_chunk *this)
{
	if (this != NULL && this->value != NULL)
	{
		ft_putnbr(*(this->value));
		ft_putstr("   chunk is ");
		ft_putnbr(this->chunk);
	}
}

void	free_chunk(void *this)
{
	if (this != NULL)
	{
		if (((t_chunk *)this)->value != NULL)
			free(((t_chunk *)this)->value);
		free(this);
	}
}

void	*clone_chunk(void *item)
{
	t_chunk	*chunk;
	int		*ptr;

	if (item == NULL)
		return (NULL);
	ptr = malloc(sizeof(int));
	if (ptr == NULL)
		return (NULL);
	memcpy(ptr, ((t_chunk *)item)->value, sizeof(int));
	chunk = new_chunk(ptr, ((t_chunk *)item)->index);
	if (chunk == NULL)
	{
		free(ptr);
		return (NULL);
	}
	chunk->chunk = ((t_chunk *)item)->chunk;
	return (chunk);
}
