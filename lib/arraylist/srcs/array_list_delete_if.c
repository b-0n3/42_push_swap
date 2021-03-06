/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_list_delete_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:36:27 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:08:55 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_list.h"

void	delete_if_free(t_array_list *this,
			t_bool (*cond)(void *item),
	 		void (*fe)(void *item), size_t ixx)
{
	size_t	i;

	i = 0;
	while (i < this->index)
	{
		if (!cond(this->arr[i]))
			ixx++;
		i++;
	}
	this->index = ixx + 1;
	while (ixx < this->length)
	{
		if (fe != NULL)
			fe(this->arr[ixx]);
		this->arr[ixx] = NULL;
		ixx++;
	}
}

void	delete_if(t_array_list *this,
			t_bool (*cond)(void *item),
			void (*fe)(void *item))
{
	size_t	i;
	size_t	x;
	size_t	ixx;

	i = 0;
	ixx = 0;
	while (i < this->index)
	{
		x = i + 1;
		if (cond(this->arr[i]))
		{
			if (fe != NULL)
				fe(this->arr[i]);
			while (x++ < this->index)
			{
				if (!cond(this->arr[x]))
				{
					this->swap(&(this->arr[i]), &(this->arr[x]));
					break ;
				}
			}
		}
		i++;
	}
	delete_if_free(this, cond, fe, ixx);
}
