/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:06:56 by aait-ham          #+#    #+#             */
/*   Updated: 2021/07/11 19:07:02 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_cmd(t_stacks *this)
{
	if (this != NULL)
		this->rra(this, FALSE);
}

void	reverse_rotate_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->rrb(this, FALSE);
}

void	reverse_rotate_a_and_b_cmd(t_stacks *this)
{
	if (this != NULL)
		this->rrr(this, FALSE);
}
